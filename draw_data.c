#include <stdio.h>
#include <stdlib.h>
#include <g2.h>
#include <g2_X11.h>

void draw_data(int pdev, char label, float value, char units, int x_pos, int y_pos, int font_size int label_value_dist)
{
	int strlen = 0;
	
	sprintf(char value_s[64], "%.2f". value);                                           /*Float to String*/
	
	for(i=0;value_s[i]!='\0';i++)
	{
		strlen = strlen + 1;                                /* count number of characters to be diplayed */
	}
	
	g2_string(pdev, x_pos, y_pos, label);                                            /* First draw label */
	g2_string(pdev, label_value_dist + x_pos, y_pos, value_s);                        /* Then draw value */
	g2_string(pdev, label_value_dist + x_pos + (strlen * font_size), y_pos, value_s);
		
}