#include <stdio.h>
#include <stdlib.h>

#include "./structs/Candidato.h"
#include "./structs/Setor.h"
#include "./utils/Incluir_setores.h"
#include "./utils/Incluir_candidatos.h"
#include "./utils/Atribuir.h""

int num_setores = 4;
int num_candidatos = 4; 

int main(){
  
   void ler_setores(Setor setores[], int num_setores);
   void ler_candidatos(Candidato candidatos[], int num_candidatos);
     
   Setor setores[num_setores];
   Candidato candidatos[num_candidatos]; 

  ler_setores(setores, num_setores);
  ler_candidatos(candidatos, num_candidatos);

  gale_shapley(setores, candidatos, num_setores);

  
  printf("Resultados do Algoritmo Gale-Shapley:\n");
  for (int i = 0; i < num_setores; i++) {
      printf("Setor %d está emparelhado com Candidato %d\n", setores[i].setor, setores[i].candidato + 1);
  }
  for (int i = 0; i < num_candidatos; i++) {
      printf("Candidato %d está emparelhado com Setor %d\n", candidatos[i].candidato, candidatos[i].setor);
  }
  
}

