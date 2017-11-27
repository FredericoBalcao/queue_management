//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Menus.h                                                      //
//**************************************************************//


#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Print.h"

#define BalcaoA 'A'
#define BalcaoB 'B'
#define BalcaoC 'C'
#define BalcaoD 'D'
#define Nada 'N'
#define Todos 'T'
#define TodosP 2
#define TipoFifo 0
#define TipoLista 1

#define Prioritaria 1
#define Desistente 1
#define Normal 0

char MenuTipoOrdenacao();                /* Menu Tipo Ordenação */
void Menu();                             /* Menu (apresentacao) */
char MenuP();                            /* Menu do programa */
char MenuUtilizador();                   /* Menu do utilizador */
char MenuSenha();                        /* Menu da senha */
char MenuBalcao();                       /* Menu do balcao  */
char MenuBalcaoOpcao();                  /* Menu do atendimento das senhas */
char MenuBalcaoSenha();                  /* Menu para atender senhas       */
char MenuATransf();                      /* Menu transfere senhas balcao A */
char MenuBTransf();                      /* Menu transfere senhas balcao B */
char MenuCTransf();                      /* Menu transfere senhas balcao C */
char MenuDTransf();                      /* Menu transfere senhas balcao D */
char MenuListagens();                    /* Menu das ordenações */
char MenuEstatisticas();                 /* Menu estatisticas */
char MenuTeste();                        /* Menu para teste */
char MenuAuxiliar(char);                 /* Menu atender senhas inexistentes */
char MenuRandom();                       /* Menu para senhas aleatorias */
char MenuMais1();                        /* Menu Estatisticas no Balcao*/
char MenuMais2();


#endif // MENUS_H_INCLUDED
