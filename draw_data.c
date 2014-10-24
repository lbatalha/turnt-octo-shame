#include <stdio.h>
#include <stdlib.h>
#include <g2.h>
#include <g2_X11.h>

void draw_data(int vdev, char *label, float value, char *units, int x_pos, int y_pos, int font_size, char label_value_dist)
{
	int lenght = 0;
	char value_s[64];
	
	lenght = sprintf(value_s, "%.2f", value);                                           /*Float to String*/
		
	g2_string(vdev, x_pos, y_pos, label);                                            /* First draw label */
	g2_string(vdev, label_value_dist + x_pos, y_pos, value_s);                        /* Then draw value */
	g2_string(vdev, label_value_dist + x_pos + (lenght * font_size), y_pos, units);
		
}