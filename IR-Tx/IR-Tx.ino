#include <IRremote.h>
IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  //if (Serial.read() != -1) {
    //for (int i = 0; i < 3; i++) {
      //irsend.sendNEC(0xEAD02569, 32);  //HEX of Rx Data
      irsend.sendNEC(0xD67E4BC0, 32);
      //delay(100);
      irsend.sendNEC(0x07200000, 28);
      irsend.sendNEC(0xFFFFFFFF, 32);  //HEX of Rx Data

      //FB38C7

      //irsend.sendNEC(0x00FB38C7, 32);
      //irsend.sendNEC(0xFFFFFFFF, 32);  //HEX of Rx Data
      
      Serial.println("Tx");
      delay(10000);
    //}
  //}
} 
