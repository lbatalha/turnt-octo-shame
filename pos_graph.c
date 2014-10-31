/*
Grupo 74

63282 - Artur Guilherme Rodrigues de Vasconcelos
70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <g2.h>
#include <g2_X11.h>
#include <unistd.h>
#include "eagle2014.h"

void *pos_graph(void *input)
{

	int ef = 1;

	struct main_data* data = (struct main_data*)input;

	data->pdev = g2_open_X11(data->window_w , data->window_h);
	data->vdev = g2_open_vd();
	g2_attach(data->vdev, data->pdev);
	
	while(ef != -1)
	{
		printf("%d\n", ef);
		g2_clear(data->vdev);
		g2_pen(data->vdev, 1);
		g2_set_font_size(data->vdev, data->font_size);
		
		ef = read_file(data, &ef);

		
		/*printf("%.2e\t%.2e\t%.2e\t%.2e\t%.2e\t%.2e\t%.2e\n", data->tempo, data->h_dist, data->altitude, data->vel_x, data->vel_z, data->atitude, data->fuel);*/
		
		usleep(1000000);
		

		if(ef == -2){
			ef = -1;
			g2_close(data->vdev);
		}
	}	
	return 0;
}