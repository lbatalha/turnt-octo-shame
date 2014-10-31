/*
Grupo 74

63282 - Artur Guilherme Rodrigues de Vasconcelos
70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "eagle2014.h"

int init_file(struct main_data data)
{
     FILE *fp;
     
     fp=fopen("vooLunarCorrente.txt","w");
     
     if(fp==NULL)
     {
          printf("ERRO, Falha ao Abrir o Ficheiro");
          return 1;     
     }
     
     /*Cabecalhodo Ficheiro*/
     fprintf(fp, "%.2f[kg]\n", data.module_mass);
     fprintf(fp, "tempo[s]\tx[m]\tz[m]\tvx[m/s]\tvz[m/s]\tatitude[graus]\tfuel[kg]\n");
     
     fclose(fp);
               
     return 0;    
}

int write_file(struct main_data data)
{
     static FILE *fp;
     
     if(fp == NULL)
          fp=fopen("vooLunarCorrente.txt", "a");
     
     if(fp == NULL)
     {
          printf("ERRO, Falha ao Abrir o Ficheiro\n");
          return 1;
     }
     
     fprintf(fp, "%.2e\t%.2e\t%.2e\t%.2e\t%.2e\t%.2e\t%.2e\n", data.tempo, data.h_dist, data.altitude, data.vel_x, data.vel_z, data.atitude, data.fuel);
     /*fclose(fp);*/
     
     return 0; 
}

int read_file(struct main_data *data, int *line_num)
{
     static FILE *fp;
     char line[80];
     printf("start: %d\n", *line_num);
     printf("line: %s\n", line);

     if(fp == NULL)
          fp = fopen("./vooLunarCorrente.txt", "r");
     
     if(fp == NULL)
     {
          printf("ERRO, Falha ao Abrir o Ficheiro\n");
          return -2;
     }
     
     if(fgets(line, 80, fp) == NULL);                
          *line_num = -1;
          printf("fgets: %d\n", *line_num);
     if(*line_num == 1)
          sscanf(line, "%f[kg]\n", &data->module_mass);
     if(*line_num == 2)
          sscanf(line, "tempo[s]\tx[m]\tz[m]\tvx[m/s]\tvz[m/s]\tatitude[graus]\tfuel[kg]\n");
     if(*line_num > 2)
          sscanf(line, "%e\t%e\t%e\t%e\t%e\t%e\t%e\n", &data->tempo, &data->h_dist, &data->altitude, &data->vel_x, &data->vel_z, &data->atitude, &data->fuel);
     
     *line_num = *line_num + 1;
     printf("%s\n", strerror(errno));

     return *line_num;
}

