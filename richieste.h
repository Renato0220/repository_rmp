#ifndef RICHIESTE_H
#define RICHIESTE_H

// numero massimo di richieste
#define MAX 100

// ================== STRUTTURA RICHIESTA ==================

typedef struct {

    int codice;                     // codice identificativo richiesta

    char appartamento[50];          // appartamento o area interessata

    char tipologia[50];             // tipo problema (idraulico, elettrico...)

    char descrizione[200];          // descrizione del problema

    char dataRichiesta[11];         // data richiesta formato YYYY-MM-DD

    int urgenza;                    // livello urgenza (1-3)

    char stato[20];                 // stato richiesta

    int tecnicoAssegnato;           // id tecnico assegnato (-1 se nessuno)

} Richiesta;


// ================== PROTOTIPI FUNZIONI ==================

// aggiunge una nuova richiesta
void aggiungiRichiesta(
    Richiesta richieste[],
    int *nRichieste
);

// stampa tutte le richieste
void stampaRichieste(
    Richiesta richieste[],
    int nRichieste
);

// ricerca richiesta tramite codice
int cercaRichiestaPerCodice(
    Richiesta richieste[],
    int nRichieste,
    int codice
);








// queste 2 funzioni aggiorna Stato Richiesta e cambio Stato Valido servono per l'opzione 5 del menu principale, ovvero aggiornamento stato richiesta 
// aggiorna lo stato di una richiesta se il passaggio è valido 
// da aperta a pianificata, da pianificata passa in lavorazione, da in lavorazione a conclusa .

void aggiornaStatoRichiesta(
    Richiesta richieste[],
    int nRichieste
);

int cambioStatoValido(
    char statoAttuale[],
    char nuovoStato[]
);



#endif

