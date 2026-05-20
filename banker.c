#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

int main(int argc, char *argv[]){

    int available[argc - 1];

    for (int i = 1; i < argc; i++) {
        available[i - 1] = atoi(argv[i]);
    }  

    FILE *commands = fopen("commands.txt", "r");

    if (commands == NULL){
        printf("ERRO! Arquivo inexistente\n");
        return 0;
    }

    FILE *customers = fopen("customer.txt", "r");

    if (customers == NULL){
        printf("ERRO! Arquivo inexistente\n");
        return 0;
    }

    ler_comandos(commands, customers, argc - 1, available);

    fclose(commands);
    fclose(customers);
}