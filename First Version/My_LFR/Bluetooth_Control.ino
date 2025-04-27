//////DONE/////

void bluetooth() {
  int s = 10; //for adjustable speed system
  char x; //for storing receiving incoming data
  while (1) {
    if (Serial.available() > 0) {
      x = Serial.read();
      //    if(x != 'S') Serial.println(x);

      if (x == 'F') motor(s * spr, s * spl);
      else if (x == 'B') motor(-s * spr, -s * spl);
      else if (x == 'L') motor(s * spr, -s * spl);
      else if (x == 'R') motor(-s * spr, s * spl);
      else if (x == 'G') motor(s * spr, 0);
      else if (x == 'I') motor(0, s * spl);
      else if (x == 'H') motor(-s * spr, 0);
      else if (x == 'J') motor(0, -s * spl);
      else if (x == 'S') motor(0, 0);
      else if (x == 'W') digitalWrite(head_light, HIGH);
      else if (x == 'w') digitalWrite(head_light, LOW);
      else if (x == 'U') digitalWrite(back_light, HIGH);
      else if (x == 'u') digitalWrite(back_light, LOW);
      else if (x == '0') s = 0;
      else if (x == '1') s = 1;
      else if (x == '2') s = 2;
      else if (x == '3') s = 3;
      else if (x == '4') s = 4;
      else if (x == '5') s = 5;
      else if (x == '6') s = 6;
      else if (x == '7') s = 7;
      else if (x == '8') s = 8;
      else if (x == '9') s = 9;
      else if (x == 'q') s = 10;
    }
  }
}
