#ifndef ASSEGNA_H
#define ASSEGNA_H

#include "richieste.h"
#include "tecnico.h"



// MENU LAVORI - mostra i tecnici disponibili per una tipologia di lavoro e consente di assegnare un tecnico a una richiesta specifica
// aggiornando lo stato della richiesta e la disponibilità del tecnico.

void menuLavori(char tipologia[]);



// ASSEGNAZIONE TECNICO A RICHIESTA 
//assegna un tecnico disponibile a una richiesta specifica, aggiornando lo stato della richiesta e la disponibilità del tecnico

void assegnaTecnico(Richiesta richieste[], int n, Tecnico *lista);


#endif
