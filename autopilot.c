/*
Grupo 74

>	63282 - Artur Guilherme Rodrigues de Vasconcelos
	70037 - Luis Filipe Ramos Batalha

Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
*/
#define _BSD_SOURCE
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "eagle2014.h"

void *autopilot(void *input)
{
  while(data->vel_z>=10 || data->vel_x>=5)
  {
    if(data->force_t < 100 && data->force_r>0)
    {
      data->force_t = data->force_t - 5;
    }
  }
  while(data->atitude>=5)
  {
    if(data->force_r<100 && data->force_r>-100)
    {
		  data->force_r = data->force_r - 5;
    }
  while(data->atitude<=-5)
  {
    if(data->force_r<100 && data->force_r>-100)
    {
		  data->force_r = data->force_r + 5;
    }
}