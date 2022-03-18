#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include"practica2.h"
#include<sys/mman.h>
int ordenanotas(int fd)
{
int intercambio,i,j;
struct evaluacion *p1,paux;
struct stat buffer;

fstat(fd,&buffer);
int lista=buffer.st_size/sizeof(struct evaluacion);

p1=mmap(NULL, buffer.st_size, PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
for (i=0; i<lista-1; i++)
{
	for(j=0 ; j<lista-1-i; j++)
	{		
	  if (p1[j].notamedia < p1[j+1].notamedia){
		paux=p1[j];
		p1[j]=p1[j+1];
		p1[j+1]=paux;
		intercambio++;}
	}
}
munmap(p1,buffer.st_size);
return(intercambio);
}
