void setupMissionTime(){
  DateTime now = rtc.now();
  int missionStartTime = now.second();
}


//Calls all sensors just so I dont have to repeat this over and over again
void callAll(){
  callTemp();
  callAlt();
  callRTC();
  callGPS();
}

/*
 *These are all the states that the software will go through 
 */
void boot(){
  //int states = readData(sState).toFloat();
  /*if(states != 0){
    softwareState = int8_t(states);
    packetCount = readData(pack).toFloat();
    totalSecondsElapsed = readData(mTime).toFloat();
  }else{*/
     setupBMP();
     setupRTC();
     setupGPS();
     setupSD();
     softwareState = 2;
  //}
}

void initialize(){
  callInitialPressureAndAltitude();
  callAll();
  transmitData();
  softwareState = 3;
}

void middleStages(){
  callAll();
  transmitData();
}

void deployment(){
  deploy();
  callAll();
  transmitData();
}
void pDeploy(){
  Serial.print("Final data sent...Going into post deployment stage");
}
void landed(){
  writeDPin();
  //callGPS();
  //transmitOneTelem(TeleLat);
  //transmitOneTelem(TeleLong);
}












