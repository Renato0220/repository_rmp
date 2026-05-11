#include <stdio.h>
#include <string.h>

#include "richieste.h"


// ================== AGGIUNTA RICHIESTA ==================

void aggiungiRichiesta(
    Richiesta richieste[],
    int *nRichieste
) {

    // variabile temporanea
    Richiesta r;

    // inserimento dati richiesta

    printf("Codice richiesta: ");
    scanf("%d", &r.codice);

    printf("Appartamento/Area: ");
    scanf("%s", r.appartamento);

    printf("Tipologia problema: ");
    scanf("%s", r.tipologia);

    printf("Descrizione: ");
    scanf("%s", r.descrizione);

    printf("Data richiesta (YYYY-MM-DD): ");
    scanf("%s", r.dataRichiesta);

    printf("Urgenza (1=bassa, 2=media, 3=alta): ");
    scanf("%d", &r.urgenza);

    // stato iniziale della richiesta
    strcpy(r.stato, "aperta");

    // nessun tecnico assegnato all'inizio
    r.tecnicoAssegnato = -1;

    // salvataggio richiesta nell'array
    richieste[*nRichieste] = r;

    // incremento numero richieste
    (*nRichieste)++;

    printf("Richiesta aggiunta con successo\n");
}


// ================== STAMPA RICHIESTE ==================

void stampaRichieste(
    Richiesta richieste[],
    int nRichieste
) {

    int i;

    // ciclo stampa richieste
    for (i = 0; i < nRichieste; i++) {

        printf("\n--- RICHIESTA %d ---\n", i + 1);

        printf("Codice: %d\n",
               richieste[i].codice);

        printf("Appartamento: %s\n",
               richieste[i].appartamento);

        printf("Tipologia: %s\n",
               richieste[i].tipologia);

        printf("Descrizione: %s\n",
               richieste[i].descrizione);

        printf("Data richiesta: %s\n",
               richieste[i].dataRichiesta);

        printf("Urgenza: %d\n",
               richieste[i].urgenza);

        printf("Stato: %s\n",
               richieste[i].stato);

        printf("Tecnico assegnato: %d\n",
               richieste[i].tecnicoAssegnato);
    }
}


// ================== RICERCA PER CODICE ==================

int cercaRichiestaPerCodice(
    Richiesta richieste[],
    int nRichieste,
    int codice
) {

    int i;

    // ricerca nell'array richieste
    for (i = 0; i < nRichieste; i++) {

        // confronto codice
        if (richieste[i].codice == codice) {

            printf("\nRichiesta trovata\n");

            printf("Codice: %d\n",
                   richieste[i].codice);

            printf("Tipologia: %s\n",
                   richieste[i].tipologia);

            printf("Stato: %s\n",
                   richieste[i].stato);

            return i;
        }
    }

    // richiesta non trovata
    printf("Richiesta non trovata\n");

    return -1;
}
