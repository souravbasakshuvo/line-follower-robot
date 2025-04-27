#include <NewPing.h>
#include <EEPROM.h>

//******************************** Motor Parameters *************************//
#define right_motor_forward 2
#define right_motor_backward 3
#define left_motor_forward 4
#define left_motor_backward 5
#define right_motor_speed 6
#define left_motor_speed 9
//***************************************************************************//

#define head_light 12
#define back_light 13

#define spr 24 //right motor speed coeficient
#define spl 19.5 //left motor speed coeficient

// #define sw 2

//Line Follow
char flag = 's';
int pos;

int right_base_speed = 240;
int left_base_speed = 195;
int max_speed = 255;

//***************************** Sensor Parameters ***********************//
#define num_of_sensors 6
int s[num_of_sensors]; //this is for storing analog value of each sensor
int threshold[num_of_sensors] = {300, 400, 400, 400, 350, 350};
int base[num_of_sensors] = {1, 2, 4, 8, 16, 32}; //this is for binary to decimal conversion
char last_sensor = ' ';
int sensor = 0;
int sum = 0;
//***********************************************************************//

//***************************** PD Parameters ***************************//
float kP = 5;
float kD = 5;
int prev_err = 0;
//***********************************************************************//

//************************** Function Declaration ***********************//
void line_follow_black();
void line_follow_white();
void bluetooth();
void reading_black();
void reading_white();
void show_the_value();
void calibration();
void motor(int a, int b);
int pd_algorithm_error();
void pd_line_follow();
//***********************************************************************//

void setup() {
  //************************** Motor Pin Setup **************************//
  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_speed, OUTPUT);
  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(left_motor_speed, OUTPUT);
  //*********************************************************************//

  pinMode(head_light, OUTPUT);
  pinMode(back_light, OUTPUT);
  //pinMode(sw, INPUT_PULLUP);
  //(digitalRead(sw) == 0) ? bluetooth() : line_follow();
  //if I connect D2 with ground and then power on the arduino, then it will run on bluetooth ccontrol mode. else it will go on as line follower
  Serial.begin(9600);
}

void loop() {
  //line_follow_black();
  line_follow_white();
  //bluetooth();
  //show_the_value();
  //calibration();
  //pd_line_follow();
  //motor(10 * spl, 10 * spr);
}
