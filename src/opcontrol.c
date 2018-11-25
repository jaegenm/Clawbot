/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "chassis.h"
#include "claw.h"
#include "lift.h"

void operatorControl() {
	int power;
	int turn;
	while (1) {
		// Drive Train
		power = joystickGetAnalog(1, 2); // vertical axis on left joystick
		turn = joystickGetAnalog(1, 1);  // horizontal axis on left joystick
		chassisSet(power + turn, power - turn);

		// Claw
		clawSet(joystickGetAnalog(1, 4));

		// Lift
		if(joystickGetDigital(1, 6, JOY_UP)) {
			liftSet(127);
		}
		else if(joystickGetDigital(1, 6, JOY_DOWN)) {
			liftSet(-127);
		}
		else {
			liftSet(0);
		}

		delay (20);
	}
}
