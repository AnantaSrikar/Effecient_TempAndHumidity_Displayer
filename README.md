# Power Efficient Temperature and Humidity Displayer
## Project Description
Basically, the sensors work and show the values only when there's enough light for the user to see, the other times the sensor is switched off and reduces the power consumption of the device.
## Requirements
* Arduino (I used an UNO here)
* LDR module (To detect light, and then display the Temperature and Humidity)
* Temperature and Humidity module (I have used a DHT11 here)
* A LCD display (still have to buy one yet, so stay tuned)

## Connections
* LCD : [From Arduino's](https://www.arduino.cc/en/Tutorial/HelloWorld) official page
* LDR Module : 3.3V power supply, GND, Data pin to D7
* DHT module : Vcc to D8, GND, Data pin to D6

The project should work as expected
