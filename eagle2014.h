#ifndef EAGLE2014_H_INCLUDED
#define EAGLE2014_H_INCLUDED
#define _BSD_SOURCE
#define M_PI 3.14159265358979323846264338327

struct main_data
{
	float tempo, altitude, atitude, h_dist, vel_x, vel_y, fuel, fuel_rate, force_r, force_t, module_mass;
	
	char landing_status[32];
	
	int option;
	int pdev, vdev;
	int window_h, window_w; 
	int font_size, label_value_dist;
	int radius;

	double mouse_x, mouse_y;
	unsigned int mouse_button;


	float vel_ang, a_ang, m_total, ax, az;
};


void * cockpit_display(void *input);
void draw_data(struct main_data data, char *label, float value, char *units, int x_pos, int y_pos );
void spec_input(struct main_data *data);
void ship_draw(int vdev, float x, float y, float radius, float atitude);
void mouse_control(struct main_data *data);
void fisica(struct main_data *data);

int open_file(struct main_data data);
int write_file(struct main_data data);

#endif