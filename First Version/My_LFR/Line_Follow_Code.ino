void line_follow() {
  while (1) {
    reading();
    if (sum == 0) {
      if (flag != 's') {
        motor  (10 * spr, 10 * spl);
        delay(27);
        if (flag == 'l') {
          motor(6 * spr, -6 * spl);
          while (s[2] == 0 && s[3] == 0) reading();
        }
        else if (flag == 'r') {
          motor(-6 * spr, 6 * spl);
          while (s[2] == 0 && s[3] == 0) reading();
        }
        else if (flag == 't') { //For T section, we are choosing right
          motor(-6 * spr, 6 * spl);
          while (s[2] == 0 && s[3] == 0) reading();
        }
        flag = 's';
      }
    }
    else if (sum == 1 || sum == 2) {
      if (sensor == 0b001100) {
        if (flag == 't') flag = 's';
        if (pos != 0) {
          (pos == 1) ? motor(-10 * spl, 10 * spr) : motor(10 * spl, -10 * spr);
          delay(5); pos = 0;  //this logic is for those whose bot is wabbling during high speed run. this logic will forcefully return bot to its midpoint. don't give more than 30ms delay here!
        }
        motor(10 * spr, 10 * spl);
      }
      // Moving bot to Right Side
      else if (sensor == 0b000100) {
        if (flag == 't') flag = 's';
        motor(9 * spr, 10 * spl);
      }
      else if (sensor == 0b000110) {
        pos = 1;
        motor(6 * spr, 10 * spl);
      }
      else if (sensor == 0b000010) {
        pos = 1;
        motor(3 * spr, 10 * spl);
      }
      else if (sensor == 0b000011) {
        pos = 1;
        motor(0 * spr, 10 * spl);
      }
      else if (sensor == 0b000001) {
        pos = 1;
        motor(-3 * spr, 10 * spl);
      }
      // Moving bot to Left Side
      else if (sensor == 0b001000) {
        if (flag == 't') flag = 's';
        motor(10 * spr, 9 * spl);
      }
      else if (sensor == 0b011000) {
        pos = -1;
        motor(10 * spr, 6 * spl);
      }
      else if (sensor == 0b010000) {
        pos = -1;
        motor(10 * spr, 3 * spl);
      }
      else if (sensor == 0b110000) {
        pos = -1;
        motor(10 * spr, 0 * spl);
      }
      else if (sensor == 0b100000) {
        pos = -1;
        motor(10 * spr, -3 * spl);
      }
    }
    else if ((sum == 3 || sum == 4 || sum == 5) && flag != 't') { //only for sharp turn logic
      if (sensor == 0b101100 || sensor == 0b100110 || sensor == 0b110100) flag = 'l'; // Left
      else if (sensor == 0b001101 || sensor == 0b011001 || sensor == 0b001011) flag = 'r'; // Right
      else if (sensor == 0b111100 || sensor == 0b111000 || sensor == 0b111110) flag = 'l';
      else if (sensor == 0b001111 || sensor == 0b000111 || sensor == 0b011111) flag = 'r';
    }
    else if (sum == 6) {
      flag = 't';
      delay(50);
      reading();
      if (sum == 6) { //Stop Point Detection
        motor(0, 0);
        while (sum == 6) reading();
        delay(1000);
      }
    }
  }
}
