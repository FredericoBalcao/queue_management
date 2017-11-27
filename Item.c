//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Item.c                                                       //
//**************************************************************//

#include"Item.h"

/*-----------------------------------------------*/
/* Informações das senhas na FIFO                */
/*-----------------------------------------------*/
void Print_Item(bool tipo, Item *item)
{
    if(tipo==TipoFifo)
    {
        struct tm *aux1;
        int a=0, i, espaco=9, espaco2=23;

        espaco2= CalculaEspaco(item->Id, espaco2);

        aux1 = gmtime(&item->HoraEntrada);
        Cols(7);
        MolduraCols(1);
        printf(" Numero de Senha: %i", item->Id);
        MolduraEspaco(espaco2);
        MolduraCols(1);
        Lines(1);
        Cols(7);
        MolduraCols(1);
        printf(" Balcao da Senha: %c", item->Balcao);
        MolduraEspaco(22);
        MolduraCols(1);
        Lines(1);
        Cols(7);
        MolduraCols(1);
        printf(" Data de Entrada: %i/%i/%i ",(aux1->tm_year+1900),(aux1->tm_mon+1),aux1->tm_mday);
        if(aux1->tm_hour!=23)
        {
            printf("%i:%i:%i",aux1->tm_hour+1, aux1->tm_min, aux1->tm_sec);
        }
        else
        {
            printf("%i:%i:%i ",a, aux1->tm_min, aux1->tm_sec);
        }

        espaco= CalculaEspacoHoras(aux1,espaco);

        if((aux1->tm_mon+1)>=10)
        {
            espaco--;
        }
        if(aux1->tm_mday>=10)
        {
            espaco--;
        }
        MolduraEspaco(espaco);
        MolduraCols(1);
        Lines(1);
        if(item->prioridade == 1)
        {
            Cols(7);
            MolduraCols(1);
            printf(" Senha Prioritaria");
            MolduraEspaco(23);
            MolduraCols(1);
            Lines(1);
        }

        else
        {
            Cols(7);
            MolduraCols(1);
            printf(" Senha nao Prioritaria");
            MolduraEspaco(19);
            MolduraCols(1);
            Lines(1);
        }

    }
    else if(tipo==TipoLista)
    {
        struct tm *aux1, *aux2, *aux3;
        int a=0, i, espaco=9, espaco2=23;

        aux1 = gmtime(&item->HoraEntrada);

        espaco2= CalculaEspaco(item->Id, espaco2);

        Cols(7);
        MolduraCols(1);
        printf(" Numero de Senha: %i", item->Id);
        MolduraEspaco(espaco2);
        MolduraCols(1);
        Lines(1);
        Cols(7);
        MolduraCols(1);
        printf(" Balcao da Senha: %c", item->Balcao);
        MolduraEspaco(22);
        MolduraCols(1);
        Lines(1);
        Cols(7);
        MolduraCols(1);
        printf(" Data de Entrada: %i/%i/%i ",(aux1->tm_year+1900),(aux1->tm_mon+1),aux1->tm_mday);
        if(aux1->tm_hour!=23)
        {
            printf("%i:%i:%i",aux1->tm_hour+1, aux1->tm_min, aux1->tm_sec);
        }
        else
        {
            printf("%i:%i:%i ",a,aux1->tm_min, aux1->tm_sec);
        }

        espaco= CalculaEspacoHoras(aux1,espaco);

        if((aux1->tm_mon+1)>=10)
        {
            espaco--;
        }
        if(aux1->tm_mday>=10)
        {
            espaco--;
        }
        aux2 = gmtime(&item->HoraAtendimento);
        MolduraEspaco(espaco);
        MolduraCols(1);
        Lines(1);
        if(item->status == 0)
        {
            Cols(7);
            MolduraCols(1);
            printf(" Data de Atendimento: %i/%i/%i ",(aux2->tm_year+1900),(aux2->tm_mon+1),aux2->tm_mday);
            if(aux2->tm_hour!=23)
            {
                printf("%i:%i:%i",aux2->tm_hour+1, aux2->tm_min, aux2->tm_sec);
            }
            else
            {
                printf("%i:%i:%i ",a, aux2->tm_min, aux2->tm_sec);
            }
            espaco=5;

            espaco= CalculaEspacoHoras(aux1,espaco);

            if((aux2->tm_mon+1)>=10)
            {
                espaco--;
            }
            if(aux2->tm_mday>=10)
            {
                espaco--;
            }
            aux3 = gmtime(&item->HoraSaida);

            MolduraEspaco(espaco);
            MolduraCols(1);
            Lines(1);
            Cols(7);
            MolduraCols(1);
            printf(" Data de Saida: %i/%i/%i ",(aux3->tm_year+1900),(aux3->tm_mon+1),aux3->tm_mday);
            if(aux3->tm_hour!=23)
            {
                printf("%i:%i:%i",aux3->tm_hour+1, aux3->tm_min, aux3->tm_sec);
            }
            else
            {
                printf("%i:%i:%i ",a, aux3->tm_min, aux3->tm_sec);
            }
            espaco=11;

            espaco= CalculaEspacoHoras(aux1,espaco);

            if((aux3->tm_mon+1)>=10)
            {
                espaco--;
            }
            if(aux3->tm_mday>=10)
            {
                espaco--;
            }
            MolduraEspaco(espaco);
            MolduraCols(1);
            Lines(1);
        }

        if(item->status == Desistente)
        {
            Cols(7);
            MolduraCols(1);
            printf(" A senha desistiu");
            MolduraEspaco(24);
            MolduraCols(1);
            Lines(1);
        }
        else
        {
            if(item->prioridade == Prioritaria )
            {
                Cols(7);
                MolduraCols(1);
                printf(" A senha e prioritaria");
                MolduraEspaco(19);
                MolduraCols(1);
                Lines(1);
            }
            if(item->prioridade == Normal )
            {
                Cols(7);
                MolduraCols(1);
                printf(" A senha e normal");
                MolduraEspaco(24);
                MolduraCols(1);
                Lines(1);
            }
        }
    }
}
/*-----------------------------------------------*/
/* Insere senha, balcao, hora Entrada           */
/*-----------------------------------------------*/
Item *InsereItem(char balcao, int id)
{
    Item *item = (Item *)malloc(sizeof(Item));

    item->Balcao = balcao;
    item->Id = id;
    item->status = Normal;
    time(&item->HoraEntrada);


    return item;
}

/*Ordenações*/

/*-----------------------------------------------*/
/* Diferença tempo menor para maior              */
/*-----------------------------------------------*/

int PorDiffMenorMaior(Item *A, Item *B)
{
    int diff_A, diff_B;

    diff_A = A->HoraSaida - A->HoraEntrada;
    diff_B = B->HoraSaida - B->HoraEntrada;

    return diff_A > diff_B;
}

/*-----------------------------------------------*/
/* Por balcao do menor para maior                */
/*-----------------------------------------------*/

int PorBalcaoMenorMaior (Item *A, Item *B)
{
    int balc_A, balc_B;

    balc_A = A->Balcao;
    balc_B = B->Balcao;

    return balc_A > balc_B;
}


/*-----------------------------------------------*/
/* Por data de entrada do menor para maior       */
/*-----------------------------------------------*/
int PorDataEntradaMenorMaior (Item *A, Item *B)
{
    return A->HoraEntrada > B->HoraEntrada;
}

/*-----------------------------------------------*/
/* Por data de atendimento do menor para maior   */
/*-----------------------------------------------*/
int PorDataAtendimentoMenorMaior (Item *A, Item *B)
{
    return A->HoraAtendimento > B->HoraAtendimento;
}

/*-----------------------------------------------*/
/* Por data de saida do menor para maior         */
/*-----------------------------------------------*/
int PorDataSaidaMenorMaior (Item *A, Item *B)
{
    return A->HoraSaida > B->HoraSaida;
}

/*-----------------------------------------------*/
/* Por senha Menor para Maior                    */
/*-----------------------------------------------*/
int PorSenhaMenorMaior (Item *A, Item *B)
{

    return A->Id > B->Id;
}

/*-----------------------------------------------*/
/* Por diferenca maior para menor                */
/*-----------------------------------------------*/

int PorDiffMaiorMenor (Item *A, Item *B)
{
    int diff_A, diff_B;

    diff_A = A->HoraSaida - A->HoraEntrada;
    diff_B = B->HoraSaida - B->HoraEntrada;

    return diff_A < diff_B;
}

/*-----------------------------------------------*/
/* Por balcao do maior para menor                */
/*-----------------------------------------------*/
int PorBalcaoMaiorMenor (Item *A, Item *B)
{
    int balc_A, balc_B;

    balc_A = A->Balcao;
    balc_B = B->Balcao;

    return balc_A < balc_B;
}

/*-----------------------------------------------*/
/* Por data de entrada Maior para o menor        */
/*-----------------------------------------------*/
int PorDataEntradaMaiorMenor (Item *A, Item *B)
{
    return A->HoraEntrada < B->HoraEntrada;
}

/*-----------------------------------------------*/
/* Por data atendimento maior para o menor       */
/*-----------------------------------------------*/
int PorDataAtendimentoMaiorMenor (Item *A, Item *B)
{
    return A->HoraAtendimento < B->HoraAtendimento;
}

/*-----------------------------------------------*/
/* Por data de saida do maior para menor         */
/*-----------------------------------------------*/
int PorDataSaidaMaiorMenor (Item *A, Item *B)
{
    return A->HoraSaida < B->HoraSaida;
}

/*-----------------------------------------------*/
/* Por senha do maior para menor                 */
/*-----------------------------------------------*/
int PorSenhaMaiorMenor (Item *A, Item *B)
{

    return A->Id < B->Id;
}

/*-----------------------------------------------*/
/* Por status do maior para menor                */
/*-----------------------------------------------*/
int PorStatusMaiorMenor (Item *A, Item *B)
{
    return A->status < B->status;
}

/*-----------------------------------------------*/
/* Por prioridade do maior para menor            */
/*-----------------------------------------------*/
int PorPrioridadeMaiorMenor (Item *A, Item *B)
{
    return A->prioridade < B->prioridade;
}

/*-----------------------------------------------*/
/* Por status do menor para maior                */
/*-----------------------------------------------*/
int PorStatusMenorMaior (Item *A, Item *B)
{
    return A->status > B->status;
}

/*-----------------------------------------------*/
/* Por prioridade do menor para maior            */
/*-----------------------------------------------*/
int PorPrioridadeMenorMaior (Item *A, Item *B)
{
    return A->prioridade > B->prioridade;
}
