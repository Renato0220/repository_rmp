//PROGETTO PSD ------ MENU DI SCELTA 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "richieste.h" 
#include "tecnico.h"

// ================== STRUTTURA INTERVENTO ==================

typedef struct {

    int codiceRichiesta;

    int idTecnico;

    char data[20];

    int oraInizio;

    int oraFine;

} Intervento;


// array interventi
Intervento interventi[100];

// numero interventi
int nInterventi = 0;


//array richieste 
Richiesta richieste[MAX];
int nRichieste = 0;



void stampa_menu() {
    printf("\n\t __________________________________________ \n");
    printf("\t|             MENU PRINCIPALE              |\n");
    printf("\t|__________________________________________|\n");
    printf("\t|                                          |\n");
    printf("\t|  1.  Inserimento nuova richiesta         |\n");
    printf("\t|  2.  Registrazione tecnici               |\n");
    printf("\t|  3.  Assegnazione richiesta              |\n");
    printf("\t|  4.  Pianificazione intervento           |\n");
    printf("\t|  5.  Aggiornamento stato                 |\n");
    printf("\t|  6.  Visualizzazione richieste           |\n");
    printf("\t|  7.  Ricerca per codice o tipologia      |\n");
    printf("\t|  8.  Visualizzazione storico             |\n");
    printf("\t|  9.  Monitoraggio carico di lavoro       |\n");
    printf("\t| 10.  Generazione report                  |\n");
    printf("\t|                                          |\n");
    printf("\t|  0.  Esci                                |\n");
    printf("\t|__________________________________________|\n");
    
}


void opzione_uno() {                                                         // Inserimento di una nuova richiesta
    printf("\n--- Hai scelto l'opzione 1 ---\n");
   //DA AMPLIARE ............
}                                                 
void opzione_due(Tecnico **lista) { 
    int id;
    char nome[50], spec[50];

    printf("\n--- REGISTRAZIONE NUOVO TECNICO ---\n");
    
    printf("ID (numero): ");
    scanf("%d", &id);
    getchar(); // Pulizia del buffer per non saltare il nome

    printf("Nome e Cognome: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = 0; // Toglie l'invio finale

    printf("Specializzazione: ");
    fgets(spec, 50, stdin);
    spec[strcspn(spec, "\n")] = 0;

    // Chiama la funzione presente in tecnico.c
    if (registra_tecnico(lista, id, nome, spec)) {
        printf("\n[OK] Tecnico registrato con successo!\n");
    } else {
        printf("\n[ERRORE] Memoria piena, impossibile aggiungere.\n");
    }


}
                             
void opzione_tre() {                                                     //Assegnazione di una richiesta    
    printf("\n--- Hai scelto l'opzione 3 ---\n");
     //DA AMPLIARE ............
}
                
   
void opzione_cinque(Richiesta richieste[], int nRichieste) {                        //Aggiorna stato
    aggiornaStatoRichiesta(richieste, nRichieste);
}





void opzione_sei() {                                                     //Visualizza richieste
    printf("\n--- Hai scelto l'opzione 6 ---\n");
     //DA AMPLIARE ............
}


void opzione_otto() {                                        //Visualizzazione dello storico
    printf("\n--- Hai scelto l'opzione 8 ---\n");
     //DA AMPLIARE ............
}

void opzione_nove() {                                             //Monitoraggio del carico di lavoro
    printf("\n--- Hai scelto l'opzione 9 ---\n");
     //DA AMPLIARE ............
}



// ================== PIANIFICAZIONE INTERVENTO ==================

void opzione_quattro() {

    int i;

    Intervento nuovo;

    int conflitto = 0;

    printf("\n--- PIANIFICAZIONE INTERVENTO ---\n");

    printf("Codice richiesta: ");
    scanf("%d", &nuovo.codiceRichiesta);

    printf("ID Tecnico: ");
    scanf("%d", &nuovo.idTecnico);

    printf("Data (YYYY-MM-DD): ");
    scanf("%s", nuovo.data);

    printf("Ora inizio: ");
    scanf("%d", &nuovo.oraInizio);

    printf("Ora fine: ");
    scanf("%d", &nuovo.oraFine);

    // controllo conflitti
    for (i = 0; i < nInterventi; i++) {

        if (
            interventi[i].idTecnico == nuovo.idTecnico &&
            strcmp(interventi[i].data, nuovo.data) == 0
        ) {

            if (
                nuovo.oraInizio < interventi[i].oraFine &&
                nuovo.oraFine > interventi[i].oraInizio
            ) {

                conflitto = 1;
            }
        }
    }

    // se esiste conflitto
    if (conflitto) {

        printf("\nERRORE: conflitto di orario!\n");

        return;
    }

    // salvataggio intervento
    interventi[nInterventi] = nuovo;

    nInterventi++;

    printf("\nIntervento pianificato correttamente!\n");
}

// ================== RICERCA INTERVENTO ==================

void opzione_sette() {

    int codice;

    int i;

    printf("\n--- RICERCA INTERVENTO ---\n");

    printf("Inserisci codice richiesta: ");

    scanf("%d", &codice);

    for (i = 0; i < nInterventi; i++) {

        if (interventi[i].codiceRichiesta == codice) {

            printf("\nIntervento trovato!\n");

            printf("Codice richiesta: %d\n",
                   interventi[i].codiceRichiesta);

            printf("Tecnico: %d\n",
                   interventi[i].idTecnico);

            printf("Data: %s\n",
                   interventi[i].data);

            printf("Orario: %d - %d\n",
                   interventi[i].oraInizio,
                   interventi[i].oraFine);

            return;
        }
    }

    printf("\nIntervento non trovato\n");
}

// ================== GENERAZIONE REPORT ==================

void opzione_dieci() {

    int i;

    printf("\n===== REPORT INTERVENTI =====\n");

    printf("Numero totale interventi: %d\n",
           nInterventi);

    // controllo presenza interventi
    if (nInterventi == 0) {

        printf("Nessun intervento presente\n");

        return;
    }

    // stampa interventi
    for (i = 0; i < nInterventi; i++) {

        printf("\n--- Intervento %d ---\n", i + 1);

        printf("Codice richiesta: %d\n",
               interventi[i].codiceRichiesta);

        printf("Tecnico: %d\n",
               interventi[i].idTecnico);

        printf("Data: %s\n",
               interventi[i].data);

        printf("Orario: %d - %d\n",
               interventi[i].oraInizio,
               interventi[i].oraFine);
    }

    printf("\n===== FINE REPORT =====\n");
}


int main () { 

 
    int scelta ; 
    Tecnico *lista_tecnici = NULL;

     do {                                                       // ciclo per la scelta delle varie opzioni 
        
        stampa_menu();              
        
        printf("\n\n\tScelta: ");
        if (scanf("%d", &scelta) != 1) {
            while (getchar() != '\n');                               // svuota buffer
            scelta = -1;                                     //lo scanf fallisce e scelta diventa -1 e quindi stampa default 
        }
        
        switch (scelta) {

            case 1 : opzione_uno(aggiungiRichiesta(richieste, &nRichieste);); 
            break;
			
			case 2 : opzione_due(&lista_tecnici); // Passiamo l'indirizzo della lista con la &
            break;

            case 3 : opzione_tre(); 
            break;

            case 4 : opzione_quattro(); 
            break;

            case 5:  opzione_cinque(aggiornaStatoRichiesta(richieste, nRichieste););        //opzione 5 funziona solo se la richiesta esiste e un tecnico è stato assegnato, altrimenti stampa richiesta non trovata o tecnico non assegnato
            break;

            case 6 : opzione_sei();
            break;

            case 7 : opzione_sette();
            break;

            case 8 : opzione_otto();
            break;

            case 9 : opzione_nove();
            break;
            
            case 10 : opzione_dieci();
            break;

            case 0: printf("\nArrivederci!\n");
            break;                                             //se la scelta è 0 stamperà arrivederci 
           
            default: printf("\nOpzione non valida.\n");
        }
        
        if (scelta != 0) {
            printf("\nPremi INVIO per continuare...");
            while (getchar() != '\n');
            getchar();
        }
        
    } while (scelta != 0);
    
    return 0;

}






/*Casi di Test:
● Verifica della registrazione delle richieste
● Test della registrazione dei tecnici
● Verifica dell’assegnazione corretta
● Test della pianificazione e gestione conflitti
● Verifica aggiornamento stato
● Test della ricerca e filtri
● Verifica dello storico interventi
● Test della generazione dei report



Report:
● Motivazione della Scelta dell'ADT: Illustrare perché specifici ADT sono stati
scelti per gestire richieste, tecnici, pianificazione, priorità e ricerche.
● Progettazione: Descrivere l’architettura del sistema e l’interazione tra i moduli.
● Specifica Sintattica e Semantica: Descrivere operazioni, pre/post condizioni,
input/output ed effetti collaterali.
● Razionale dei Casi di Test.*/



