#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 65

int main(int argc, char *argv[])
{
	char line[MAXCHAR];
	char lines[];

	FILE *fp = fopen(argv[1], "r");

	while(fgets(line, MAXCHAR, fp) != NULL)
	{












	}





	return 0;
}