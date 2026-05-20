CC = gcc
CFLAGS = -Wall -Wextra -lm

banker: banker.o contar_clientes.o is_safe.o ler_comandos.o imprimir_status.o
	$(CC) $(CFLAGS) -o banker banker.o contar_clientes.o is_safe.o ler_comandos.o imprimir_status.o

banker.o: banker.c biblioteca.h
	$(CC) $(CFLAGS) -c banker.c

contar_clientes.o: contar_clientes.c biblioteca.h
	$(CC) $(CFLAGS) -c contar_clientes.c

is_safe.o: is_safe.c biblioteca.h
	$(CC) $(CFLAGS) -c is_safe.c 

ler_comandos.o: ler_comandos.c biblioteca.h
	$(CC) $(CFLAGS) -c ler_comandos.c 

imprimir_status.o: imprimir_status.c biblioteca.h 
	$(CC) $(CFLAGS) -c imprimir_status.c 

clean: 
	rm -rf *.o banker result.txt

