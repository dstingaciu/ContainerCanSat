//Transmits data through XBee
void transmitData() {
  if(Serial.available()){
    receiveSerialData();
  }
  Serial.print(TeamID);
  Serial.print(',');
  Serial.print("CONTAINER");
  Serial.print(',');
  
  for (int telem = 1; telem < TeleArrayLength-2; telem++){
    Serial.print(TeleArray[telem]);
    Serial.print(',');
    writeToSD('d', TeleArray[telem]);
  }

  Serial.println();
}

//The whole point of this is for the last stage in order to send GPS location on command so the whole point of this is just that it waits for that command to be sent
void transmitOneTelem(int telem){
  if(Serial.available()){
    receiveSerialData();
  }
  
}

//Waits for a command and does a certain task based on that command
void receiveSerialData() {
//Receive single char that was transmitted by ground station
  int command = Serial.read();
  switch(command){
    case '*' : 
    deploy();
    break;
    case '@' :
    callGPS();
    Serial.println(TeleArray[TeleLong]);
    Serial.println(TeleArray[TeleLat]);
    break;
  }
//If it is a certain char, ex '*', release the payload
}

//Pretty much starts off buzzer but in actuality can change and pin to HIGH or LOW
void writeDPin(){
  int pin;
  if(softwareState == 8){
    pin = 4;
    pinMode(pin, OUTPUT); // Set pin as an OUTPUT
    digitalWrite(pin, HIGH); // Write pin accordingly
  }
}



// dealys time by one second
void timeDelay(){
  unsigned long tempSecs = millis();
  while(millis()-tempSecs < 1000){}
}
