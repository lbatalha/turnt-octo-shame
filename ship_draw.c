/*
Grupo 74

	63282 - Artur Guilherme Rodrigues de Vasconcelos
>	70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <g2.h>
#include <g2_X11.h>
#include "eagle2014.h"



void ship_draw(int vdev, float x, float y, float radius, float atitude)
{

	float leg_length = 0;
	float left_leg_x = 0;
	float left_leg_y = 0;
	float right_leg_x = 0;
	float right_leg_y = 0;
	float angle = 0;
	float leg_angle = 45*(M_PI/180);

	angle = (atitude*(M_PI/180)) + (270*(M_PI/180));

	leg_length = radius / cos(45*(M_PI/180));

	left_leg_x = x + (cos(angle - leg_angle) * leg_length);
	left_leg_y = y + (sin(angle - leg_angle) * leg_length);
	right_leg_x = x + (cos(angle + leg_angle) * leg_length);
	right_leg_y = y + (sin(angle + leg_angle) * leg_length);

	/*Attention: Positive rotation is counter-clockwise*/

	g2_set_line_width(vdev, (radius*2) / 10);
	g2_line(vdev, x, y, left_leg_x, left_leg_y);
	g2_line(vdev, x, y, right_leg_x, right_leg_y);
	g2_filled_circle(vdev, x, y, radius);

}