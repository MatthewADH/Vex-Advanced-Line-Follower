#pragma config(Sensor, in1,    leftLine,       sensorLineFollower)
#pragma config(Sensor, in2,    midLine,        sensorLineFollower)
#pragma config(Sensor, in3,    rightLine,      sensorLineFollower)
#pragma config(Sensor, dgtl1,  pbtn,           sensorTouch)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int thresh;
int left;
int right;
int mid;
int speed;
bool power;
bool setUpTest;

void turnLeft (){
	motor(rightMotor)= speed;
	motor(leftMotor)= 0;
}
void turnRight (){
	motor(rightMotor)= 0;
	motor(leftMotor)= speed;
}
void turnStraight (){
	motor(rightMotor)= speed;
	motor(leftMotor)= speed;
}
void turnStop (){
	motor (rightMotor)= 0;
	motor (leftMotor)= 0;
}
void automatic() {
	if (SensorValue(midLine) > thresh) {
		turnStraight();
	}
	else if (SensorValue(leftLine) > thresh){
		turnLeft();
	}
	else if (SensorValue(rightLine) > thresh) {
		turnRight();
	}
	else {
		turnStraight();
	}
}
void setUp() {
	if (setUpTest==false) {
		speed=(40);
		left=(SensorValue(leftLine));
		right=(SensorValue(rightLine));
		mid=(SensorValue(midLine));
		thresh=((((left+right)/2)+mid)/2);
		setUpTest=true;
	}
}
task powerListen() {
	while (1==1) {
		if (SensorValue(pbtn) == 1) {
			if (power==false) {
				power=true;
			}
			else {
				power=false;
			}
			wait1Msec(500);
		}
		wait1Msec(10);
	}
}
task main(){
	wait1Msec(500);
	setUp ();
	startTask(powerListen);
	while (1==1) {
		if (power==true){
			automatic ();
		}
		else {
			turnStop ();
			.````````````````````d
		}
	}
	wait1Msec(10);
}
