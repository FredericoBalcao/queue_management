//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Item.h                                                       //
//**************************************************************//


#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#include "Print.h"
#include "Menus.h"

typedef struct
{
    int Id;                                     /* numero da senha */
    char Balcao;                                /* balcao previamente selecionado [A,B,C,D] */
    time_t HoraEntrada;                         /* hora de entrada do utilizador */
    time_t HoraAtendimento;                     /* hora de atendimento do utilizador */
    time_t HoraSaida;                           /* hora de saida do utilizador */
    bool status;                                /* status especifico */
    bool prioridade;                            /* para senha normal ou senha prioritária */
} Item;

void Print_Item(bool, Item*);                         /* Imprime o Item para a FIFO */
Item *InsereItem(char, int);                    /* O Balcao e o numero da senha e hora de entrada no Item */

/*Ordenar por Maior para Menor*/
int PorDiffMaiorMenor (Item *A, Item *B);           /* Verifica se a diferença de tempo é igual */
int PorBalcaoMaiorMenor (Item *A, Item *B);         /* Verifica se a balcao é igual */
int PorDataAtendimentoMaiorMenor(Item *A, Item *B); /* Verifica se a data de atendimento é igual */
int PorDataEntradaMaiorMenor(Item *A, Item *B);     /* Verifica se a data de entrada é igual */
int PorDataSaidaMaiorMenor(Item *A, Item *B);       /* Verifica se a data de saida é igual */
int PorSenhaMaiorMenor(Item *A, Item *B);           /* Verifica se a senha é igual */

/*Ordenar por Menor para Maior*/
int PorDiffMenorMaior (Item *A, Item *B);           /* Verifica se diferença é igual */
int PorBalcaoMenorMaior (Item *A, Item *B);         /* Verifica se a balcao é igual */
int PorDataAtendimentoMenorMaior(Item *A, Item *B); /* Verifica se a data de atendimento é igual */
int PorDataEntradaMenorMaior(Item *A, Item *B);     /* Verifica se a data de entrada é igual */
int PorDataSaidaMenorMaior(Item *A, Item *B);       /* Verifica se a data de saida é igual */
int PorSenhaMenorMaior(Item *A, Item *B);           /* Verifica se a senha é igual */

#endif // ITEM_H_INCLUDED
