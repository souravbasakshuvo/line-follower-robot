//////DONE/////

#define right_motor_forward 2
#define right_motor_backward 3
#define left_motor_forward 4
#define left_motor_backward 5
#define right_motor_speed 6
#define left_motor_speed 9
#define head_light 12
#define back_light 12
#define spr 24 //right motor speed coeficient
#define spl 19.5 //left motor speed coeficient

// #define sw 2

//Line Follow
char flag = 's';
int pos;

//Sensor Reding
int s[6]; //this is for storing analog value of each sensor
int threshold[] = {300, 400, 400, 400, 350, 350}; //this is the mid value for each sensor. (digitalRead(sw) == 0) ? bluetooth() : line_follow(); //if you connect D2 with ground and then power on the arduino, then it will run on bluetooth ccontrol mode. else it will go on as line follower
int base[6] = {1, 2, 4, 8, 16, 32}; //this is for binary to decimal conversion
int sensor; //this is to store final value after binary conversion(digitalRead(sw) == 0) ? bluetooth() : line_follow(); //if you connect D2 with ground and then power on the arduino, then it will run on bluetooth ccontrol mode. else it will go on as line follower
int sum = 0; //this is to store the count of detected sensor


void setup() {
  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_speed, OUTPUT);
  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(left_motor_speed, OUTPUT);
  pinMode(head_light, OUTPUT);
  //  pinMode(back_light, OUTPUT);
  //  pinMode(sw, INPUT_PULLUP);
  //  (digitalRead(sw) == 0) ? bluetooth() : line_follow();
  //(digitalRead(sw) == 0) ? bluetooth() : line_follow(); //if I connect D2 with ground and then power on the arduino, then it will run on bluetooth ccontrol mode. else it will go on as line follower
  Serial.begin(9600);
}

void loop() {
  //  bluetooth(); //uncomment this if you want to use it as a rc car. comment this if you want to folow the line
  //  show_the_value(); // only uncomment this if you need to test sensor value in serial monitor
    line_follow(); // comment this if you want to test sensor value or want to use robot a rc car
  //  motor(10 * spl, 10 * spr);  //only uncomment this when you need to test if robot is moving forward
}
