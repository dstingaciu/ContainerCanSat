int SoftwareState = 1;
int deploy_pin = 7;
double packetCount = 0;
boolean trigger = false;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  switch(SoftwareState){
    case 6:
      deploy();
  }
  packetCount+=1;
    
}

void deploy(){
  if(!trigger){
    int a = packetcount;
    trigger=true;
    digitalWrite(7, HIGH);
  }
  if(packetCount-a>=2){
    digitalWrite(7,LOW);
  }
  if(packetCount-a>=4){
    switchState();
  }
}

