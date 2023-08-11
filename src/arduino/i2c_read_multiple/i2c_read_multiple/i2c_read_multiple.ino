#include <Wire.h> // I2C communication with wire library

// display
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
int displayMode = 0; // 0: CO2, 1: Temperature (T), 2: Relative Humidity (RH)

// button
#define BUTTON_PIN 7
int lastButtonState;

// hexadecimal I2C addresses as global const
#define I2C_ADDRESS_CO2 0x62
#define I2C_ADDRESS_DISPLAY 0x3C


void setup() {
  
  // co2
  Serial.begin (9600); 
  Wire.begin();
  // start_periodic_measurement = 0x21b1 --> arduino library can only send 1 byte a time
  // ready to read afterwards
  Wire.beginTransmission(I2C_ADDRESS_CO2); 
  Wire.write(0x21);  
  Wire.write(0xb1);  
  Wire.endTransmission();   

  // oled
  display.begin(SSD1306_SWITCHCAPVCC, I2C_ADDRESS_DISPLAY);
  display.clearDisplay();

  // button
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // enable the internal pull-up resistor
  lastButtonState = digitalRead(BUTTON_PIN);

} 


void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
    if (lastButtonState != buttonState) {
      delay(50); // Debounce time
      lastButtonState = buttonState;
  
      if (buttonState == LOW) {
        // Cycle through display modes: CO2 -> T -> RH
        displayMode = (displayMode + 1) % 3;
      }
    }



// co2

  // co2 read = 0xec05
  Wire.beginTransmission(I2C_ADDRESS_CO2); 
  Wire.write(0xec);   
  Wire.write(0x05); 
  Wire.endTransmission();    

  // read [co2, T, RH], 3 bytes each
  Wire.requestFrom(I2C_ADDRESS_CO2,9);  
  uint8_t v0 = Wire.read();
  uint8_t v1 = Wire.read();
  uint8_t v2 = Wire.read();
  uint8_t v3 = Wire.read();
  uint8_t v4 = Wire.read();
  uint8_t v5 = Wire.read();
  uint8_t v6 = Wire.read();
  uint8_t v7 = Wire.read();
  uint8_t v8 = Wire.read();

  // big-endian order = most significant byte is sent first
  // word0 constructed by shifting v0 by 8 bits to the left and then combining it with v1.
  // this forms a 16-bit value representing CO2 concentration.
  uint16_t word0 = (v0 << 8) | v1;  // co2 [ppm]
  Serial.print(word0);
  Serial.print(' ');

  // 1u in binary is                      0000000000000001 
  // shifting it left by 16 bits gives    1000000000000000
  // Subtracting 1 from that gives range  0111111111111111
  // range = 65535 = max value of unsigned 16-bit integer
  const uint32_t range = (1u << 16)-1;

  uint16_t word1 = (v3 << 8) | v4;
  float T = -45 + 175*static_cast<float>(word1)/( range );  // T [°C]
  Serial.print(T);
  Serial.print(' ');
  
  // word2 = RH
  uint16_t word2 = (v6 << 8) | v7;
  float RH = 100 * static_cast<float>(word2)/( range );
  Serial.print(RH);
  Serial.print(' ');

  // output serial line
  Serial.println();



// display

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

switch (displayMode) {
    case 0:
      display.print("CO2: ");
      display.println(word0);
      display.print("[ppm]");
      break;
    case 1:
      display.print("T: ");
      display.println(T);
      display.print("[C]");
      break;
    case 2:
      display.print("RH: ");
      display.println(RH);
      display.print("[%]");
      break;
  }


  display.display();

  // delay between measurements
  delay(5000);
}
