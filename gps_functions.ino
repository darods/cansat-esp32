void gps_init()
{
  RGBLed_progress();
  Serial.begin(115200); //Serial port of USB
  SerialGPS.begin(9600, SERIAL_8N1, 16, 17);

  Serial.println(F("-------------------------------------"));
  Serial.println(F("GPS inizalization"));
  Serial.println(F("-------------------------------------"));
}

String gps_data(){
  while (SerialGPS.available() >0) {
       gps.encode(SerialGPS.read());
    }
    String packet="";
    Serial.print(F("GPS:\t"));
    Serial.print(F("LAT= "));  
    Serial.print(gps.location.lat(), 6);
    packet+=(String)gps.location.lat()+",";
    Serial.print("\t");
    Serial.print(F("LONG= ")); 
    Serial.print(gps.location.lng(), 6);
    packet+=(String)gps.location.lng()+",";
    Serial.print("\t");
    Serial.print(F("ALT= "));  
    Serial.print(gps.altitude.meters());
    packet+=(String)gps.altitude.meters()+",";
    Serial.println();
    return packet;
}
