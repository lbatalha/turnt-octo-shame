/*
Grupo 74

63282 - Artur Guilherme Rodrigues de Vasconcelos
70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#include <stdio.h>
#include <stdlib.h>
#include <g2.h>
#include <g2_X11.h>
#include "eagle2014.h"

int pos_graph(struct main_data *data)
{
	  /* Holds the window height and width */
	        /* Device ident for g2 */
	
	data->pdev = g2_open_X11(data->window_w , data->window_h);
	data->vdev = g2_open_vd();
	g2_attach(data->vdev, data->pdev);
	
	g2_clear(data->vdev);
	g2_pen(data->vdev, 1);
	g2_set_font_size(data->vdev, font_size);
	

	/* g2_line(x_origin,  */
	
	
	
	return vdev;
}