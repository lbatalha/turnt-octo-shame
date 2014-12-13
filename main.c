/*
Grupo 74

	63282 - Artur Guilherme Rodrigues de Vasconcelos
>	70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <g2.h>
#include <g2_X11.h>
#include "eagle2014.h"



int main()
{
	struct main_data data;
	struct point *tail;
	struct point *start;

	pthread_t t_cockpit = 0, t_fisica = 0, t_graph = 0;

	data.option = -1;
	data.pdev = -1;
	data.vdev = -1;
	data.font_size = 16;
	data.label_value_dist = 10;			/*Define Some variables from main_data*/
	data.window_h = 600;
	data.window_w = 800;
	data.tempo = 0;
	data.radius = 5;
	data.force_t = 0;
	data.force_r = 0;
	data.terminate_cp = 0;

	while(1)										/* Main Loop */
	{
		
		printf("\033[2J");
		printf("\n");
		printf(" 1. Especificação dos dados do módulo e das condições iniciais do voo (Unidades S.I.).\n");
		printf(" 2. Simulação do voo em modo de \"cockpit\".\n");
		printf(" 3. Apresentação em modo gráfico da trajectória do módulo.\n");
		printf(" 4. Definição do perfil  da superfície lunar.\n");
		printf(" 5. Simulação do voo em modo gráfico.\n");
		printf(" 0. Terminar Programa\n");
		printf("\n");
		printf(" Escolha uma opção: ");
		
		if((scanf("%d", &data.option)) < 1){
			printf("Opção Invalida\n");
			__fpurge(stdin);
		}
		
		switch(data.option)
		{
			case 1 :
				spec_input(&data);
				data.option = -1;
				break;
			case 2 :
				if(data.vdev == -1 || data.pdev == -1)
				{
					data.pdev = g2_open_X11(data.window_w, data.window_h);
					data.vdev = g2_open_vd();
					g2_attach(data.vdev, data.pdev);
					strcpy(data.landing_status,"Ready");
				}
				pthread_join(t_cockpit, NULL);
				pthread_join(t_fisica, NULL);
				pthread_join(t_graph, NULL);
				
				pthread_create(&t_cockpit, NULL, &cockpit_display, &data);
				pthread_create(&t_fisica, NULL, &fisica, &data);
				data.option = -1;
				
				break;
			case 3 :
				data.terminate_cp = 1;
				pthread_join(t_cockpit, NULL);
				pthread_join(t_fisica, NULL);
				pthread_join(t_graph, NULL);
				data.terminate_cp = 0;
				
				pthread_create(&t_graph, NULL, &pos_graph, &data);
				data.option = -1;
				break;
			case 4 :
				pthread_join(t_cockpit, NULL);
				pthread_join(t_fisica, NULL);
				pthread_join(t_graph, NULL);
				
				surface_setup(start, tail);
				
				break;
			case 5 :
				printf("\nList Points\n");



				break;
			case 0 :
				g2_detach(data.vdev, data.pdev);
				g2_close(data.pdev);
				exit(0);
			default :
				if(data.vdev != -1 || data.pdev != -1)
					data.pdev = -1; data.vdev = -1;

				break;
		}
		
		usleep(100000);
	}
	
	return 0;
}
