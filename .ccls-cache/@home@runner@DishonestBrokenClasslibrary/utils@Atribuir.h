#ifndef ATRIBUIR_H
#define ATRIBUIR_H

#define NUM_SECTORS 4

#include <stdbool.h>
#include "../structs/Candidato.h"
#include "../structs/Setor.h"

void gale_shapley(Setor setores[], Candidato candidatos[], int num_sectors);
#endif