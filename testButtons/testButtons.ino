int v2=1;
int v3=1;
int v4=1;
int v5=1;
int v6=1;
int v7=1;
int v8=1;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);
  
  pinMode(2, OUTPUT); //Acts as Anode. 
  pinMode(3, OUTPUT); //Used to control LED. A 
  pinMode(4, OUTPUT); //Used to control LED. B 
  pinMode(5, INPUT); //Used to control LED. B
  pinMode(6, INPUT); //Used to control LED. B
  pinMode(7, INPUT); //Used to control LED. B
  pinMode(8, INPUT); //Used to control LED. B
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  //digitalWrite(4,HIGH);
  v2 = digitalRead(2);
  v3 = digitalRead(3);
  v4 = digitalRead(4);
  v5 = digitalRead(5);
  v6 = digitalRead(6);
  v7 = digitalRead(7);
  v8 = digitalRead(8);
  Serial.print("2: ");
  Serial.println(v2);
  Serial.print("3: ");
  Serial.println(v3);
  Serial.print("4: ");
  Serial.println(v4);
  Serial.print("5: ");
  Serial.println(v5);
  Serial.print("6: ");
  Serial.println(v6);
  Serial.print("7: ");
  Serial.println(v7);
  Serial.print("8: ");
  Serial.println(v8);
  Serial.println(" ");
  delay(500);
  
  
}

