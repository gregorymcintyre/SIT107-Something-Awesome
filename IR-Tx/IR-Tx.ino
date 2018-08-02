/*
 * Automated IR Remote using a DHT22 Temp and Humidity Sensor, the K845754 IR Reciever and the K851262 IR Transmitter.
 * 
 * This code includes elements from a modified version of Ken Shirriff's IRremote: IRsendRawDemo
 * This code included elements from a modified version of niroshini's DHT22tempHum
 * 
 * this code is designed to work with a CS-S9JKR air conditioner
 */


#include <IRremote.h>
#include <DHT.h>

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
#define KHZ 38
#define OPTIMALTEMP 30
#define OPTIMALHUM 90

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino


//Variables
IRsend irsend;
bool flag;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Serial.begin(9600); //not essential used for testing
  dht.begin();
}

void loop() {

  hum = dht.readHumidity();
  temp= dht.readTemperature();
  flag = 0;

  if(hum>=OPTIMALHUM && temp>=OPTIMALTEMP){

  /*
  Serial.print("Humidity: ");   //error checking
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  */

  flag =1;
   
  //Serial.println("Tx"); //to indicate Trasmission during testing
  }

  if (flag) {
    unsigned int irSignal[] = {3500, 1650, 450, 400, 450, 1250, 450, 350, 450, 400, 450, 350, 500, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 1250, 450, 350, 500, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 1250, 450, 1250, 450, 1250, 450, 400, 450, 350, 450, 1300, 450, 350, 450, 350, 500, 350, 450, 350, 500, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450}; //AnalysIR Batch Export (IRremote) - RAW
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), KHZ); //Note the approach used to automatically calculate the size of the array.
  }
  
  delay(2000);
  
}
