#include <IRremote.h>
IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  //if (Serial.read() != -1) {
    //for (int i = 0; i < 3; i++) {
      irsend.sendNEC(0xEAD02569, 32);  //HEX of Rx Data
      //irsend.sendNEC(0x7200000, 32);
      irsend.sendNEC(0xFFFFFFFF, 32);  //HEX of Rx Data
      Serial.println("Tx");
      delay(5000);
    //}
  //}
} 
