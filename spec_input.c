#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void spec_input(float *altitude_ptr, float *atitude_ptr, float *h_dist_ptr, float *vel_x_ptr, float *vel_y_ptr, float *fuel_ptr, float *module_mass_ptr)
{
	printf("\033[2J");
	printf("\n======== Especifica��o dos dados do m�dulo ========");
	
	printf("\nMassa do Modulo (Kg): "); scanf("%f", module_mass_ptr);
	printf("\nQuantidade de Combustivel (Kg): "); scanf("%f", fuel_ptr);	
	
	printf("\n\n======== Dados iniciais de voo ========");
	
	printf("\nAltitude Inicial (m): "); scanf("%f", altitude_ptr);
	printf("\nAtitude (�): "); scanf("%f", atitude_ptr);	
	printf("\nDistancia Horizontal (m): "); scanf("%f", h_dist_ptr);	
	printf("\nVelocidade Horizontal (m/s): "); scanf("%f", vel_x_ptr);	
	printf("\nVelocidade Vertical (m/s): "); scanf("%f", vel_y_ptr);
	
}