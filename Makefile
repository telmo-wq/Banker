CC = gcc
CFLAGS = -Wall -Wextra

banker: banker.o contar_clientes.o is_safe.o ler_comandos.o 
	$(CC) $(CFLAGS) -o banker banker.o contar_clientes.o is_safe.o ler_comandos.o

banker.o: banker.c biblioteca.h
	$(CC) $(CFLAGS) -c banker.c

contar_clientes.o: contar_clientes.c biblioteca.h
	$(CC) $(CFLAGS) -c contar_clientes.c

is_safe.o: is_safe.c biblioteca.h
	$(CC) $(CFLAGS) -c is_safe.c 

ler_comandos.o: ler_comandos.c biblioteca.h
	$(CC) $(CFLAGS) -c ler_comandos.c 

clean: 
	rm -rf *.o banker

