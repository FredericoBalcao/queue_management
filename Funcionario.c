//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Funcionario.c                                                //
//**************************************************************//

#include "Funcionario.h"

/*-----------------------------------------------*/
/* Balcao                                        */
/*-----------------------------------------------*/
void Balcao()
{
    char opcao;                                                 //opcao do tipo char usada na função do MenuBalcao
    struct tm *Pausa;                                           //estrutura tm com a criação de um ponteiro Pausa
    time_t HoraActual;                                          //variavel HoraActual do tipo time_t

    time(&HoraActual);                                          //regista a HoraActual do sistema

    Pausa=gmtime(&HoraActual);                                  //Pausa é igual à comversão time_t para estrutura pelo função gmtime da HoraActual

    if(Pausa->tm_wday != 0)                                     //se o dia da semana não corresponder a domingo
    {
        if((Pausa->tm_hour+1) >= 13 && (Pausa->tm_hour+1) <= 14)//entre as 13h e as 14h estará fechado para almoço
        {
            printBalcaoPausa(Almoco);                           //printa o alerta do almoco
        }
        else
        {
            do
            {
                opcao = MenuBalcao();                           //opcao para MenuBalcao

                switch(opcao)
                {
                case BalcaoA:
                    AtenderSenha(FIFOA, BalcaoA);               //atende a senha do balcao A
                    break;
                case BalcaoB:
                    AtenderSenha(FIFOB, BalcaoB);               //atende a senha do balcao B
                    break;
                case BalcaoC:
                    AtenderSenha(FIFOC, BalcaoC);               //atende a senha do balcao C
                    break;
                case BalcaoD:
                    AtenderSenha(FIFOD, BalcaoD);               //atende a senha do balcao D
                    break;
                case '0':                                       //caso for 0, volta para o menu anterior
                    break;
                }
            }
            while(opcao != '0');                                //enquanto a opcao for diferente de 0
        }
    }
    else                                                        //se o dia da semana corresponder a domingo
    {
        printBalcaoPausa(Domingo);                              //printa o alerta do domingo
    }
}

/*-----------------------------------------------*/
/* Atender Senha                                 */
/*-----------------------------------------------*/
void AtenderSenha(FIFO *fifo, char balcao)                      //função para atender senhas que recebe uma fifo e um balcao
{
    // int count=0;
    char opcao3;                                                //opcao3 para o MenuBalcaoOpcao
    do
    {
        if(!empty_queue(fifo))                                  //se a fifo não estiver vazia
        {
            No *aux;                                            //criação de um ponteiro aux do tipo No

            aux = fifo->primeiro;                               //aux aponta para o primeiro nó da fifo

            printAtenderSenha(balcao, INICIAL);                 //printa o atender senha do balcao selecionado com status INICIAL (a 0)

            Print_Item(TipoFifo, aux->dados);                   //printa os dados da fifo

            printAtenderSenha(balcao, FINAL);                   //printa o atender senha do balcao selecionado com status FINAL (a 1)

            opcao3 = MenuBalcaoOpcao();                         //chama o MenuBalcaoOpcao

            switch(opcao3)
            {
            case '1':
                Atendimento(fifo, balcao);                      //Atender a senha que recebe uma fifo e um balcao
                break;
            case '2':
                aux->dados->status = Desistente;                //senha considerada como status desistente
                TransFIFOPraLista(fifo, lst);                   //senha transferida automaticamente da fifo para a lista lst
                break;
            case '3':
                InformacaoBalcao(fifo, lst, balcao);            //printa a Informação correspondente a fifo, a lista e ao balcao selecionado
                system("pause");                                //pausa
                break;
            case '0':
                break;                                          //volta para o menu anterior
            }
        }
        else                                                    //se a fifo estiver vazia
        {
            opcao3 = MenuAuxiliar(balcao);                      //chama o MenuAuxiliar do balcao selecionado

            switch(opcao3)
            {
            case '1':
                InformacaoBalcao(fifo, lst, balcao);            //printa a Informação correspondente a fifo, a lista e ao balcao selecionado
                system("pause");                                //pausa
                break;
            case '0':
                break;                                          //volta para o menu anterior
            }
        }
    }
    while(opcao3 != '0');                                       //enquanto a opcao3 for diferente de 0
}

/*-----------------------------------------------*/
/* Transfere FIFO para a Lista                   */
/*-----------------------------------------------*/
void TransFIFOPraLista(FIFO *fifo, Lista *lista)               //função para transferir fifo para lista, recebe uma fifo e uma lista
{
    No *p;                                                     //ponteiro p do tipo No

    if (empty_queue(fifo))                                     //se a fifo estiver vazia
    {
        return;                                                //retorna no programa
    }

    p = fifo->primeiro;                                        //p aponta para o primeiro nó da fifo
    adicionarF(lista, p->dados);                               //adiciona na lista que recebe uma lista e um ponteiro para os dados

    read_fifo(fifo);                                           //recebe uma fifo que será apagada
}

/*-----------------------------------------------*/
/* Atendimento                                   */
/*-----------------------------------------------*/
void Atendimento(FIFO *fifo, char balcao)                       //função atendimento do balcao que recebe uma fifo e uma balcao
{
    No *aux;                                                    //ponteiro aux do tipo No
    aux = fifo->primeiro;                                       //aux aponta para o primeiro nó da fifo
    char opcao1=NULL;                                           //opcao1 do tipo char inicializada a NULL
    aux->dados->status = Normal;                                //status a Normal
    time(&aux->dados->HoraAtendimento);                         //regista a HoraAtendimento com a hora do sistema
    system("cls");                                              //limpa a tela do ecrã
    opcao1=MenuBalcaoSenha();                                   //chama a função MenuBalcaoSenha
    switch(opcao1)
    {
    case '1':                                                   //se for Concluir Atendimento
        time(&aux->dados->HoraSaida);                           //regista a HoraSaida com a hora do sistema
        AlertaTempo(lst,aux,balcao,Maximo);                     //chama um AlertaTempo que recebe uma lista, um nó, um balcao e um tipo de alerta (neste caso Maximo)
        AlertaTempo(lst,aux,balcao,Minimo);                     //chama um AlertaTempo que recebe uma lista, um nó, um balcao e um tipo de alerta (neste caso Minimo)
        TransFIFOPraLista(fifo, lst);                           //transfere da fifo para a lista
        system("Pause");                                        //pausa
        break;
    case '2':                                                   //se for para transferir a senha para outro balcao
        TransferirSenhas(balcao);                               //chama a função TransferirSenhas que recebe um determinado balcao
        break;
    }
}

/*------------------------------------------------*/
/* Transferir as Senhas                           */
/*------------------------------------------------*/
void TransferirSenhas(char BalcaoOrigem)                        //função transfere senhas para outro balcao que recebe um balcao de origem
{
    char BalcaoDestino;                                         //variavel BalcaoDestino do tipo char
    system("cls");                                              //limpa a tela do ecrã

    if(BalcaoOrigem == BalcaoA)                                 //se o balcao de origem for igual ao balcao A
    {
        BalcaoDestino = MenuATransf();                          //balcao destino chama o menu para transferencia do balcao A
    }

    else if(BalcaoOrigem == BalcaoB)                            //se o balcao de origem for igual ao balcao B
    {
        BalcaoDestino = MenuBTransf();                          //balcao destino chama o menu para transferencia do balcao B
    }

    else if(BalcaoOrigem ==BalcaoC)                             //se o balcao de origem for igual ao balcao C
    {
        BalcaoDestino =MenuCTransf();                           //balcao destino chama o menu para transferencia do balcao C
    }

    else if(BalcaoOrigem == BalcaoD)                            //se o balcao de origem for igual ao balcao D
    {
        BalcaoDestino = MenuDTransf();                          //balcao destino chama o menu para transferencia do balcao D
    }

    if(BalcaoDestino == BalcaoA )                               //se o balcao destino for igual ao balcao A
    {
        if (BalcaoOrigem == BalcaoB)                            //se o balcao de origem for igual ao balcao B
        {
            Transferir(FIFOB, FIFOA, BalcaoA);                  //transfere da fifo B para a A pelo Balcao A
        }

        else if(BalcaoOrigem == BalcaoC)                        //se o balcao de origem for igual ao balcao C
        {
            Transferir(FIFOC, FIFOA, BalcaoA);                  //transfere da fifo C para a A pelo Balcao A
        }

        else if(BalcaoOrigem == BalcaoD)                        //se o balcao de origem for igual ao balcao D
        {
            Transferir(FIFOD, FIFOA, BalcaoA);                  //transfere da fifo D para a A pelo Balcao A
        }
    }

    else if(BalcaoDestino == BalcaoB )                         //se o balcao destino for igual ao balcao B
    {
        if (BalcaoOrigem == BalcaoA)                           //se o balcao de origem for igual ao balcao A
        {
            Transferir(FIFOA, FIFOB, BalcaoB);                 //transfere da fifo A para a B pelo Balcao B
        }

        else if(BalcaoOrigem == BalcaoC)                       //se o balcao de origem for igual ao balcao C
        {
            Transferir(FIFOC, FIFOB, BalcaoB);                 //transfere da fifo C para a B pelo Balcao B
        }

        else if(BalcaoOrigem == BalcaoD)                       //se o balcao de origem for igual ao balcao D
        {
            Transferir(FIFOD, FIFOB, BalcaoB);                 //transfere da fifo D para a B pelo Balcao B
        }
    }

    else if(BalcaoDestino == BalcaoC)                          //se o balcao destino for igual ao balcao C
    {
        if (BalcaoOrigem == BalcaoA)                           //se o balcao de origem for igual ao balcao A
        {
            Transferir(FIFOA, FIFOC, BalcaoC);                 //transfere da fifo A para a C pelo Balcao C
        }

        else if(BalcaoOrigem == BalcaoB)                       //se o balcao de origem for igual ao balcao B
        {
            Transferir(FIFOB, FIFOC, BalcaoC);                 //transfere da fifo B para a C pelo Balcao C
        }

        else if(BalcaoOrigem == BalcaoD)                       //se o balcao de origem for igual ao balcao D
        {
            Transferir(FIFOD, FIFOC, BalcaoC);                 //transfere da fifo D para a C pelo Balcao C
        }
    }

    else if(BalcaoDestino == BalcaoD )                         //se o balcao de destino for igual ao balcao D
    {
        if (BalcaoOrigem == BalcaoA)                           //se o balcao de origem for igual ao balcao A
        {
            Transferir(FIFOA, FIFOD, BalcaoD);                 //transfere da fifo A para a D pelo Balcao D
        }

        else if(BalcaoOrigem == BalcaoB)                       //se o balcao de origem for igual ao balcao B
        {
            Transferir(FIFOB, FIFOD, BalcaoD);                 //transfere da fifo B para a D pelo Balcao D
        }

        else if(BalcaoOrigem == BalcaoC)                       //se o balcao de origem for igual ao balcao C
        {
            Transferir(FIFOC, FIFOD, BalcaoD);                 //transfere da fifo C para a D pelo Balcao D
        }
    }
}
