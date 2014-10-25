#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "eagle2014.h" 

void input_check(char *label, float *input)
{
	int end = 1;
	while(end)
	{
		printf("%s", label); 
		if((scanf("%f", input)) < 1)
			printf("Insira apenas numeros Reais\n");
		else
			end = 0;
	}
}
void spec_input(struct main_data data)
{
	printf("\033[2J");
	printf("\n======== Especifica��o dos dados do m�dulo ========");
	
	input_check("\nMassa do Modulo (Kg): ", &data.module_mass); 
	input_check("Quantidade de Combustivel (Kg): ", &data.fuel);
	
	printf("\n\n======== Dados iniciais de voo ========");
	
	input_check("\nAltitude Inicial (m): ", &data.altitude);
	input_check("Atitude (�): ", &data.atitude);
	input_check("Distancia Horizontal (m): ", &data.h_dist);
	input_check("Velocidade Horizontal (m/s): ", &data.vel_x);
	input_check("Velocidade Vertical (m/s): ", &data.vel_y);
	
	/* printf("\n\n======== Ponto de Alunagem ========");
	printf("\nPonto de Alunagem (x): "); scanf("%f", vel_y_ptr); */
	
}