#include <stdio.h>
#include <string.h>
#include "interventi.h"
#include "richieste.h"
#include "tecnici.h"

// ================== FUNZIONI ==================

// Controllo conflitti
int verificaConflitto(Intervento interventi[], int n, Intervento nuovo) {
    for (int i = 0; i < n; i++) {
        if (interventi[i].idTecnico == nuovo.idTecnico &&
            strcmp(interventi[i].data, nuovo.data) == 0) {

            if (!(nuovo.oraFine <= interventi[i].oraInizio ||
                  nuovo.oraInizio >= interventi[i].oraFine)) {
                return 1; // conflitto
            }
        }
    }
    return 0;
}

// Pianifica intervento
int pianificaIntervento(
    Intervento interventi[],
    int *nInterventi,
    int codiceRichiesta,
    int idTecnico,
    char data[],
    int oraInizio,
    int oraFine
) {
    Intervento nuovo;

    nuovo.codiceRichiesta = codiceRichiesta;
    nuovo.idTecnico = idTecnico;
    strcpy(nuovo.data, data);
    nuovo.oraInizio = oraInizio;
    nuovo.oraFine = oraFine;

    // controllo conflitto
    if (verificaConflitto(interventi, *nInterventi, nuovo)) {
        printf("Errore: conflitto di orario\n");
        return 0;
    }

    // aggiungi intervento
    interventi[*nInterventi] = nuovo;
    (*nInterventi)++;

    printf("Intervento pianificato con successo\n");
    return 1;
}

// Stampa interventi
void stampaInterventi(Intervento interventi[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Intervento %d ---\n", i + 1);
        printf("Richiesta: %d\n", interventi[i].codiceRichiesta);
        printf("Tecnico: %d\n", interventi[i].idTecnico);
        printf("Data: %s\n", interventi[i].data);
        printf("Orario: %d - %d\n",
               interventi[i].oraInizio,
               interventi[i].oraFine);
    }
}
