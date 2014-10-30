#include <math.h>
#include "eagle2014.h"

void fisica(struct main_data *data)
{

	
	float grav_lua=1.622;				/*Gravidade da Lua*/
	float beta=0.255;				/*Consumo Combustivel*/
	float tt=450;					/*impulso principal*/
	float tr=17.6;					/*impulso rotaçao*/
	float inercia;

	data->m_total = data->module_mass + data->fuel;				/*Massa Total*/
		
	inercia = 2/5 * data->m_total * pow(data->radius,2);			/*Momento de Inercia*/

	data->a_ang = (tt * data->force_r * data->radius) / inercia;			/*aceleracao Angular*/

	data->vel_ang = data->vel_ang + data->a_ang * data->tempo;

	data->atitude = data->atitude + data->vel_ang * data->tempo + 1/2 * data->a_ang * pow(data->tempo,2);	/*Atitude*/

	data->ax = -tt * data->force_t * sin(data->atitude * (M_PI/180)) / data->m_total;		/*aceleração horizontal;*/
	data->az = -tt * data->force_t * cos(data->atitude * (M_PI/180)) / data->m_total-grav_lua;	/*aceleração vertical;*/

	data->vel_x = data->vel_x + data->ax * data->tempo;				/*velocidade horizontal*/
	data->vel_y = data->vel_y + data->az * data->tempo;				/*velocidade vertical*/

	data->h_dist = data->h_dist + data->vel_x * data->tempo + 1/2 * data->ax * pow(data->tempo,2);			/*posicao x*/
	data->altitude = data->altitude + data->vel_y * data->tempo + 1/2 * data->az * pow(data->tempo,2);			/*posicao z*/

	data->fuel_rate = beta * tt * data->force_t * data->tempo + beta * tr * data->force_r * data->tempo;

	data->fuel = data->fuel - data->fuel_rate;				/*consumo fuel*/
	
}