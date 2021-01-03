#ifndef PEDIDOS_FILA_H_INCLUDED
#define PEDIDOS_FILA_H_INCLUDED
#include "Pedidos_Pilha.h"

typedef struct NoFila
{

    int   NumeroPedido;
    int   RegiaoPedido; /// Valor numerico que representa uma RegiaoPedido de entrega
    int   TempoEntrega; /// Tempo de entrega para cada pedido
    Pilha *ItensPedido; /// Itens do pedido de cada cliente/

    struct NoFila *prox;

} NoFila;

typedef struct fila
{
    NoFila *inicio;
    NoFila *fim;
} Fila;

/// Verifica se a fila esta vazia
int VaziaFila(Fila *Aux)
{
    if (Aux->inicio == NULL)
    {
        return 1;
    }
    return 0;

}

/// Funcao cria uma fila
Fila *CriaFila(void)
{
    Fila *Aux = (Fila *) malloc(sizeof(Fila));
    Aux->inicio = Aux->fim = NULL;
    return Aux;

}

/// Funcao que auxilia a criacao de um pedido
NoFila *Insere_NoFila(NoFila *fim, int AuxRegiaoPedido, char AuxDescricao[], int AuxQuantidadeProduto, float AuxValorUnitario,
                      char AuxObservacoes[], int AuxNumeroPedido)
{


    NoFila *Aux = (NoFila *) malloc(sizeof(NoFila));
    Aux->ItensPedido = (Pilha *)malloc(sizeof(Pilha));

    if (Aux->prox == NULL)
    {
        Aux->ItensPedido = CriaPilha();
    }

    Aux->RegiaoPedido = AuxRegiaoPedido;

    Aux->TempoEntrega = 20;

    Aux->NumeroPedido = AuxNumeroPedido;

    push(Aux->ItensPedido, AuxDescricao, AuxQuantidadeProduto, AuxValorUnitario, AuxObservacoes);

    Aux->prox = NULL;


    if (fim != NULL)
    {
        fim->prox = Aux;/* verifica se lista não estava vazia */
    }


    return Aux;
};


/// Funcao que anota o pedido
void InsereFila(Fila *Aux, int AuxExperiencia, int AuxRegiaoPedido, char AuxDecricao[], int AuxQuantidadeProduto,
                float AuxValorUnitario, char AuxObservacoes[], int AuxNumeroPedido, int *VetorTempoEntrega[])
{

    Aux->fim = Insere_NoFila(Aux->fim, AuxRegiaoPedido, AuxDecricao, AuxQuantidadeProduto, AuxValorUnitario, AuxObservacoes,
                             AuxNumeroPedido);


    if (Aux->inicio == NULL) /* fila antes vazia? */
    {
        Aux->inicio = Aux->fim;
    }
    CalculoTempEntrega(Aux, VetorTempoEntrega, AuxExperiencia, AuxQuantidadeProduto);



};

///Funcao que auxilia o cancelamento de um pedido
NoFila *Insere_NoFilaCancela(NoFila *fim, int AuxRegiaoPedido, char AuxDescricao[], int AuxQuantidadeProduto,
                             float AuxValorUnitario, char AuxObservacoes[], int AuxNumeroPedido, int AuxTempoEntrega)
{


    NoFila *Aux = (NoFila *) malloc(sizeof(NoFila));
    Aux->ItensPedido = (Pilha *)malloc(sizeof(Pilha));
    Aux->RegiaoPedido = AuxRegiaoPedido;
    Aux->TempoEntrega = AuxTempoEntrega;

    Aux->NumeroPedido = AuxNumeroPedido;

    push(Aux->ItensPedido, AuxDescricao, AuxQuantidadeProduto, AuxValorUnitario, AuxObservacoes);

    Aux->prox = NULL;

    if (fim != NULL)
    {
        fim->prox = Aux;/* verifica se lista não estava vazia */
    }
    return Aux;
};



/// Funcao que cancela um pedido
void InsereFilaCancela(Fila *Aux, int AuxRegiaoPedido, char AuxDecricao[], int AuxQuantidadeProduto, float AuxValorUnitario,
                       char AuxObservacoes[], int AuxNumeroPedido, int AuxTempoEntrega)
{

    Aux->fim = Insere_NoFilaCancela(Aux->fim, AuxRegiaoPedido, AuxDecricao, AuxQuantidadeProduto, AuxValorUnitario, AuxObservacoes,
                                    AuxNumeroPedido, AuxTempoEntrega);


    if (Aux->inicio == NULL) /* fila antes vazia? */
    {
        Aux->inicio = Aux->fim;
    }

}



///Funcao que imprime um pedido
void imprimeFila(Fila *Aux)
{
    if (VaziaFila(Aux) == 1)
    {
        printf("\n\n Não Há Pedidos \n\n");
    }
    else
    {

        NoFila *N;
        for (N = Aux->inicio ; N != NULL ; N = N->prox)
        {


            printf("\n");
            printf("Numero do pedido - %d \n", N->NumeroPedido);
            printf("Regiao do pedido - %d \n", N->RegiaoPedido);
            printf("Tempo de entrega - %d \n", N->TempoEntrega);
            ImprimePilha(N->ItensPedido);
        }
    }


}

///Funcao que imprime os dados de um pedido
void imprimeNotaFiscal(Fila *Aux)
{
    if (VaziaFila(Aux) == 1)
    {
        printf("\n\nNão Há Pedidos\n\n");
    }
    else
    {

        NoFila *N;
        for (N = Aux->fim ; N != NULL; N = N->prox)
        {
            system("cls");
            printf("\n\n\n============NOTA FISCAL============");
            printf("\n");
            printf("|   Numero do pedido - %d \n", N->NumeroPedido);
            printf("|   Regiao do pedido - %d \n", N->RegiaoPedido);
            printf("|   Tempo de entrega - %d Minutos - \n", N->TempoEntrega);
            ImprimePilha(N->ItensPedido);
            printf("\n====================================\n\n\n\n");
            break;
        }
    }


}

///Funcao que imprimi os pedidos para o relatorio
void imprimeNotaFiscalRelatorio(Fila *Aux)
{
    if (VaziaFila(Aux) == 1)
    {
        printf("\n\nNão Há Pedidos\n\n");
    }
    else
    {

        NoFila *N;
        for (N = Aux->inicio ; N != NULL; N = N->prox)
        {
            system("cls");
            printf("\n\n\n============NOTA FISCAL============");
            printf("\n");
            printf("|   Numero do pedido - %d \n", N->NumeroPedido);
            printf("|   Regiao do pedido - %d \n", N->RegiaoPedido);
            printf("|   Tempo de entrega - %d Minutos \n", N->TempoEntrega);
            ImprimePilha(N->ItensPedido);
            printf("\n====================================\n\n\n\n");
            break;
        }
    }


}

///Funcao que imprimi a nota fiscal do pedido cancelado
void imprimeNotaFiscalCancela(Fila *Aux)
{
    if (VaziaFila(Aux) == 1)
    {
        printf("Fila Vazia\n\n");
    }
    else
    {

        NoFila *N;
        for (N = Aux->inicio; N != NULL; N = N->prox)
        {
            system("cls");
            printf("\n\n\n============NOTA FISCAL============");
            printf("\n");
            printf("|   Numero do pedido - %d \n", N->NumeroPedido);
            printf("|   Regiao do pedido - %d \n", N->RegiaoPedido);
            printf("|   Tempo de entrega - PRONTO PARA ENTREGA \n");
            ImprimePilha(N->ItensPedido);
            printf("\n\n\n===================================");

            printf("\n\n\n\tPATRICIA´s AGRADECE A PREFERENCIA\n\n\n");
            break;
        }
    }


}

///Funcao que libera uma fila
Fila *liberaFila(Fila *Aux)
{
    Fila *Flag = Aux;
    NoFila *Flag2 = Aux->inicio->prox;

    while (Flag2 != NULL)
    {
        Flag2->TempoEntrega = Flag2->TempoEntrega - Flag->inicio->TempoEntrega;
        Flag2 = Flag2->prox;
    }
    Aux->inicio = Aux->inicio->prox;

    return Aux;
}

///Funcao que cancela um pedido
Fila *CancelaPedido(Fila *Original, int AuxNumeroPedido)
{

    Fila *Nova = CriaFila();

    int AuxRetiraTempo = 0, AuxCalculoTempo,flag=0;



    while (Original->inicio != NULL)
    {


        if (Original->inicio->NumeroPedido != AuxNumeroPedido)
        {


            AuxCalculoTempo = Original->inicio->TempoEntrega;

            InsereFilaCancela(Nova, Original->inicio->RegiaoPedido, Original->inicio->ItensPedido->Primeiro->Descricao,
                              Original->inicio->ItensPedido->Primeiro->QuantidadeProduto, Original->inicio->ItensPedido->Primeiro->ValorUnitario,
                              Original->inicio->ItensPedido->Primeiro->Observacoes, Original->inicio->NumeroPedido,
                              Original->inicio->TempoEntrega - AuxRetiraTempo);


        }
        else
        {
            printf("========= PEDIDO CANCELADO ==========\n");
            imprimeNotaFiscalCancela(Original);
            AuxRetiraTempo = Original->inicio->TempoEntrega - AuxCalculoTempo;
            system("pause");
            system("cls");
            flag = 1;

        }

        Original->inicio = Original->inicio->prox;

    }

    if (flag == 0)
    {
        printf("\n\n\n PEDIDO NÂO EXISTE\n\n\n");
    }

    return Nova;


}

///Funcao que calcula o tempo de entrega
void CalculoTempEntrega(Fila *Original, int *VetorTempoEntrega[], int AuxExperiencia, int AuxQauntidadePedido)
{

    Fila *FAux = Original;


    if (AuxExperiencia == 1)
    {
        FAux->fim->TempoEntrega = FAux->fim->TempoEntrega + (5 * AuxQauntidadePedido);
    }
    else
    {
        FAux->fim->TempoEntrega = FAux->fim->TempoEntrega + ((5 - (AuxExperiencia * 3 / 3)) * AuxQauntidadePedido);
    }

    VetorTempoEntrega[FAux->fim->RegiaoPedido] += FAux->fim->TempoEntrega ;
    FAux->fim->TempoEntrega =  VetorTempoEntrega[FAux->fim->RegiaoPedido];
    FAux->fim->TempoEntrega = FAux->fim->TempoEntrega / 4;
};


#endif // PEDIDOS_FILA_H_INCLUDED
