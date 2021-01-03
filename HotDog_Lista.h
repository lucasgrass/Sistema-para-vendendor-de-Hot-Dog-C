#ifndef HOTDOG_FILA_H_INCLUDED
#define HOTDOG_FILA_H_INCLUDED
#include "Pedidos_Fila.h"
#include "Pedidos_Pilha.h"

struct lista
{

    int RegiaoPonto;       /// Regiao da barraca
    int experiencia;       /// Nivel da regiao em preparo de cachorro-quente
    int QuantidadePedidos; /// Quantidade de pedidos realizados
    float VendasTotal;        /// Valor total vendido
    Fila *Pedidos;

    struct lista *prox;
};

typedef struct lista Lista;


/// Funcao que inializia uma lista
Lista *inicializa()
{

    return NULL;

}

/// Funcao para cadastrar um ponto
Lista *InsereCadastro(Lista *recebida, int AuxRegiaoPonto, int AuxExperiencia)
{

    Lista *novo;

    novo = (Lista *)malloc(sizeof(Lista));

    novo->RegiaoPonto = AuxRegiaoPonto;

    novo->experiencia = AuxExperiencia;

    novo->VendasTotal = 0;

    novo->QuantidadePedidos = 0;

    novo->Pedidos = CriaFila();

    novo->prox = recebida;

    return novo;
}

/// Funcao que imprime as informacoes de um ponto
void imprimeListaParcial(Lista *recebida)
{


    if (recebida == NULL)
    {
        printf("Lista vazia");
        system("pause");
    }

    Lista *p = recebida;

    printf(" Regiao = %d \n",p->RegiaoPonto);
    printf(" Experiencia = %d \n",p->experiencia);
    printf(" Quantidade de Pedidos = %d \n",p->QuantidadePedidos);
    printf(" Vendas totais em R$ = %.2f \n",p->VendasTotal);

    system("pause");

}

/// Imprimi o relatorio de cada ponto
void imprimeLista(Lista *recebida)
{


    if (recebida == NULL)
    {
        printf("\n\nNão Há Pedidos\n\n");
        system("pause");
    }
    system("cls");

    for (Lista *p = recebida ; p != NULL ; p = p->prox)
    {
        printf("\n\n==========Relatório===========\n\n");
        printf(" Regiao = %d \n", p->RegiaoPonto);
        printf(" Experiencia = %d \n", p->experiencia);
        printf(" Quantidade de Pedidos = %d \n", p->QuantidadePedidos);
        printf(" Vendas totais em R$ = %.2f \n", p->VendasTotal);
    }
    system("pause");

}

/// Verifica se a lista esta vazia
int VaziaLista(Lista *recebida)
{

    if (recebida == NULL)
    {

        return 1;

    }

    else
    {

        return 0;
    }

}







#endif // HOTDOG_FILA_H_INCLUDED
