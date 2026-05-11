#include <stdio.h>
#include "visualizza.h"

void visualizza_anagrafica_tecnici(Tecnico *lista) {
    if (lista == NULL) {
        printf("\n[!] Archivio vuoto. Nessun tecnico registrato.\n");
        return;
    }

    printf("\n--- ELENCO TECNICI REGISTRATI ---\n");
    printf("%-10s | %-20s | %-20s\n", "ID", "NOME", "SPECIALIZZAZIONE");
    printf("------------------------------------------------------------\n");

    while (lista != NULL) {
        printf("%-10d | %-20s | %-20s\n", lista->id, lista->nome, lista->specializzazione);
        lista = lista->next; 
    }
    printf("------------------------------------------------------------\n");
}