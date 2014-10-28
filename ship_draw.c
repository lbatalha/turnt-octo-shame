#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <g2.h>
#include <g2_X11.h>
#include "eagle2014.h"

#define __USE_BSD


void ship_draw(int vdev, float x, float y, float radius, float atitude)
{

	float leg_length;
	float left_leg_x;
	float left_leg_y;
	float right_leg_x;
	float right_leg_y;
	float angle;
	float leg_angle = 45*(M_PI/180);

	angle = (atitude*(M_PI/180)) + (270*(M_PI/180));

	leg_length = cos(45) * radius;

	left_leg_x = x + (cos(angle - leg_angle) * leg_length);
	left_leg_y = y + (sin(angle - leg_angle) * leg_length);
	right_leg_x = x + (cos(angle + leg_angle) * leg_length);
	right_leg_y = y + (sin(angle + leg_angle) * leg_length);

	g2_circle(vdev, x, y, radius);
	g2_line(vdev, x, y, left_leg_x, left_leg_y);
	g2_line(vdev, x, y, right_leg_x, right_leg_y);


}