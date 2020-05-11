# Power Efficient Temperature and Humidity Displayer
## Project Description
After a lot of messing around with the LCD, I figured out that the LCD backlight consumes the most power in the whole circuit. Turning off sensors don't really matter. Hence, the backlight of the LCD turns on only when there's not enough light in the surroundings, thus making it truely power efficient

## Requirements
* Arduino (I used an Nano here)
* LDR module (To detect light, obviously)
* Temperature and Humidity module (I have used a DHT11 here)
* A LCD display

## Connections
* LCD : [From Arduino's](https://www.arduino.cc/en/Tutorial/HelloWorld) official page. The second pin from right of LCD to D8
* LDR Module : 3.3V power supply, GND, Data pin to D7
* DHT module : Vcc to 5V, GND, Data pin to D6

The project is almost complete. Bread board model working as expected. Final product to be ready.