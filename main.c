#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <g2.h>
#include <g2_X11.h>
#include "pos_graph.h"
#include "cockpit_display.h"
#include "spec_input.h"

int main()
{
	int option = -1;
	float altitude, atitude, h_dist, vel_x, vel_y, fuel, fuel_rate = 0, force_r = 0, force_t = 0, module_mass;
	char landing_status[32] = "";
	int pdev = -1;
	int vdev = -1;
	int window_h = 600; 
	int window_w = 800; /* Holds the window height and width */
	
	/* pid_t pid_clear; */
	
	
	while(1)										/* Main Loop */
	{
		sleep(1);
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
		strcpy(landing_status,"Em Progresso...");
		

		switch(option){
			case 1 :
				spec_input(&altitude, &atitude, &h_dist, &vel_x, &vel_y, &fuel, &module_mass);
				
				printf("\n\n%f %f %f %f %f", altitude, atitude, h_dist, vel_x, vel_y);
				sleep(5);
				option = -1;
				break;
			case 2 :
				if(vdev == -1 || pdev == -1)
				{
					pdev = g2_open_X11(window_w , window_h);
					vdev = g2_open_vd();
					g2_attach(vdev, pdev);
				}
				printf("\nvdev: %d - pdev: %d",vdev,pdev);
				
				cockpit_display(vdev, window_h, window_w, altitude, atitude, h_dist, vel_x, vel_y, fuel, fuel_rate, force_r, force_t, landing_status);
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
				if(vdev != -1)
					g2_close(vdev);
				
				exit(0);
			default :
				g2_close(vdev);
				pdev = -1; vdev = -1;
				break;
		}
		
		
		
		
	}
	
	/* ############################################################################ 
	###############################################################################
	###############################################################################
	*/
	
	return 0;
}