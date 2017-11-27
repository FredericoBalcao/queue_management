//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Lista.c                                                      //
//**************************************************************//

#include "Lista.h"

/*-----------------------------------------------*/
/* Cria lista                                    */
/*-----------------------------------------------*/
Lista *criar_lista()
{
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->primeiro= NULL;
    lista->ultimo = NULL;

    return lista;
}

/*-----------------------------------------------*/
/* Adiciona Fim da lista                         */
/*-----------------------------------------------*/
void adicionarF(Lista *lista, Item *item)
{
    No *temp;

    temp = (No*)malloc(sizeof(No));
    temp->next = NULL;
    temp->dados = item;

    if (empty_queuelista(lista))
    {
        /* inserção na fila com ela vazia */
        lista->primeiro = temp;
        lista->ultimo = lista->primeiro;
    }
    else
    {
        /* fila não está vazia... */
        lista->ultimo->next = temp;
        lista->ultimo = temp;
    }
}

/*-----------------------------------------------*/
/* Listar lista                                  */
/*-----------------------------------------------*/
void listar(Lista* lista)
{
    No *p;

    // fila vazia
    if (empty_queuelista(lista))
    {
        Cols(7); printf("[VAZIA]\n");
        return;
    }

    /* fila não está vazia... */
    /* ... percorrer lista e imprimir cada nó */

    p = lista->primeiro;
    int i=1;

    do
    {
        if(i==4){
            Cols(8);system("Pause");
            system("cls");
            Lines(8);
            Cols(7); MolduraQSE(); MolduraLines(40); MolduraQSD();
            i=1;
        }

    if(i < 3){
            Print_Item(TipoLista, p->dados);                          //Printa os dados que recebe um tipo de lista e os dados
            if(p->next!=NULL){
                Cols(7); MolduraQED(); MolduraLines(40); MolduraQEE();
            }
        p = p->next;
        i++;                                                         //incrementa o i
    }
    else if(i == 3){
        Print_Item(TipoLista, p->dados);
        Cols(7); MolduraQID(); MolduraLines(40); MolduraQIE();
        p = p->next;
        i++;
    }

    }
    while (p != NULL);

    Cols(7); MolduraQID(); MolduraLines(40); MolduraQIE();
}

/*-----------------------------------------------*/
/* Verica se a lista está vazia                  */
/*-----------------------------------------------*/
int empty_queuelista(Lista *lista)
{
    return lista->primeiro == NULL;
}

/*-----------------------------------------------*/
/* Troca nós da lista                            */
/*-----------------------------------------------*/
void exch(No *no1, No *no2)
{
    Item *aux;

    aux = no1->dados;

    no1->dados = no2->dados;
    no2->dados = aux;
}

/*-----------------------------------------------*/
/* Apaga a lista                                 */
/*-----------------------------------------------*/
void apaga_lista(Lista *lista)
{
    No *p, *p1;

    if(empty_queuelista(lista))
    {
        //liberar a lista
        free(lista);
        return;
    }
    /* fila não está vazia... */
    /* ... percorrer fifo e libertar cada nó */
    p = lista->primeiro;
    do
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
    while (p != NULL);

    /* libertar a FIFO */
    free(lista);
}

/*-----------------------------------------------*/
/* Gera aleatoriamente senhas                    */
/*-----------------------------------------------*/
void Random(Lista *lista, int limite)
{
    int i=1;
    Item *item;

    for(i=1; i<= limite; i++)                                       //desde i=1 até i ser menor ou igual ao limite de senhas dado
    {
        item = (Item *)malloc(sizeof(Item));

        time(&item->HoraEntrada);                                   //regista a HoraEntrada com a hora do sistema

        item->Balcao = 'A' + rand()%4;                              //gera 4 balcões
        item->Id= i;                                                //o numero da senha será a ronda do i desde 1 até ao limite
        item->prioridade= (rand()%2) - 1;                           //gera duas prioridades (Normal e Prioritaria)
        item->status= (rand()%2) - 1;                               //gera dois status (Normal e Desistente)
        item->HoraEntrada = item->HoraEntrada - ((rand())*245);     //gera uma HoraEntrada
        item->HoraAtendimento = item->HoraEntrada + (rand()%900);   //gera uma HoraAtendimento até 900seg (9min)
        item->HoraSaida = item->HoraAtendimento + (rand()%1800);    //gera uma HoraSaida até 1800seg (18min)

        adicionarF(lista, item);                                    //adiciona todos os dados numa lista criada
    }
    system("cls");                                                  //limpa a tela do ecrã
    Lines(8);
    Cols(7); MolduraQSE(); MolduraLines(40); MolduraQSD();
    Cols(7); MolduraCols(1);MolduraEspaco(3); printf("Lista:");MolduraEspaco(32);MolduraCols(1);Lines(1);
    Cols(7); MolduraQED(); MolduraLines(40); MolduraQEE();
    listar(lst);                                                    //lista a lista criada aleatoriamente
    Cols(8);
    system("Pause");                                                //pausa
}
