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

        int invalido = 0;
        
        for (int i = 0; i < argc; i++) {
            if (sscanf(linha + offset, "%d%n", &recursos[i], &consumed) != 1) {
                printf("ERRO! Formato invalido no commands.txt\n");
                return;
            }
            offset += consumed;
        }

        if (strcmp(op, "RQ") == 0) {
            int exceeded = 0;
            int not_enough = 0;
            for (int j = 0; j < argc; j++){
                if (recursos[j] > need[customer][j]){
                    exceeded = 1;
                    break;
                }
            }
            
            for (int j = 0; j < argc; j++){
                if (recursos[j] > avaiable[j]){
                    not_enough = 1;
                    break;
                }
            }

            if (exceeded){
                fprintf(log, "The customer %d request ", customer);
                for (int i = 0; i < argc; i++){
                    fprintf(log, "%d ", recursos[i]);
                }
                fprintf(log, "was denied because exceed its maximum allocation\n");
                continue;
            }

            if (not_enough){
                fprintf(log, "The resources ");
                for(int i = 0; i < argc; i++){
                    fprintf(log, "%d ", avaiable[i]);
                }
                fprintf(log, "are not enough to customer %d request ", customer);
                for (int i = 0; i < argc; i++){
                    fprintf(log, "%d ", recursos[i]);
                }
                fprintf(log, "\n");
                continue;
            }
            
        } else if (strcmp(op, "RL") == 0) {
            int invalido = 0;
            for (int j = 0; j < argc; j++){   //cancela se o comando pedir uma quantidade de recurso que não tem
                if (recursos[j] > allocation[customer][j]){
                    invalido = 1;
                    break;
                }
            }

            if (invalido){
                fprintf(log, "ERRO! Alocacao invalida\n");
                continue;
            }

            for (int j = 0; j < argc; j++){
                allocation[customer][j] -= recursos[j];
                avaiable[j] += recursos[j];
                need[customer][j] = max[customer][j] - allocation[customer][j];
            }

            fprintf(log, "Release from customer %d the resources ", customer);

            for(int j = 0; j < argc; j++){
                fprintf(log, "%d ", recursos[j]);
            }
            fprintf(log, "\n");
        }
    }
}