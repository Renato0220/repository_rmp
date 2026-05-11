#include <stdio.h>
#include "monitoraggio.h"

void monitoraggio_carico_lavoro(Tecnico *lista_t, Intervento interventi[], int n_int) {
    if (lista_t == NULL) {
        printf("\n[!] Errore: Nessun tecnico registrato in anagrafica.\n");
        return;
    }

    printf("\n============================================================\n");
    printf("             REPORT CARICO DI LAVORO TECNICI                \n");
    printf("============================================================\n");
    printf("%-10s | %-20s | %-15s\n", "ID", "NOME", "N. INTERVENTI");
    printf("------------------------------------------------------------\n");

    Tecnico *attuale = lista_t;
    
    // Ciclo esterno: scorre la lista dei tecnici 
    while (attuale != NULL) {
        int conteggio = 0;
        
        // Ciclo interno: scorre l'array degli interventi per contare quelli assegnati al tecnico attuale
        for (int i = 0; i < n_int; i++) {
            if (interventi[i].idTecnico == attuale->id) {
                conteggio++;
            }
        }

        printf("%-10d | %-20s | %-15d\n", attuale->id, attuale->nome, conteggio);
        attuale = attuale->next;
    }
    printf("------------------------------------------------------------\n");
}