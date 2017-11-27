//**************************************************************//
// Engenharia Informática - Algoritmos e Estruturas de Dados    //
// Projeto - Gestão de Filas de Espero                          //
// Data- 12/06/2015                                             //
// Docente - Sérgio Correia                                     //
// Álvaro Benjamim - 16372                                      //
// Frederico Balcão - 15307                                     //
// Estatisticas.c                                               //
//**************************************************************//

#include "Estatisticas.h"

/*---------------------------------------------------------------------------------------------------*/
/* Função calcula o numero de senhas                                                                 */
/* Parametros: ponteiro aux do tipo No, um balcao do tipo char, status e prioridade do tipo inteiro  */
/*---------------------------------------------------------------------------------------------------*/
int NumeroSenhas (No * aux, char balcao, int status,  int prioridade)
{
    int count = 0;

    do
    {
        if(balcao!=Todos && aux->dados->Balcao == balcao)                         // verifica se é um balcao
        {
            if (status==Desistente && aux->dados->status == status)               // verifica se o status é Desistente
            {
                count++;                                                          // conta o numero de senhas desistentes
            }
            else if(status == Normal && aux->dados->status == status)             // verifica se o status é Normal
            {
                if(prioridade==TodosP)
                {
                    count++;                                                      // conta o numero de senhas atendidas
                }
                else
                {
                    if(aux->dados->prioridade == prioridade)                      // verifica a prioridade da senha
                    {
                        count++;                                                  // conta o numero de senhas por a prioridade
                    }
                }
            }
            else if(status == TodosP)                                             //se status for TodosP
            {
                count++;                                                          //conta o numero de senhas por total
            }
        }

        else if(balcao==Todos)                                                    // verifica se sao todos os balcao
        {
            if (status==Desistente && aux->dados->status == status)               // verifica se o status é Desistente
            {
                count++;                                                          // conta o numero de senhas desistentes
            }
            else if(status == Normal && aux->dados->status == status)             // verifica se o status é Normal
            {
                if(prioridade==TodosP)
                {
                    count++;                                                      // conta o numero de senhas atendidas
                }
                else
                {
                    if(aux->dados->prioridade == prioridade)
                    {
                        count++;                                                  // conta o numero de senhas por prioridade
                    }
                }
            }
            else if(status == TodosP)
            {
                count++;
            }
        }
        aux = aux->next;
    }
    while (aux != NULL);

    return count;
}


/*---------------------------------------------------------------------------------------------------------------*/
/* Função que calcula o somatorio do tempo de senhas em espera                                                   */
/* Parametros: ponteiro aux do tipo No, um balcao do tipo char, status do tipo bool, prioridade do tipo inteiro  */
/*---------------------------------------------------------------------------------------------------------------*/
double TempoSenhas (No* aux, char balcao, bool status,  int prioridade)
{
    double diferencas=0;                                                     //diferencas do tipo double inicializada a 0

    do
    {
        if(balcao!=Todos && aux->dados->Balcao == balcao)                    // verifica se é um balcao
        {
            if(status == Normal && aux->dados->status == status)             // verifica se o status é Normal
            {
                if(prioridade==TodosP)
                {
                    diferencas += difftime(aux->dados->HoraAtendimento,aux->dados->HoraEntrada); //soma as diferencas com o difftime da HoraAtendimento e HoraEntrada
                }
                else
                {
                    if(aux->dados->prioridade == prioridade)                 // verifica a prioridade da senha
                    {
                        diferencas += difftime(aux->dados->HoraAtendimento,aux->dados->HoraEntrada);
                    }
                }
            }
        }

        else if(balcao==Todos)                                              // verifica se sao todos os balcao
        {
            if(status == Normal && aux->dados->status == status)            // verifica se o status é Normal
            {
                if(prioridade==TodosP)
                {
                    diferencas += difftime(aux->dados->HoraAtendimento,aux->dados->HoraEntrada);                                                        // conta o numero de senhas atendidas
                }

                else
                {
                    if(aux->dados->prioridade == prioridade)
                    {
                        diferencas += difftime(aux->dados->HoraAtendimento,aux->dados->HoraEntrada);
                    }
                }
            }
        }
        aux = aux->next;
    }
    while (aux != NULL);

    return diferencas;
}
/*----------------------------------------------------------------------------------------------------------------------*/
/* Função que informa o retirar a senha, quantas senhas tem á sua frente                                                */
/* e a hora provavel de atendimento                                                                                     */
/* Parametros: ponteiro fifo do tipo fifo, uma lista do tipo lista, um balcao do tipo char, prioridade do tipo inteiro  */
/*----------------------------------------------------------------------------------------------------------------------*/
void InformacaoUtilizador(FIFO *fifo, Lista *lista, char balcao, int prioridade)
{
    No *aux;                                                          //ponteiro aux do tipo No
    int count=0, count1=0;                                            //varaiveis para contagens inicializadas a 0
    double diferencas = 0, tempo = 0;                                 //variavel diferencas e tempo inicializadas a 0
    time_t HoraProvavel;                                              //HoraProvavel do tipo time_t

    if(!empty_queuelista(lista))                                      //se a lista nao estiver vazia
    {
        aux = lista->primeiro;                                        //aponta para o primeiro nó da lista
        if(prioridade == Prioritaria)                                 //se prioridade for do tipo Prioritaria
        {
            count = NumeroSenhas(aux,balcao,Normal,prioridade);        //conta o numero de senhas prioritarias
            diferencas = TempoSenhas(aux, balcao,Normal,prioridade);   //diferencas é igual ao cálculo do tempo das senhas com prioridade
        }
        else if(prioridade == TodosP)                                  //se a prioridade for dos dois (normal e prioritária)
        {
            count = NumeroSenhas(aux,balcao,Normal,TodosP);            //conta o numero de senhas pelo TodosP
            diferencas = TempoSenhas(aux, balcao,Normal,TodosP);       //diferencas é igual ao cálculo do tempo de senhas pelo TodosP
        }
        if(count != 0){                                                //se a contagem for diferente de 0
            tempo = diferencas/count;                                  //tempo é igual à divisão das diferencas pela contagem
        }
    }

    if(!empty_queue((fifo)))                                           //se a fifo nao estiver vazia
    {
        aux = fifo->primeiro;                                          //aponta para o primeiro nó da fifo
        if(prioridade == Prioritaria)
        {
            count1 = NumeroSenhas(aux,balcao,Normal,prioridade) - 1;   //conta o numero de senhas excepto o ultimo utilizador
            HoraProvavel = fifo->maior->dados->HoraEntrada;
        }
        else if(prioridade == TodosP)
        {
            count1 = NumeroSenhas(aux,balcao,Normal,TodosP) - 1;       //conta o numero de senhas excepto o ultimo utilizador
            HoraProvavel = fifo->ultimo->dados->HoraEntrada;
        }
        HoraProvavel += (tempo * count1);                             //HoraProvavel será calculada soma com a multiplicação do tempo calculado com a contagem
    }

    printInformacaoUtilizador(count1, HoraProvavel);                  //printa a informação do utilizador que recebe uma contagem e uma hora provavel
}

/*-----------------------------------------------------------------------------------------------------*/
/* Função que informa quantas senhas existem para serem atendidas e a hora provavel da ultima senha    */
/* Parametros: ponteiro fifo do tipo fifo, uma lista do tipo lista, um balcao do tipo char             */
/*-----------------------------------------------------------------------------------------------------*/
void InformacaoBalcao(FIFO *fifo, Lista *lista, char balcao)
{
    No *aux;
    int count = 0, count1 = 0;
    double diferencas = 0, tempo = 0;
    time_t HoraProvavel;

    if(!empty_queuelista(lista))                                //se a lista nao estiver vazia
    {
        aux = lista->primeiro;
        count = NumeroSenhas(aux,balcao,Normal,TodosP);
        diferencas = TempoSenhas(aux,balcao,Normal,TodosP);

        tempo = diferencas/count;
    }

    if(!empty_queue((fifo)))
    {

        aux = fifo->primeiro;
        count1 = NumeroSenhas(aux,balcao,Normal,TodosP);
        HoraProvavel = fifo->ultimo->dados->HoraEntrada;

        HoraProvavel = HoraProvavel + (tempo * count1);

    }
    PrintInformacaoBalcao(count1,HoraProvavel);                         //printa a informação do balcao que recebe uma contagem e uma hora provavel
}

/*---------------------------------------------------------------------------------------------------------------------------------------*/
/* Função que informa o alerta do tempo minimo ou máximo                                                                                 */
/* Parametros: ponteiro lista do tipo lista, ponteiro no do tipo no uma lista do tipo lista, um balcao do tipo char, tipo do tipo bool   */
/*---------------------------------------------------------------------------------------------------------------------------------------*/
void AlertaTempo(Lista *lista,No *no, char balcao, bool tipo)
{
    No *aux;
    double diferencas = 0, tempo, tempo1;

    if(!empty_queuelista(lista))                                     //se a lista não estiver vazia
    {
        aux = lista->primeiro;

        do
        {
            if(aux->dados->Balcao == balcao )
            {
                if (aux->dados->status == Normal)                    //status Normal
                {
                    diferencas = difftime(aux->dados->HoraSaida,aux->dados->HoraAtendimento); //diferencas é igual ao difftime da HoraSaida e HoraAtendimento

                    if(tempo < diferencas && tipo==Maximo)          //se o tempo for menor que as diferencas calculadas e o tipo for igual ao Maximo
                    {
                        tempo = difftime(aux->dados->HoraSaida,aux->dados->HoraAtendimento); //tempo é igual ao difftime da HoraSaida e HoraAtendimento
                    }
                    else if(tempo > diferencas && tipo == Minimo)   //se o tempo for maior que as diferencas calculadas e o tipo for igual ao Minimo
                    {
                        tempo = difftime(aux->dados->HoraSaida,aux->dados->HoraAtendimento); //tempo é igual ao difftime da HoraSaida e HoraAtendimento
                    }
                }
            }
            aux = aux->next;
        }
        while (aux != NULL);                                                 //até aux for diferente de vazio

        tempo1 = difftime(no->dados->HoraSaida,no->dados->HoraAtendimento);  //tempo1 é igual ao difftime da HoraSaida e HoraAtendimento

        if(tempo < tempo1 && tipo == Maximo)                                 //se o tempo anteriormente calculado for menor que o tempo1 e o tipo for igual ao Maximo
        {
            printAlertaTempo(Maximo);                                        //printa o Alerta do Tempo Maximo atinjido
        }
        else if(tempo > tempo1 && tipo == Minimo)                            //se o tempo anteriormente calculado for maior que o tempo1 e o tipo for igual ao Minimo
        {
            printAlertaTempo(Minimo);                                        //printa o Alerta do Tempo Minimo atinjido
        }
    }
}

/*---------------------------------------------------------------------*/
/* Função que informa o senhas entre datas dadas                       */
/* Parametros: ponteiro lista do tipo lista, um balcao do tipo char    */
/*---------------------------------------------------------------------*/
void Entredatas(Lista *lista, char balcao)
{
    No *aux;
    int countN = 0, countP=0, countD = 0;       //contagem senhas: countN- contagem senhas normais, countP - contagem senhas prioritarias, countD - contagem de senhas desistentes
    double diferencasN = 0, diferencasP = 0;    //diferencas Normais e diferencas Prioritarias
    double tempoN = 0, tempoP = 0;

    if(!empty_queuelista(lista))                         //se a lista nao estiver vazia
    {
        int ano = 0, mes = 0, dia = 0, ano1 = 0, mes1 = 0, dia1 = 0;   //ano, mes, dia para data inicial //ano1, mes1, dia1 para data final
        bool flag;                                                     //flag para verificações nas comparações entre as datas ao nivel da superioridade entre elas
        time_t tempo1, tempo2;                                         //tempo1 e tempo2 do tipo time_t
        struct tm data1;                                               //estrutura tm data1 para usar o mktime
        struct tm data2;                                               //estrutura tm data2 para usar o mktime

        PrintEntreDatas(Insere, INICIAL);                              //Print Insere data Inicial

        fflush(stdin);

        Cols(8);
        scanf("%i-%i-%i",&ano,&mes,&dia);                               //recebe a data inicial

        data1.tm_year = ano - 1900;                                     //desde o ano 1900 até ao ano inicial colocado
        data1.tm_mon = mes - 1;                                         //mes colocado menos 1
        data1.tm_mday = dia;
        data1.tm_hour = 0;
        data1.tm_min = 0;
        data1.tm_sec = 1;

        tempo1 = mktime(&data1);                                        //converte estrutura tm para time_t
        if(tempo1 == -1)
        {
            PrintEntreDatas(ERRO, INICIAL);                             //Print ERRO data Inicial
        }

        else
        {
            PrintEntreDatas(Insere, FINAL);                             //Print insere data Final
            fflush(stdin);
            Cols(8);
            scanf("%i-%i-%i",&ano1,&mes1,&dia1);                        //recebe a data final
            if(ano1 != 0 || mes1 != 0 || dia1 != 0)                     //se a data final inserida for diferente de 0
            {
                if((data1.tm_year + 1900) > ano1)                       //se o ano inicial for maior que o ano final
                {
                    flag=1;                                             //flag a 1
                    PrintEntreDatas(Verifica, D_ANO);                   //chama o Print EntreDatas que recebe a verificação e D_ANO (0)
                }

                if((data1.tm_year + 1900) == ano1)                      //se o ano inicial for igual ao ano final
                {
                    if((data1.tm_mon + 1) > mes1)                       //se o mes inicial for maior que o mes final
                    {
                        flag=1;                                         //flag a 1
                        PrintEntreDatas(Verifica, D_Mes);               //chama o Print EntreDatas que recebe a verificação e D_Mes (1)
                    }

                    if((data1.tm_mon + 1) ==mes1)                       //se o mes inicial for igual ao mes final
                    {
                        if(data1.tm_mday > dia1)                        //Se o dia inicial for maior que o dia final
                        {
                            flag=1;                                     //flag a 1
                            PrintEntreDatas(Verifica, D_Dia);           //chama o Print EntreDatas que recebe a verificação e D_Dia (2)
                        }
                    }
                }
            }
            if(flag==0)                                                 //se a flag for zero
            {
                data2.tm_year = ano1 - 1900;                            //desde o ano 1900 até ao ano final colocado
                data2.tm_mon = mes1 - 1;                                //mes final menos 1
                data2.tm_mday = dia1;
                data2.tm_hour = 23;                                     //para 0-23 horas
                data2.tm_min = 59;                                      //para 0-59 minutos
                data2.tm_sec = 59;                                      //para 0-59 segundos

                tempo2 = mktime(&data2);                                //converte estrutura tm para time_t
                if(tempo2 == -1)                                        //tempo2 for igual a -1
                {
                    PrintEntreDatas(ERRO, FINAL);                        //Print ERRO data Final
                }

                else
                {
                    aux = lista->primeiro;

                    do
                    {
                        if(aux->dados->Balcao == balcao )
                        {
                            if(aux->dados->HoraEntrada >= tempo1 && tempo2 >= aux->dados->HoraEntrada)
                            {
                                if(aux->dados->status == Normal)
                                {
                                    if (aux->dados->prioridade==Prioritaria)
                                    {
                                        diferencasP = diferencasP + difftime(aux->dados->HoraAtendimento,aux->dados->HoraEntrada);
                                        countP++;  //contagem das senhas prioritarias
                                    }
                                    if ( aux->dados->prioridade==Normal)
                                    {
                                        diferencasN = diferencasN + difftime(aux->dados->HoraAtendimento,aux->dados->HoraEntrada);
                                        countN++; //contagem das senhas normais
                                    }
                                }

                                else if (aux->dados->status == Desistente)
                                {
                                    //aqui não há necessidade de guardar as diferencas pelo difftime porque como é dessistente não tem HoraAtendimento nem HoraEntrada
                                    countD++; //contagem das senhas desistentes
                                }

                            }
                        }
                        aux = aux->next;
                    }
                    while (aux != NULL);

                    if(countN != 0)                                                         //se as contagens das senhas normais forem diferentes de zero
                    {
                        tempoN = diferencasN/countN;                                        // Tempo Medio das senhas Normais
                        PrintResultadoEntreDatas(countN, tempoN, SemPrioridade);            // print resultado ads senhas Normais
                    }

                    if(countP!=0)                                                            //se as contagens das senhas prioritarias forem diferentes de zero
                    {
                        tempoP = diferencasP/countP;                                         // Tempo Medio das senhas Prioritarias
                        PrintResultadoEntreDatas(countP, tempoP, ComPrioridade);             // print resultado das senhas Prioritarias
                    }

                    if(countD!=0)                                                            //se as contagens das senhas desistentes forem diferentes de zero
                    {
                        PrintResultadoEntreDatas(countD, 0, Desiste);                       // print resultado das senhas desistentes
                    }

                    if(countN == 0 && countP == 0 && countD == 0)
                    {
                        PrintResultadoEntreDatas(0, 0, Nenhum);                      // print resultado de nao haver senhas

                    }
                }
            }
        }
    }
}

/*---------------------------------------------------------------------*/
/* Função que informa as estatisticas das senhas                       */
/*---------------------------------------------------------------------*/
void Estatistica()
{
    char opcao1;
    system("cls");                                              //limpa a tela do ecrã

    do
    {
        opcao1 = MenuEstatisticas();                            //chama a função MenuEstatisticas

        switch(opcao1)
        {
        case '1':
            InformacaoSenhas(lst,Desiste);                      //Informação das senhas desistentes, recebe uma lista
            Cols(8);
            system("Pause");                                    //pausa
            break;
        case '2':
            InformacaoSenhas(lst,SemPrioridade);                //Informação das senhas sem prioridade (1)
            Cols(8);
            system("Pause");                                    //pausa
            break;
        case '3':
            InformacaoSenhas(lst,ComPrioridade);                 //Informação das senhas com prioridade (2)
            Cols(8);
            system("Pause");                                     //pausa
            break;

        case '4':
            BalcaoEstatisticas();                               //escolhe o balcao para EntreDatas
            Cols(8);
            system("Pause");

            break;

        case '0':
            break;
        }
    }
    while(opcao1 != '0');
}

/*---------------------------------------------------------------------*/
/* Função que informa as senhas entre datas de cada balcao             */
/*---------------------------------------------------------------------*/
void BalcaoEstatisticas()
{
    char opcao;
    system("cls");

    do
    {
        opcao= MenuBalcao();                //chama o MenuBalcao

        if (opcao == BalcaoA )              //se a opcao for igual ao Balcao A
        {
            Entredatas(lst,BalcaoA);        //calcula as senhas EntreDatas da lista criada e do Balcao A
        }

        else if (opcao == BalcaoB )         //se a opcao for igual ao Balcao B
        {
            Entredatas(lst,BalcaoB);        //calcula as senhas EntreDatas da lista criada e do Balcao B
        }

        else if (opcao == BalcaoC )         //se a opcao for igual ao Balcao C
        {
            Entredatas(lst,BalcaoC);        //calcula as senhas EntreDatas da lista criada e do Balcao C
        }

        else if (opcao == BalcaoD )         //se a opcao for igual ao Balcao D
        {
            Entredatas(lst,BalcaoD);        //calcula as senhas EntreDatas da lista criada e do Balcao D
        }
        else
        {
            break;                          //volta para o menu anterior
        }

    }
    while(opcao == '0');                    //enquanto a opcao for diferente de 0
}

/*-------------------------------------------------------------------------------------------------------------------*/
/* Função que informa a percentagem de desistencias e de senhas normais, numero de senhas e o numero total de senhas */
/*Parametros: ponteiro do tipo lista, tipo do tipo inteiro                                                           */
/*-------------------------------------------------------------------------------------------------------------------*/
void InformacaoSenhas(Lista *lista, int tipo)
{
    No *aux;
    float total = 0, status = 0, resultado;                         //variaveis para o total de NumeroSenhas, resultado das senhas

    if(!empty_queuelista(lista))                                    //se a lista nao estiver vazia
    {
        aux = lista->primeiro;

        total = NumeroSenhas(aux,Todos,TodosP,TodosP);              //total é igual ao numero de senhas totais de todos os balcões com total status e prioridade

        if(tipo == Desiste)                                         //se o tipo for Desiste
        {
            status = NumeroSenhas(aux,Todos,Desistente,TodosP);     //numero de senhas para todos os balcões com status Desistente
        }
        else if(tipo==SemPrioridade)                                //se o tipo for sem Prioridade
        {
            status = NumeroSenhas(aux,Todos,Normal,Normal);         //numero de senhas para todos os balcões com status Normal sem Prioridade
        }
        else if(tipo==ComPrioridade)                                //se o tipo for com Prioridade
        {
            status = NumeroSenhas(aux,Todos,Normal,Prioritaria);    //numero de senhas para todos os balcões com status desistente com Prioridade
        }

        resultado = (status/total) * 100;                           //calcula a percentagem
    }
    if(tipo == Desiste)                                             //se o tipo for Desiste
    {
        PrintInformacao(status, resultado, total, Desiste);         //printa a informação total do tipo Desiste
    }
    else if(tipo == SemPrioridade)                                  //se o tipo for sem Prioridade
    {
        PrintInformacao(status, resultado, total, SemPrioridade);   //printa a informação total do tipo sem Prioridade
    }
    else if(tipo == ComPrioridade)                                  //se o tipo for com Prioridade
    {
        PrintInformacao(status, resultado, total, ComPrioridade);   //printa a informação total do tipo com Prioridade
    }
}
