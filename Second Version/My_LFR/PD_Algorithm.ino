int pd_algorithm_error(){
  reading_black();
  int error, sum_state, sum_state_weight, line_pos, set_point;
  sum_state = sum;
  if (sum_state == 0) return 420;
  //sum_state_weight  = (s[0]*weight+s[1]*weight);????????????????????
  //line_pos = (sum_state_weight / sum_state);
  //error = line_pos - set_point;
  if (sensor == 0b001100) error = 0;
  else if (sensor == 0b001000) error = 1;
  else if (sensor == 0b011000) error = 2;
  else if (sensor == 0b010000) error = 3;
  else if (sensor == 0b110000) error = 5;
  else if (sensor == 0b100000) error = 7;
  else if (sensor == 0b000100) error = -1;
  else if (sensor == 0b000110) error = -2;
  else if (sensor == 0b000010) error = -3;
  else if (sensor == 0b000011) error = -5;
  else if (sensor == 0b000001) error = -7;
  
  if(s[0] == 1) last_sensor = 'r';
  else if (s[5] == 1) last_sensor = 'l';
  return error;
}

void pd_line_follow(){
  int error, delSpeed;
  float P, D;
  error = pd_algorithm_error();
  if (error == 420) {
    if (last_sensor == 'r') motor(-3 * spr, 10 * spl);
    else if (last_sensor == 'l') motor(10 * spr, -3 * spl);
  }
  else {
    P = kP * error;
    D = kD * (error - prev_err);
    delSpeed = P + D;

    motor(right_base_speed + delSpeed, left_base_speed - delSpeed);
    prev_err = error;
  }
}
