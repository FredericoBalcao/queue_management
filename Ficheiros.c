// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Ficheiro.c                                                   //
//**************************************************************//

#include "Ficheiros.h"

/*-----------------------------------------------*/
/* Gravar dados para uma lista                   */
/*-----------------------------------------------*/
void gravar_ficheiro(Lista *lista)
{
    No *aux;
    FILE *fp;
    struct tm *aux1;

    fp = fopen ("Dados.txt", "w+");                      //abre o ficheiro para leitura

    if (fp == NULL)                                      //se o fp for vazio
    {
        printf("Erro na abertura do ficheiro!!\n");
        exit(0);
    }

    // Exportar dados da lista

    fprintf(fp,"Lista:  \n");                                       //envia para o .txt o print
    int a;
    a = NumeroSenhas(aux,Todos,TodosP,TodosP);
    fprintf(fp, "Quantidade de Senhas: %i", a);                     //envia para o .txt o print da quantidade de senhas

    if(!empty_queuelista(lista))                                    //se a lista estiver vazia
    {
        aux = lista->primeiro;                                      //aponta para o primeiro nó da lista
        do
        {
            fprintf(fp,"Balcao: %c\n", aux->dados->Balcao);         //envia para o .txt o print
            fprintf(fp,"Numero de Senha: %i\n", aux->dados->Id);    //envia para o .txt o print
            fprintf(fp,"Status: %d\n", aux->dados->status);         //envia para o .txt o print
            fprintf(fp,"Prioridade: %d\n", aux->dados->prioridade); //envia para o .txt o print

            aux1 = gmtime(&aux->dados->HoraEntrada);                //converte time_t para struct tm da HoraEntrada
            fprintf(fp,"Hora de Entrada: %i/%i/%i %i:%i:%i\n",aux1->tm_year+1900, aux1->tm_mon+1, aux1->tm_mday, aux1->tm_hour+1, aux1->tm_min, aux1->tm_sec);
            if(aux->dados->status != Desistente)                    //se o status for desistente
            {
                aux1 = gmtime(&aux->dados->HoraAtendimento);       //converte time_t para struct tm da HoraAtendimento
                fprintf(fp,"Hora de Atendimento: %i/%i/%i %i:%i:%i\n", aux1->tm_year+1900, aux1->tm_mon+1, aux1->tm_mday, aux1->tm_hour+1, aux1->tm_min, aux1->tm_sec);
                aux1 = gmtime(&aux->dados->HoraSaida);             //converte time_t para struct tm da HoraSaida
                fprintf(fp,"Data de Saida: %i/%i/%i %i:%i:%i\n", aux1->tm_year+1900, aux1->tm_mon+1, aux1->tm_mday, aux1->tm_hour+1, aux1->tm_min, aux1->tm_sec);

            }

            fprintf(fp,"\n");                                      //envia para o .txt um paragrafo
            aux = aux->next;                                       //aponta para o nó seguinte
        }
        while(aux != NULL);                                        //enquanto o aux for diferente de vazio
    }
    fprintf(fp,"\n");
    fclose(fp);                                                   //fecha o arquivo fp
    printf("Ficheiro gravado com sucesso!!!\n\n");                //printa que foi gravado com sucesso para o utilizador
}
