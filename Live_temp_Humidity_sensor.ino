#include <dht.h>
#include <LiquidCrystal.h>

#define DHT11_PIN 3
dht DHT;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // the necessary pins for LCD to work

const int sensorPin = 2; // Input pin for LDR
const int sensorValue = 0; // Variable to store the value coming from the LDR
const int voltagePin = 4; // pin to control the power supply to the Humidity and Temp sensor

void setup() {
  Serial.begin(9600);
  switchOffBuiltInLED();
  pinMode(voltagePin, OUTPUT);
  
  digitalWrite(voltagePin, HIGH);
  lcd.begin(16,2);
}

void loop() {
  
  if(isLightOn()){
    //print Temp and humidity values on the LCD display
    giveTempAndHumidityValues(DHT);
  }

  else {
    digitalWrite(voltagePin, LOW); //This is where power consumption is reduced
  }
  
  delay(1098);  //IDK y but, if u reduce the time less than this, u start getting negative values for the temp and humidity, which we don't want
                //besides that, 1098 is child helpline number in India ;)
}

void switchOffBuiltInLED(){ //Switching of that built in LED also saves power
  int BuiltInLEDpin = 13;
  pinMode(BuiltInLEDpin, OUTPUT);
  digitalWrite(BuiltInLEDpin, LOW);
}

bool isLightOn(){
  /*read the value from the sensor : if light is available --> sensorValue = 0 , else sensorValue = 1
  (IK this is weird, but I didn't make it so can't complaint much about it*/
  sensorValue = digitalRead(sensorPin);
  return (!sensorValue);
}

void giveTempAndHumidityValues(dht DHT){
  //print Out temp and humidity for now, as I don't have the LCD display
  DHT.read11(DHT11_PIN);
  digitalWrite(voltagePin, HIGH); //This is IMP
  lcd.clear(); //Clearing previous display
  lcd.setCursor(0,0);
  lcd.print("Temp = " + String(DHT.temperature) + " `C");
  lcd.setCursor(0,1);
  lcd.print("Humidity=" + String(DHT.humidity) + "%");
}
