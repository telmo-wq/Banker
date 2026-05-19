#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){

    int available[argc - 1];

    for (int i = 1; i < argc; i++) {
        available[i - 1] = atoi(argv[i]);
    }  
     
    FILE *arquivo_com = fopen("commandos.txt", "r");

    if (arquivo_com == NULL){
        printf("ERRO! Arquivo inexistente\n");
        return 0;
    }

    FILE *arquivo_cli = fopen("customer.txt", "r");

    if (arquivo_cli == NULL){
        printf("ERRO! Arquivo inexistente\n");
        return 0;
    }

    
}