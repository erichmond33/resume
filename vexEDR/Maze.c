#pragma config(Sensor, dgtl1,  rangeFinder,    sensorSONAR_inch)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void turn(char direction, int degrees);

task main()
{

wait1Msec(5000);

while(1==1)
{
	if (SensorValue[rangeFinder] < 10)
	{
		stopAllMotors();
		turn('L', 90);
		//turn left 90
		if (SensorValue[rangeFinder] < 10)
		{
			stopAllMotors();
			turn('R', 180);
			//turn 180 right
			if (SensorValue[rangeFinder] < 10)
			{
				stopAllMotors();
				turn('R', 90);
				//turn right 90
			}
		}
	}

	else
	{
		motor[leftMotor] = 40;
		motor[rightMotor] = 40;
	}
}
}




void turn(char direction, int degrees)
{
	int seconds = (degrees * 2000) / 180;
	int reverse1 = 1;
	int reverse2 = 1;

	if (direction == 'L')
	{
		reverse2 = -1;
	}
	else if (direction == 'R')
	{
		reverse1 = -1;
	}

	wait1Msec(500);
	motor[leftMotor] = reverse1 * 60;
	motor[rightMotor] =  reverse2 * 60;
	wait1Msec(seconds);
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}
