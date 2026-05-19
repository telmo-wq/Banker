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

//simula se a alocação de recursos é segura
//work e finish são vetores cópia de recursos[] e avaiable[]
int is_safe(int work[], int finish[], int **need, int number_of_costumers, int argc, int **allocation){
    int progresso = 1;

    while(progresso == 1){
        progresso = 0;

        for (int i = 0; i < number_of_costumers; i++){  //para cada costumer
            int flag = 0;
            if (finish[i] == 1){
                continue;
            }

            for (int j = 0; j < argc; j++){   //para cada recurso
                if (need[i][j] > work[j]){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){
                for (int j = 0; j < argc; j++){
                    work[j] += allocation[i][j];
                }
                finish[i] = 1;
                progresso = 1;

            }   
        }
    }

    int safe = 1;
    for (int i = 0; i < number_of_costumers; i++){
        if (finish[i] == 0){
            safe = 0;
            break;
        }
    }
    if (safe){
        return 1;
    }else {
        return 0;
    }
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

            int work[argc-1];
            int finish[number_of_customers];

            for (int i = 0; i < argc; i++){
                work[i] = avaiable[i];
            }

            for (int i = 0; i < number_of_customers; i++){
                finish[i] = 0;
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