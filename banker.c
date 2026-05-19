#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    

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