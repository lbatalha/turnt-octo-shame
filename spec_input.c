/*
Grupo 74

	63282 - Artur Guilherme Rodrigues de Vasconcelos
>	70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "eagle2014.h" 

float input_check(const char *label)
{
	float input;
	while(1)
	{
		printf("%s", label);
		if((scanf("%f", &input)) < 1){
			printf("Insira apenas numeros");
			__fpurge(stdin);
		}
		else
			return input;
	}
}
void spec_input(struct main_data *data)
{
	printf("\033[2J");
	printf("\n======== Especificacao dos dados do modulo ========\n\n");
	
	data->module_mass = input_check("Massa do Modulo (Kg): "); 
	data->fuel = input_check("Quantidade de Combustivel (Kg): ");
	
	printf("\n============== Dados iniciais de voo ==============\n\n");
	
	data->altitude = input_check("Altitude Inicial (m): ");
	data->atitude = input_check("Atitude (graus): ");
	data->h_dist = input_check("Distancia Horizontal (m): ");
	data->vel_x = input_check("Velocidade Horizontal (m/s): ");
	data->vel_z = input_check("Velocidade Vertical (m/s): ");
	
	data->atitude = -data->atitude; /*Invert Rotation*/
}




