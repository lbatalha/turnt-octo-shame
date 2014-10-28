
int openfile (struct main_data data)
{
     FILE *fp;
     
     fp=open("vooLunarCorrente.txt","w");                    /*Abre o Ficheiro*/
     
     if(fp==NULL)                                           /*Testa a Abertura do Ficheiro*/
     {
          printf("ERRO, Falha ao Abrir o Ficheiro");
          return 1;     
     }
     
     /*Cabecalhodo Ficheiro*/
     fprintf(fp, "%f [kg]\n\n" data.module_mass)                 /*Ver nome variavel*/
     fprinrf(fp, "tempo[s]\t x[m]\t z[m]\t vx[m/s]\t vz[m/s]\t atitude[graus]\t fuel[kg]\n\n")
     
     fclose(fp);                                            /*Fecha o Ficheiro*/
               
     return 0;    
}

int writefile (float tempo, float data.h_dist, float data.altitude, float data.vel_x, float data.vel_z, float data.atitude, float data.fuel)
{
     FILE *fp;
     
     fp=open("vooLunarCorrente.txt", "a");
     
     if(fp==NULL)
     {
          printf("ERRO, Falha ao Abrir o Ficheiro");
          return 1;
     }
     
     fprintf(fp, "%f\t %f\t %f\t %f\t %f\t %f\t %f\n\n", tempo,data.h_dist,data.altitude,data.vel_x,data.vel_z,data.atitude,data.fuel);
     
     fpclose(fp);
     
     return 0; 
}

