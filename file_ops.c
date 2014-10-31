/*
Grupo 74

63282 - Artur Guilherme Rodrigues de Vasconcelos
70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "eagle2014.h"

int open_file(struct main_data data)
{
     FILE *fp;
     
     fp=fopen("vooLunarCorrente.txt","w");                    /*Abre o Ficheiro*/
     
     if(fp==NULL)                                           /*Testa a Abertura do Ficheiro*/
     {
          printf("ERRO, Falha ao Abrir o Ficheiro");
          return 1;     
     }
     
     /*Cabecalhodo Ficheiro*/
     fprintf(fp, "%f [kg]\n", data.module_mass);                 /*Ver nome variavel*/
     fprintf(fp, "tempo[s]\t x[m]\t z[m]\t vx[m/s]\t vz[m/s]\t atitude[graus]\t fuel[kg]\n");
     
     fclose(fp);                                            /*Fecha o Ficheiro*/
               
     return 0;    
}

int write_file(struct main_data data)
{
     FILE *fp;
     
     fp=fopen("vooLunarCorrente.txt", "a");
     
     if(fp==NULL)
     {
          printf("ERRO, Falha ao Abrir o Ficheiro");
          return 1;
     }
     
     fprintf(fp, "%f\t %f\t %f\t %f\t %f\t %f\t %f\n", data.tempo,data.h_dist,data.altitude,data.vel_x,data.vel_y,data.atitude,data.fuel);
     
     fclose(fp);
     
     return 0; 
}

