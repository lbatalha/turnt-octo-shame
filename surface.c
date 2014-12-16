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

struct point *create_point(char *name, float x, float y)
{
	struct point *current;
	current = malloc(sizeof(struct point));
	current->x = x;
	current->y = y;
	current->next = NULL;
	strcpy(current->name, name);
	return current;
}
 
int remove_point(char *name, struct point *tail)
{
	
	return 0;
}

int list_points(struct point *tail)
{
	if(tail->next == NULL)
		return 1;

	do{
		printf("%s,%.2f,%.2f \n", tail->next->name, tail->next->x, tail->next->y);
		tail->next = tail->next->next;
	}while(tail->next != NULL);
	return 0;
}

int surface_setup(struct point *start, struct point *tail)
{
	char label[32];
	char *name/*, *namedelete*/;
	/*char delete[32];*/
	float x,y;
	int option = 0;
	int list_return = -1;
	name = label;
	
	while(1)
	{
		printf("\033[2J");
		printf("\n");
		printf(" 1. Inserir pontos.\n");
		printf(" 2. Remover pontos\n");
		printf(" 3. Listar pontos\n");
		printf(" 0. Terminar\n");
		printf("\n");
		printf(" Escolha uma opção: ");

		if((scanf("%d", &option)) < 1){
			printf("Opção Invalida\n");
			__fpurge(stdin);
		}
		printf("\033[2J"); /*clear terminal*/

		switch(option)
		{
			case 1: /*Insert new point*/
				while(1)
				{
					printf("Input point name; \"!q\" to exit.\n");
					scanf("%s", name);
					if(strcmp("!q",name) == 0){
						printf("\ndone\n");
						option = -1;
						break;
					}	
					
					printf("Input \"x y\": ");
					if(scanf("%f %f", &x, &y) < 2){
						printf("Invalid Format.\n");
						option = -1;
						break;
					}
								
					if(tail == NULL){
						tail = create_point(name, x, y);
						start = tail;
					}
					else{
						tail->next = create_point(name, x, y);
						tail = tail->next;
					}
				}
				break;
			case 2: /*Delete point*/
	/*			while(1)
				{
					printf("Name of point to delete: ");
					scanf("%s", namedelete);				
									
				}*/

				option = -1;
				break;
			case 3: /*List all point DEBUG*/
				list_return = -1;
				tail = start;
				printf("abc\n");
				list_return = list_points(tail);
				if(list_return == 1)
					printf("Empty List.\n");

				printf("\nPress Enter to continue.");
				__fpurge(stdin);
				getchar();
				option = -1;
				break;
			case 0: /*exit*/
				return 0;
			default:
				printf("\033[2J"); /*clear terminal*/
				
		}
	}
}