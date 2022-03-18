#include<sys/time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include"practica2.h"

int main(int argc, char *argv[])
{
int tiempo;
int fd;
int intercambios;
struct timeval inicio,final;
//verificamos elementos correctos en lineas de comandos
if (argc !=2){
	printf("Numero de argumentos insuficientes\n Uso: ./practica2_mostrar file\n");		 exit(-1);}
//Abrir en modo Lectura
fd=open(argv[1],O_RDWR);
if (fd== -1)
	{
		perror("Error al abrir el archivo");
		exit(-1);

	}
gettimeofday(&inicio, NULL);   // Instante inicial
intercambios=ordenanotas(fd);
gettimeofday(&final, NULL);   // Instante final
printf("Intercambios: %d\n",intercambios);
tiempo= (final.tv_sec - inicio.tv_sec)*1000000 + (final.tv_usec - inicio.tv_usec);
printf("Tiempo empleado: %d us\n",tiempo);
close(fd);
return(0);


}
