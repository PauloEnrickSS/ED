#include <stdio.h>
#include <stdlib.h>

#include "../structs/Candidato.h"
#define NUM_CANDIDATOS 4

void ler_candidatos(Candidato candidatos[], int num_candidatos) {
    FILE *file = fopen("Arquivos_de_entrada/candidatos.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo 2.\n");
        exit(1);
    }

    for (int i = 0; i < num_candidatos; i++) {
        if (fscanf(file, "%d %d %d %d %d %d", 
                   &candidatos[i].candidato, 
                   &candidatos[i].setor_pref[0], 
                   &candidatos[i].setor_pref[1], 
                   &candidatos[i].setor_pref[2], 
                   &candidatos[i].setor_pref[3], 
                   &candidatos[i].setor) != 6) {
            printf("Erro ao ler os dados do candidato.\n");
            fclose(file);
            exit(1);
        }
    }
 fclose(file);
}
