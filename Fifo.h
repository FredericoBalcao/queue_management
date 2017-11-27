//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Fifo.h                                                       //
//**************************************************************//


#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

#include <stdio.h>
#include <time.h>
#include "No.h"
#include "Print.h"
#include "Menus.h"

/* Estrutura que representa uma FIFO */
typedef struct
{
    No *primeiro;	                    /* primeiro nó da fifo */
    No *ultimo;		                    /* último nó da fifo */
    No *maior;                          /* nó com maior numero de senha nes a fifo */
} FIFO;

FIFO *criar_fifo();                     /* criar FIFO*/
void lista_fifo(FIFO*);                 /* lista FIFO*/
int empty_queue(FIFO*);                 /* verifica se a FIFO esta vazia*/
void ADD_FIFO(FIFO*, char);             /* insere No a FIFO (normal)*/
void read_fifo(FIFO*);                  /* Apaga FIFO*/
void Transferir(FIFO*, FIFO*, char);    /* Transfere de uma FIFO para outra FIFO*/
void ADDFIFO1(FIFO *, char );           /* insere No a FIFO (prioritária)*/

FIFO *FIFOA;
FIFO *FIFOB;
FIFO *FIFOC;
FIFO *FIFOD;

#endif // FIFO_H_INCLUDED
