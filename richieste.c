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









// AGGIORNAMENTO STATO RICHIESTA

// Questa funzione permette di aggiornare lo stato di una richiesta
// dopo aver verificato la validità del passaggio di stato


void aggiornaStatoRichiesta(
    Richiesta richieste[],
    int nRichieste
) {
    int codice;                                                       // codice identificativo della richiesta
    int indice;                                                       // indice della richiesta nell'array
    char nuovoStato[20];                                                 // nuovo stato scelto dall'utente

    printf("\nInserisci codice richiesta: ");
    scanf("%d", &codice);


                                                                            // Ricerca della richiesta tramite codice
  
    indice = cercaRichiestaPerCodice(
        richieste,
        nRichieste,
        codice
    );
                                                                            // Se non trovata, esce dalla funzione
    if (indice == -1) {
        printf("Richiesta non trovata\n");
        return;
    }

                                                                            // Mostra stato attuale della richiesta
    printf("\nStato attuale: %s\n",
           richieste[indice].stato);

    printf("\nNuovo stato disponibile:\n");

                                                                    // Menu scelta nuovo stato
    printf("1 -> pianificata\n");
    printf("2 -> in_lavorazione\n");
    printf("3 -> conclusa\n");
    printf("4 -> annullata\n");

    int scelta;

    printf("Scelta: ");
    scanf("%d", &scelta);

                                                            // Conversione scelta numerica -> stringa stato
    switch(scelta) {

        case 1:
            strcpy(nuovoStato, "pianificata");
            break;

        case 2:
            strcpy(nuovoStato, "in_lavorazione");
            break;

        case 3:
            strcpy(nuovoStato, "conclusa");
            break;

        case 4:
            strcpy(nuovoStato, "annullata");
            break;

        default:
            printf("Scelta non valida\n");
            return;
    }

                                                                                    // Controllo tecnico assegnato (caso speciale)
    if (
        strcmp(nuovoStato, "in_lavorazione") == 0 &&
        richieste[indice].tecnicoAssegnato == -1
    ) {
        printf("Errore: nessun tecnico assegnato\n");
        return;
    }

                                                        // Verifica se il cambio di stato è consentito
    if (
        cambioStatoValido(
            richieste[indice].stato,
            nuovoStato
        )
    ) {

                                                                                // Aggiornamento stato
        strcpy(
            richieste[indice].stato,
            nuovoStato
        );

        printf("\nStato aggiornato con successo\n");

    } else {
        printf("\nCambio stato NON consentito\n");
    }
}


// CONTROLLO VALIDITÀ CAMBIO STATO
// Verifica se è possibile passare da uno stato
// attuale a uno nuovo secondo le regole definite

int cambioStatoValido(
    char statoAttuale[],
    char nuovoStato[]
) {

                                                                        // aperta -> pianificata / annullata
    if (
        strcmp(statoAttuale, "aperta") == 0 &&
        (
            strcmp(nuovoStato, "pianificata") == 0 ||
            strcmp(nuovoStato, "annullata") == 0
        )
    ) {
        return 1;
    }

                                                                                                        // pianificata -> in lavorazione / annullata
      if (
        strcmp(statoAttuale, "pianificata") == 0 &&
        (
            strcmp(nuovoStato, "in_lavorazione") == 0 ||
            strcmp(nuovoStato, "annullata") == 0
        )
    ) {
        return 1;
    }
                                                                        // in lavorazione -> conclusa
    if (
        strcmp(statoAttuale, "in_lavorazione") == 0 &&
        strcmp(nuovoStato, "conclusa") == 0
    ) {
        return 1;
    }
                                                                                        // qualsiasi altro caso non è valido
    return 0;
}

#endif


