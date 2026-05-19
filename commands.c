#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contar_clientes(FILE *customers){
    char linha[200];
    int clientes = 0;

    while(fgets(linha, sizeof(linha), customers) != NULL){
        clientes++;
    }

    rewind(customers);
    return clientes;
}


//lembrar que avaiable[] é o array de instâncias disponíveis dos recursos passados na linha de comando
void ler_comandos(FILE *commands, FILE *customers, int argc, int avaiable[]){   //argc é o número de recursos
    int number_of_customers = contar_clientes(customers);
    char linha[200];
    int max[number_of_customers][argc];
    int need[number_of_customers][argc];
    int allocation[number_of_customers][argc];

    FILE *log = fopen("result.txt", "w");

 
    
    int linha_atual = 0;

    while(fgets(linha, sizeof(linha), customers) != NULL){  //percorre customers para preencher max[][]
        int offset = 0;
        int consumed = 0;

        
        for (int j = 0; j < argc; j++){
            if (sscanf(linha + offset, "%d, %n", &max[linha_atual][j], &consumed) != 1){
                printf("ERRO! Certifique-se de que o numero de recursos dos clientes bate com o registrado\n");
                return;
            }
            offset += consumed;
        }

        linha_atual++;
        
    }

    for (int i = 0; i < number_of_customers; i++){
        for (int j = 0; j < argc; j++){
            allocation[i][j] = 0;
            need[i][j] = max[i][j];
        }
    }
    
    while (fgets(linha, sizeof(linha), commands) != NULL) {  //percorrendo cada linha do arquivo_commands
        char op[10];
        int customer;
        int offset = 0;
        int consumed = 0;
        int recursos[argc];

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

        
        for (int i = 0; i < argc; i++) {
            if (sscanf(linha + offset, "%d%n", &recursos[i], &consumed) != 1) {
                printf("ERRO! Formato invalido no commands.txt\n");
                return;
            }
            offset += consumed;
        }

        if (strcmp(op, "RQ") == 0) {
            
        } else if (strcmp(op, "RL") == 0) {
            // operação release
        }
    }
}