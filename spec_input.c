#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "eagle2014.h" 


void spec_input(struct main_data data)
{
	printf("\033[2J");
	printf("\n======== Especificação dos dados do módulo ========");
	
	printf("\nMassa do Modulo (Kg): "); scanf("%f", &data.module_mass);
	printf("Quantidade de Combustivel (Kg): "); scanf("%f", &data.fuel);	
	
	printf("\n\n======== Dados iniciais de voo ========");
	
	printf("\nAltitude Inicial (m): "); scanf("%f", &data.altitude);
	printf("Atitude (º): "); scanf("%f", &data.atitude);	
	printf("Distancia Horizontal (m): "); scanf("%f", &data.h_dist);	
	printf("Velocidade Horizontal (m/s): "); scanf("%f", &data.vel_x);	
	printf("Velocidade Vertical (m/s): "); scanf("%f", &data.vel_y);
	
	/* printf("\n\n======== Ponto de Alunagem ========");
	printf("\nPonto de Alunagem (x): "); scanf("%f", vel_y_ptr); */
	
}