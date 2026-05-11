#ifndef MONITORAGGIO_H
#define MONITORAGGIO_H

#include "tecnico.h"     // Per la struttura Tecnico
#include "interventi.h"  // Per la struttura Intervento

// Dichiarazione della funzione 
void monitoraggio_carico_lavoro(Tecnico *lista_t, Intervento interventi[], int n_int);

#endif