#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void spec_input(float *altitude_ptr, float *atitude_ptr, float *h_dist_ptr, float *vel_x_ptr, float *vel_y_ptr, float *fuel_ptr, float *module_mass_ptr)
{
	printf("\033[2J");
	printf("\n======== Especificação dos dados do módulo ========");
	
	printf("\nMassa do Modulo (Kg): "); scanf("%f", module_mass_ptr);
	printf("Quantidade de Combustivel (Kg): "); scanf("%f", fuel_ptr);	
	
	printf("\n\n======== Dados iniciais de voo ========");
	
	printf("\nAltitude Inicial (m): "); scanf("%f", altitude_ptr);
	printf("Atitude (º): "); scanf("%f", atitude_ptr);	
	printf("Distancia Horizontal (m): "); scanf("%f", h_dist_ptr);	
	printf("Velocidade Horizontal (m/s): "); scanf("%f", vel_x_ptr);	
	printf("Velocidade Vertical (m/s): "); scanf("%f", vel_y_ptr);
	
	/* printf("\n\n======== Ponto de Alunagem ========");
	printf("\nPonto de Alunagem (x): "); scanf("%f", vel_y_ptr); */
	
}