#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int contar_clientes(FILE *customer);

int is_safe(int work[], int finish[], int **need, int number_of_costumers, int argc, int **allocation);

void ler_comandos(FILE *commands, FILE *consumers, int argc, int avaiable[]);


void imprimir_status(FILE *log, int **max, int **allocation, int **need, int number_of_customers, int argc, int avaiable[]);

#endif