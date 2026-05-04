#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tecnico.h"

/* Inserimento di un nuovo tecnico nella lista collegata */
int registra_tecnico(Tecnico **lista, int id, const char *nome, const char *spec) {
    /* Alloca la memoria necessaria per il nuovo nodo */
    Tecnico *nuovo = (Tecnico*)malloc(sizeof(Tecnico));
    
    /* se la memoria è esaurita, restituisce 0 */
    if (nuovo == NULL) return 0;

    /* Assegnazione dei dati */
    nuovo->id = id;
    strncpy(nuovo->nome, nome, 49);  /*Utilizziamo Strncpy per evitare buffer overflow */
    strncpy(nuovo->specializzazione, spec, 49);
    nuovo->disponibile = 1; /* Di default il tecnico è libero */

    /* Inserimento in testa il nuovo nodo punta alla vecchia testa della lista */
    nuovo->next = *lista;
    
    /* Aggiorna il puntatore della testa con il nuovo nodo */
    *lista = nuovo;
    
    return 1;
}

/*  Ricerca di un tecnico tramite il suo codice ID */
Tecnico* ricerca_tecnico(Tecnico *lista, int id) {
    /* Caso base: lista finita o tecnico non trovato */
    if (lista == NULL) return NULL;
    
    /* Caso base: ID trovato */
    if (lista->id == id) return lista;
    
    /* Chiamata per analizzare il prossimo elemento della lista */
    return ricerca_tecnico(lista->next, id);
}

/*  Stampa tutti i tecnici registrati */
void visualizza_anagrafica_tecnici(Tecnico *lista) {
    if (lista == NULL) {
        printf("\n[AVVISO]: Nessun tecnico presente in anagrafica.\n");
        return;
    }

    printf("\n--- ELENCO TECNICI REGISTRATI ---\n");
    while (lista != NULL) {
        printf("ID: %d | Nome: %s | Specializzazione: %s | Stato: %s\n", 
               lista->id, lista->nome, lista->specializzazione, 
               lista->disponibile ? "Libero" : "Occupato");
        lista = lista->next;
    }
}