//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Estatistica.h                                                //
//**************************************************************//

#ifndef ESTATISTICAS_H_INCLUDED
#define ESTATISTICAS_H_INCLUDED

#include "Fifo.h"
#include "Lista.h"
#include "Menus.h"
#include <math.h>
#include <time.h>
#include "Print.h"

int NumeroSenhas (No *, char, int,  int);                           /* Conta o numero de senhas */
double TempoSenhas (No*, char, bool,  int);                         /* Conta a diferença de tempo das senhas */
void AlertaTempo(Lista *,No *, char, bool );                        /* Informação do tempo maximo e minimo*/
void InformacaoUtilizador(FIFO *, Lista *, char, int);              /* Informação do utilizador*/
void InformacaoBalcao(FIFO *, Lista *, char );                      /* Informação do balcao */
void InformacaoSenhas(Lista *,int);                                 /* Informação sobre as senhas na lista */
void Entredatas(Lista *, char );                                    /* Informação das senhas entre datas */
void Estatistica();                                                 /* Informação estatistica */
void BalcaoEstatisticas();                                          /* Informação estatistica do balcao */



#endif // ESTATISTICAS_H_INCLUDED
