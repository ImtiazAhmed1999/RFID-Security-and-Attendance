void unlockDoor() {
  digitalWrite(Buzzer, 1);
  delay(300);
  digitalWrite(Buzzer, 0);
  delay(300);
  digitalWrite(Buzzer, 1);
  delay(300);
  digitalWrite(Buzzer, 0);
  for (int pos = 150; pos >= 80; pos--) {  // go from 0-180 degrees
    myservo.write(pos);        // set the servo position (degrees)
    delay(15);
  }
}

void lockDoor() {
  digitalWrite(Buzzer, 1);
  delay(300);
  digitalWrite(Buzzer, 0);
  delay(300);
  digitalWrite(Buzzer, 1);
  delay(300);
  digitalWrite(Buzzer, 0);
  for (int pos = 80; pos <= 150; pos++) {  // go from 0-180 degrees
    myservo.write(pos);        // set the servo position (degrees)
    delay(15);
  }
}
