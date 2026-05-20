
#include "biblioteca.h"

void imprimir_status(FILE *log, int **max, int **allocation, int **need, int number_of_customers, int argc, int avaiable[]){
    int maior_num = 0;
    for (int i = 0; i < number_of_customers; i++){
        for (int j = 0; j < argc; j++) {
            if (max[i][j] > maior_num) {
                maior_num = max[i][j];
            }
            if (allocation[i][j] > maior_num) {
                maior_num = allocation[i][j];
            }
            if (need[i][j] > maior_num) {
                maior_num = need[i][j];
            }
        }
    }
    int digitos;
    if (maior_num > 0) {
        digitos = (int)log10(maior_num) + 1;
    } else {
        digitos = 1;
    }
    int largura = digitos * argc + (argc - 1);
    int len_max = strlen("MAXIMUM");
    int len_aloc = strlen("ALLOCATION");
    if (largura > len_aloc) {
        len_aloc = largura;
    }
    if (largura > len_max) {
        len_max = largura;
    }

    fprintf(log, "%-*s   |   %-*s  |   %s\n", len_max, "MAXIMUM", len_aloc, "ALLOCATION", "NEED");
    for (int i = 0; i < number_of_customers; i++) {
        char buf_max[256], buf_aloc[256], buf_nece[256];
        int pos = 0;

        for (int j = 0; j < argc; j++) {
            if (j > 0) {
                pos += sprintf(buf_max + pos, " ");
            }
            pos += sprintf(buf_max + pos, "%*d", digitos, max[i][j]);
        }
        pos = 0;
        for (int j = 0; j < argc; j++) {
            if (j > 0) {
                pos += sprintf(buf_aloc + pos, " ");
            }
            pos += sprintf(buf_aloc + pos, "%*d", digitos, allocation[i][j]);
        }
        pos = 0;
        for (int j = 0; j < argc; j++) {
            if (j > 0) {
                pos += sprintf(buf_nece + pos, " ");
            }
            pos += sprintf(buf_nece + pos, "%*d", digitos, need[i][j]);
        }

        fprintf(log, "%-*s   |   %-*s  |   %s \n", len_max, buf_max, len_aloc, buf_aloc, buf_nece);
    }
}