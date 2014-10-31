/*
Grupo 74

63282 - Artur Guilherme Rodrigues de Vasconcelos
70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "eagle2014.h" 

void input_check(char *label, float *input)
{
	int end = 1;
	while(end)
	{
		printf("%s", label); 
		if((scanf("%f", input)) < 1){
			printf("Insira apenas numeros");
			__fpurge(stdin);
		}
		else
			end = 0;
	}
}
void spec_input(struct main_data *data)
{
	printf("\033[2J");
	printf("\n======== Especificacao dos dados do modulo ========");
	
	input_check("\nMassa do Modulo (Kg): ", &data->module_mass); 
	input_check("Quantidade de Combustivel (Kg): ", &data->fuel);
	
	printf("\n\n======== Dados iniciais de voo ========");
	
	input_check("\nAltitude Inicial (m): ", &data->altitude);
	input_check("Atitude (graus): ", &data->atitude);
	input_check("Distancia Horizontal (m): ", &data->h_dist);
	input_check("Velocidade Horizontal (m/s): ", &data->vel_x);
	input_check("Velocidade Vertical (m/s): ", &data->vel_z);
	printf("%f %f %f %f %f\n", data->altitude, data->atitude, data->h_dist, data->vel_x, data->vel_z);
	
}
