CFLAGS=-Wall -Werror -Wextra

rebuild: clean all

all: graph

graph: graph.o polka.o parser.o eval.o render.o input.o
	gcc $(CFLAGS) graph.o polka.o input.o parser.o eval.o render.o -o ../build/graph

graph.o: graph.c parser.h polka.h rendering_image.h input.h
	gcc $(CFLAGS) -c graph.c

polka.o: polka.c polka.h
	gcc $(CFLAGS) -c polka.c

parser.o: parser.c parser.h
	gcc $(CFLAGS) -c parser.c

eval.o: eval.c eval.h 
	gcc $(CFLAGS) -c eval.c

render.o: render.c eval.h rendering_image.h 
	gcc $(CFLAGS) -c render.c

input.o : input.c parser.h input.h
	gcc $(CFLAGS) -c input.c
clean:
	rm -rf *.o ../build/graph
