/*
Grupo 74

	63282 - Artur Guilherme Rodrigues de Vasconcelos
>	70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#ifndef EAGLE2014_H_INCLUDED
#define EAGLE2014_H_INCLUDED


struct main_data
{
	float tempo, altitude, atitude, h_dist, vel_x, vel_z, fuel, fuel_rate, force_r, force_t, module_mass;
	float vel_ang, a_ang, m_total, ax, az, tempo_t;

	char landing_status[32];
	
	int option;
	int pdev, vdev;
	int window_h, window_w; 
	int font_size, label_value_dist;
	int radius;
	int terminate_cp, cp_return;

	FILE *fp;

	
};



void draw_data(struct main_data data, char *label, float value, char *units, int x_pos, int y_pos );
void spec_input(struct main_data *data);
void ship_draw(int vdev, float x, float y, float radius, float atitude);
void mouse_control(struct main_data *data);

void *fisica(void *input);
void *pos_graph(void *input);
void *cockpit_display(void *input);

int init_file(struct main_data *data);
int write_file(struct main_data *data);
int read_file(struct main_data *data, int line_num, FILE *fp);

#endif