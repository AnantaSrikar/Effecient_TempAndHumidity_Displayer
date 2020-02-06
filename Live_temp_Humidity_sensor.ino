#include <dht.h>
#include <LiquidCrystal.h>

#define DHT11_PIN 6
dht DHT;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // the necessary pins for LCD to work

const int sensorPin = 7; // Input pin for LDR. Use 3.3V power supply for LDR
int sensorValue = 0; // Variable to store the value coming from the LDR
const int voltagePin = 8; // pin to control the power supply to the Humidity and Temp sensor
const int vPinLCD = 9; // pin to control the power supply to the LCD

void setup() {
  Serial.begin(9600);
  switchOffBuiltInLED();
  pinMode(voltagePin, OUTPUT);
  pinMode(vPinLCD, OUTPUT);
  digitalWrite(voltagePin, HIGH);
  digitalWrite(vPinLCD, HIGH);
  lcd.begin(16,2);
}

void loop() {
  
  if(isLightOn()){
    //print Temp and humidity values on the LCD display
    giveTempAndHumidityValues(DHT);
  }

  else {
    savePower();
  }
  
  delay(2000);  //IDK y but, if u reduce the time less than this, u start getting negative values for the temp and humidity, which we don't want
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

void resetLCD(){
  lcd.begin(16,2);  
}

void savePower(){   //This is where power consumption is reduced
  digitalWrite(voltagePin, LOW);
  digitalWrite(vPinLCD, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
}

void giveTempAndHumidityValues(dht DHT){
  DHT.read11(DHT11_PIN);
  digitalWrite(voltagePin, HIGH); //Ths is IMP
  digitalWrite(vPinLCD, HIGH);
  resetLCD();
  //Serial.println("Temp : " + String(DHT.temperature) + " C\nHumidity : " + String(DHT.humidity) + "%\n\n");
  lcd.clear(); //Clearing previous display
  lcd.setCursor(0,0);
  lcd.print("Temp = " + String(DHT.temperature) + " C");
  lcd.setCursor(0,1);
  lcd.print("Humidity=" + String(DHT.humidity) + "%");
}
