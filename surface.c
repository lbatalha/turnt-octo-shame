#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "eagle2014.h"

struct point *add_point(float x, float y, char *name, struct point *tail)
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

struct point *list_points(struct point *tail)
{
	
	
	return 0;
}