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

struct stat fileStat;
int fd;
struct evaluacion pinf;
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
lseek(fd,0,SEEK_SET);
//read(fd,&pinf,sizeof(struct evaluacion));
fstat(fd,&fileStat);
int lista;
lista=fileStat.st_size/sizeof(struct evaluacion);
//printf("El de una SOLA:%d\n",lista);
for(int i=0;i<lista;i++)
	{
		
	read(fd,&pinf,sizeof(struct evaluacion));
	printf("%10s:%5.2f:%5.2f:%5.2f:%s %s,%s \t\n",pinf.id,pinf.nota1p,pinf.nota2p,pinf.notamedia,pinf.apellido2,pinf.apellido1,pinf.nombre);
	}	
	
}
