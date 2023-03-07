
# Ambiainvis

Environmental monitoring to welcome you home.

A creation from the Romansh words for environment (ambiaint) and welcome (bainvis).

## Overview

![Overview](Ambiainvis.drawio.png)

## Sensors

### Humidity & Temperature - Si7021

- Interface: I2C
- Relative Humdity Range: 0% - 100%
- Relative Humdity Accuracy (Typical, 0% - 80%): ±2%
- Temperature Range: -40°C - 85°C
- Temperature Accuracy (Typical, -10°C - 85°C): ±0.3°C
- Voltage: 1.9V - 3.6V
- Current: ???

https://www.silabs.com/documents/public/data-sheets/Si7021-A20.pdf

https://aliexpress.com/item/4000074032970.html

### Humidity & Temperature - SHT30-D

- Interface: I2C
- Relative Humdity Range: 0% - 100%
- Relative Humdity Accuracy (Typical, 10% - 90%): ±2%
- Temperature Range: -40°C - 125°C
- Temperature Accuracy (Typical, 0°C - 65°C): ±0.2°C
- Voltage: 2.15V - 5.5V
- Current: ???

https://sensirion.com/products/catalog/SHT30-DIS-B/
https://sensirion.com/media/documents/213E6A3B/63A5A569/Datasheet_SHT3x_DIS.pdf

https://aliexpress.com/item/32700729302.html

### NDIR CO2 - SCD40

- Interface: I2C
- CO2 Range: 0ppm - 40'000ppm
- CO2 Accuracy (400ppm - 2'000ppm): ±50ppm
- Relative Humdity Range: 0% - 100%
- Relative Humdity Accuracy (Typical, 15°C - 35°C, 20% - 65%): ±6%
- Temperature Range: -10°C - 60°C
- Temperature Accuracy (Typical, 15°C - 35°C): ±0.8°C
- Voltage: 2.4V - 5.5V
- Current (Typical, Periodic, 3.3V): 15mA

https://sensirion.com/products/catalog/SCD40/
https://sensirion.com/media/documents/E0F04247/631EF271/CD_DS_SCD40_SCD41_Datasheet_D1.pdf

https://aliexpress.com/item/1005004494206882.html

### CO2 - Senseair S8

- Interface: I2C
- CO2 Range: ???
- CO2 Accuracy: ???
- Voltage: ???
- Current: ???

https://senseair.com/products/size-counts/s8-residential/
https://senseair.com/products/size-counts/s8-2/

https://aliexpress.com/item/32863793412.html

### CO2 - Senseair Sunrise CO2

- Interface: I2C
- CO2 Range: ???
- CO2 Accuracy: ???
- Voltage: ???
- Current: ???

https://senseair.com/products/power-counts/sunlight-co2/

### CO2 - MH-Z19

- Interface: I2C
- CO2 Range: ???
- CO2 Accuracy: ???
- Voltage: ???
- Current: ???

### TVOC/eCO2 - CJMCU-811

https://aliexpress.com/item/1005003829532007.html

- Interface: I2C
- CO2 Range: ???
- CO2 Accuracy: ???
- Voltage: ???
- Current: ???

### Particulate Matter - PMS5003/PMS7003

- Interface: ???
- Accuracy PM2.5: ???
- Voltage: ???
- Current: ???

https://aqicn.org/sensor/pms5003-7003/
https://aqicn.org/air/sensor/spec/pms5003-english-v2.3.pdf
https://aqicn.org/air/sensor/spec/pms7003-english-v2.5.pdf

### Ozone - MQ131

### VOC - MP503

### Pressure - MPL3115A2

- Interface: ???
- Voltage: ???
- Current: ???

### Pressure - DPS310

- Interface: ???
- Voltage: ???
- Current: ???

## Actors

### NVRAM - AT24C256

- Interface: I2C
- Storage (Bytes): ???
- Voltage: ???
- Current: ???

https://aliexpress.com/item/1005003469549569.html

### Display - SSD1306

- Interface: I2C
- Voltage: ???
- Current: ???

https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf

https://github.com/adafruit/Adafruit_SSD1306

## Environment Values

### CO2

Outside (2023): 420 ppm
Outside (1950): 311 ppm

https://www.volker-quaschning.de/datserv/CO2/index.php

- \< 1'000 ppm: everything fine
- \> 2'000 ppm: fresh air necessary

https://www.umweltbundesamt.de/sites/default/files/medien/pdfs/kohlendioxid_2008.pdf

- \> 30'000 ppm / 30 minutes: intoxication
- \> 70'000 ppm / 2 minutes: unconsciousness
- \> 100'000 ppm: dangerous for life

https://www.cdc.gov/niosh/idlh/124389.html

### Relative Humidity

- 30% - 65%: comfortable for humans
- \> 60%: increased probability for molds
- 40% - 60% & 18°C - 23°C: ideal for wood (floor, furniture, ...), as wood does not contract/expand in this range

https://www.umweltbundesamt.de/sites/default/files/medien/publikation/long/2885.pdf
https://www.umweltbundesamt.de/themen/faq-absenkung-der-raumtemperatur-in-herbst-winter
https://www.venta-air.com/en_de/Usage/Humidity-for-wooden-floors-and-furniture/

## Abbreviations

| Abbreviation | Description |
| -- | -- |
| TVOC | Total Volatile Organic Compound |
| eCO2 | Equivalent CO2 |
| NDIR | Non-Dispersive Infrared |
| VOC | Volatile Organic Compound |

https://en.wikipedia.org/wiki/Volatile_organic_compound
https://en.wikipedia.org/wiki/Nondispersive_infrared_sensor