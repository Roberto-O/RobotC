#pragma config(Sensor, dgtl1,  bumpSwitchStart, sensorTouch)
#pragma config(Sensor, dgtl2,  bumpSwitchRight, sensorTouch)
#pragma config(Sensor, dgtl3,  bumpSwitchLeft, sensorTouch)
#pragma config(Motor,  port2,           robotMotor,    tmotorVex269_MC29, openLoop)

/*
	Code created by: Roberto Olivera
  Period: 2nd
  Date: 10/26/2015
  Programming Challenge: Write a code for a robot to drive in a straight line between two walls, pausing for 5 seconds at each wall once arriving.
  											 Start robot motion with the push of a button.
*/

task main(){ 																//Program Begins
	untilBump(bumpSwitchStart);								//press start button to start robot & program
	wait(3);																	//wait 3 seconds before robot actually starts

		while(true){ 														//while infinite loop
			startMotor(robotMotor, 127);					//motor starts running
		 untilBump(bumpSwitchRight);						//if it bumps to the right wall
			stopMotor(robotMotor);								//stop robot motor
				wait(5);														//wait five seconds
			startMotor(robotMotor, -127);					//start robot motor the other way
		 untilBump(bumpSwitchLeft);							//if it bumps to the left wall
			stopMotor(robotMotor);								//stop robot motor
				wait(5);														//wait five seconds (from here it repeats to the top of while loop)

	}//end while
}//end main
