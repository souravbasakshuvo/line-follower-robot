void reading_black() {
  sensor = 0;
  sum = 0;
  for (int i = 0; i < num_of_sensors; i++) {
    s[i] = analogRead(i);
    (s[i] > threshold[i]) ? s[i] = 1 : s[i] = 0;
    //this is to merge all 6 values and imagine them in a single binary number
    //then converted it into decimal number to use as final value
    sensor += s[i] * base[i]; //Decimal Value
    sum += s[i];
  }
}

void reading_white() {
  sensor = 0;
  sum = 0;
  for (int i = 0; i < num_of_sensors; i++) {
    s[i] = analogRead(i);
    (s[i] < threshold[i]) ? s[i] = 1 : s[i] = 0;
    //this is to merge all 6 values and imagine them in a single binary number
    //then converted it into decimal number to use as final value
    sensor += s[i] * base[i]; //Decimal Value
    sum += s[i];
  }
}

void show_the_value() {
  reading_black();
  //reading_white();
  for (int i = num_of_sensors - 1 ; i >= 0 ; i--)
    Serial.print(String(s[i]) + " ");
  Serial.println(String(sensor, 10) + " " + String(sum) + " " + String(sensor, 2));
}

//void calibration() {
//  while (1) {
//    reading_black();
//    motor(0 * spr, 10 * spl);
//  }
//}
