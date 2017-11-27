//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// No.h                                                  //
//**************************************************************//

#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include "Item.h"


typedef struct no No;

struct no
{
    Item *dados;                 /* Item*/
    No *next;                    /* Ponteiro para proximo No*/

};




#endif // NO_H_INCLUDED
