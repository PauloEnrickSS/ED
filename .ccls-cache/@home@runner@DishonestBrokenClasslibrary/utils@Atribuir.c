#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../structs/Candidato.h"
#include "../structs/Setor.h"
#include "Incluir_candidatos.h"
#include "Incluir_setores.h"


void gale_shapley(Setor setores[], Candidato candidatos[], int num_sectors) {
    bool candidatos_livres[num_sectors];  
    int propostas[num_sectors];         


    for (int i = 0; i < num_sectors; i++) {
        candidatos_livres[i] = true;
        propostas[i] = 0;
        candidatos[i].setor = -1;          
        setores[i].candidato = -1;        
    }

    int livres = num_sectors;              

 
    while (livres > 0) {
        int c; 
        for (c = 0; c < num_sectors; c++) {
            if (candidatos_livres[c]) break;
        }

        
        int setor_pref_id = candidatos[c].setor_pref[propostas[c]]; 
        propostas[c]++;

       
        if (setores[setor_pref_id - 1].candidato == -1) {
            setores[setor_pref_id - 1].candidato = c; 
            candidatos[c].setor = setor_pref_id;       
            candidatos_livres[c] = false;              
            
            livres--;
        } else {
           
            int candidato_atual = setores[setor_pref_id - 1].candidato;
            int prefere_novo = -1;
            for (int i = 0; i < 4; i++) {
                if (setores[setor_pref_id - 1].candidato_pref[i] == c) {
                    prefere_novo = 1;
                    break;
                } else if (setores[setor_pref_id - 1].candidato_pref[i] == candidato_atual) {
                    prefere_novo = 0;
                    break;
                }
            }
            
            if (prefere_novo == 1) {
                setores[setor_pref_id - 1].candidato = c;
                candidatos[c].setor = setor_pref_id;
                candidatos_livres[c] = false;
                candidatos_livres[candidato_atual] = true; 
            }
        }
    }
}