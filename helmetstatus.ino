int dis;
int dur;
int recentavr;
int rondo=5;
int room[10];
int MAX;
int recmsg;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(2, INPUT); 
  Serial.begin(9600);
}

void loop() {
  rondo++;
  if(rondo==100) rondo=0;
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);
  dur = pulseIn(2, HIGH);
  dis = dur * 0.034 / 2;
  
  room[rondo%5]=dis;
  recentavr=(room[0]+room[1]+room[2]+room[3]+room[4]+room[5]+room[6]+room[7]+room[8]+room[9])/3;
  for(int i=0;i<3;i++) {                  
    if(room[i]>room[i-1]) MAX=room[i];
  }
  if(recentavr>=20){
      if(recmsg!=1) Serial.print("Helmet not detected !\n");
      recmsg=1;
  }
  else if(recentavr>=7){
      if(recmsg!=2) Serial.print("Please wear your helmet properly !\n");
      recmsg=2;
  }
  else{
          if(recmsg!=3) Serial.print("Good Job\n");
          recmsg=3;
  }
  delay(100);

}
