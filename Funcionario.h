//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Funcionario.h                                                //
//**************************************************************//

#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED

#include "Lista.h"
#include "Fifo.h"
#include "Estatisticas.h"
#include "Menus.h"
#include "Ordenacao.h"
#include "Print.h"
#include "Define.h"

void Balcao();                                        //atender as senhas
void AtenderSenha(FIFO *, char);                      //atendimento da senha
void Atendimento(FIFO*, char);                        //conclusão do atendimento ou transferencia para outro balcao
void TransFIFOPraLista(FIFO * , Lista *);             //transfere filas para a lista
void EstatisticaBalcao(char);                         //calcula as estatisticas do balcao selecionado
void TransferirSenhas(char);                          //transfere as senhas para outro balcao

#endif // FUNCIONARIO_H_INCLUDED
