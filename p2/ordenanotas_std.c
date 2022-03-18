
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include"practica2.h"
int ordenanotas(int fd)
{
int intercambio;
struct evaluacion p1,p2;
struct stat buffer;
fstat(fd,&buffer);
int lista=buffer.st_size/sizeof(struct evaluacion);

	
	for (int i=0;i<lista-1;i++)
	{
	for(int j=0;j<lista-1-i;j++){
	lseek(fd,j*sizeof(struct evaluacion),SEEK_SET);
	read(fd,&p1,sizeof(struct evaluacion));
	read(fd,&p2,sizeof(struct evaluacion));
	if (p1.notamedia<p2.notamedia)
		{
		lseek(fd,j*sizeof(struct evaluacion),SEEK_SET);
		write(fd,&p2,sizeof(struct evaluacion));	
		write(fd,&p1,sizeof(struct evaluacion));	
		intercambio++;
		}
	
	}	}
return (intercambio);	
}
