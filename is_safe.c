#include "biblioteca.h"

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
