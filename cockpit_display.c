#include <stdio.h>
#include <stdlib.h>
#include <g2.h>
#include <g2_X11.h>
#include <draw_data.h>

int cockpit_display(float altitude, float atitude, float h_dist, float vel_x, float vel_y, float fuel, float force_r, float force_t, char landing_status)
{
	int window_h = 600, window_w = 800; /* Holds the window height and width */
	int pdev = -1; /* Device ident for g2 */
	int font_size = 12, label_value_dist = 22;
	
	
	pdev = g2_open_X11(window_w , window_h);
	g2_clean(pdev);
	g2_set_font_size(pdev, font_size);
	
	
	/*Protype: draw_data(int pdev, char label, float value, char units, int x_pos, int y_pos, int font_size int label_value_dist) */
	draw_data(pdev, "Altitude:", altitude, "m", 20, window_h - 5 - font_size, font_size, label_value_dist);
	draw_data(pdev, "Atitude:", atitude, "º", 20, window_h - 10 - 2*font_size, font_size, label_value_dist);
	draw_data(pdev, "Distancia Horizontal:", h_dist, "m", 20, window_h - 10 - 3*font_size, font_size, label_value_dist);
	draw_data(pdev, "Velocidade x:", vel_x, "m/s", 20, window_h - 10 - 4*font_size, font_size, label_value_dist);
	draw_data(pdev, "Velocidade y:", vel_y, "m/s", 20, window_h - 10 - 5*font_size, font_size, label_value_dist);
	draw_data(pdev, "Combustivel:", fuel, "", 20, window_h - 20 - 6*font_size, font_size, label_value_dist);
	draw_data(pdev, "FR:", force_r, "%%", 200, window_h - 10 - 3*font_size, font_size, label_value_dist);
	draw_data(pdev, "FM:", force_t, "%%", 200, window_h - 10 - 4*font_size, font_size, label_value_dist);
	
	
	
return pdev;
}


