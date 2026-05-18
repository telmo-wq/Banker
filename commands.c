#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void commands(FILE *arquivo_com, FILE *arquivo_cli, int argc){
    char linha[200];
    char op[10];
    int customer;
    int offset = 0;
    int consumed = 0;

    
    while (fgets(linha, sizeof(linha), arquivo_com) != NULL) {
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
    int number_of_resources[argc];
    for (int i = 0; i < number_of_resources; i++) {
        if (sscanf(linha + offset, "%d%n", &number_of_resources[i], &consumed) != 1) {
            // erro de formato
        }
        offset += consumed;
    }

    if (strcmp(op, "RQ") == 0) {
        // operação request
    } else if (strcmp(op, "RL") == 0) {
        // operação release
    }
}
}

