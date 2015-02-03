//Maker REmote RX : Chiangmai maker club

#include <SPI.h>
#include <nRF24L01p.h>

nRF24L01p receiver(7,8);//CSN,CE
static unsigned long curr_time;
static unsigned long prev_time;
unsigned long time;
void setup(){
  delay(150);
  Serial.begin(115200);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  receiver.channel(90);  // ตั้งช่องความถี่ให้ตรงกัน
  receiver.RXaddress("ALL");  // ตั้งชื่อตำแห่นงให้ตรงกัน ชื่อตั้งได้สูงสุด 5 ตัวอักษร
  receiver.init();
}

String message;

void loop()
{ 

  if(receiver.available()){
    receiver.read(); // สั่งให้เริ่มอ่าน
    receiver.rxPL(message); // สั่งใหอ่านเก็บไว้ที่ตัวแปร
    prev_time = curr_time;
    curr_time = micros();
    time = curr_time - prev_time;
    Serial.println(time);
    message="";
  }
}
