#include <stdio.h>
#include <stdlib.h>
#include <g2.h>
#include <g2_X11.h>
#include "eagle2014.h"


void draw_data(struct main_data data, char *label, float value, char *units, int x_pos, int y_pos )
{
	int length = 0;
	char value_s[64];
	
	length = sprintf(value_s, "%.2f", value);
		
	g2_string(data.vdev, x_pos, y_pos, label);
	g2_string(data.vdev, data.label_value_dist + x_pos, y_pos, value_s);
	g2_string(data.vdev, data.label_value_dist + x_pos + (length * data.font_size), y_pos, units);
		
}