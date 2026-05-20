#include "biblioteca.h"


void imprimir_status(FILE *log, int **max, int **allocation, int **need, int number_of_customers, int argc, int avaiable[]){
    fprintf(log, "MAXIMUM  | ALLOCATION  | NEED\n");

    for (int i = 0; i < number_of_customers; i++){
        //exibindo max do cliente i
        for (int j = 0; j < argc; j++){
            fprintf(log, "%d ", max[i][j]);
        }
        fprintf(log, " | ");

        //exibindo o allocation do cliente i

        for (int j = 0; j < argc; j++){
            fprintf(log, "%d ", allocation[i][j]);
        }
        fprintf(log, " | ");

        //exibindo o need do cliente i

        for (int j = 0; j < argc; j++){
            fprintf(log, "%d ", need[i][j]);
        }
        fprintf(log, "\n");
    }

    //exibindo o avaiable no final
    fprintf(log, "AVAIABLE ");
    for (int i = 0; i < argc; i++){
        fprintf(log, "%d ", avaiable[i]);
    }
    fprintf(log, "\n");
}