//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Utilizador.c                                                 //
//**************************************************************//


#include "Utilizador.h"

/*--------------------------------------------------------------------*/
/* Função que escolhe o tipo de senha a ser retirada pelo utilizador  */
/*--------------------------------------------------------------------*/
void Senha()
{
    char opcao;
    struct tm *Pausa;
    time_t HoraActual;

    time(&HoraActual);                      //regista a HoraActual como a hora do sistema

    Pausa = gmtime(&HoraActual);            //converte time_t para tm como o tempo UTC


    if(Pausa->tm_wday != 0)                                      //se o dia da semana não corresponder a domingo
    {
        if((Pausa->tm_hour+1) >= 13 && (Pausa->tm_hour+1) <= 14) //entre as 13h e as 14h estará fechado para almoço
        {
            system("cls");
            Lines(8);
            Cols(7); MolduraQSE(); MolduraLines(36); MolduraQSD();
            Cols(7); MolduraCols(1); MolduraEspaco(3); printf("Servico fechado para Almoco"); MolduraEspaco(7); MolduraCols(1);Lines(1);
            Cols(7); MolduraQID(); MolduraLines(36); MolduraQIE();
            Cols(8);system("Pause");
        }
        else
        {
    do
    {
        system("cls");                              //limpa a tela do ecrã
        opcao = MenuUtilizador();                   //chama o MenuUtilizador

        switch(opcao)
        {

        case '1':
            system("cls");
            RetirarSenha(Normal);                   //retira senha do tipo Normal
            break;

        case '2':
            system("cls");
            RetirarSenha(1);                        //retira senha do tipo prioritaria
            break;

        case '0':                                   //volta para o menu anterior
            break;

        }
    }
    while(opcao !='0');
        }
    }
    else
    {
        system("cls");
        Lines(8);
        Cols(7); MolduraQSE(); MolduraLines(36); MolduraQSD();
        Cols(7); MolduraCols(1); MolduraEspaco(3); printf("Servico fechado por ser Domingo"); MolduraEspaco(3); MolduraCols(1);Lines(1);
        Cols(7); MolduraQID(); MolduraLines(36); MolduraQIE();
        Cols(8);system("Pause");

    }
}

/*-----------------------------------------------*/
/* Função que retira senhas pelo utilizador      */
/* Parametros: recebe um priority do tipo bool   */
/*-----------------------------------------------*/
void RetirarSenha(bool priority)
{
    char op;

    op = MenuSenha();                                               //chama o MenuSenha

    if( op==BalcaoA )                                               //se a op for para o BalcaoA
    {
        system("cls");
        if(priority==Normal)                                        //se priority for Normal
        {
            ADD_FIFO(FIFOA, BalcaoA);                               //adiciona na fifo A no balcao A
            InformacaoUtilizador(FIFOA, lst, BalcaoA,TodosP);       //informa a fifo A, lista, o balcao A, para TodosP
        }
        else
        {
            ADDFIFO1(FIFOA, BalcaoA);                               //adiciona na fifo A no balcao A
            InformacaoUtilizador(FIFOA, lst, BalcaoA, Prioritaria); //informa a fifo A, lista, o balcao A, para Prioritaria
        }
       Cols(8);
       system("pause");
    }

    else if( op==BalcaoB )                                              //se a op for para o BalcaoB
    {
        system("cls");
        if(priority==0)                                                 //se a priority for 0
        {
            ADD_FIFO(FIFOB, BalcaoB);                                   //adiciona na fifo B no balcao B
            InformacaoUtilizador(FIFOB, lst, BalcaoB,TodosP);           //informa a fifo B, lista, o balcao B, para TodosP
        }

        else
        {
            ADDFIFO1(FIFOB, BalcaoB);                                   //adiciona na fifo B no balcao B
            InformacaoUtilizador(FIFOB, lst, BalcaoB, Prioritaria);     //informa a fifo B, lista, o balcao B, para Prioritaria
        }

       Cols(8); system("pause");
    }

    else if( op==BalcaoC )                                               //se a op for para o BalcaoC
    {
        system("cls");
        if(priority==0)                                                  //se a priority for 0
        {
            ADD_FIFO(FIFOC, BalcaoC);                                    //adiciona na fifo C no balcao C
            InformacaoUtilizador(FIFOC, lst, BalcaoC,TodosP);            //informa a fifo C, lista, o balcao C, para TodosP
        }

        else
        {
            ADDFIFO1(FIFOC, BalcaoC);                                   //adiciona na fifo C no balcao C
            InformacaoUtilizador(FIFOC, lst, BalcaoC, Prioritaria);     //informa a fifo C, lista, o balcao C, para Prioritaria
        }

       Cols(8); system("pause");
    }

    else if( op==BalcaoD )                                              //se a op for para o BalcaoD
    {
        system("cls");
        if(priority==0)                                                 //ss a priority for 0
        {
            ADD_FIFO(FIFOD, BalcaoD);                                   //adiciona na fifo D no balcao D
            InformacaoUtilizador(FIFOD, lst, BalcaoD,TodosP);           //informa a fifo D, lista, o balcao D, para TodosP
        }

        else
        {
            ADDFIFO1(FIFOD, BalcaoD);                                   //adiciona na fifo D no balcao D
            InformacaoUtilizador(FIFOD, lst, BalcaoD, Prioritaria);     //informa a fifo D, lista, o balcao D, para Prioritaria
        }

       Cols(8);
       system("pause");
    }
}
