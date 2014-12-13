#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "eagle2014.h"

struct point *add_point(char *name, float x, float y, struct point *tail)
{
	tail->next = malloc(48);
	tail->next->x = x;
	tail->next->y = y;
	strcpy(tail->next->name, name);
	return tail->next;
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