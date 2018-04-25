void setup() {
  Serial.begin(9600);
  //pinMode(A2, INPUT_PULLUP);
  pinMode(A0, INPUT);
}

void loop() {
  Serial.println(analogRead(A0));
//  Serial.print(",");
//  Serial.print(analogRead(A0));
//  Serial.print(",");
//  Serial.println(digitalRead(A0));
}
