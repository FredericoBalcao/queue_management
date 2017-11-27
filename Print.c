//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Print.c                                                  //
//**************************************************************//

#include "Print.h"

/*
Color Codes:
0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
A = Light Green
B = Light Aqua
C = Light Red
D = Light Purple
E = Light Yellow
F = Bright White
*/


/*-----------------------------------------------*/
/* Função Cria nova linha                        */
/* Parametros: int e tamanho                     */
/* Representa a quantidade de linhas que recebe  */
/*-----------------------------------------------*/
void Lines(int tamanho)
{
    int i;
    for(i=1; i<= tamanho; i++)
    {
        printf("\n");
    }
}

/*-----------------------------------------------*/
/* Função Cria nova coluna                       */
/* Parametros: int e tamanho                     */
/* Representa a quantidade de colunas que recebe */
/*-----------------------------------------------*/
void Cols(int tamanho)
{
    int i=0;
    for(i=0; i<= tamanho; i++)
    {
        printf("    ");
    }
}

/*-----------------------------------------------*/
/* Função representa um espaço                   */
/* Parametros: int e tamanho                     */
/* Representa a quantidade de espaços que recebe */
/*-----------------------------------------------*/
void MolduraEspaco(int tamanho)
{
    int i;
    for(i=1; i<= tamanho; i++)
    {
        printf(" ");
    }
}

/*-----------------------------------------------*/
/* Função representa uma linha                   */
/* Parametros: int e tamanho                     */
/* Representa a quantidade de linhas que recebe  */
/*-----------------------------------------------*/
void MolduraLines(int tamanho)
{
    int i=0;
    for(i=0; i<= tamanho; i++)
    {
        printf("%c",205);
    }
}

/*-----------------------------------------------*/
/* Função representa canto superior esquerdo     */
/*-----------------------------------------------*/
void MolduraQSD()
{
    printf("%c\n",187);
}
/*-----------------------------------------------*/
/* Função representa canto inferior esquerdo     */
/*-----------------------------------------------*/
void MolduraQIE()
{
    printf("%c\n",188);
}
/*-----------------------------------------------*/
/* Função representa canto superior direito      */
/*-----------------------------------------------*/
void MolduraQSE()
{
    printf("%c",201);
}
/*-----------------------------------------------*/
/* Função representa canto inferior direito      */
/*-----------------------------------------------*/
void MolduraQID()
{
    printf("%c",200);
}
/*-----------------------------------------------*/
/* Função representa entroncamento esquerdo      */
/*-----------------------------------------------*/
void MolduraQEE()
{
    printf("%c\n",185);
}
/*-----------------------------------------------*/
/* Função representa entroncamento direito       */
/*-----------------------------------------------*/
void MolduraQED()
{
    printf("%c",204);
}

/*-----------------------------------------------*/
/* Função representa uma coluna                  */
/* Parametros: int e tamanho                     */
/* Representa a quantidade de colunas que recebe */
/*-----------------------------------------------*/
void MolduraCols(int tamanho)
{
    int i;
    for(i=1; i<= tamanho; i++)
    {
        printf("%c",186);
    }
}

/*-----------------------------------------------*/
/* Função mostra os prints do Menu principal     */
/* Parametros: opcao pelo char                   */
/*-----------------------------------------------*/
void printMenuP(char *opcao)
{
    system("cls");
    Lines(8);                                       //recebe 8 linhas
    Cols(7);                                        //recebe 7 colunas
    MolduraQSE();                                   //chama canto superior esquerdo
    MolduraLines(20);                               //recebe 20 como linhas para moldura
    MolduraQSD();                                   //chama canto superior direito
    Cols(7);                                        //recebe 7 colunas
    MolduraCols(1);                                 //recebe 1 como colunas para moldura
    printf("\t MENU \t");                           //printa o Menu com tabulação \t
    MolduraEspaco(6);                               //recebe 6 como espacos para moldura
    MolduraCols(1);                                 //recebe 1 como colunas para moldura
    Lines(1);                                       //recebe 1 linha
    Cols(7);                                        //recebe 7 colunas
    MolduraQED();                                   //recebe entroncamento direito
    MolduraLines(20);                               //recebe 20 como linhas para moldura
    MolduraQEE();                                   //recebe entroncamento esquerdo
    Cols(7);                                        //recebe 7 colunas
    MolduraCols(1);                                 //recebe 1 como colunas para moldura
    printf(" [%c] Utilizador",opcao[0]);            //printa opcao[0] para Utilizador
    MolduraEspaco(6);                               //recebe 6 como espacos para moldura
    MolduraCols(1);                                 //recebe 1 como colunas para moldura
    Lines(1);                                       //recebe 1 linha
    Cols(7);                                        //recebe 7 colunas
    MolduraCols(1);                                 //recebe 1 como colunas para moldura
    printf(" [%c] Balcao",opcao[1]);                //printa opcao[1] para Balcao
    MolduraEspaco(10);                              //recebe 10 como espacos para moldura
    MolduraCols(1);                                 //recebe 1 como colunas para moldura
    Lines(1);                                       //recebe 1 linha
    Cols(7);                                        //recebe 7 colunas
    MolduraCols(1);                                 //recebe 1 como colunas para moldura
    printf(" [%c] Outras opcoes",opcao[2]);         //printa opcao[2] para OutrasOpcoes
    MolduraEspaco(3);                               //recebe 3 como espacos para moldura
    MolduraCols(1);                                 //recebe 1 como colunas para moldura
    Lines(1);                                       //recebe 1 linha
    Cols(7);                                        //recebe 7 colunas
    MolduraCols(1);                                 //recebe 1 como colunas para moldura
    printf(" [%c] Sair",opcao[3]);                  //printa opcao[3] para Sair
    MolduraEspaco(12);                              //recebe 12 como espacos para moldura
    MolduraCols(1);                                 //recebe 1 como colunas para moldura
    Lines(1);                                       //recebe 1 linha
    Cols(7);                                        //recebe 7 colunas
    MolduraQID();                                   //chama canto inferior direito
    MolduraLines(20);                               //recebe 20 como linhas para moldura
    MolduraQIE();                                   //chama canto inferior esquerdo

}

/*-----------------------------------------------*/
/* Função mostra os prints do Menu utilizador    */
/* Parametros: opcao pelo char                   */
/*-----------------------------------------------*/
void printMenuUtilizador(char *opcao)
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(30);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    printf("\t Utilizador \t");
    MolduraEspaco(8);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(30);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Retirar senha",opcao[0]);
    MolduraEspaco(13);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Retirar senha prioritaria",opcao[1]);
    MolduraEspaco(1);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Voltar",opcao[2]);
    MolduraEspaco(20);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(30);
    MolduraQIE();
}

/*-----------------------------------------------*/
/* Função mostra os prints do Menu senha         */
/* Parametros: opcao pelo char                   */
/*-----------------------------------------------*/
void printMenuSenha(char *opcao)
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(20);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    printf("\t Senhas\t");
    MolduraEspaco(6);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(20);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao A",opcao[0]);
    MolduraEspaco(8);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao B",opcao[1]);
    MolduraEspaco(8);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao C",opcao[2]);
    MolduraEspaco(8);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao D",opcao[3]);
    MolduraEspaco(8);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Voltar",opcao[4]);
    MolduraEspaco(10);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(20);
    MolduraQIE();
}


/*-----------------------------------------------*/
/* Função mostra os prints do Menu balcao        */
/* Parametros: opcao pelo char                   */
/*-----------------------------------------------*/
void printMenuBalcao(char *opcao)
{
    system("cls");
    Lines(8);

    Cols(7);
    MolduraQSE();
    MolduraLines(20);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    printf("\t Balcao\t");
    MolduraEspaco(6);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(20);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao A", opcao[0]);
    MolduraEspaco(8);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao B",opcao[1]);
    MolduraEspaco(8);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao C",opcao[2]);
    MolduraEspaco(8);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao D",opcao[3]);
    MolduraEspaco(8);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Voltar",opcao[4]);
    MolduraEspaco(10);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(20);
    MolduraQIE();
}


/*-----------------------------------------------*/
/* Função mostra os prints do Menu balcao senha  */
/* Parametros: opcao pelo char                   */
/*-----------------------------------------------*/
void printMenuBalcaoSenha(char *opcao)
{
    system("cls");
    Lines(8);

    Cols(7);
    MolduraQSE();
    MolduraLines(40);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Proxima senha", opcao[0]);
    MolduraEspaco(23);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Tranferir senha para outro Balcao",opcao[1]);
    MolduraEspaco(3);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(40);
    MolduraQIE();
}

/*---------------------------------------------------*/
/* Função mostra os prints da transferencia balcao A */
/* Parametros: opcao pelo char                       */
/*---------------------------------------------------*/
void printMenuATransf(char *opcao)
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(21);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    MolduraEspaco(6);
    printf("Transferencia");
    MolduraEspaco(3);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(21);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao B", opcao[0]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao C", opcao[1]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao D", opcao[2]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(21);
    MolduraQIE();
}


/*---------------------------------------------------*/
/* Função mostra os prints da transferencia balcao B */
/* Parametros: opcao pelo char                       */
/*---------------------------------------------------*/
void printMenuBTransf(char *opcao)
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(21);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    MolduraEspaco(6);
    printf("Transferencia");
    MolduraEspaco(3);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(21);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao A", opcao[0]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao C", opcao[1]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao D", opcao[2]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(21);
    MolduraQIE();
}


/*---------------------------------------------------*/
/* Função mostra os prints da transferencia balcao C */
/* Parametros: opcao pelo char                       */
/*---------------------------------------------------*/
void printMenuCTransf(char *opcao)
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(21);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    MolduraEspaco(6);
    printf("Transferencia");
    MolduraEspaco(3);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(21);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao A", opcao[0]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao B", opcao[1]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao D", opcao[2]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(21);
    MolduraQIE();
}

/*---------------------------------------------------*/
/* Função mostra os prints da transferencia balcao D */
/* Parametros: opcao pelo char                       */
/*---------------------------------------------------*/
void printMenuDTransf(char *opcao)
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(21);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    MolduraEspaco(6);
    printf("Transferencia");
    MolduraEspaco(3);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(21);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao A", opcao[0]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao B", opcao[1]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Balcao C", opcao[2]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(21);
    MolduraQIE();

}

/*---------------------------------------------------*/
/* Função mostra os prints do menu mais              */
/* Parametros: opcao pelo char                       */
/*---------------------------------------------------*/
void printMenuMais(char *opcao)
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(36);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    MolduraEspaco(6);
    printf("\tMais Opcoes\t");
    MolduraEspaco(14);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(36);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Estatisticas", opcao[0]);
    MolduraEspaco(20);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Listagem das senhas atendidas", opcao[1]);
    MolduraEspaco(3);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Listagem das senhas por atender", opcao[2]);
    MolduraEspaco(1);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Gravar Ficheiros", opcao[3]);
    MolduraEspaco(1);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Voltar", opcao[5]);
    MolduraEspaco(26);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(36);
    MolduraQIE();
}

/*---------------------------------------------------*/
/* Função mostra os prints do menu estatistica       */
/* Parametros: opcao pelo char                       */
/*---------------------------------------------------*/
void printMenuEstatistica(char *opcao)
{
    system("cls");
    Lines(8);

    Cols(7);
    MolduraQSE();
    MolduraLines(39);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    MolduraEspaco(7);
    printf("Estatisticas");
    MolduraEspaco(21);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(39);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Informacoes de Desistencias", opcao[0]);
    MolduraEspaco(8);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Informacoes de Senhas Normais", opcao[1]);
    MolduraEspaco(6);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Informacoes de Senhas Prioritarias", opcao[2]);
    MolduraEspaco(1);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Entre datas", opcao[3]);
    MolduraEspaco(24);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Voltar", opcao[4]);
    MolduraEspaco(29);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(39);
    MolduraQIE();
}

/*---------------------------------------------------*/
/* Função mostra os prints do menu listagens         */
/* Parametros: opcao pelo char                       */
/*---------------------------------------------------*/
void printMenuListagens(char *opcao)
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(30);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    MolduraEspaco(12);
    printf("Listagem");
    MolduraEspaco(11);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(30);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Por balcao", opcao[0]);
    MolduraEspaco(16);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Por tempo de atendimento", opcao[1]);
    MolduraEspaco(2);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Por data de Entrada", opcao[2]);
    MolduraEspaco(7);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Por data de Atendimento", opcao[3]);
    MolduraEspaco(3);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Por data de Saida", opcao[4]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Por senha", opcao[5]);
    MolduraEspaco(17);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Por status", opcao[6]);
    MolduraEspaco(17);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Por prioridade", opcao[7]);
    MolduraEspaco(17);
    MolduraCols(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Voltar", opcao[8]);
    MolduraEspaco(20);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(30);
    MolduraQIE();
}
/*---------------------------------------------------*/
/* Função mostra os prints do menu auxiliar          */
/* Parametros: opcao pelo char                       */
/*---------------------------------------------------*/
void printMenuAuxiliar(char *opcao, char balcao)
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(20);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    MolduraEspaco(6);
    printf("Balcao %c", balcao);
    MolduraEspaco(7);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(20);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Estatisticas", opcao[0]);
    MolduraEspaco(4);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Voltar", opcao[1]);
    MolduraEspaco(10);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(20);
    MolduraQIE();
}


/*---------------------------------------------------*/
/* Função mostra os prints do menu random            */
/* Parametros: opcao pelo char                       */
/*---------------------------------------------------*/
void printMenuRandom(char *opcao)
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(30);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    MolduraEspaco(6);
    printf("Quer Introduzir senhas?");
    MolduraEspaco(2);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(30);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] SIM", opcao[0]);
    MolduraEspaco(23);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] NAO", opcao[1]);
    MolduraEspaco(23);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Voltar", opcao[2]);
    MolduraEspaco(20);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(30);
    MolduraQIE();
}

/*---------------------------------------------------*/
/* Função mostra os prints do menu mais              */
/* Parametros: opcao pelo char                       */
/*---------------------------------------------------*/
void printMenuMaisListagem(char *opcao)
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(36);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    MolduraEspaco(6);
    printf("\tMais Opcoes\t");
    MolduraEspaco(14);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(36);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Listagem das senhas por atender", opcao[0]);
    MolduraEspaco(1);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Voltar", opcao[1]);
    MolduraEspaco(26);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(36);
    MolduraQIE();
}

/*---------------------------------------------------*/
/* Função mostra os prints do menu tipo ordenacao    */
/* Parametros: opcao pelo char                       */
/*---------------------------------------------------*/
void printMenuTipoOrdenacao(char *opcao)
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(40);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    MolduraEspaco(14);
    printf("Tipo Ordenacao");
    MolduraEspaco(13);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(40);
    MolduraQEE();
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Ordenar do Menor para Maior", opcao[0]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Ordenar do Maior para Menor", opcao[1]);
    MolduraEspaco(9);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraCols(1);
    printf(" [%c] Voltar", opcao[2]);
    MolduraEspaco(30);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(40);
    MolduraQIE();
}

/*para o Gestor.c*/

/*---------------------------------------------------*/
/* Função mostra os prints do balcao pausa           */
/* Parametros: pausa do tipo bool                    */
/*---------------------------------------------------*/
void printBalcaoPausa(bool pausa)
{
    if(pausa == Domingo)
    {
        system("cls");
        Lines(8);
        Cols(7);
        MolduraQSE();
        MolduraLines(36);
        MolduraQSD();
        Cols(7);
        MolduraCols(1);
        MolduraEspaco(3);
        printf("Servico fechado por ser Domingo");
        MolduraEspaco(3);
        MolduraCols(1);
        Lines(1);
        Cols(7);
        MolduraQID();
        MolduraLines(36);
        MolduraQIE();
        Cols(8);
        if(pausa == Almoco)
        {
            system("cls");
            Lines(8);
            Cols(7);
            MolduraQSE();
            MolduraLines(36);
            MolduraQSD();
            Cols(7);
            MolduraCols(1);
            MolduraEspaco(3);
            printf("Servico fechado para Almoco");
            MolduraEspaco(7);
            MolduraCols(1);
            Lines(1);
            Cols(7);
            MolduraQID();
            MolduraLines(36);
            MolduraQIE();
            Cols(8);
        }
        system("pause");
    }
}

/*------------------------------------------------------------*/
/* Função mostra os prints do atender senha                   */
/* Parametros: balcao do tipo char, e um status do tipo bool  */
/*------------------------------------------------------------*/
void printAtenderSenha(char balcao, bool status)
{
    if(status == 0){
        system("cls");
        system("COLOR 4F");
        printf("\a");
        Lines(8);
        Cols(7);
        MolduraQSE();
        MolduraLines(40);
        MolduraQSD();
        Cols(7);
        MolduraCols(1);
        MolduraEspaco(7);
        printf("PROXIMA SENHA PARA O BALCAO %c",balcao);
        MolduraEspaco(5);
        MolduraCols(1);
        Lines(1);
        Cols(7);
        MolduraQED();
        MolduraLines(40);
        MolduraQEE();
    }else{
        Cols(7);
        MolduraQID();
        MolduraLines(40);
        MolduraQIE();
        Cols(8);
        system("pause");
    }
}

/*----------------------------------------------------------*/
/* Função mostra os prints da listagem das senhas atendidas */
/*----------------------------------------------------------*/
void printListagemSenhasAtendidas()
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(40);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    MolduraEspaco(6);
    printf("Lista: ");
    MolduraEspaco(29);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(40);
    MolduraQEE();
}

/*------------------------------------------------------------*/
/* Função mostra os prints da listagem das senhas por atender */
/* Parametros: recebe um balcao do tipo char                  */
/*------------------------------------------------------------*/
void printListagemSenhasPorAtender(char balcao)
{
    system("cls");
    Lines(8);
    Cols(7);
    MolduraQSE();
    MolduraLines(40);
    MolduraQSD();
    Cols(7);
    MolduraCols(1);
    MolduraEspaco(3);
    printf("Balcao %c: ", balcao);
    MolduraEspaco(28);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQED();
    MolduraLines(40);
    MolduraQEE();
}

/*-----------------------------------------------------------------------*/
/* Função calcula os espacos para os caracteres enviados para a moldura  */
/* Parametros: recebe um count e um espaco do tipo inteiros              */
/*-----------------------------------------------------------------------*/
int CalculaEspaco(int count, int espaco){
    int i;
    for(i=0;; i++)                          //ciclo for desde i=0
    {
        double aux_count = count;           //um auxiliar igual ao count recebido na função
        if( aux_count <  pow(10, i) )       //se esse auxiliar for menor que 10 elevado a i, ou seja, quanto mais o i elevar uma casa, menor será o espaco
        {
            espaco=espaco-i;                //espaco será espaco menor o i passado
            break;
        }
    }
    return espaco;                         //retorna o valor do espaco calculado
}

/*------------------------------------------------------------------------*/
/* Função calcula os espacos para horas enviadas para a moldura           */
/* Parametros: recebe aux1 do tipo struct tm, e um espaco do tipo inteiro */
/*------------------------------------------------------------------------*/
int CalculaEspacoHoras(struct tm * aux1, int espaco){
    if(aux1->tm_hour+1 >= 10)                //se o auxiliar recebido da hora for maior ou igual a 10
    {
        espaco--;                            //decrementa o espaco
    }
    if(aux1->tm_min >= 10)                   //se o auxiliar recebido do minuto for maior ou igual a 10
    {
        espaco--;                           //decrementa o espaco
    }
    if(aux1->tm_sec >= 10)                  //se o auxiliar recebido do segundo for maior ou igual a 10
    {
        espaco--;                           //decrementa o espaco
    }
    return espaco;                          //retorna o valor do espaco calculado
}

/*-----------------------------------------------------------------------------------*/
/* Função que printa o numero de senhas á frente e uma hora provavel de atendimento  */
/* Parametros: recebe count1 do tipo inteiro e uma HoraProvavel do tipo time_t       */
/*-----------------------------------------------------------------------------------*/
void printInformacaoUtilizador(int count1, time_t HoraProvavel)
{
    int espaco=12, espaco2= 5;
    struct tm *aux1;

    system("cls");
    Lines(8);

    espaco = CalculaEspaco(count1,espaco);                  //calcula o espaco pelo count1 recebido (numero de senhas) e o espaco

    Cols(7);
    MolduraQSE();
    MolduraLines(40);
    MolduraQSD();
    if  (count1 == 1)                                       //se for uma senha
    {
        Cols(7);
        MolduraCols(1);
        printf(" Existe %i senha a sua frente", count1);    //mostra 1 senha à sua frente
        MolduraEspaco(13);
        MolduraCols(1);
        Lines(1);
    }

    else if  (count1 > 1 )                                  //se for mais que uma senha
    {
        Cols(7);
        MolduraCols(1);
        printf(" Existem %i senhas a sua frente", count1);  //mostra o valor de senhas à sua frente
        MolduraEspaco(espaco);
        MolduraCols(1);
        Lines(1);
    }
    else if(count1 == 0)                                    //se for igual a 0
    {
        Cols(7);
        MolduraCols(1);
        printf(" Nao existem senhas a sua frente");         //nao existem senhas à sua frente
        MolduraEspaco(9);
        MolduraCols(1);
        Lines(1);
    }

    Cols(7);
    MolduraCols(1);
    aux1 = gmtime(&HoraProvavel);                           //Converte time_t para tm como o tempo UTC

    if(aux1->tm_hour != 23)
    {
        printf(" Hora Provavel de Atendimento: %i:%i:%i",aux1->tm_hour+1, aux1->tm_min, aux1->tm_sec);
    }
    else
    {
        printf(" Hora Provavel de Atendimento: 0:%i:%i",aux1->tm_min, aux1->tm_sec);
    }

    espaco2 = CalculaEspacoHoras(aux1,espaco2);            //calcula o espaco2 pelo aux1 recebido (numero de senhas) e o espaco2


    MolduraEspaco(espaco2);
    MolduraCols(1);
    Lines(1);
    Cols(7);
    MolduraQID();
    MolduraLines(40);
    MolduraQIE();
}


/*--------------------------------------------------------------------------------------------*/
/* Função que printa o numero de senhas para serem atendidas e hora provavel da ultima senha  */
/* Parametros: recebe count1 do tipo inteiro e uma HoraProvavel do tipo time_t                */
/*--------------------------------------------------------------------------------------------*/
void PrintInformacaoBalcao(int count1 , time_t HoraProvavel)
{
    struct tm *aux1;
    int espaco=4, espaco2=7;                                         //variaveis espaco para calcular os espacos

    Cols(7);
    MolduraQSE();
    MolduraLines(40);
    MolduraQSD();

    espaco=CalculaEspaco(count1,espaco);                             //calcula o espaco pelo count1 recebido (numero de senhas) e o espaco


    if  (count1 == 1)                                                //se for uma senha
    {
        Cols(7);
        MolduraCols(1);
        printf(" Existe %i senha para ser atendida", count1);        //mostra uma senha para ser atendida
        MolduraEspaco(9);
        MolduraCols(1);
        Lines(1);
    }

    else if  (count1 > 1 )                                          //se for mais que uma senha
    {
        Cols(7);
        MolduraCols(1);
        printf(" Existem %i senhas para serem atendidas", count1);   //mostra as senhas para serem atendidas
        MolduraEspaco(espaco);
        MolduraCols(1);
        Lines(1);
    }

    aux1 = gmtime(&HoraProvavel);                                   //Converte time_t para tm como o tempo UTC
    if(count1 != 0)                                                 //se count1 for diferente de 0
    {
        Cols(7);
        MolduraCols(1);
        if(aux1->tm_hour != 23)
        {
            printf(" Hora Prov. da ultima senha: %i:%i:%i",aux1->tm_hour+1, aux1->tm_min, aux1->tm_sec); //printa a HoraProvavel

        }
        else
        {
            printf("0:%i:%i",aux1->tm_min, aux1->tm_sec);
        }

        espaco2 = CalculaEspacoHoras(aux1,espaco2);             //calcula os espacos para horas pelo aux1 e espaco2 recebidos

        MolduraEspaco(espaco2);
        MolduraCols(1);
        Lines(1);
    }

    else                                                         //se o count1 for igual a 0
    {
        Cols(7);
        MolduraCols(1);
        printf(" Nao existem senhas para serem atendidas");     //nao existem senhas para serem atendidas
        MolduraEspaco(1);
        MolduraCols(1);
        Lines(1);
    }

    Cols(7);
    MolduraQID();
    MolduraLines(40);
    MolduraQIE();
}


/*--------------------------------------------------------------------------------------------*/
/* Função que printa alerta do tempo minimo e maximo                                          */
/* Parametros: recebe um tipo do tipo bool                                                    */
/*--------------------------------------------------------------------------------------------*/
void printAlertaTempo(bool tipo)
{
    system("cls");
    Lines(8);

    system("COLOR 2C");                                           //coloca o programa com cor definida por 2C
    Cols(7);
    MolduraQSE();
    MolduraLines(41);
    MolduraQSD();
    if(tipo==Maximo)                                              //se o tipo for Maximo
    {
        Cols(7);
        MolduraCols(1);
        printf("\a Tempo maximo de atendimento atingindo!!!");   //printa o alerta para tempo maximo
        MolduraEspaco(1);
        MolduraCols(1);
        Lines(1);
    }
    else if(tipo==Minimo)                                         //se o tipo for Minimo
    {
        Cols(7);
        MolduraCols(1);
        printf("\a Tempo minimo de atendimento atingindo!!!");   //printa o alerta para tempo minimo
        MolduraEspaco(1);
        MolduraCols(1);
        Lines(1);
    }
    Cols(7);
    MolduraQID();
    MolduraLines(41);
    MolduraQIE();
}

/*--------------------------------------------------------------------------------------------*/
/* Função que printa a informacao das estatisticas                                            */
/* Parametros: recebe um count, resultado e total do tipo float, e um tipo do tipo inteiro    */
/*--------------------------------------------------------------------------------------------*/
void PrintInformacao(float count, float resultado, float total, int tipo)
{
    int espaco, espaco2, espaco3;
    if(tipo==Desiste)                    // tipo Desistente
    {
        espaco=8;
        espaco2=18;
        espaco3=3;
    }
    else if(tipo==SemPrioridade)        // tipo Normal
    {
        espaco=6;
        espaco2=18;
        espaco3=9;
    }
    else if(tipo==ComPrioridade)        // tipo Prioritario
    {
        espaco=14;
        espaco2=18;
        espaco3=9;
    }

    Lines(1);

    //calcula espacos
    espaco=CalculaEspaco(count,espaco);

    espaco2=CalculaEspaco(total,espaco2);

    espaco3=CalculaEspaco(resultado,espaco3);


    if(count != 0)
    {
        Cols(7);
        MolduraQSE();
        MolduraLines(40);
        MolduraQSD();
        if(tipo==Desiste)                                                       //para tipo Desiste
        {
            Cols(7);
            MolduraCols(1);
            printf(" A percentagem de Desistencias e de %1.1f", resultado);     //printa a percentagem de desistencias
            MolduraEspaco(espaco3);
            MolduraCols(1);
            Lines(1);
            Cols(7);
            MolduraCols(1);
            printf(" O Numero de Desistencias e de %1.1f", count);              //printa o numero de desistencias
            MolduraEspaco(espaco);
            MolduraCols(1);
        }
        else if(tipo==SemPrioridade)                                            //para o tipo sem Prioridade
        {
            Cols(7);
            MolduraCols(1);
            printf(" A percentagem de Senhas e de %1.1f", resultado);           //printa a percentagem de senhas
            MolduraEspaco(espaco3);
            MolduraCols(1);
            Lines(1);
            Cols(7);
            MolduraCols(1);
            printf(" O Numero de Senhas Normais e de %1.1f", count);            //printa o numero de senhas normais
            MolduraEspaco(espaco);
            MolduraCols(1);
        }
        else if(tipo == ComPrioridade)                                          //para o tipo com Prioridade
        {
            Cols(7);
            MolduraCols(1);
            printf(" A percentagem de Senhas e de %1.1f", resultado);          //printa a percentagem de senhas
            MolduraEspaco(espaco3);
            MolduraCols(1);
            Lines(1);
            Cols(7);
            MolduraCols(1);
            printf(" O Numero de Senhas e de %1.1f", count);                    //printa o numero de senhas
            MolduraEspaco(espaco);
            MolduraCols(1);
        }
        Lines(1);
        Cols(7);
        MolduraCols(1);
        printf(" O Numero total e de %1.1f", total);                            //printa o numero total de senhas
        MolduraEspaco(espaco2);
        MolduraCols(1);
        Lines(1);
    }

    else                                                                    //se o count for 0
    {
        Cols(7);
        MolduraCols(1);
        printf(" Nao existem senhas atendidas");                            //nao existem senhas atendidas
        MolduraEspaco(13);
        MolduraCols(1);
        Lines(1);

    }
    Cols(7);
    MolduraQID();
    MolduraLines(40);
    MolduraQIE();

}

/*--------------------------------------------------------------------------------------------*/
/* Função que printa senhas entre datas                                                       */
/* Parametros: recebe uma funcionalidade do tipo char e um estado do tipo inteiro             */
/*--------------------------------------------------------------------------------------------*/
void PrintEntreDatas(char Funcionalidade, int estado)
{
    if(Funcionalidade==Insere)                                  //Prints dos insere
    {
        if(estado==INICIAL)                                     //Estado Inicial
        {
            system("cls");
            Lines(8);
            Cols(7);
            MolduraQSE();
            MolduraLines(42);
            MolduraQSD();
            Cols(7);
            MolduraCols(1);
            MolduraEspaco(6);
            printf("Insira a data inicial (ano-mes-dia)");
            MolduraEspaco(2);
            MolduraCols(1);
            Lines(1);
            Cols(7);
            MolduraQID();
            MolduraLines(42);
            MolduraQIE();
        }
        else                                                    //Estado Final
        {
            system("cls");
            Lines(8);
            Cols(7);
            MolduraQSE();
            MolduraLines(42);
            MolduraQSD();
            Cols(7);
            MolduraCols(1);
            MolduraEspaco(6);
            printf("Insira a data final (ano-mes-dia)");
            MolduraEspaco(4);
            MolduraCols(1);
            Lines(1);
            Cols(7);
            MolduraQID();
            MolduraLines(42);
            MolduraQIE();
        }
    }
    else if(Funcionalidade == ERRO)                             //Prints dos erros
    {
        if(estado==INICIAL)                                     //Estado Inicial
        {
            Lines(1);
            Cols(7);
            MolduraQSE();
            MolduraLines(42);
            MolduraQSD();
            Cols(7);
            MolduraCols(1);
            MolduraEspaco(6);
            printf("DATA INICIAL INCORRECTA");
            MolduraEspaco(14);
            MolduraCols(1);
            Lines(1);
            Cols(7);
            MolduraQID();
            MolduraLines(42);
            MolduraQIE();
        }
        else                                                    //Estado Final
        {
            Lines(1);
            Cols(7);
            MolduraQSE();
            MolduraLines(42);
            MolduraQSD();
            Cols(7);
            MolduraCols(1);
            MolduraEspaco(6);
            printf("DATA FINAL INCORRECTA");
            MolduraEspaco(14);
            MolduraCols(1);
            Lines(1);
            Cols(7);
            MolduraQID();
            MolduraLines(42);
            MolduraQIE();
        }
    }
    else if (Funcionalidade == Verifica)                    // Prints da Verificaçao de datas
    {
        if(estado == D_ANO)                                  // print da Verificaçao do ano final menor ao ano inicial
        {
            Cols(7);
            MolduraQSE();
            MolduraLines(41);
            MolduraQSD();
            Cols(7);
            MolduraCols(1);
            MolduraEspaco(1);
            printf(" Ano Final maior ou igual ao Ano inicial");
            MolduraEspaco(1);
            MolduraCols(1);
            Lines(1);
            Cols(7);
            MolduraQID();
            MolduraLines(41);
            MolduraQIE();
        }
        else if(estado == D_Mes)                             // print da Verificaçao do mes final menor ao mes inicial
        {
            Cols(7);
            MolduraQSE();
            MolduraLines(41);
            MolduraQSD();
            Cols(7);
            MolduraCols(1);
            MolduraEspaco(1);
            printf("Mes Final maior ou igual ao Mes incial");
            MolduraEspaco(3);
            MolduraCols(1);
            Lines(1);
            Cols(7);
            MolduraQID();
            MolduraLines(41);
            MolduraQIE();
        }
        else if(estado == D_Dia)                             // print da Verificaçao do dia final menor ao dia inicial
        {
            Cols(7);
            MolduraQSE();
            MolduraLines(41);
            MolduraQSD();
            Cols(7);
            MolduraCols(1);
            MolduraEspaco(1);
            printf("Dia Final maior ou igual ao Dia incial");
            MolduraEspaco(3);
            MolduraCols(1);
            Lines(1);
            Cols(7);
            MolduraQID();
            MolduraLines(41);
            MolduraQIE();
        }
    }
}

/*--------------------------------------------------------------------------------------------*/
/* Função que printa resultado entre datas                                                    */
/* Parametros: recebe um count e um estado do tipo inteiro, e um tempo do tipo double         */
/*--------------------------------------------------------------------------------------------*/
void PrintResultadoEntreDatas(int count, double Tempo, int estado)
{
    int espaco, espaco1;                                     //variaveis para calcular espacos
    if(estado==Desiste)                                      //Desistencia
    {
        espaco=13;
        espaco1=0;
    }
    else if(estado==SemPrioridade)                           //SemPrioridade
    {
        espaco=7;
        espaco1=13;
    }
    else if(estado==ComPrioridade)                           //ComPrioridade
    {
        espaco=2;
        espaco1=13;
    }

    //calcula espacos
    espaco=CalculaEspaco(count,espaco);

    espaco1=CalculaEspaco(Tempo,espaco1);

    if(count!=0)
    {
        system("cls");
        Lines(8);
        Cols(7);
        MolduraQSE();
        MolduraLines(42);
        MolduraQSD();
        if (estado==Desiste)                                  //Desistencia
        {
            if  (count == 1)                                  //se for uma senha desistente
            {
                Cols(7);
                MolduraCols(1);
                MolduraEspaco(5);
                printf(" Existe %i senha Desistente", count); //printa uma senha desistente
                MolduraEspaco(5);
                MolduraCols(1);
                Lines(1);
            }

            else if  (count > 1 )                               //se for mais que uma senha desistente
            {
                Cols(7);
                MolduraCols(1);
                MolduraEspaco(2);
                printf(" Existem %i senhas Desistentes", count); //printa o numero das senhas desistentes
                MolduraEspaco(espaco);
                MolduraCols(1);
                Lines(1);
            }

        }
        else if(estado==SemPrioridade)                                   //Normal
        {
            if  (count ==1)                                             //se for uma senha normal
            {
                Cols(7);
                MolduraCols(1);
                MolduraEspaco(3);
                printf(" Existe %i senha Normal atendida", count);      //printa uma senha normal atendida
                MolduraEspaco(9);
                MolduraCols(1);
                Lines(1);
            }

            else if  (count > 1 )                                        //se for mais que uma senha normal
            {
                Cols(7);
                MolduraCols(1);
                MolduraEspaco(2);
                printf(" Existem %i senhas Normais atendidas", count);  //printa o numero das senhas normais atendidas
                MolduraEspaco(espaco);
                MolduraCols(1);
                Lines(1);
            }

            Cols(7);
            MolduraCols(1);
            MolduraEspaco(3);
            printf("Tempo medio de senhas: %1.1f s", Tempo);            //printa o tempo medio das senhas normais
            MolduraEspaco(espaco1);
            MolduraCols(1);
            Lines(1);

        }
        else if(estado==ComPrioridade)                               //Prioritarias
        {
            if  (count ==1)                                         //se for uma senha prioritaria
            {
                Cols(7);
                MolduraCols(1);
                MolduraEspaco(2);
                printf(" Existe %i senha Prioritaria atendida", count); //printa uma senha prioritaria atendida
                MolduraEspaco(5);
                MolduraCols(1);
                Lines(1);
            }

            else if  (count > 1 )                                       //se for mais que uma senha prioritaria
            {
                Cols(7);
                MolduraCols(1);
                MolduraEspaco(2);
                printf(" Existem %i senhas Prioritarias atendidas", count);//printa o numero de senhas prioritarias atendidas
                MolduraEspaco(espaco);
                MolduraCols(1);
                Lines(1);
            }

            Cols(7);
            MolduraCols(1);
            MolduraEspaco(3);
            printf("Tempo medio de senhas: %1.1f s", Tempo);            //tempo medio das senhas prioritarias
            MolduraEspaco(espaco1);
            MolduraCols(1);
            Lines(1);

        }
        Cols(7);
        MolduraQID();
        MolduraLines(42);
        MolduraQIE();
    }
    else if(estado==Nenhum)                                  //Nenhum
    {
        Cols(7);
        MolduraCols(1);
        MolduraEspaco(6);
        printf("Nao Existem senhas");                       //nao existem senhas
        MolduraEspaco(14);
        MolduraCols(1);
        Lines(1);
        Cols(7);
        MolduraQID();
        MolduraLines(42);
        MolduraQIE();
    }
    Cols(8);
    system("pause");
}
