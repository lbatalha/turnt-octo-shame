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
	struct main_data data;
	
	data.option = -1;
	data.pdev = -1;
	data.vdev = -1;
	data.font_size = 12;
	data.label_value_dist = 22;
	data.window_h = 600;
	data.window_w = 800;
	
	pthread_t t_id;
	int t_return;	
	
	
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
		
		
		switch(data.option)
		{
			case 1 :
				spec_input(data);
				data.option = -1;
				break;
			case 2 :
				if(data.vdev == -1 || data.pdev == -1)
				{
					
					data.pdev = g2_open_X11(data.window_w, data.window_h);
					data.vdev = g2_open_vd();
					g2_attach(data.vdev, data.pdev);
					strcpy(data.landing_status,"Em Progresso...");

				}

				printf("vdev: %d - pdev: %d\n", data.vdev, data.pdev);
				
				t_return = pthread_create(&t_id, NULL, &cockpit_display, &data);

				data.option = -1;
				break;
			case 3 :
				
				break;
			case 4 :
				
				break;
			case 5 :
				
				break;
			case 0 :
				
				exit(0);
			default :
				data.pdev = -1; data.vdev = -1;
				break;
		}
		
		
		
		
	}
	
	
	return 0;
}