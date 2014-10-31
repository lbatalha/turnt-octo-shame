/*
Grupo 74

63282 - Artur Guilherme Rodrigues de Vasconcelos
70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#define _BSD_SOURCE
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "eagle2014.h"

void *fisica(void *input)
{

	struct main_data *data = (struct main_data*)input;

	float grav_lua = 1.622;           /*Gravidade da Lua*/
	float beta = 0.0005;               /*Consumo Combustivel*/
	float impulse_t = 45000;            /*impulso principal*/
	float impulse_r = 1760;           /*impulso rotaçao*/
	float inercia;
	float force_trans, force_rot;
	int stop = 0;
	data->tempo_t = 0;
	
	sleep(2);

	data->fp=fopen("vooLunarCorrente.txt", "a");

	while(stop != 1)
	{
		if(data->fuel <= 5){
			impulse_t = 0;
			impulse_r = 0;
            /*If fuel is below 5Kg, force engine stop*/
		}
		
		force_trans = data->force_t / 100;
		force_rot = data->force_r / 100;

		data->tempo = 0.1;
		data->tempo_t = data->tempo_t + data->tempo;

		data->m_total = data->module_mass + data->fuel;	                             /*Massa Total*/

		inercia = 0.4 * data->m_total * pow(data->radius,2);                         /*Momento de Inercia*/

		data->a_ang = (impulse_t * -force_rot * data->radius) / inercia;	         /*aceleracao Angular*/

		data->vel_ang = data->vel_ang + (data->a_ang * data->tempo);

		data->atitude = data->atitude + (data->vel_ang * data->tempo) + (0.5 * data->a_ang * pow(data->tempo,2));        /*Atitude*/

		data->ax = -1 * impulse_t * force_trans * sin(data->atitude * (M_PI/180)) / data->m_total;                       /*aceleração horizontal;*/
		data->az = (impulse_t * force_trans * cos(data->atitude * (M_PI/180)) / data->m_total) - grav_lua;          /*aceleração vertical;*/

		data->vel_x = data->vel_x + (data->ax * data->tempo);                       /*velocidade horizontal*/
		data->vel_z = data->vel_z + (data->az * data->tempo);                       /*velocidade vertical*/

		data->h_dist = data->h_dist + (data->vel_x * data->tempo) + (0.5 * data->ax * pow(data->tempo,2));               /*posicao x*/
		data->altitude = data->altitude + (data->vel_z * data->tempo) + (0.5 * data->az * pow(data->tempo,2));           /*posicao z*/


		data->fuel_rate = (beta * (impulse_t * force_trans) * data->tempo) + (beta * (impulse_r * fabs(force_rot)) * data->tempo);

		data->fuel = data->fuel - data->fuel_rate;                                  /*consumo fuel*/


		write_file(*data);

		if( (((data->altitude + data->radius) > 0) && ((data->altitude + data->radius) < 1)) && (fabs(data->atitude) < 5) && (fabs(data->vel_z) < 0.1) && (fabs(data->vel_x) < 0.05))
		{
			/*Check for successful landing, and exit the physics function*/
			strcpy(data->landing_status, "SUCCESS!!");
			stop = 1;
		}else if( ((data->altitude + data->radius) > 1)){
			/*If altitude is over safe landing then landing in progress*/
			strcpy(data->landing_status, "In Progress...");
		}else if(((data->altitude + data->radius) < 1) && ((fabs(data->atitude) > 5) || (fabs(data->vel_z) > 0.1) || (fabs(data->vel_x) > 0.05))){
			/*failure, stop physics calc*/
			strcpy(data->landing_status, "Failed!");
			stop = 1;
		}

		usleep(10000);         /*~0.1s*/
	}
	fclose(data->fp);
	return 0;
	
}