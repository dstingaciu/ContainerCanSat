void deploy(){
  Ir ir(0);
  if(!(ir.status())){
    digitalWrite(7, HIGH);
  }else{
    digitalWrite(7,LOW);
    trigger = false;
  }
}
