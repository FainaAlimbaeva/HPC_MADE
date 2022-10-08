CC=gcc
CFLAGS=-O3 -g -o
CFLAGS_LIB=-c -O3 -g 


# SOURCES=main.c matmul_matrix.c matmul_vector.c 
# OBJECTS=$(SOURCES:.c=.o) 
# EXECUTABLE=main

all: main
main: matmul_matrix.a matmul_vector.a
	$(CC) main.c matmul_matrix.a matmul_vector.a $(CFLAGS) main
matmul_matrix.a: matmul_matrix.o
	ar rc matmul_matrix.a matmul_matrix.o
matmul_vector.a: matmul_vector.o
	ar rc matmul_vector.a matmul_vector.o
matmul_matrix.o:
	$(CC) $(CFLAGS_LIB) matmul_matrix.c
matmul_vector.o:
	$(CC) $(CFLAGS_LIB) matmul_vector.c
clean:
	rm -f *.o *.a main
