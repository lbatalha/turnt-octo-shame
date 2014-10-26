#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <g2.h>
#include <g2_X11.h>
#include "eagle2014.h"


void draw_data(struct main_data data, char *label, float value, char *units, int x_pos, int y_pos )
{
	int length = 0;
	char value_s[64];
	
	length = sprintf(value_s, "%.2f", value);

	g2_string(data.pdev, x_pos, y_pos, label);                                /*Draw Label*/
	g2_string(data.pdev, (data.font_size * data.label_value_dist) + x_pos, y_pos, value_s);      /*Draw Value*/
	g2_string(data.pdev, (length * data.font_size) + (data.font_size * data.label_value_dist) + x_pos, y_pos, units); /*Draw Units*/
	/*printf("Label: %s Value: %s\n", label, value_s); Debug*/

}