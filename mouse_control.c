/*
Grupo 74

	63282 - Artur Guilherme Rodrigues de Vasconcelos
>	70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <g2.h>
#include <g2_X11.h>
#include "eagle2014.h"

void mouse_control(struct main_data *data)
{
	double mouse_x, mouse_y;
	unsigned int mouse_button;
	
	g2_set_line_width(data->vdev,4);
	g2_set_font_size(data->vdev, 20);
	g2_query_pointer(data->pdev, &mouse_x, &mouse_y, &mouse_button);
	
	g2_rectangle(data->vdev, data->window_w - 50, 50, data->window_w -100, 100);
	g2_rectangle(data->vdev, data->window_w - 125, 50, data->window_w - 175, 100);
	g2_rectangle(data->vdev, data->window_w - 200, 50, data->window_w - 250, 100);
	g2_rectangle(data->vdev, data->window_w - 125, 125, data->window_w - 175, 175);

	g2_string(data->vdev, data->window_w - 100, 75, " +FR");
	g2_string(data->vdev, data->window_w - 175, 75, " -FT");
	g2_string(data->vdev, data->window_w - 250, 75, " -FR");
	g2_string(data->vdev, data->window_w - 175, 150, " +FT");
/*debug*//*printf("x: %f y: %f mouse: %i\n", data->mouse_x, data->mouse_y, data->mouse_button);*/
	
	if( data->force_r < 100 && ((mouse_button & 0x100 ) == 0x100) && mouse_x < (data->window_w - 50) && mouse_x > (data->window_w - 100) && mouse_y > 50 && mouse_y < 100){
		data->force_r = data->force_r + 1;
	}
	if( data->force_t > 0 && ((mouse_button & 0x100 ) == 0x100) && mouse_x < (data->window_w - 125) && mouse_x > (data->window_w - 175) && mouse_y > 50 && mouse_y < 100){
		data->force_t = data->force_t - 1;
	}
	if( data->force_r > -100 && ((mouse_button & 0x100 ) == 0x100) && mouse_x < (data->window_w - 200) && mouse_x > (data->window_w - 250) && mouse_y > 50 && mouse_y < 100){
		data->force_r = data->force_r - 1;
	}
	if( data->force_t < 100 && ((mouse_button & 0x100 ) == 0x100) && mouse_x < (data->window_w - 125) && mouse_x > (data->window_w - 175) && mouse_y > 125&& mouse_y < 175){
		data->force_t = data->force_t + 1;
	}

}
