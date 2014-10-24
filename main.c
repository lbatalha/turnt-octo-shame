#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pos_graph.h"
#include "cockpit_display.h"
#include "spec_input.h"

int main()
{
	int option = -1;
	float altitude, atitude, h_dist, vel_x, vel_y, fuel, fuel_rate, force_r = 0, force_t = 0, module_mass;
	char landing_status[32];
	/* int pdev = NULL, vdev = NULL; */
	/* pid_t pid_clear; */
	
	
	while(1)										/* Main Loop */
	{
		
		printf("\033[2J");
		printf("\n");
		printf("1. Especificação dos dados do módulo e das condições iniciais do voo (utilizar unidades do S.I.).\n");
		printf("2. Simulação do voo em modo de \"cockpit\".\n");
		printf("3. Apresentação em modo gráfico da trajectória do módulo.\n");
		printf("4. Definição do perfil  da superfície lunar.\n");
		printf("5. Simulação do voo em modo gráfico.\n");
		printf("0. Terminar Programa\n");
		printf("\n");
		printf("Escolha uma opção: ");
		
		scanf("%d", &option);
		

		switch(option){
			case 1 :
				spec_input(&altitude, &atitude, &h_dist, &vel_x, &vel_y, &fuel, &module_mass);
				option = -1;
				break;
			case 2 :
				cockpit_display(altitude, atitude, h_dist, vel_x, vel_y, fuel, fuel_rate, force_r, force_t, landing_status);
				break;
			case 3 :
				/* pdev = pos_graph(altitude, h_dist, x_origin, y_origin); */
				break;
			case 4 :
				/* vdev = pos_graph(altitude, h_dist, x_origin, y_origin); */
				break;
			case 5 :
				
				break;
			case 0 :
				exit(0);
			default :
				break;
		}
	}
	
	/* ############################################################################ 
	###############################################################################
	###############################################################################
	*/
	
	return 0;
}