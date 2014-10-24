#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <g2.h>
#include <g2_X11.h>
#include "eagle2014.h"



int main()
{
	struct main_data 
	{
		int option = -1;
		float altitude, atitude, h_dist, vel_x, vel_y, fuel, fuel_rate = 0, force_r = 0, force_t = 0, module_mass;
		char landing_status[32] = "";
		int pdev = -1;
		int vdev = -1;
		int window_h = 600; 
		int window_w = 800; /* Holds the window height and width */
	};
	
	struct main_data data;
	
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
		
		scanf("%d", &data.option);
		strcpy(data.landing_status,"Em Progresso...");
		
		
		switch(option){
			case 1 :
				spec_input(&data);
				
				data.option = -1;
				break;
			case 2 :
				if(data.vdev == -1 || data.pdev == -1)
				{
					main_data.pdev = g2_open_X11(data.window_w, data.window_h);
					main_data.vdev = g2_open_vd();
					g2_attach(data.vdev, data.pdev);
				}
				printf("vdev: %d - pdev: %d\n", data.vdev, data.pdev);
				
				cockpit_display(data.vdev, data.window_h, data.window_w, data.altitude, data.atitude, data.h_dist, data.vel_x, data.vel_y, data.fuel, data.fuel_rate, data.force_r, data.force_t, data.landing_status);
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
				if(data.vdev != -1)
					g2_close(data.vdev);
				exit(0);
			default :
				data.pdev = -1; data.vdev = -1;
				break;
		}
		
		
		
		
	}
	
	
	return 0;
}