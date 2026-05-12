#include <stdio.h>
#include <string.h>

#include "assegna.h"


#include "richieste.h"
#include "tecnico.h"




// menu lavori - mostra i tecnici disponibili per una tipologia di lavoro e consente di assegnare un tecnico a una richiesta specifica
// aggiornando lo stato della richiesta e la disponibilità del tecnico.
//invece di inserire a mano la tipologia, mostra un menu con le opzioni più comuni e consente di scegliere da lì, semplificando l'assegnazione e riducendo ERRORI .

void menuLavori(char tipologia[]) {

    int scelta;

    printf("\n--- MENU LAVORI ---\n");
    printf("1. Idraulico\n");
    printf("2. Elettricista\n");
    printf("3. Muratore\n");
    printf("4. Ascensorista\n");
    printf("5. Giardiniere\n");
    printf("6. Falegname\n");
    printf("7. Pittore\n");
    printf("8. Termoidraulico\n");
    printf("9. Piastrellista\n");
    printf("10. Elettronico\n");

    printf("Scelta: ");
    scanf("%d", &scelta);

    switch(scelta) {

        case 1: strcpy(tipologia, "idraulico"); break;
        case 2: strcpy(tipologia, "elettricista"); break;
        case 3: strcpy(tipologia, "muratore"); break;
        case 4: strcpy(tipologia, "ascensorista"); break;
        case 5: strcpy(tipologia, "giardiniere"); break;
        case 6: strcpy(tipologia, "falegname"); break;
        case 7: strcpy(tipologia, "pittore"); break;
        case 8: strcpy(tipologia, "termoidraulico"); break;
        case 9: strcpy(tipologia, "piastrellista"); break;
        case 10: strcpy(tipologia, "elettronico"); break;

        default:
            printf("Scelta non valida.\n");
            strcpy(tipologia, "");
    }
}











void assegnaTecnico(
    Richiesta richieste[],
    int n,
    Tecnico *lista
)           {

    int codice;
    int pos = -1;                           // posizione richiesta da assegnare 

    printf("Inserisci codice richiesta: ");
    scanf("%d", &codice);

                                                                        // cerca richiesta
    for(int i = 0; i < n; i++) {

        if(richieste[i].codice == codice) {
            pos = i;    
            break;
        }
    }

    if(pos == -1) {                         
        printf("Richiesta non trovata.\n");
        return;
    }

    if(richieste[pos].tecnicoAssegnato != -1) {                       
        printf("Gia assegnata.\n");
        return;
    }

                                                    // MENU LAVORI - mostra i tecnici disponibili 
    menuLavori(richieste[pos].tipologia);




    if(strlen(richieste[pos].tipologia) == 0) {
        printf("Operazione annullata.\n");
        return;
    }

    Tecnico *temp = lista;          // cerca tecnico disponibile con specializzazione richiesta 

    while(temp != NULL) {                                     // scorre lista tecnici 

        if(strcmp(richieste[pos].tipologia,
                  temp->specializzazione) == 0                                              // specializzazione richiesta e tecnico coincidono 
           && temp->disponibile == 1) {             // tecnico disponibile 

            richieste[pos].tecnicoAssegnato = temp->id;                   // assegna tecnico a richiesta 
            temp->disponibile = 0;                          // aggiorna disponibilità tecnico



            strcpy(richieste[pos].stato, "pianificata");                             // aggiorna stato richiesta

            printf("\nTecnico assegnato: %s\n", temp->nome);                // conferma assegnazione

            return;
        }

        temp = temp->next;              // passa al tecnico successivo 
    }

    printf("Nessun tecnico disponibile.\n");
}
