//Initilize setup of SD Card which really just lets us know if it works sort of like a "hello world"
void setupSD(){
  Serial.println("Initializing SD card...");
  if(!SD.begin(chipSelect)){
    Serial.println("Card not found");
    return;
  }
  Serial.println("Card initialized");
}

//Writes any string data to SD card
void writeToSD(float data, char nom){
  File file;
  file = SD.open(String(nom), FILE_WRITE);
  file.print(data);
  file.print(" ");
  file.close();
}

//Reads any data from any file on the SD card
String readData(char FileName){
    File file;
    String data;
    if(!SD.exists(String(FileName))){
      file = SD.open(String(FileName), FILE_WRITE);
      file.close();
    }
    file = SD.open(String(FileName), FILE_READ);
    while (file.available()) {
      data = file.read();
    }
    file.close();
    return data;
}


