//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Gestor.c                                                     //
//**************************************************************//

#include "Gestor.h"

/*-----------------------------------------------*/
/* Outras Opções                                 */
/*-----------------------------------------------*/
void OutrasOpcoes()
{
    char opcao;
    do
    {
        if(!empty_queuelista(lst))                              //se a lista não for vazia
        {
            opcao = MenuMais1();                                //chama a função do MenuMais1 porque retorna um char

            switch(opcao)
            {
            case '1':
                Estatistica();                                  //chama a função estatistica
                break;
            case '2':
                Ordenacao(lst);                                 //chama a função ordenação que recebe a lista
                printListagemSenhasAtendidas();                 //chama a função que printa a listagem das senhas atendidas
                listar(lst);                                    //lista a lista das senhas já ordenadas
                system("Pause");                                //pausa
                break;
            case '3':
                printListagemSenhasPorAtender(BalcaoA);         //chama a função que printa a listagem das senhas por atender do balcao A
                lista_fifo(FIFOA);                              //lista a fifo do balcao A
                Cols(8);
                system("pause");
                printListagemSenhasPorAtender(BalcaoB);         //chama a função que printa a listagem das senhas por atender do balcao B
                lista_fifo(FIFOB);                              //lista a fifo do balcao B
                Cols(8);
                system("pause");
                printListagemSenhasPorAtender(BalcaoC);         //chama a função que printa a listagem das senhas por atender do balcao C
                lista_fifo(FIFOC);                              //lista a fifo do balcao C
                Cols(8);
                system("pause");
                printListagemSenhasPorAtender(BalcaoD);         //chama a função que printa a listagem das senhas por atender do balcao D
                lista_fifo(FIFOD);                              //lista a fifo do balcao D
                Cols(8);
                system("pause");
                break;

            case '4':
                system("cls");                                  //limpa a tela do ecrã
                gravar_ficheiro(lst);                           //chama a função gravar_ficheiros que recebe uma lista
                system("pause");
                break;
            case '0':
                break;                                          //caso for 0 faz voltar para o menu anterior
            }
        }

        else                                                    //se a lista for vazia
        {
            char o;

            o= MenuRandom();                                    //chama a função MenuRandom porque retorna um char

            if(o=='S')                                          //caso for SIM, para um 'S'
            {
                int numero;                                     //variavel numero para guardar o numero de senhas
                Cols(7);
                printf("Quantas senhas? ");                     //printa quantas senhas o utilizador pretende
                fflush(stdin);                                  //limpa o buffer
                if(scanf("%d",&numero) !=1)                     //se o numero for diferente de 1 dá erro, verifica inteiros
                {
                    printf("ERRO!!\n");                         //printa ERRO!!
                    system("Pause");                            //limpa a tela
                    break;
                }
                else                                            //senão
                {
                    Random(lst, numero);                        //chama a função Random para gerar uma lista com o numero definido de senhas pelo utilizador
                    OutrasOpcoes();                             //chama a função de OutrasOpcoes
                }

            }
            else if(o=='0')                                     //se for 0 volta para o menu anterior
            {
                break;
            }
            else
            {
                char p;
                p= MenuMais1();                                 //chama a função MenuMais1 que retorna um char

                switch(p)
                {
                case'1':
                    printListagemSenhasPorAtender(BalcaoA);     //chama a função que printa a listagem das senhas por atender do balcao A
                    lista_fifo(FIFOA);                          //lista a fifo A
                    Cols(8);
                    system("pause");
                    printListagemSenhasPorAtender(BalcaoB);     //chama a função que printa a listagem das senhas por atender do balcao B
                    lista_fifo(FIFOB);                          //lista a fifo B
                    Cols(8);
                    system("pause");
                    printListagemSenhasPorAtender(BalcaoC);     //chama a função que printa a listagem das senhas por atender do balcao C
                    lista_fifo(FIFOC);                          //lista a fifo C
                    Cols(8);
                    system("pause");
                    printListagemSenhasPorAtender(BalcaoD);     //chama a função que printa a listagem das senhas por atender do balcao A
                    lista_fifo(FIFOD);                          //lista a fifo D
                    Cols(8);
                    system("pause");                            //pausa
                    break;
                case '0':                                       //caso for 0 volta para o menu anterior
                    break;
                }
            }
        }
    }
    while(opcao != '0');                                        //enquanto a opcao do utilizador for diferente de 0
}

/*-----------------------------------------------*/
/* Programa                                      */
/*-----------------------------------------------*/
void Programa()
{
    char asd;
    do
    {

        asd = MenuP();                                          //chama a função MenuP que retorna um char
        switch(asd)
        {
        case '1':
            Senha();                                            //chama a função Senha para o utilizador
            break;

        case '2':
            Balcao();                                           //chama a função Balcao
            break;

        case '3':
            OutrasOpcoes();                                     //chama a função para OutrasOpcoes
            break;

        case '0':                                               //caso for 0 sai do programa
            break;
        }
    }
    while(asd != '0');                                          //enquanto for diferente de 0
}
