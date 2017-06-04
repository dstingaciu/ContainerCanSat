void setupGPS() {
  GPS.begin(19200);
  Serial.begin(19200);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);  // Selects output type from GPS
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);   // 1 Hz update rate
  Serial.println("GPS OK...");
}

//updates GPS data
uint32_t timer = millis();
void callGPS() {
  char c = GPS.read();
  if (GPS.newNMEAreceived()) {
    if (!GPS.parse(GPS.lastNMEA()))   // This sets the newNMEAreceived() flag to false
      return;  // If fail to parse a sentence in which case we should just wait for another
  }

  // If millis() or timer wraps around, we'll just reset it
  if (timer > millis())  timer = millis();

  // Approximately every 1 seconds or so, save the current Lat/Long values
  if (millis() - timer >  1000) { 
    timer = millis(); // reset the timer
    Serial.print("Location (in degrees): ");   // Comment to hide debugging output
    Serial.print(GPS.latitudeDegrees, 6);      //
    Serial.print(", ");                        //
    Serial.println(GPS.longitudeDegrees, 6);   //
    TeleArray[TeleLat] = float(GPS.latitudeDegrees);
    TeleArray[TeleLong] = float(GPS.longitudeDegrees);
  }
}
