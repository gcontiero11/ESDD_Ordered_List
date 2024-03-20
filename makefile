all: listaEncadeada.o
	gcc listaEncadeada.o main.c -o main

listaEncadeada.o: listaEncadeada.h
	gcc -c listaEncadeada.c

run:
	./main

clean:
	rm -rf *.o