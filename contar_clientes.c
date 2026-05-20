#include "biblioteca.h"


int contar_clientes(FILE *customers){
    char linha[200];
    int clientes = 0;

    while(fgets(linha, sizeof(linha), customers) != NULL){
        clientes++;
    }

    rewind(customers);
    return clientes;
}