#include <dht.h>
#define DHT11_PIN 3
dht DHT;

int sensorPin = 2; // select the input pin for LDR
int sensorValue = 0; // Variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
  switchOffBuiltInLED();
}

void loop() {
  
  if(isLightOn()){
    //give Temp and humidity values to LCD display
    giveTempAndHumidityValues(DHT);
  }

  else {
    //Serial.write("Light is off\n");
  }
  delay(1098);  //IDK y but, if u reduce the time less than this, u start getting negative values for the temp and humidity, which we don't want
                //besides that, 1098 is child helpline number in India ;)

}

void switchOffBuiltInLED(){
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
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.print(" C\n");
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("\n\n");
  
}
