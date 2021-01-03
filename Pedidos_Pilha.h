#ifndef PEDIDOS_PILHA_H_INCLUDED
#define PEDIDOS_PILHA_H_INCLUDED
#include <string.h>

typedef struct NoPilhas
{
    char  Descricao[50];         /// Descricao do produto
    int   QuantidadeProduto;   /// Quantidade do produto
    float ValorUnitario;       /// Valor de cada produto
    float ValorTotal;          /// Valor total da compra
    char  Observacoes[50];       /// Observacoes do pedido
    struct NoPilhas *prox;
} NoPilha;

typedef struct pilha
{
    NoPilha *Primeiro;

} Pilha;

///Funcao que cria uma pilha
Pilha *CriaPilha(void)
{
    Pilha *p;
    p = (Pilha *)malloc(sizeof(Pilha));
    p->Primeiro = NULL;
    return p;
};

///Funcao que auxilia a insercao
NoPilha *Cria_NoPilha(NoPilha *endereco, char AuxDescricao[], int AuxQuantidadeProduto, float AuxValorUnitario, char AuxObservacoes[])
{

    NoPilha *aux2 = (NoPilha *) malloc(sizeof(NoPilha));
    strcpy(aux2->Descricao, AuxDescricao);
    aux2->QuantidadeProduto = AuxQuantidadeProduto;
    aux2->ValorUnitario = AuxValorUnitario;
    aux2->ValorTotal = AuxQuantidadeProduto * AuxValorUnitario;
    strcpy(aux2->Observacoes, AuxObservacoes);
    aux2->prox = endereco;
    return aux2;

};

///Funcao que insere os dados na pilha
void push(Pilha *Original,  char AuxDescricao[], int AuxQuantidadeProduto, float AuxValorUnitario, char AuxObservacoes[])
{
    Original->Primeiro = Cria_NoPilha(Original->Primeiro, AuxDescricao, AuxQuantidadeProduto, AuxValorUnitario, AuxObservacoes);

};


float pop_ValorTotal(Pilha *p)
{
    float AuxValorTotal;

    if (p == NULL)
    {
        printf("Pedido nao existe.\n");

        return 0;
    }

    AuxValorTotal = p->Primeiro->ValorTotal;

    return AuxValorTotal;
};



int pop_QuantidadeProduto(Pilha *p)
{
    int AuxQuantidadeProduto;

    if (p == NULL)
    {
        printf("Pedido nao existe.\n");
        return 0;
    }

    AuxQuantidadeProduto = p->Primeiro->QuantidadeProduto;

    return AuxQuantidadeProduto;
};




///Funcao que imprimi a pilha
void ImprimePilha(Pilha *Aux)
{

    NoPilha *Imprime = Aux->Primeiro;
    if (!Aux->Primeiro)
    {
        printf("Pilha vazia\n\n\n");

    }
    else
    {
        printf("\n|   ");
        puts(Imprime->Descricao);
        printf("|   Quantidade de produto: %d", Imprime->QuantidadeProduto);
        printf("\n|   Unitario: %.2f", Imprime->ValorUnitario);
        printf("\n|   Total: %.2f", Imprime->ValorTotal);
        printf("\n|   Obeservacoes: ");
        puts(Imprime->Observacoes);
    }
};

///Funcao que verifica se a pilha esta vazia
int VaziaPilha(Pilha *Aux)
{
    if (!Aux->Primeiro)
    {
        return 1; //pilha vazia
    }
    return 0;
};

#endif // PEDIDOS_PILHA_H_INCLUDED
