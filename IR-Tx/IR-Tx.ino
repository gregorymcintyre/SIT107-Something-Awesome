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
#define OPTIMALTEMP 30  //set optimal temp here
#define OPTIMALHUM 90   //set optimal humm here

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino


//Variables
IRsend irsend;
bool flag;  //indicates if message needs to be sent
bool sent;  //indicates if message was sent
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

  /*
  Serial.print("Humidity: ");   //error checking
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  */
  
  flag = 0;
  sent = 0;

  if(hum>=OPTIMALHUM && temp>=OPTIMALTEMP){

    flag = 1;                     //indicates code needs to be sent

  }else{

    sent = 0;                   //no message has been sent (also gives portenital for the program to turn off the sircon when it is under temp in future iterations
  
  }

  if (flag && !sent) {
    unsigned int irSignal[] = {3500, 1650, 450, 400, 450, 1250, 450, 350, 450, 400, 450, 350, 500, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 1250, 450, 350, 500, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 1250, 450, 1250, 450, 1250, 450, 400, 450, 350, 450, 1300, 450, 350, 450, 350, 500, 350, 450, 350, 500, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450, 350, 450, 400, 450}; //AnalysIR Batch Export (IRremote) - RAW
    irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), KHZ); //Note the approach used to automatically calculate the size of the array.
    //Serial.println("Tx"); //to indicate Trasmission during testing
    sent = 1;                                   //indicates code has been sent to reduce excessive sending.
  }
  
  delay(2000);      //sample every 2 seconds
}
