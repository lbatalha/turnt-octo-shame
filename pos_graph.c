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
	float h_max = 0, altitude_max = 0, h_min = 0;

	struct main_data* data = (struct main_data*)input;

	data->pdev = g2_open_X11(data->window_w , data->window_h);
	data->vdev = g2_open_vd();
	g2_attach(data->vdev, data->pdev);

	data->fp = fopen("vooLunarCorrente.txt", "r");
	if(data->fp == NULL){
		printf("ERRO, Falha ao Abrir o Ficheiro\n");

	}
	else while(ef != -2) /*Loop que verifica os maximos e minimos*/
	{
		ef = read_file(data, &ef);

		if(altitude_max < data->altitude)
			altitude_max = data->altitude; /*Verifica altitude maxima*/
		if(h_max < data->h_dist)
			h_max = data->h_dist;         /*Verifica pos x maxima*/
		if(h_min > data->h_dist)
			h_min = data->h_dist;         /*Verifica pos x minima*/
	}
	fclose(data->fp);
	ef = 1;
	
	data->fp = fopen("vooLunarCorrente.txt", "r");
	if(data->fp == NULL){
		printf("ERRO, Falha ao Abrir o Ficheiro\n");
	}
	else while(ef != -2)
	{
		g2_clear(data->vdev);
		g2_pen(data->vdev, 1);
		g2_set_font_size(data->vdev, data->font_size);
		
		ef = read_file(data, &ef);
		
		usleep(100000);
		
	}
	fclose(data->fp);
	return 0;
}