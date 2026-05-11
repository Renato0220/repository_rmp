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














    void visualizzaStorico(Intervento interventi[], int nInterventi) {              //Visualizzazione dello storico degli interventi completati            

    int trovati = 0;

    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║              STORICO INTERVENTI COMPLETATI                 ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");

    printf("┌────────┬──────────┬────────────┬────────────┬────────────┐\n");
    printf("│ CODICE │ TECNICO  │    DATA    │    INIZIO  │     FINE   │\n");
    printf("├────────┼──────────┼────────────┼────────────┼────────────┤\n");

    for (int i = 0; i < nInterventi; i++) {

        if (strcmp(interventi[i].stato, "conclusa") == 0) {

            printf("│ %-6d │ %-8d │ %-10s │ %-10d │ %-10d │\n",
                   interventi[i].codiceRichiesta,
                   interventi[i].idTecnico,
                   interventi[i].data,
                   interventi[i].oraInizio,
                   interventi[i].oraFine);

            trovati++;
        }
    }

    if (trovati == 0) {
        printf("│ %-52s │\n", "Nessun intervento completato presente.");
    }

  printf("___________________________________________________________\n");
}

  
