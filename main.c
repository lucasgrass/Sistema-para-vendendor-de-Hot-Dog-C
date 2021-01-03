#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "HotDog_Lista.h"
#include "Pedidos_Fila.h"
#include "Pedidos_Pilha.h"
#include <locale.h>

Lista *AnotarPedido(Lista *Recebida,int *VetorTempoEntrega[], int *VerificaRegiao[], int AuxRandom, int AuxRandom2); /// Anota novo pedido

Lista *AnotarPedidoA(Lista *Recebida, int *VetorTempoEntrega[], int AuxControle, int AuxRandom, int AuxRandom2); /// anota novo pedido de forma automatizada e aleatória

Lista *CadastroPonto(Lista *Aux, int *AuxControle[]); /// cadastra novo ponto

Lista *CadastroPontoA(Lista *Original, int *AuxControle[], int *AuxTempoEntrega[], int AuxRandom, int AuxRandom2); /// cadastra novo ponto de forma aleatoria e automatizada

void ConcluirPedido(Lista *OriginalLista, int *VetorTempo[], int *VerificaRegiao[]); /// conclui pedido de acordo com a regiao selecionada

void CancelaPedidoMain(Lista *OriginalLista); /// cancela pedido pelo numero + Região do pedido

int Menu(void); /// menu inicial

int MenuR(void);/// menu de regiões

int MenuRImpressao(void); /// menu de regiões com + algumas funcionalidades;

void Relatorio(Lista *Original, int AuxRegioes[]);/// imprime relatorio de acordo com desejo do cliente



///MAIN----------------------------------------------------------------------------------------------------------------------------------------------------
int main(void)
{

    int Opcao, QuantidaPontosA, *VerificaRegiao[6] = {0}, *AuxTempoEntrega[6] = {0}, AuxRandom = 100, AuxRandom2 = 3;
    Lista *PontosVenda = inicializa();

/**
int Opcao;              /// Variavel controladora do switch case;
int QuantidadePontosA   /// Variavel gerada de forma aleatoria entre 1 a 5 para definir o numero de pontos a ser gerados
int *VerificaRegiao[6]; /// Controle para saber quais pontos de venda já foram ocupado.
int *AuxTempoEntrega[6];/// Controle para saber o tempo de entrega do pedido anterior ao que esta sendo feito
int AuxRandom = 100 e AuxRendom2 = 3 /// são duas variaveis para evitar ocorrencia de numeros aleatorios repetidos ao gerar numero de pedidos
Lista *PontosVenda /// Lista responsavel por todas informações dos pontos de vendas
*/

    srand(time(NULL)); ///Faz com que numeros aleatórios nao se repitam

    setlocale(LC_ALL, "Portuguese");///Acesso a lingua portuguesa no programa




    while (Opcao != 0) /// Repetir o programa até que o usuario finalize
    {

        do
        {
            Opcao = Menu();
        }
        while (Opcao < 0 || Opcao > 6);///Evitar numeros incorretos

        switch (Opcao)///Usado para acesso da função selecionada pelo usuario
        {
            case 1:///Cadastro Ponto

                PontosVenda = CadastroPonto(PontosVenda, VerificaRegiao);
                /// Cadastro de um novo ponto de venda sendo 1 por região

                break;

            case 2:///Anota novo pedido

                PontosVenda = AnotarPedido(PontosVenda, AuxTempoEntrega, VerificaRegiao, AuxRandom, AuxRandom2);
                ///Função anota o pedido dentro da Fila e Pilha na Lista selecionada

                AuxRandom2 += + 3;
                AuxRandom += + AuxRandom2;
                ///Soma para evitar ocorrecia de numero de pedido repetido

                break;

            case 3:///Finaliza pedido

                ConcluirPedido(PontosVenda, AuxTempoEntrega, VerificaRegiao);
                ///Finaliza o 1 pedido da fila a partir da regiao escolhida

                break;

            case 4:///Cancela pedido

                CancelaPedidoMain(PontosVenda);
                ///Cancela pedido pelo numero do pedido e região

                system("pause");
                break;


            case 5:///Imprimi relatórios

                Relatorio(PontosVenda, VerificaRegiao);
                ///Printa relatório de acordo com as opções do usuario
                break;

            case 6:/// teste automatizado
                QuantidaPontosA = (1 + rand() % 5);/// gera numero entre 1 a 5

                for (int i = 0; i < QuantidaPontosA; i++)
                {

                    system("cls");

                    PontosVenda = CadastroPontoA(PontosVenda,VerificaRegiao,AuxTempoEntrega,AuxRandom,AuxRandom2);
                    /// Cadastro os pontos de forma aleatoria e automatizada

                    int   PedidosA = (5 + rand() % 10);
                    /// gera numero de pedidos que serão anotados

                    for (int i = 0; i < PedidosA; i++)
                    {
                        PontosVenda = AnotarPedidoA(PontosVenda, AuxTempoEntrega, PontosVenda->RegiaoPonto, AuxRandom, AuxRandom2);
                        /// Anota os pedidos de forma automatizada e aleatória
                        AuxRandom2 += + 3;
                        AuxRandom += + AuxRandom2;

                    }

                }

                break;
        }

    }


}
///MAIN--------------------------------------------------------------------------------------------------------------------------------------------------




///Menu ==========================================================================================================================================================

int Menu(void) ///Menu de console para utilização do usuario
{
    int aux;
    system("cls");

    printf("-----------------------------------------------------------------------------------------------\n");
    printf("-----------------------------------HOT DOG PATRICIA'S------------------------------------------\n");
    printf("|----------------------------------------------------------------------------------------------|\n");
    printf("|                                   Cadastrar Ponto de Venda        [1]                        |\n");
    printf("|                                   Anotar Pedido                   [2]                        |\n");
    printf("|                                   Concluir Pedidos                [3]                        |\n");
    printf("|                                   Cancelar Pedidos                [4]                        |\n");
    printf("|                                   Relatório De Vendas             [5]                        |\n");
    printf("|                                   Teste Aleatório                 [6]                        |\n");
    printf("|                                   Sair                            [0]                        |\n");
    printf("|----------------------------------------------------------------------------------------------|\n");

    scanf("%d", &aux);

    return aux;

}

///Menu Regioes======================================================================================================================================================================

int MenuR(void) ///Menu de console para utilização do usuario
{
    int aux;
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("-----------------------------------HOT DOG PATRICIA'S------------------------------------------\n");
    printf("|----------------------------------------------------------------------------------------------|\n");
    printf("|                                    Regiao [1]                                                |\n");
    printf("|                                    Regiao [2]                                                |\n");
    printf("|                                    Regiao [3]                                                |\n");
    printf("|                                    Regiao [4]                                                |\n");
    printf("|                                    Regiao [5]                                                |\n");
    printf("|                                Menu anterior [0]                                             |\n");
    printf("|----------------------------------------------------------------------------------------------|\n");

    scanf("%d", &aux);
    return aux;
}

int MenuRImpressao(void)///Menu de console para utilização do usuario
{
    int aux;
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("-----------------------------------HOT DOG PATRICIA'S------------------------------------------\n");
    printf("|----------------------------------------------------------------------------------------------|\n");
    printf("|                                    Regiao [1]                                                |\n");
    printf("|                                    Regiao [2]                                                |\n");
    printf("|                                    Regiao [3]                                                |\n");
    printf("|                                    Regiao [4]                                                |\n");
    printf("|                                    Regiao [5]                                                |\n");
    printf("|                      Imprimir relatório de todas regiões [6]                                 |\n");
    printf("|                                Menu anterior [0]                                             |\n");
    printf("|----------------------------------------------------------------------------------------------|\n");

    scanf("%d", &aux);
    return aux;
}


///CADASTRO DOS PONTOS====================================================================================================================================

Lista *CadastroPonto(Lista *Aux, int *AuxControle[])///função para cadastro dos pontos de venda
{
    int  RegiaoCarrinho,Experiencia;

    /**int RegiaoCarrinho /// Regiao do ponto
        int Experiencia	   /// experiencia do dono do ponto*/


    do /// evita cadastro de pontos na mesma regiao
    {
        system("cls");
        RegiaoCarrinho = MenuR();///recebe a regiao do usuario

        if (RegiaoCarrinho == 0) /// caso usuario decida cancelar operação
        {
            return Aux;
        }

        if (AuxControle[RegiaoCarrinho] == 1) /// caso ja exista ponto na regiao impede o cadastro
        {
            printf("\nJa existe um ponte de venda nessa regiao\n");
            system("pause");

            RegiaoCarrinho = 10;
        }
        else
        {
            AuxControle[RegiaoCarrinho] = 1; /// devolve para main a nova região cadastrada
        }
    }
    while (RegiaoCarrinho < 1 || RegiaoCarrinho > 5); /// controla para que nao digitem regiões inexistentes

    do
    {
        system("cls");

        printf("\n Experiencia 1-[baixa] 2-[média] 3-[alta]:");
        scanf("%d", &Experiencia);
        /// armazena experiencia selecionada pelo usuario
    }
    while (Experiencia < 0 || Experiencia > 3); /// evita digitos incorretos de experiencia

    Aux = InsereCadastro(Aux, RegiaoCarrinho, Experiencia);
    /// chama de função que insere de fato o ponto na nossa Lista

    return Aux;
}


/// Cadastro dos pontos aleatorio=================================================================================================================================================


/** Repete cadastro de forma automatizada e aleatoria*/
Lista *CadastroPontoA(Lista *Original, int *AuxControle[], int *AuxTempoEntrega[], int AuxRandom, int AuxRandom2)
{
    srand(time(NULL));

    int  RegiaoCarrinho, Experiencia=(1 + rand() % 3);/// gera experiencia random

    do
    {
        RegiaoCarrinho = (1 + rand() % 5);/// gera regiao do carrinho de forma aleatoria


        if (AuxControle[RegiaoCarrinho] == 1)
        {

            RegiaoCarrinho = 999;
        }
        else
        {
            AuxControle[RegiaoCarrinho] = 1; /// devolve para main regiao cadastrada
        }
    }
    while (RegiaoCarrinho < 0 || RegiaoCarrinho > 5);
  /// impede ocorrencia de pontos repetidos


    printf("\n\n=====NOVO PONTO=====");

    printf("\n\n|   Regiao Do Novo Ponto - %d\n\n", RegiaoCarrinho);

    system("pause");

    system("cls");

    Original = InsereCadastro(Original, RegiaoCarrinho, Experiencia);

    /// insere o ponto na lista

    return Original;
}




/// Anotar pedido=================================================================================================================================================================
Lista *AnotarPedido(Lista *Recebida, int *VetorTempoEntrega[], int *VerificaRegiao[], int AuxRandom, int AuxRandom2)
{
    int AuxRegiaoPedido, AuxNPedido = 0, AuxQuantidade;

    float AuxValorUnit, AuxValorTotal;

    char AuxObservacoes[50], AuxDescricao[50] = "Cachorro Quente";

    /**int AuxRegiaoPedido /// Regiao do pedido
        int AuxNPedido     /// Numero do pedido gerado de forma aleatória
        int AuxQuantidade /// Quantidade do pedido selecionada pelo usuario

        float AuxValorUnit /// Valor unitario do cachorro quente  gerado de forma aleatoria
        float AuxValorTotal /// Valor unitario * quantidade do pedido.

        char Auxobsercoes /// possiveis obeservações do cliente
        char Descricao /// descrição padrão do pedido "Cachorro Quente"*/


    srand(time(NULL));/// evita repitição de numero aleatórios

    ///Informações necessarias------------------------------------------------------------------------------------------------------------------------------------------

    do
    {
        system("cls");

        AuxRegiaoPedido = MenuR();

        if (AuxRegiaoPedido == 0)/// caso usuario deseje cancelar operação
        {
            return Recebida;
        }

        srand(time(NULL));

        if (VerificaRegiao[AuxRegiaoPedido] == 0) /// verifica se tem atendimento na região
        {
            printf("\n\nDesculpe mas ainda não aendemos nessa região\n\n\n");
            system("pause");
        }
    }
    while (VerificaRegiao[AuxRegiaoPedido] != 1); /// caso nao atenda na região solicita outra

    AuxNPedido = (AuxRandom + (rand() % AuxRandom2)); /// gera o numero do pedido aleatorio

    printf("Numero do seu pedido:%d \n", AuxNPedido); /// informa o numero do pedido pro usuario

    printf("\nDigite a quantidade de Carrochos Quente o pedido: ");

    scanf("%d", &AuxQuantidade);

    /// armazena a quantidade de cachorros quentes solicitada pelo usuario

    srand(time(NULL));

    AuxValorUnit = ((10 + rand() % 5) + ((rand() % 100) / 100.00));

    /// gera o valor da unidade de forma aleatoria

    printf("\nValor Unitario de cada Cachorro Quente: %.2f", AuxValorUnit);

    AuxValorTotal = (AuxQuantidade * AuxValorUnit);

    printf("\nValor Total do pedido %d : %.2f", AuxNPedido, AuxValorTotal);

    /// informa pro usuario valor total do pedido

    printf("\nObservacoes do Pedido: ");

    fflush(stdin);

    gets(AuxObservacoes);

    ///armazena eventuais observações do cliente

    ///Busca Lista Correta --------------------------------------------------------------------------------------------------------------

    Lista *Aux = Recebida;///Lista auxiliar para evitar perda de informações

    while (Aux != NULL)
    {
        if (Aux->RegiaoPonto == AuxRegiaoPedido)
        {

            break;
        }
        Aux = Aux->prox;

    }

    /// ^ loop usado para selecionar a Lista correta

    ///inserção Fila -----------------------------------------------------------------------------------------------------------------------
    InsereFila(Aux->Pedidos, Recebida->experiencia, AuxRegiaoPedido, AuxDescricao, AuxQuantidade, AuxValorUnit, AuxObservacoes, AuxNPedido, VetorTempoEntrega);

    /// comando que insere pedido na fila e pilha;

    imprimeNotaFiscal(Aux->Pedidos); /// nota fiscal do pedido realizado

    system("pause");

    return Recebida;
}

/// Anotar pedido Aleatorio=================================================================================================================================================================


/// Realiza o comando anotar pedido de forma aleatoria e automatizada

Lista *AnotarPedidoA(Lista *Recebida, int *VetorTempoEntrega[], int AuxControle, int AuxRandom, int AuxRandom2)
{
    int AuxRegiaoPedido, AuxNPedido, AuxQuantidade;

    float AuxValorUnit;

    char AuxObservacoes[50] = "NULL", AuxDescricao[50] = "Cachorro Quente";

    AuxRegiaoPedido = AuxControle;

    AuxNPedido = (AuxRandom + (rand() % AuxRandom2));

    AuxQuantidade = (1 + rand() % 5);

    AuxValorUnit = (10 + rand() % 5);



    Lista *Aux = Recebida;

    while (Aux != NULL)
    {
        if (Aux->RegiaoPonto == AuxRegiaoPedido)
        {

            break;
        }
        Aux = Aux->prox;

    }

    InsereFila(Aux->Pedidos,Recebida->experiencia,AuxRegiaoPedido,AuxDescricao,AuxQuantidade,AuxValorUnit,AuxObservacoes,AuxNPedido,VetorTempoEntrega);
    imprimeNotaFiscal(Aux->Pedidos);
    system("pause");
    return Recebida;
}




/// cancelar pedido

/// função cancela um pedido a partir do seu numero

void CancelaPedidoMain(Lista *OriginalLista)
{

    int AuxNPedido, AuxRegiao;

/**
int AuxNpedido /// armazena numero do pedido que vai ser cancelado
int auxregião /// armazena região do pedido a ser cancelado
*/

    printf("Qual o numero do pedido que deseja Cancelar: ");
    scanf("%d", &AuxNPedido);

    /// armazena o numero do pedido a ser cancelado

    printf("\n\nQual a Região do Pedido:");
    scanf("%d", &AuxRegiao);

    /// armazena refião do pedido a ser cancelado

    Lista *Aux = OriginalLista;

    /// Lista auxiliar para preservar a lista originaç

    while (Aux != NULL)
    {
        if (Aux->RegiaoPonto == AuxRegiao)
        {

            break;
        }
            Aux = Aux->prox;
    }

    ///loop para achar a lista correta

    if (Aux == NULL)
    {
        printf("\n\n Verifique região do pedido \n\n");

        return;
    }

    system("cls");

    Aux->Pedidos = CancelaPedido(Aux->Pedidos,AuxNPedido);

    /// função que cancela o pedido

    printf("\n\n==========Pedidos Restantes ==========\n\n");

    imprimeFila(Aux->Pedidos);

    ///imprimi pedidos restantes


}


///concluir pedido
    /// Atender Pedido

    /**. Atender pedido: atendimento da fila de pedidos do ponto. Remove um a um os
    itens do pedido e exibe a nota fiscal (a ordem dos itens deve ser a ordem de
    remoção da pilha). Por fim, remove o pedido da fila e atualiza o valor total
    vendido do ponto;**/


void ConcluirPedido(Lista *OriginalLista, int *VetorTempo[], int *VerificaRegiao[])
{



    /// variaveis pedido

    int AuxRegiaoPedido,AuxQuantidadePedidos;

    float ValorTotalMain;

    /**
int auxregiaopedido /// armazena regiao que deve concluir o pedido
int auxquantidadepedidos /// atualiza na lista a quantidade de pedidos realizados

float valortotalmain /// atualiza o valor total na lista
*/

    do
    {
        system("cls");

        AuxRegiaoPedido = MenuR();

        if (AuxRegiaoPedido == 0) /// retorna para o menu anterior
        {
            return OriginalLista;
        }

        if (VerificaRegiao[AuxRegiaoPedido] == 0) /// impede o acesso a regioes que nao tem cadastro
        {
            AuxRegiaoPedido = 10;
        }

    }
    while (AuxRegiaoPedido < 0 || AuxRegiaoPedido > 5);

    /// verifica se o numero esta dentro do intervalo estabelecido

    Lista *Aux = OriginalLista;///Lista auxiliar para nao comprometer a lista original

    while (Aux != NULL)
    {
        if (Aux->RegiaoPonto == AuxRegiaoPedido)
        {

            break;
        }
        Aux = Aux->prox;

    }

    /// while responsavel por achar a lista correta de acordo com a região

        if (Aux->Pedidos->inicio == NULL)
    {
        printf("\n\nNÃO EXISTE PEDIDOS PARA ESSA REGIÂO\n\n");
        system("pause");
        return OriginalLista;
    }

    /// caso o pedido nao exista informa o usuario e aborta a operação

    AuxQuantidadePedidos = pop_QuantidadeProduto(Aux->Pedidos->inicio->ItensPedido);

    /// retira da pilha o valor para armazenar na lista

    ValorTotalMain = pop_ValorTotal(Aux->Pedidos->inicio->ItensPedido);

    /// retira da pilha para armazenar o valor na lista

    VetorTempo[AuxRegiaoPedido] = VetorTempo[AuxRegiaoPedido] - Aux->Pedidos->inicio->TempoEntrega;

    ///Corrige o tempo do pedido anterior no nosso array de controle

    imprimeNotaFiscalCancela(Aux->Pedidos);

    ///imprime nota fiscal do pedido cancelado

    Aux->Pedidos = liberaFila(Aux->Pedidos);

    ///corrige tempos de entrega e espaço de memorias

    Aux->VendasTotal += ValorTotalMain;

    Aux->QuantidadePedidos += AuxQuantidadePedidos;

    /// atualiza os valores da lista

    system("pause");

    system("cls");

    printf("==========PEDIDOS RESTANTES==========");

    imprimeFila(Aux->Pedidos);
    system("pause");

    /// imprime os pedidos que restam e atualiza o tempo de entrega

}


/// imprime relatório para o usuario de acordo com as suas opçoes

void Relatorio(Lista *OriginalLista, int AuxRegioes[])
{

    int flag, AuxNumPedido;

/**
int flag	  /// Flag utilizada para auxiliar o algoritmo
int AuxNumPedido /// Armazena numero do pedido
*/
    do
    {
        system("cls");
        flag = MenuRImpressao();

        if (flag == 0) /// caso usuario deseje retornar ao menu anterior
        {
            return;
        }

        if (flag == 6)/// imprime um resumo de todas as listas
        {
            imprimeLista(OriginalLista);
            return;
        }

        if (AuxRegioes[flag] == 0) /// impede caso nao exista ponto de antendimento na região
        {
            flag = 10;
        }

    }
    while (flag < 1 || flag > 6);

    /// controla para que o usuario siga o intervalo

    if (flag == 6)
    {
        imprimeLista(OriginalLista);
        return;
    }



    Lista *Aux = OriginalLista;///Lista auxiliar para nao perder informações da lista original

    while (Aux != NULL)
    {
        if (Aux->RegiaoPonto == flag)
        {

            break;
        }
        Aux = Aux->prox;

    }

    /// encontra a lista desejada de acordo com a regiao;

    imprimeListaParcial(Aux);

    /// imprime apenas as informações da struct lista


   do
    {
        system("cls");
        printf("Deseja consultar:\nTodos Pedidos Pendentes [1]\nConsultar Pedido especifico [2]\nVoltar [0]\n:");
        scanf("%d",&flag);

    }
    while (flag < 0 || flag > 2);

    /// while que verifica qual o proximo passo do usuario

    if(flag == 0) /// cancela operação
    {
        return;
    }

    else if(flag == 1)/// imprime todos os pedidos no ponto
    {
        imprimeFila(Aux->Pedidos);
        system("pause");
    }
    else/// caso usuario queira consultar pedido expecifico
    {
        printf("\n\n Digite o numero do pedido que deseja consultar: ");
        scanf("%d",&AuxNumPedido);
        system("cls");

        /// armazena numero do pedido


    Fila *AuxF = Aux->Pedidos;/// fila auxiliar para nao comprometer original




    while (AuxF->inicio != NULL)
    {
        if (AuxF->inicio->NumeroPedido == AuxNumPedido)
        {
            imprimeNotaFiscalRelatorio(AuxF);
            system("pause");
            return;
        }

        AuxF->inicio = AuxF->inicio->prox;

    }

    /// while responsavel por imprimir o pedido correto

    printf("\n\n\t\tPEDIDO INEXISTENTE VERIFIQUE NUMERO E REGIÃO\n\n");
    system("pause");

    /// caso pedido nao exista informa usuario e para a operação


    }




}




