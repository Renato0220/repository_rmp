#ifndef TECNICO_H
#define TECNICO_H

/* Definizione della struttura dati per la gestione dei tecnici */
typedef struct Tecnico {
    int id;
    char nome[50];
    char specializzazione[50];
    int disponibile; /* 1: Libero, 0: Occupato */
    struct Tecnico *next; /* Puntatore per la gestione dinamica a lista */
} Tecnico;

/* Funzioni del modulo Gestione Tecnici */
int registra_tecnico(Tecnico **lista, int id, const char *nome, const char *spec);
Tecnico* ricerca_tecnico(Tecnico *lista, int id);
void visualizza_anagrafica_tecnici(Tecnico *lista);

#endif