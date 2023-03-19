#include <Wire.h>

// global const
#define I2C_ADDRESS 0x62

void setup() {
  Serial.begin (115200);  // setup serial connection
  Wire.begin();

  // start_periodic_measurement = 0x21b1 --> arduino library can only send 1 byte a time
  // ready to read afterwards
  Wire.beginTransmission(I2C_ADDRESS); 
  Wire.write(0x21);  
  Wire.write(0xb1);  
  Wire.endTransmission();    

} 

void loop() {

// WRITE

// read_measurement = 0xec05
  Wire.beginTransmission(I2C_ADDRESS); 
  Wire.write(0xec);   
  Wire.write(0x05); 
  Wire.endTransmission();    

  Wire.requestFrom(I2C_ADDRESS,9); // number of bytes to read
  
  // Wire library = I2C
  // store 3x values to measure each [co2, T, RH]
    uint8_t v0 = Wire.read();
    uint8_t v1 = Wire.read();
    uint8_t v2 = Wire.read();
    uint8_t v3 = Wire.read();
    uint8_t v4 = Wire.read();
    uint8_t v5 = Wire.read();
    uint8_t v6 = Wire.read();
    uint8_t v7 = Wire.read();
    uint8_t v8 = Wire.read();

  // shift by 8 bits and apply on trailing zeros to copy v(x) to v(x+1)
    // word0 = ppm
    uint16_t word0 = (v0 << 8) | v1;
    Serial.print(word0);
    Serial.print(' ');

    // range used to calculate T and RH
    const uint32_t range = (1u << 16)-1;

    // wort1 = T
    uint16_t word1 = (v3 << 8) | v4;
    float T = -45 + 175*static_cast<float>(word1)/( range );
    Serial.print(T);
    Serial.print(' ');
    
    // wort2 = RH
    uint16_t word2 = (v6 << 8) | v7;
    float RH = 100 * static_cast<float>(word2)/( range );
    Serial.print(RH);
    Serial.print(' ');

  // output serial line
  Serial.println();

  // delay between measurements
  delay(5000);
}




















