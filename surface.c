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
	if(tail->next == NULL){
		printf("\nEmpty List!\n");
		return 1;
	}
	while (tail->next != NULL) {
		printf("%s,%.2f,%.2f", tail->next->name, tail->next->x, tail->next->y);
	}
	return 0;
}

void surface_setup(struct point *start, struct point *tail)
{
	char label[32];
	char *name;
	float x,y;
	int option = 0;
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
					printf("Input: 'name x y'; type \"done\" to exit.\n");
					if((scanf("%s %f %f", name, &x, &y)) < 3)
					{
						if(strcmp("done",name) == 0){
							printf("\ndone\n");
							option = -1;
							break;
						}	
						else
							printf("Invalid Format\n");
					}
					printf("\nend\n");
					if(tail==NULL){
						tail = create_point(name, x, y);
						start = tail;
					}
					else{
						tail->next = create_point(name, x, y);
						tail = tail->next;
					}
				}
			case 2: /*Delete point*/
				option = -1;
				break;
			case 3: /*List all point DEBUG*/
				tail = start; /*rewind*/
				while(1)
				{
					printf("\nPoint List\n");
					printf("%s %.2f %.2f\n", tail->name, tail->x, tail->y);
					tail = tail->next;
					if(tail->next == NULL){
						option = -1;
						break;
					}
				}
			case 0: /*exit*/
				exit(0);
			default:
				printf("\033[2J"); /*clear terminal*/
				sleep(1);
		}
	}
}