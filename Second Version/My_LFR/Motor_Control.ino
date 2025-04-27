void motor(int a, int b){
  if(a>=0){
    digitalWrite(right_motor_forward, HIGH);
    digitalWrite(right_motor_backward, LOW);
  }
  else{
    a=-a;
    digitalWrite(right_motor_forward, LOW);
    digitalWrite(right_motor_backward, HIGH);
  }
  if(b>=0){
    digitalWrite(left_motor_forward, HIGH);
    digitalWrite(left_motor_backward, LOW);
  }
  else{
    b=-b;
    digitalWrite(left_motor_forward, LOW);
    digitalWrite(left_motor_backward, HIGH);
  }

  analogWrite(right_motor_speed, abs(a));
  analogWrite(left_motor_speed, abs(b));

}
