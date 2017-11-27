//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Menus.c                                                      //
//**************************************************************//

#include "Print.h"

/*-----------------------------------------------*/
/* Menu Inicial (apresentacao)                   */
/*-----------------------------------------------*/
void Menu()                                                  //função que do menu de apresentação
{
    system("cls");                                          //limpa a tela do ecrã
    system("COLOR 4F");                                     //colocada a cor vermelho bright white (pelo codigo cor 4F)
    Lines(5);
    MolduraQSE();                                           //chama a função para inserir no canto superior esquerdo
    MolduraLines(70);                                       //função que recebe 70 linhas
    MolduraQSD();                                           //chama a função para inserir no canto superior direito
    MolduraCols(1);Cols(16);MolduraEspaco(3);MolduraCols(1);Lines(1);
    MolduraCols(1);Cols(6); printf("\t PROJECTO DE AED \t");Cols(3);MolduraCols(1);Lines(1);
    MolduraCols(1);Cols(16); MolduraEspaco(3); MolduraCols(1);Lines(1);
    MolduraQED();                                           //chama a função para inserir no entrocamento direito
    MolduraLines(70);
    MolduraQEE();                                          //chama a função para inserir no entrocamento esquerdo
    MolduraCols(1);Cols(16); MolduraEspaco(3);MolduraCols(1);Lines(1);
    MolduraCols(1);Cols(4); printf("\t   GESTAO DE FILAS DE ESPERA   \t");Cols(3);MolduraCols(1);Lines(1);
    MolduraCols(1);Cols(16); MolduraEspaco(3);MolduraCols(1);Lines(1);
    MolduraQED();
    MolduraLines(70);
    MolduraQEE();
    MolduraCols(1); printf("\t          INSTITUTO POLITECNICO DE PORTALEGRE             \t");MolduraCols(1);Lines(1);
    MolduraCols(1); printf("\t        ESCOLA SUPERIOR DE TECNOLOGIA E GESTAO            \t");MolduraCols(1);Lines(1);
        MolduraCols(1); MolduraEspaco(71);MolduraCols(1);Lines(1);

    MolduraCols(1); printf("\tANO LECTIVO:       2014/2015               \tSEMESTRE: 2    \t");MolduraCols(1);Lines(1);
    MolduraCols(1); printf("\tCURSO:             Engenharia Informatica (EI)\tCODIGO: 9119  \t");MolduraCols(1);Lines(1);
    MolduraCols(1); printf("\tCADEIRA:           Algoritmos e Estruturas de Dados (AED)   \t");MolduraCols(1);Lines(1);
    MolduraCols(1); printf("\tDOCENTE (Pratica): Sergio Correia                           \t");MolduraCols(1);Lines(1);
    MolduraCols(1); printf("\tDOCENTE (teorica): Valentim Realinho                          \t");MolduraCols(1);Lines(1);
    MolduraCols(1); printf("\tANO LECTIVO:       2014-2015                                \t");MolduraCols(1);Lines(1);
    MolduraCols(1); printf("\tGRUPO:             1                                        \t");MolduraCols(1);Lines(1);
    MolduraCols(1);printf("\tNOME:              Alvaro Benjamim        \tNUMERO: 16372 \t");MolduraCols(1);Lines(1);
    MolduraCols(1); printf("\tNOME:              Frederico Balcao       \tNUMERO: 15307 \t");MolduraCols(1);Lines(1);
    MolduraQID();
    MolduraLines(70);
    MolduraQIE();
    Cols(8);system("Pause");
}

/*-----------------------------------------------*/
/* Menu Principal                                */
/*-----------------------------------------------*/
char MenuP()
{
    int i = 0, tecla, sair=0;                                //i e tecla para utilização das condições das teclas, sair inicializado a 0
    char aux, opcao[4] = {'*', ' ', ' ', ' '};               //esta função tem 4 arrays do tipo char para a opcao desejada

    system("cls");                                           //limpa a tela do ecrã
    system("COLOR 4F");                                      //coloca a correspondência da cor 4F no programa (vermelho bright white)

    while(sair==0)                                           //enquanto o sair for igual a 0
    {
        printMenuP(opcao);                                   //chama o printMenuP (menu do programa principal) que recebe uma opcao

        tecla = getch();                                     //espera até o utilizador colocar a tecla desejada

        if(tecla == 224){                                    //verifica se é caracter especial

         tecla = getch();                                    //espera até o utilizador colocar a tecla desejada

            if(tecla==72)                                    //pressionada a tecla da seta up (72)
            {
                if(i>=1)                                     //se i for maior ou igual que 1
                {
                    opcao[i]= ' ';                           //opcao[i] sem asterisco
                    i=i-1;                                   //decrementa i--
                    opcao[i]= '*';                           //opcao[i] com asterisco
                }
            }
            if(tecla==80)                                    //pressionada a tecla da seta down (80)
            {
                if(i<=2)
                {
                    opcao[i]= ' ';                           //opcao[i] sem asterisco
                    i=i+1;                                   //incrementa i++
                    opcao[i]= '*';                           //opcao[i] com asterisco
                }
            }
        }else{
          if(tecla==13)                                     //pressionada a tecla enter (13)
            {
                if(i==3)                                    //se i for igual a 3 opções possiveis
                {
                    aux= '0';                               //aux fica a '0'
                }
                else                                        //senão
                {
                    aux= '1' + i;                           //aux soma '1' com i
                }
                sair=1;                                     //sair fica a 1
            }
        }
    }
    return aux;                                             //retorna variavel aux do tipo char
}

/*-----------------------------------------------*/
/* Menu Utilizador                               */
/*-----------------------------------------------*/
char MenuUtilizador()
{
    int i = 0, tecla, sair=0;                               //i e tecla para utilização das condições das teclas, sair inicializado a 0
    char aux, opcao[3] = {'*', ' ', ' '};                   //esta função tem 3 arrays do tipo char para a opcao desejada

    system("COLOR 4F");                                     //coloca a correspondência da cor 4F no programa (vermelho bright white)

    while(sair==0)                                          //enquanto o sair for igual a 0
    {
        printMenuUtilizador(opcao);                         //chama o printMenuUtilizador que recebe uma opcao

        tecla = getch();                                    //espera até o utilizador colocar a tecla desejada

        if(tecla == 224){                                   //verifica se é caracter especial

            tecla = getch();

            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<2)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                if(i==2)                                            //se i for igual a 2 opções possiveis
                {
                    aux = '0';
                }
                else
                {
                    aux = '1' + i;
                }
                sair=1;
            }
        }
    }
    return aux;

}

/*-----------------------------------------------*/
/* Menu Senha                                    */
/*-----------------------------------------------*/
char MenuSenha()
{
    int i = 0, tecla, sair=0;
    char aux, opcao[5] = {'*', ' ', ' ', ' ',' '};                   //esta função tem 5 arrays do tipo char para a opcao desejada

    system("COLOR 4F");

    while(sair==0)
    {
        printMenuSenha(opcao);

        tecla = getch();

        if(tecla == 224){

            tecla = getch();

            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<=3)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                if(i==4)                                               //se i for igual a 4 opções possiveis
                {
                    aux = '0';
                }
                else
                {
                    aux = 'A' + i;
                }
                sair=1;
            }
        }
    }
    return aux;

}

/*-----------------------------------------------*/
/* Menu Balcao                                   */
/*-----------------------------------------------*/
char MenuBalcao()
{
    int i = 0, tecla, sair=0;
    char aux, opcao[5] = {'*', ' ', ' ', ' ', ' '};              //esta função tem 5 arrays do tipo char para a opcao desejada

    system("COLOR 4F");

    while(sair==0)
    {
       printMenuBalcao(opcao);

       tecla = getch();

        if(tecla == 224){

            tecla = getch();

            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<=3)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                if(i==4)                                               //se i for igual a 4 opções possiveis
                {
                    aux = '0';
                }
                else
                {
                    aux = 'A'+ i;
                }
                sair=1;
            }
        }
    }
    return aux;
}

/*-----------------------------------------------*/
/* Menu Opcao de Balcao                          */
/*-----------------------------------------------*/
char MenuBalcaoOpcao()
{
    int i = 0, tecla, sair=0;
    char aux, opcao[4] = {'*', ' ', ' ', ' '};                     //esta função tem 4 arrays do tipo char para a opcao desejada

    system("COLOR 4F");

    while(sair==0)
    {
        system("cls");
        Lines(8);

        Cols(7); MolduraQSE(); MolduraLines(21); MolduraQSD();
        Cols(7); MolduraCols(1); MolduraEspaco(6); printf("Atendimento");MolduraEspaco(5);MolduraCols(1);Lines(1);
        Cols(7); MolduraQED(); MolduraLines(21); MolduraQEE();
        Cols(7); MolduraCols(1); printf(" [%c] Atender Senha", opcao[0]); MolduraEspaco(4); MolduraCols(1);Lines(1);
        Cols(7); MolduraCols(1); printf(" [%c] Senha Desistente", opcao[1]); MolduraEspaco(1); MolduraCols(1);Lines(1);
        Cols(7); MolduraCols(1); printf(" [%c] Estatisticas",opcao[2]); MolduraEspaco(5); MolduraCols(1);Lines(1);
        Cols(7); MolduraCols(1); printf(" [%c] Voltar", opcao[3]); MolduraEspaco(11); MolduraCols(1);Lines(1);
        Cols(7); MolduraQID(); MolduraLines(21); MolduraQIE();
        tecla = getch();

        if(tecla == 224){

            tecla = getch();

            if(tecla==72)
                {
                    if(i>=1)
                    {
                        opcao[i]= ' ';
                        i=i-1;
                        opcao[i]= '*';
                    }
                }
                if(tecla==80)
                {
                    if(i<=2)
                    {
                        opcao[i]= ' ';
                        i=i+1;
                        opcao[i]= '*';
                    }
                }
        }else{
            if(tecla==13)
            {
                if(i==3)                                               //se i for igual a 3 opções possiveis
                {
                    aux =  '0';
                }
                else
                {
                    aux = '1' + i;
                }
                sair=1;
            }
        }
    }
    return aux;
}


/*-----------------------------------------------*/
/* Menu Balcao Senhas                            */
/*-----------------------------------------------*/
char MenuBalcaoSenha()
{
    int i = 0, tecla, sair=0;
    char opcao[2] = {'*', ' '};                                   //esta função tem 2 arrays do tipo char para a opcao desejada

    system("COLOR 4F");

    while(sair==0)
    {
        printMenuBalcaoSenha(opcao);

        tecla = getch();

        if(tecla == 224){

            tecla = getch();

            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<1)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                sair=1;
            }
        }
    }
    return '1' + i;
}

/*-----------------------------------------------*/
/* Menu Transfere do Balcao A                    */
/*-----------------------------------------------*/
char MenuATransf()
{
    int i = 0, tecla, sair=0, aux;
    char opcao[3] = {'*', ' ', ' '};                              //esta função tem 3 arrays do tipo char para a opcao desejada

    system("COLOR 4F");

    while(sair==0)
    {
        printMenuATransf(opcao);

        tecla = getch();

        if(tecla == 224){
            tecla = getch();

            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<2)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                aux=i;
                sair=1;
            }
        }
    }
    return 'A' + aux;
}

/*-----------------------------------------------*/
/* Menu Transfere do Balcao B                    */
/*-----------------------------------------------*/
char MenuBTransf()
{
    int i = 0, tecla, sair=0,aux;
    char opcao[3] = {'*', ' ', ' ' };                             //esta função tem 3 arrays do tipo char para a opcao desejada

    system("COLOR 4F");

    while(sair==0)
    {
        printMenuBTransf(opcao);

        tecla = getch();

        if(tecla == 224){
            tecla = getch();
            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<=2)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                if(i==0)
                {
                    aux = 'A';
                }
                else
                {
                    aux = 'B' + i;
                    break;
                }
                sair=1;
            }
        }
    }
    return aux;
}

/*-----------------------------------------------*/
/* Menu Transfere do Balcao C                    */
/*-----------------------------------------------*/
char MenuCTransf()
{
    int i = 0, tecla, sair=0;

    char aux, opcao[3] = {'*', ' ', ' '};                         //esta função tem 3 arrays do tipo char para a opcao desejada


    system("COLOR 4F");

    while(sair==0)
    {
        printMenuCTransf(opcao);

        tecla = getch();

        if(tecla == 224){
            tecla = getch();
            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<=2)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                if(i==2)                                              //se i for igual a 2 opções possiveis
                {
                    aux = 'D';
                }
                else
                {
                    aux = 'A' + i;
                    break;
                }
                sair=1;
            }
        }
    }
    return aux;
}

/*-----------------------------------------------*/
/* Menu Transfere do Balcao D                    */
/*-----------------------------------------------*/
char MenuDTransf()
{
    int i = 0, tecla, sair=0;
    char aux,  opcao[3] = {'*', ' ', ' '};                         //esta função tem 3 arrays do tipo char para a opcao desejada

    system("COLOR 4F");

    while(sair==0)
    {
       printMenuDTransf(opcao);

        tecla = getch();

        if(tecla == 224){
            tecla = getch();
            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<2)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                aux = 'A' + i;
                sair=1;
            }
        }
    }
    return aux;
}

/*-----------------------------------------------*/
/* Menu Outras Opçoes                            */
/*-----------------------------------------------*/
char MenuMais1()
{
    int i = 0, tecla, sair=0;
    char aux, opcao[6] = {'*', ' ', ' ', ' ', ' ', ' '};              //esta função tem 6 arrays do tipo char para a opcao desejada

    system("COLOR 4F");

    while(sair==0)
    {
       printMenuMais(opcao);

        tecla = getch();

        if(tecla == 224){
            tecla = getch();
            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<=4)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                if(i==5)
                {
                    aux = '0';
                }
                else
                {
                    aux = '1' + i;
                }
                sair=1;
            }
        }
    }
    return aux;
}

/*-----------------------------------------------*/
/* Menu Estatistica                              */
/*-----------------------------------------------*/
char MenuEstatisticas()
{
    int i = 0, tecla, sair=0;

    char aux, opcao[5] = {'*', ' ', ' ',' ', ' '};                      //esta função tem 5 arrays do tipo char para a opcao desejada


    system("COLOR 4F");

    while(sair==0)
    {
        printMenuEstatistica(opcao);

        tecla = getch();

        if(tecla == 224){
            tecla = getch();
            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<=3)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                if(i==4)                                              //se i for igual a 4 opções possiveis
                {
                    aux = '0';
                }
                else
                {
                    aux = '1' + i;
                }
                sair=1;
            }
        }
    }
    return aux;
}

/*-----------------------------------------------*/
/* Menu Listagens                                */
/*-----------------------------------------------*/
char MenuListagens()
{
    int i = 0, tecla, sair=0;

    char aux, opcao[9] = {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ' , ' '};    //esta função tem 9 arrays do tipo char para a opcao desejada


    system("COLOR 4F");

    while(sair==0)
    {
       printMenuListagens(opcao);

        tecla = getch();

        if(tecla == 224){
            tecla = getch();
            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<8)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                if(i==8)                                                  //se i for igual a 8 opções possiveis
                {
                    aux = '0';
                }
                else
                {
                    aux = '1' + i;
                }
                sair=1;
            }
        }
    }
    return aux;
}

/*-----------------------------------------------*/
/* Menu Auxiliar                                 */
/*-----------------------------------------------*/
char MenuAuxiliar(char balcao)
{
    int i = 0, tecla, sair=0;

    char aux, opcao[2] = {'*', ' '};                            //esta função tem 2 arrays do tipo char para a opcao desejada


    system("COLOR 4F");

    while(sair==0)
    {
        printMenuAuxiliar(opcao, balcao);

        tecla = getch();

        if(tecla == 224){
            tecla = getch();
            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<1)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                if(i==1)                                                //se i for igual a 2 opções possiveis
                {
                    aux = '0';
                }
                else
                {
                    aux = '1' + i;
                }
                sair=1;
            }
        }
    }
    return aux;
}

/*-----------------------------------------------*/
/* Menu Random                                   */
/*-----------------------------------------------*/
char MenuRandom()
{
    int i = 0, tecla, sair=0;

    char aux, opcao[3] = {'*', ' ',' '};                                //esta função tem 3 arrays do tipo char para a opcao desejada


    system("COLOR 4F");

    while(sair==0)
    {
       printMenuRandom(opcao);

        tecla = getch();

        if(tecla == 224){
            tecla = getch();
            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<2)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                if(i==1)                                                //se i for igual a 1
                {
                    aux = 'N';                                          //aux é 'N'
                }
                if(i==2)                                                //se i for igual a 2
                {
                    aux = '0';                                          //aux é '0'
                }
                if(i==0)                                                //se i for igual a 0
                {
                    aux = 'S';                                          //aux é 'S'
                }
                sair=1;                                                 //sair é igual a 1
            }
        }
    }
    return aux;
}

/*-----------------------------------------------*/
/* Menu Mais Outras Opções                       */
/*-----------------------------------------------*/
char MenuMais2()
{
    int i = 0, tecla, sair=0;
    char aux, opcao[2] = {'*', ' ',};                                   //esta função tem 2 arrays do tipo char para a opcao desejada

    system("COLOR 4F");

    while(sair==0)
    {
       printMenuMaisListagem(opcao);

        tecla = getch();

        if(tecla == 224){
            tecla = getch();
            if(tecla==72)
            {
                if(i>=1)
                {
                    opcao[i]= ' ';
                    i=i-1;
                    opcao[i]= '*';
                }
            }
            if(tecla==80)
            {
                if(i<1)
                {
                    opcao[i]= ' ';
                    i=i+1;
                    opcao[i]= '*';
                }
            }
        }else{
            if(tecla==13)
            {
                if(i==1)
                {
                    aux = '0';
                }
                else
                {
                    aux = '1' + i;
                }
                sair=1;
            }
        }
    }
    return aux;
}

/*-----------------------------------------------*/
/* Menu Tipo de Ordenaçao                        */
/*-----------------------------------------------*/
char MenuTipoOrdenacao(){
      int i = 0, tecla, sair=0;

    char aux, opcao[3] = {'*', ' ', ' '};                               //esta função tem 3 arrays do tipo char para a opcao desejada


    system("COLOR 4F");

    while(sair==0)
    {
       printMenuTipoOrdenacao(opcao);

        tecla = getch();

        if(tecla == 224){
            tecla = getch();
                if(tecla==72)
                {
                    if(i>=1)
                    {
                        opcao[i]= ' ';
                        i=i-1;
                        opcao[i]= '*';
                    }
                }
                if(tecla==80)
                {
                    if(i<=2)
                    {
                        opcao[i]= ' ';
                        i=i+1;
                        opcao[i]= '*';
                    }
                }
            }else{
                if(tecla==13)
                {
                    if(i==2)
                    {
                        aux = '0';
                    }
                    if(i==0){
                        aux='S';
                    }
                    if(i==1){
                        aux='N';
                    }
                    sair=1;
                }
            }
        }
    return aux;
}
