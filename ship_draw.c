#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <g2.h>
#include <g2_X11.h>
#include "eagle2014.h"

#define M_PI 3.14159265358979323846264338327

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

	leg_length = radius / cos(45*(M_PI/180));

	left_leg_x = x + (cos(angle - leg_angle) * leg_length);
	left_leg_y = y + (sin(angle - leg_angle) * leg_length);
	right_leg_x = x + (cos(angle + leg_angle) * leg_length);
	right_leg_y = y + (sin(angle + leg_angle) * leg_length);

	g2_set_line_width(vdev, (radius*2) / 10);
	g2_line(vdev, x, y, left_leg_x, left_leg_y);
	g2_line(vdev, x, y, right_leg_x, right_leg_y);
	g2_filled_circle(vdev, x, y, radius);

}