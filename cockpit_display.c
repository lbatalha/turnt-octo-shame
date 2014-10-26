#include <stdio.h>
#include <stdlib.h>
#include <g2.h>
#include <g2_X11.h>
#include "eagle2014.h"

void * cockpit_display(void *input)
{

	struct main_data* data = (struct main_data*)input;

	g2_set_font_size(data->vdev, data->font_size);
	g2_pen(data->vdev, 1);
	g2_clear(data->vdev);
	
	/*Protype: draw_data(int vdev, char label, float value, char units, int x_pos, int y_pos, int font_size int label_value_dist) */
	draw_data(*data, "Altitude:", data->altitude, "m", 20, data->window_h - 5 - data->font_size);
	draw_data(*data, "Atitude:", data->atitude, "º", 20, data->window_h - 10 - 2*data->font_size);
	draw_data(*data, "Distancia Horizontal:", data->h_dist, "m", 20, data->window_h - 10 - 3*data->font_size);
	draw_data(*data, "Velocidade x:", data->vel_x, "m/s", 20, data->window_h - 10 - 4*data->font_size);
	draw_data(*data, "Velocidade y:", data->vel_y, "m/s", 20, data->window_h - 10 - 5*data->font_size);
	draw_data(*data, "Fuel:", data->fuel, "Kg", 20, data->window_h - 10 - 6*data->font_size);
	draw_data(*data, "Fuel Rate:", data->fuel_rate, "Kg/min", 20, data->window_h - 10 - 7*data->font_size);
	
	g2_string(data->vdev, 20, data->window_h - 10 - 8*data->font_size, "Aterragem:");
	g2_string(data->vdev, data->label_value_dist + 20, data->window_h - 10 - 8*data->font_size, data->landing_status);
	
	draw_data(*data, "FR:", data->force_r, "%%", 200, data->window_h - 10 - 3*data->font_size);
	draw_data(*data, "FM:", data->force_t, "%%", 200, data->window_h - 10 - 4*data->font_size);
	
	g2_flush(data->vdev);

	return 0;
}


