void setupBMP(){
  bmp.begin();
  bmp.getEvent(&event);
  //Checks if sensor can actually get pressure (if not then it doesnt work)
  if(event.pressure){
    Serial.println("BMP OK");
    Serial.println();
  }
  
}

//Get temperature
void callTemp(){
    bmp.getTemperature(&temp);
    TeleArray[TeleTemperature] = temp;
}

//Gets current altitude
void callAlt(){
  bmp.getEvent(&event);
  currentAltitude = bmp.pressureToAltitude(initialPressure, event.pressure);
  TeleArray[TeleAltitude] = currentAltitude;  //Converts current pressure to altitude based on initial pressure
}

//Gets initial pressure
void callInitialPressureAndAltitude(){
  bmp.getEvent(&event);
  initialPressure = event.pressure;
  initialAltitude = bmp.pressureToAltitude(initialPressure, event.pressure); 
}



