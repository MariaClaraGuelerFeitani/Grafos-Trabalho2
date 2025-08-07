all: compila
compila: main.o grafo.o dijkstra.o
	gcc main.o grafo.o dijkstra.o -o prog
main.o: main.c
	gcc -c main.c
grafo.o: grafo.c
	gcc -c grafo.c
dijkstra.o: dijkstra.c
	gcc -c dijkstra.c
clean:
	rm -f main.o grafo.o dijkstra.o prog