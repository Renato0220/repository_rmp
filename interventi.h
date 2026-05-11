#ifndef INTERVENTI_H
#define INTERVENTI_H

#define MAX 100

typedef struct {
    int codiceRichiesta;
    int idTecnico;
    char data[11];
    int oraInizio;
    int oraFine;
} Intervento;

// FUNZIONI

int verificaConflitto(Intervento interventi[], int n, Intervento nuovo);

int pianificaIntervento(
    Intervento interventi[],
    int *nInterventi,
    int codiceRichiesta,
    int idTecnico,
    char data[],
    int oraInizio,
    int oraFine
);

void stampaInterventi(Intervento interventi[], int n);

#endif
