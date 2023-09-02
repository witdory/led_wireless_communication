int a;
//String num[20]="";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
}

String stringread(){
  char char1;
  String stro = "";
  while(Serial.available()>0){
    char1 = Serial.read();
    delay(5);
    stro +=char1;
  }
  return stro;
}
void high(){
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  delay(15);
}
void low(){
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  delay(30);
}
void loop() {
String num="";
  if(Serial.available()>0){
    num = stringread();
  }
  
  for(int i=0; i<20; i++){
    if(int(num[i]) == 32) {
      for(int j=0; j<27; j++) {
        high();
      }
    }
    else{
      int count = int(num[i])-64;
      for(int j=0; j<count; j++) {
        high();
      }
    }
    low();
  }
}
