#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <g2.h>
#include <g2_X11.h>
#include "eagle2014.h"

void mouse_control(struct main_data *data)
{
	g2_set_line_width(data->vdev,4);
	g2_set_font_size(data->vdev, 20);
	g2_query_pointer(data->pdev, &data->mouse_x, &data->mouse_y, &data->mouse_button);

	g2_rectangle(data->vdev, data->window_w - 50, 50, data->window_w -100, 100);
	g2_rectangle(data->vdev, data->window_w - 125, 50, data->window_w - 175, 100);
	g2_rectangle(data->vdev, data->window_w - 200, 50, data->window_w - 250, 100);
	g2_rectangle(data->vdev, data->window_w - 125, 125, data->window_w - 175, 175);

	g2_string(data->vdev, data->window_w - 100, 75, " +FR");
	g2_string(data->vdev, data->window_w - 175, 75, " -FT");
	g2_string(data->vdev, data->window_w - 250, 75, " -FR");
	g2_string(data->vdev, data->window_w - 175, 150, " +FT");
/*debug*//*printf("x: %f y: %f mouse: %i\n", data->mouse_x, data->mouse_y, data->mouse_button);*/
	
	if( data->mouse_button == 272 && data->mouse_x < (data->window_w - 50) && data->mouse_x > (data->window_w - 100) && data->mouse_y > 50 && data->mouse_y < 100){
		data->force_r = data->force_r + 1;
	}
	if( data->mouse_button == 272 && data->mouse_x < (data->window_w - 125) && data->mouse_x > (data->window_w - 175) && data->mouse_y > 50 && data->mouse_y < 100){
		data->force_t = data->force_t - 1;
	}
	if( data->mouse_button == 272 && data->mouse_x < (data->window_w - 200) && data->mouse_x > (data->window_w - 250) && data->mouse_y > 50 && data->mouse_y < 100){
		data->force_r = data->force_r - 1;
	}
	if( data->mouse_button == 272 && data->mouse_x < (data->window_w - 125) && data->mouse_x > (data->window_w - 175) && data->mouse_y > 125&& data->mouse_y < 175){
		data->force_t = data->force_t + 1;
	}

}