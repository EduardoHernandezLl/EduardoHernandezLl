all:hello

hello:hello.o
	cc hello.o -o hello

hello.o:hello.c
	cc -c hello.c

clean:
	rm -f *.o
	rm -f hello
