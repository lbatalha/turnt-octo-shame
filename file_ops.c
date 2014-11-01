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

int init_file(struct main_data *data)
{
     data->fp=fopen("vooLunarCorrente.txt","w");
     
     if(data->fp==NULL)
     {
          printf("ERRO, Falha ao Abrir o Ficheiro");
          return 1;     
     }
     
     /*Cabecalhodo Ficheiro*/
     fprintf(data->fp, "%.2f[kg]\n", data->module_mass);
     fprintf(data->fp, "tempo[s]\tx[m]\tz[m]\tvx[m/s]\tvz[m/s]\tatitude[graus]\tfuel[kg]\n");
               
     return 0;    
}

int write_file(struct main_data *data)
{     
     /*data.fp=fopen("vooLunarCorrente.txt", "a");*/ /*Usar linha antes de chamar funcao*/
     
     if(data->fp == NULL)
     {
          printf("ERRO, Falha ao Abrir o Ficheiro\n");
          return 1;
     }
     
     fprintf(data->fp, "%.2e\t%.2e\t%.2e\t%.2e\t%.2e\t%.2e\t%.2e\n", data->tempo_t, data->h_dist, data->altitude, data->vel_x, data->vel_z, data->atitude, data->fuel);
     
     return 0; 
}

int read_file(struct main_data *data, int line_num, FILE *fp)
{
     char line[80];
     int rtrn = 0;

     if(fp == NULL){
          printf("ERRO, Falha ao Abrir o Ficheiro\n");
          return -3;
     }
          
     if(fgets(line, 80, fp) == NULL)              
     {     
          line_num = -3;
          fseek(fp, 0, SEEK_SET); /*Rewind file, faster than closing and opening*/
     }
     if(line_num == 1)
          rtrn = sscanf(line, "%f[kg]\n", &data->module_mass);
     
     if(line_num == 2)
          rtrn = sscanf(line, "tempo[s]\tx[m]\tz[m]\tvx[m/s]\tvz[m/s]\tatitude[graus]\tfuel[kg]\n");
     
     if(line_num > 2)
          rtrn = sscanf(line, "%e\t%e\t%e\t%e\t%e\t%e\t%e\n", &data->tempo_t, &data->h_dist, &data->altitude, &data->vel_x, &data->vel_z, &data->atitude, &data->fuel) == EOF;
               
     if(rtrn == EOF)
     {
          printf("%s\n", strerror(errno));
          exit(1);
     }

     line_num = line_num + 1;

     return line_num;
}

