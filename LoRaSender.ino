void LoRa_init()
{
  LoRa.setPins(ss, rst, dio0); 
  while (!LoRa.begin(433E6))     //433E6 - Asia, 866E6 - Europe, 915E6 - North America
  {
    Serial.println(".");
    delay(500);
    
  }LoRa.setSyncWord(0xA5);
  Serial.println("LoRa Initializing OK!");
}

void sendPacket(String packet){
  LoRa.beginPacket();   //Send LoRa packet to receiver
  LoRa.print(packet);
  LoRa.endPacket();
}
