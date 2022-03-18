FLAGS = -Wall -g

all:practica2_mostrar practica2_mmap practica2_std

practica2_mostrar:muestranotas.o
	cc $(FLAGS)  muestranotas.o -o practica2_mostrar
muestranotas.o:muestranotas.c
	cc $(FLAGS) -c muestranotas.c 

practica2_mmap:practica2.o ordenanotas_mmap.o
	cc $(FLAGS) practica2.o ordenanotas_mmap.o -o practica2_mmap

practica2_std:practica2.o ordenanotas_std.o
	cc $(FLAGS) practica2.o ordenanotas_std.o -o practica2_std

practica2.o:practica2.c
	cc $(FLAGS) -c practica2.c

ordenanotas_std.o:ordenanotas_std.c 
	cc $(FLAGS) -c ordenanotas_std.c

ordenanotas_mmap.o:ordenanotas_mmap.c
	cc $(FLAGS) -c ordenanotas_mmap.c	 


PHONY:	clean

datos:
	tar -xzvf datos.tgz 
clean:
	rm -f *.o
	rm -f *.bin
	rm -f practica2_mostrar 
	rm -f practica2_std
	rm -f practica2_mmap
