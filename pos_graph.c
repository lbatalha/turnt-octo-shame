/*
Grupo 74

63282 - Artur Guilherme Rodrigues de Vasconcelos
>70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <g2.h>
#include <g2_X11.h>
#include <math.h>
#include "eagle2014.h"

void *pos_graph(void *input)
{

	int ef = 1;

	float h_max = 0, altitude_max = 0, h_min = 0;
	float avg_x = 0;
	float factor_x, factor_y;
	float origin_x, origin_y;

	struct main_data* data = (struct main_data*)input;

	FILE *fp;

	fp = fopen("vooLunarCorrente.txt", "r");
	if(fp == NULL){
		printf("ERRO, Falha ao Abrir o Ficheiro\n");

	}
	else
	{
		while(ef != -2) /*Loop que verifica os maximos e minimos*/
		{
			ef = read_file(data, ef, fp);

			if(altitude_max < data->altitude)
				altitude_max = data->altitude; /*Verifica altitude maxima*/
			if(h_max < data->h_dist)
				h_max = data->h_dist;         /*Verifica pos x maxima*/
			if(h_min > data->h_dist)
				h_min = data->h_dist;         /*Verifica pos x minima*/
		}
	}

	ef = 1;

	avg_x = (h_max/2) / (fabs(h_min)/2+0.01); 
	
	factor_x = data->window_w / (h_max + fabs(h_min)); /*Determina o factor de escala*/
	factor_y = data->window_h / altitude_max;
	
	origin_x = data->window_w / (2*avg_x) + 20;
	origin_y = data->font_size + 20;
	printf("%f %f %f %f", origin_x, origin_y, factor_x, factor_y);
	data->pdev = g2_open_X11(data->window_w , data->window_h);
	data->vdev = g2_open_vd();
	g2_attach(data->vdev, data->pdev);
	g2_clear(data->vdev);
	g2_pen(data->vdev, 1);
	g2_set_font_size(data->vdev, data->font_size);
	
	g2_line(data->vdev, 0, origin_y, data->window_w, origin_y); /*X Axis*/
	g2_line(data->vdev, origin_x, 0, origin_x, data->window_h); /*Y Axis*/
	
	g2_string(data->vdev, data->window_h - data->font_size/2*24, origin_y - data->font_size, "Distancia Horizontal (m)");
	g2_string(data->vdev, origin_x + data->font_size/2*10, data->window_h - data->font_size, "Altitude (m)");
	g2_string(data->vdev, origin_x + data->font_size/2, 1 + data->font_size, "0");

	g2_pen(data->vdev, 3);
	
	if(data->fp == NULL){
		printf("ERRO, Falha ao Abrir o Ficheiro\n");
	}
	else 
	{
		while(ef != -2)
		{
			
			ef = read_file(data, ef, fp);
			/*DEBUG*//*printf("%e\t%e\t%e\t%e\t%e\t%e\t%e\n", data->tempo_t, data->h_dist, data->altitude, data->vel_x, data->vel_z, data->atitude, data->fuel);*/
			/*g2_filled_circle(data->vdev, data->h_dist * factor_x + 20, data->altitude*factor_y + 20, 2);*/
			g2_plot(data->vdev, data->h_dist * factor_x + 20, data->altitude*factor_y + 20);
			g2_flush(data->vdev);

		}
	}
	fclose(fp);
	return 0;
}