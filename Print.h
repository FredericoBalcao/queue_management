//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Print.h                                                  //
//**************************************************************//
#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

#include <math.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "Define.h"

void MolduraEspaco(int);                 /* Imprime o numero de espaços*/
void MolduraLines(int);                  /* Imprime o caracter na horizontal um numero de vezes na linha*/
void MolduraCols(int);                   /* Imprime o caracter na Vertical um numero de vezes na coluna*/
void MolduraQSE();                       /* Imprime o caracter no quanto superior direito*/
void MolduraQED();                       /* Imprime o caracter no quanto entrocamento direito*/
void MolduraQID();                       /* Imprime o caracter no quanto infeior direito*/
void MolduraQSD();                       /* Imprime o caracter no quanto superior esquerdo*/
void MolduraQEE();                       /* Imprime o caracter no quanto entrocamento esquerdo*/
void MolduraQIE();                       /* Imprime o caracter no quanto infeior esquerdo*/
void Lines(int );                        /* Cria novas linhas */
void Cols(int );                         /* Cria novas colunas */

void printInformacaoUtilizador(int, time_t);
void PrintInformacaoBalcao(int, time_t);
void printAlertaTempo(bool);
void PrintInformacao(float, float, float, int);
void PrintEntreDatas(char, int);
void PrintResultadoEntreDatas(int, double, int);
void printMenuP(char *opcao);
void printAtenderSenha(char , bool);
void printBalcaoPausa(bool);
void printListagemSenhasAtendidas();
void printListagemSenhasPorAtender(char balcao);
void printMenuBalcao(char *);
void printMenuBalcaoSenha(char *);
void printMenuAuxiliar(char *, char balcao);
void printMenuATransf(char *);
void printMenuBTransf(char *);
void printMenuCTransf(char *);
void printMenuDTransf(char *);
void printMenuEstatistica(char *);
void printMenuListagens(char *);
void printMenuMais(char *);
void printMenuMaisListagem(char *);
void printMenuP(char *);
void printMenuRandom(char *);
void printMenuSenha(char *);
void printMenuTipoOrdenacao(char *);
void printMenuUtilizador(char *);
void printMenuEstatistica(char *);


#endif // PRINT_H_INCLUDED
