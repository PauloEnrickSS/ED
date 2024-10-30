#include <stdio.h>
#include <stdlib.h>

#include "../structs/Setor.h"
#define NUM_SETORES 4

void ler_setores(Setor setores[], int num_setores) {
    FILE *file = fopen("Arquivos_de_entrada/setor.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo 1.\n");
        exit(1);
    }

    for (int i = 0; i < num_setores; i++) {
        if (fscanf(file, "%d %d %d %d %d %d", 
                   &setores[i].setor, 
                   &setores[i].candidato_pref[0], 
                   &setores[i].candidato_pref[1], 
                   &setores[i].candidato_pref[2], 
                   &setores[i].candidato_pref[3], 
                   &setores[i].candidato) != 6) {
            printf("Erro ao ler os dados do setor.\n");
            fclose(file);
            exit(1);
        }
    }

    fclose(file);
}

