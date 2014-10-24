#include <stdio.h>
#include <stdlib.h>
#include <g2.h>
#include <g2_X11.h>
#include "draw_data.h"

int cockpit_display(float altitude, float atitude, float h_dist, float vel_x, float vel_y, float fuel, float force_r, float force_t, char landing_status)
{
	int window_h = 600, window_w = 800; /* Holds the window height and width */
	int pdev = NULL, vdev = NULL; /* Device ident for g2 */
	int font_size = 12, label_value_dist = 22;
	
	
	pdev = g2_open_X11(window_w , window_h);
	vdev=g2_open_vd();
	g2_set_font_size(vdev, font_size);
	g2_attach(vdev, pdev);
	g2_clean(vdev);
	
	
	/*Protype: draw_data(int vdev, char label, float value, char units, int x_pos, int y_pos, int font_size int label_value_dist) */
	draw_data(vdev, "Altitude:", altitude, "m", 20, window_h - 5 - font_size, font_size, label_value_dist);
	draw_data(vdev, "Atitude:", atitude, "º", 20, window_h - 10 - 2*font_size, font_size, label_value_dist);
	draw_data(vdev, "Distancia Horizontal:", h_dist, "m", 20, window_h - 10 - 3*font_size, font_size, label_value_dist);
	draw_data(vdev, "Velocidade x:", vel_x, "m/s", 20, window_h - 10 - 4*font_size, font_size, label_value_dist);
	draw_data(vdev, "Velocidade y:", vel_y, "m/s", 20, window_h - 10 - 5*font_size, font_size, label_value_dist);
	draw_data(vdev, "Fuel:", fuel, "Kg", 20, window_h - 10 - 6*font_size, font_size, label_value_dist);
	draw_data(vdev, "Fuel Rate:", fuel_rate, "Kg/min", 20, window_h - 10 - 7*font_size, font_size, label_value_dist);
	
	g2_string(vdev, 20, window_h - 10 - 8*font_size, "Aterragem:");
	g2_string(vdev, label_value_dist + 20, window_h - 10 - 8*font_size, landing_status);
	
	draw_data(vdev, "FR:", force_r, "%%", 200, window_h - 10 - 3*font_size, font_size, label_value_dist);
	draw_data(vdev, "FM:", force_t, "%%", 200, window_h - 10 - 4*font_size, font_size, label_value_dist);
	
	g2_flush(vdev);
	
	
return vdev;
}


