/*
Grupo 74

63282 - Artur Guilherme Rodrigues de Vasconcelos
70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <g2.h>
#include <g2_X11.h>
#include "eagle2014.h"

void * cockpit_display(void *input)
{

	
	struct main_data* data = (struct main_data*)input;


	
	while(1)
	{
		/*printf("%f %f %f %f %f\n", data->altitude, data->atitude, data->h_dist, data->vel_x, data->vel_z);*/
		g2_clear(data->vdev);
		g2_set_font_size(data->vdev, data->font_size);
		g2_pen(data->vdev, 1);
		g2_pen(data->pdev, 1);
		
		/*Protype: void draw_data(struct main_data data, char *label, float value, char *units, int x_pos, int y_pos )*/
		draw_data(*data, "Altitude:", data->altitude, "m", 20, data->window_h - 5 - data->font_size);
		draw_data(*data, "Atitude:", data->atitude, "degree", 20, data->window_h - 10 - 2*data->font_size);
		draw_data(*data, "Distancia Horizontal:", data->h_dist, "m", 20, data->window_h - 10 - 3*data->font_size);
		draw_data(*data, "Velocidade x:", data->vel_x, "m/s", 20, data->window_h - 10 - 4*data->font_size);
		draw_data(*data, "Velocidade z:", data->vel_z, "m/s", 20, data->window_h - 10 - 5*data->font_size);
		draw_data(*data, "Fuel:", data->fuel, "Kg", 20, data->window_h - 10 - 6*data->font_size);
		draw_data(*data, "Fuel Rate:", (data->fuel_rate / data->tempo), "Kg/s", 20, data->window_h - 10 - 7*data->font_size);
		
		g2_string(data->pdev, 20, data->window_h - 10 - 9*data->font_size, "Aterragem:");
		g2_string(data->pdev, (data->font_size * data->label_value_dist) + 20, data->window_h - 10 - 9*data->font_size, data->landing_status);
		
		draw_data(*data, "FR:", data->force_r, "\045", data->window_w - (data->font_size*15), data->window_h - 10 - 3*data->font_size);
		draw_data(*data, "FT:", data->force_t, "\045", data->window_w - (data->font_size*15), data->window_h - 10 - 4*data->font_size);
		
		/*Prototype: void ship_draw(int vdev, float x, float y, float radius, float atitude);*/
		ship_draw(data->vdev, data->window_w / 4, data->window_h / 4, data->radius*10, data->atitude);
		mouse_control(data);

		g2_flush(data->vdev);
		usleep(100000);
	}
	
	return 0;
}


