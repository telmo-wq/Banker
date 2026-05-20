#include "biblioteca.h"


void imprimir_status(FILE *log, int **max, int **allocation, int **need, int number_of_customers, int argc, int avaiable[]){
    int largura_maxima = 1;
    for (int i = 0; i < number_of_customers; i++){
        for (int j = 0; j < argc; j++){
            int val = max[i][j];
            int digitos = (val == 0) ? 1 : 0;
            while (val > 0) { 
                digitos++; 
                val /= 10; 
            }
            if (digitos > largura_maxima) largura_maxima = digitos;
            
            val = allocation[i][j];
            digitos = (val == 0) ? 1 : 0;
            while (val > 0) { 
                digitos++; 
                val /= 10; 
            }
            if (digitos > largura_maxima) largura_maxima = digitos;
            
            val = need[i][j];
            digitos = (val == 0) ? 1 : 0;
            while (val > 0) { 
                digitos++; 
                val /= 10; 
            }
            if (digitos > largura_maxima) largura_maxima = digitos;
        }
    }

    int largura_bloco = (largura_maxima + 1) * argc - 1;
    fprintf(log, "%-*s | %-*s | NEED\n", largura_bloco, "MAXIMUM", largura_bloco, "ALLOCATION");

    fprintf(log, "\n");

    for (int i = 0; i < number_of_customers; i++){
        //exibindo max do cliente i
        for (int j = 0; j < argc; j++){
            fprintf(log, "%*d ", largura_maxima, max[i][j]);
            if (j < argc - 1) fprintf(log, " ");
        }
        fprintf(log, " | ");

        //exibindo o allocation do cliente i

        for (int j = 0; j < argc; j++){
            fprintf(log, "%*d ", largura_maxima, allocation[i][j]);
            if (j < argc - 1) fprintf(log, " ");
        }
        fprintf(log, " | ");

        //exibindo o need do cliente i

        for (int j = 0; j < argc; j++){
            fprintf(log, "%*d ", largura_maxima, need[i][j]);
            if (j < argc - 1) fprintf(log, " ");
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