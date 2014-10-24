#ifndef EAGLE2014_H_INCLUDED
#define EAGLE2014_H_INCLUDED

struct main_data
{
	int option;
	float altitude, atitude, h_dist, vel_x, vel_y, fuel, fuel_rate, force_r, force_t, module_mass;
	char landing_status[32];
	int pdev;
	int vdev;
	int window_h, window_w; 
	int font_size;
	int label_value_dist;
};


int cockpit_display(struct main_data data);
void draw_data(struct main_data data, char *label, float value, char *units, int x_pos, int y_pos );
void spec_input(struct main_data data);

#endif