//Real time clock
void setupRTC(){
  rtc.begin();
  rtc.adjust(DateTime(0,0,0,0,0,0));
  Serial.println("RTC OKAY...");
  DateTime now = rtc.now();
  initialTime = now.second() + now.minute()*60 + now.hour()*60*60 + 86400 * now.day() + 2628000 * now.month() + 31536000 * now.year();
  
}
void callRTC(){
  DateTime now = rtc.now();
  totalSecondsElapsed = (now.second() + now.minute()*60 + now.hour()*60*60 + 86400 * now.day() + 2628000 * now.month() + 31536000 * now.year()) - initialTime;
  TeleArray[TeleTime] = totalSecondsElapsed;
  
}

