//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Ordenacao.c                                                  //
//**************************************************************//

#include "Ordenacao.h"
#include "Define.h"

/*-----------------------------------------------*/
/* Ordena a Lista                                */
/* Parametros: recebe um ponteiro do tipo lista  */
/*-----------------------------------------------*/
void Ordenacao(Lista *lista)
{
    No *aux, *aux1, *aux2;                                  //variaveis auxiliares

    aux2 = lista->primeiro;

    if(!empty_queuelista(lista) && aux2->next != NULL)      //se a lista nao estiver vazia e o aux2 a apontar para o seguinte for diferente de vazio
    {
        char tipo, ordena;                                  //variaveis do tipo char para chamar as funções que retornam char
        system("cls");                                      //limpa a tela do ecrã
        tipo = MenuTipoOrdenacao();                         //chama MenuTipoOrdenacao
        system("cls");                                      //limpa a tela do ecrã
        ordena = MenuListagens();                           //chama MenuListagens

        aux = lista->primeiro;

        do
        {
            if(tipo != '0')                                                                              //se o tipo for diferente de 0
            {
                aux1 = aux;
                do
                {
                    if(tipo == 'S')                                                                     //se o tipo for igual a 'S'
                    {

                        if( ordena == '1' && PorBalcaoMenorMaior(aux->dados, aux1->dados))               //ordena por balcao de menor para maior
                        {
                            exch(aux1, aux);                                                             //troca
                        }

                        else if( ordena == '2' && PorDiffMenorMaior(aux->dados, aux1->dados))           //ordena por diferenca tempo de menor para maior
                        {
                            exch(aux1, aux);                                                            //troca
                        }


                        else if( ordena == '3' && PorDataEntradaMenorMaior(aux->dados, aux1->dados))    //ordena por data entrada de menor para maior
                        {
                            exch(aux1, aux);                                                            //troca

                        }

                        else if(ordena == '4' && PorDataAtendimentoMenorMaior(aux->dados, aux1->dados)) //ordena por data atendimento de menor para maior
                        {
                            exch(aux1, aux);                                                            //troca
                        }

                        else if(ordena == '5' && PorDataSaidaMenorMaior(aux->dados, aux1->dados))       //ordena por data saida de menor para maior
                        {
                            exch(aux1, aux);                                                            //troca
                        }
                        else if(ordena == '6' && PorSenhaMenorMaior(aux->dados, aux1->dados))           //ordena por senha de menor para maior
                        {
                            exch(aux1, aux);                                                            //troca
                        }
                        else if(ordena == '7' && PorStatusMenorMaior(aux->dados, aux1->dados))          //ordena por status de menor para maior
                        {
                            exch(aux1, aux);                                                            //troca
                        }
                        else if(ordena == '8' && PorPrioridadeMenorMaior(aux->dados, aux1->dados))      //ordena por prioridade de menor para maior
                        {
                            exch(aux1, aux);                                                            //troca
                        }
                    if(tipo == 'N')
                    {

                        if( ordena == '1' && PorBalcaoMaiorMenor(aux->dados, aux1->dados))              //ordena por balcao de maior para menor
                        {
                            exch(aux1, aux);                                                            //troca
                        }

                        else if( ordena == '2' && PorDiffMaiorMenor(aux->dados, aux1->dados))           //ordena por diferenca de tempo de maior para menor
                        {
                            exch(aux1, aux);                                                            //troca
                        }


                        else if( ordena == '3' && PorDataEntradaMaiorMenor(aux->dados, aux1->dados))    //ordena por data de entrada de maior para menor
                        {
                            exch(aux1, aux);                                                            //troca

                        }

                        else if(ordena == '4' && PorDataAtendimentoMaiorMenor(aux->dados, aux1->dados)) //ordena por data de atendimento de maior para menor
                        {
                            exch(aux1, aux);                                                            //troca
                        }

                        else if(ordena == '5' && PorDataSaidaMaiorMenor(aux->dados, aux1->dados))       //ordena por data de saida de maior para menor
                        {
                            exch(aux1, aux);                                                            //troca
                        }
                        else if(ordena == '6' && PorSenhaMaiorMenor(aux->dados, aux1->dados))           //ordena por senha de maior para menor
                        {
                            exch(aux1, aux);                                                            //troca
                        }
                        else if(ordena == '7' && PorStatusMaiorMenor(aux->dados, aux1->dados))          //ordena por status de maior para menor
                        {
                            exch(aux1, aux);                                                            //troca
                        }
                        else if(ordena == '8' && PorPrioridadeMaiorMenor(aux->dados, aux1->dados))       //ordena por prioridade de maior para menor
                        {
                            exch(aux1, aux);                                                            //troca
                        }
                    }
                }
                    aux1 = aux1->next;
                }
                while (aux1 != NULL);
                aux = aux->next;
            }
            else
            {
                break;                                        //se o tipo for igual a 0
            }
        }
        while (aux->next != NULL);                           //enquanto aux a apontar para o seguinte for diferente de vazio
    }
}
