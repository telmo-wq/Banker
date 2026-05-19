#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int contar_clientes(FILE *arquivo_cli){
    char linha[200];
    int clientes = 0;

    while(fgets(linha, sizeof(linha), arquivo_cli) != NULL){
        clientes++;
    }

    rewind(arquivo_cli);
    return clientes;
}

void commands(FILE *arquivo_com, FILE *arquivo_cli, int argc){
    int number_of_customers = contar_clientes(arquivo_cli);
    char linha[200];
    int recursos[argc];
    int max[number_of_customers][argc];
    int need[number_of_customers][argc];
    int allocation[number_of_customers][argc];
    int avaiable[number_of_customers][argc];

    FILE *log = fopen("result.txt", "w");

    while(fgets(linha, sizeof(linha), arquivo_cli) != NULL){  //percorre arquivo_cli para preencher o vetor max[]
        int offset = 0;
        int consumed = 0;

        for (int i = 0; i < argc; i++){
            if (sscanf(linha + offset, "%d, %n", &max[i], &consumed)){
                //trata erro de formatação
            }
            offset += consumed;
        }
    }

    for (int i = 0; i < number_of_customers; i++){
        for (int j = 0; j < argc; j++){
            avaiable[i][j] = 0;
        }
    }
    
    while (fgets(linha, sizeof(linha), arquivo_com) != NULL) {  //percorrendo cada linha do arquivo_com
        char op[10];
        int customer;
        int offset = 0;
        int consumed = 0;

        // lendo o código da operação (rq ou rl)
        sscanf(linha, "%s%n", op, &consumed);
        offset += consumed;

        // tratar o * separado
        if (strcmp(op, "*") == 0) {
            // operação exibir
            continue;
        }

        // lendo o número do customer
        sscanf(linha + offset, "%d%n", &customer, &consumed);
        offset += consumed;

        // lê o restante dos recursos
        for (int i = 0; i < argc; i++) {
            if (sscanf(linha + offset, "%d%n", &avaiable[i], &consumed) != 1) {
                // erro de formato
            }
            offset += consumed;

        }

        if (strcmp(op, "RQ") == 0) {
            
        } else if (strcmp(op, "RL") == 0) {
            // operação release
        }
    }
}

