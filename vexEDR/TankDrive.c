#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop, reversed, encoderPort, None)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// These are functions for basic movements //

void move_forward_fullspeed(int number_of_seconds);
void move_forward_halfspeed(int number_of_seconds);
void turn_left(int time);




task main()
{
	/* TANK DRIVE */

		while (4 == 4)
		{

			motor[leftMotor] = vexRT[Ch3];
			motor[rightMotor] = vexRT[Ch2];



	/*Open or close claw*/

				if(vexRT[Btn6U] == 1)
				{
					motor[clawMotor] = 127;
				}
				else if (vexRT[Btn6D] == 1)
				{
						motor[clawMotor] = -127;
				}
				else
				{
					motor[clawMotor] = 0;
				}


	/* Raise or lower arm */

				if(vexRT[Btn5U] == 1)
				{
					motor[armMotor] = 60;
				}
				else if (vexRT[Btn5D] == 1)
				{
					motor[armMotor] = -30;
				}
				else
				{
					motor[armMotor] = 15;
				}




	// Calling the functions for basic movements //
				if(vexRT[Btn8D] == 1)
				{
					move_forward_fullspeed(5.873);
				}
				else if (vexRT[Btn8U] == 1)
				{
					turn_left(2750);//1937.5
				}
		}


}



//Under the hood of the functions//
void move_forward_fullspeed(int number_of_seconds)
{
	motor[leftMotor] = 28.5;
  motor[rightMotor] = 30;
  wait1Msec(number_of_seconds);
  motor[leftMotor] = 0;
  motor[rightMotor] = 0;
}

void move_forward_halfspeed(int number_of_seconds)
{
	motor[leftMotor] = 127/2;
  motor[rightMotor] = 127/2;
  wait1Msec(number_of_seconds*1000);
  motor[leftMotor] = 0;
  motor[rightMotor] = 0;
}

void turn_left(int time)
{
	motor[leftMotor] = -30;
  motor[rightMotor] = 30;
  wait1Msec(time);
  motor[leftMotor] = 0;
  motor[rightMotor] = 0;
}
