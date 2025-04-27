//////DONE/////

void reading() {
  sensor = 0; //this is to refresh initial value
  sum = 0;
  for (int i = 0 ; i < 6 ; i++) {
    s[i] = analogRead(i);
    //To convert analog value to digital.
    //To see real analog value, comment it. To follow line, uncomment it.
    (s[i] > threshold[i]) ? s[i] = 1 : s[i] = 0;
    //this is to merge all 6 values and imagine them in a single binary number 
    //then converted it into decimal number to use as final value
    sensor += s[i] * base[i]; //Decimal Value
    sum += s[i]; //finds out total count of sensor
  }
 
}

void show_the_value() {
  reading();
  for (int i = 5 ; i >= 0 ; i--)
    Serial.print(String(s[i]) + " ");
  Serial.println(String(sensor, 10) + " " + String(sum) + " " + String(sensor, 2));
}
