#include <string.h>
#include <stdio.h>
#include "funcoes.h"
#include "item.h"


Produto produtos[MAX_PRODUTOS];		//vetor de produtos

void menu(){
	int op;
	do
	{
		system("cls");
		printf("\n----------Menu----------\n");
		printf("\n1 - Cadastrar produto\n2 - vender item\n3 - Produtos vendidos\n4 - Pesquisar produtos\n5 - estoque disponivel\n0 - Sair\n");
		printf("\n------------------------\n");

		scanf("%d", &op);
		getchar();

		switch(op){
		case 1:
			cadastrar();
			break;
		case 2:
			vender();
			break;
		/*case 3:
			vendidos();
			break;*/
		case 4:
			pesquisar();
			break;
		case 5:
			estoque();
			break;
		}
		getchar();

	} while (op != 0);

}

void cadastrar(){
	
	char produto[MAX_PRODUTOS];
	float precos;
	int quantidade;
	int op;
do
	{
		system("cls");
        printf("\n----------Cadastrar produtos----------\n");
		printf("\nNome do produto: ");
		fgets(produto, sizeof(produto), stdin); 				//conta automaticamente o tamanho do produto
		produto[strcspn(produto, "\n")] = '\0'; // Remove o '\n' da string produto
		printf("Digite o preco: ");
		scanf("%f", &precos);
		printf("Digite a quantidade: ");
		scanf("%d", &quantidade);
	
		//---------------------------------------------- enviando os lançamentos para o vetor produtos
		int i;
		for (i = 0; i < MAX_PRODUTOS; ++i){
			if (produtos[i].disponivel == 0)
			{
				produtos[i].precos = precos;
				produtos[i].quantidade = quantidade;
				strcpy(produtos[i].produto, produto);
				produtos[i].disponivel = 1;
				produtos[i].status = 1;
				break;
			}
		}
		//---------------------------------------------- menu de opções que fica embaixo
		printf("\nAdicionado(s) [%d] [%s] ao estoque!\n",quantidade,produto);
		printf("\n1 - Adicionar novo produto\n0 - Menu principal\n");
		scanf("%d", &op);
	} while (op != 0);
}

//---------------------------------------------------------------função vender
void vender(){

	int codigo;
	int qtde, qVendas = 0;

	estoque();
	printf("\n Digite o codigo do produto para vender: ");
	scanf("%d", &codigo);
	printf("\n Digite a quantidade: ");
	scanf("%d", &qtde);
	--codigo;

	if (qtde <= produtos[codigo].quantidade )           // se a qtde for menor ou igual do que estoque estao da pra vender
	{
		produtos[codigo].quantidade -= qtde;

		qVendas++;
		//vendidos(codigo, qtde);						//Atribui no historico de vendas
		printf("\n Produto vendido!\n");
	}
	else printf("\nProduto sem estoque");

	if (produtos[codigo].quantidade == 0)
	{
		produtos[codigo].disponivel = 0;			//Qtde zerada retira o produto do estoque
	}
	getchar();

}

//Produto historico[qVendas]; //alocação dinamica aqui

//----------------------------------------------------------função pra retornar o histórico de vendas
/*void vendidos(){

	char vendas[qVendas];
	float precos;
	int quantidade;







}*/







/*void vendidos(){

	system("cls");
	float media;
	printf("\nLISTA DE PRODUTOS VENIDOS\n");

	for (int i = 0; i < MAX_PRODUTOS; ++i)
	{
		if (produtos[i].disponivel == 1)
		{
			media = 0;
			media = produtos[i].precos[0] + produtos[i].precos[1] + produtos[i].precos[2] + produtos[i].precos[3];
			media = media / 4;
			if (media < 7.0)
			{
				printf("codigo: %d\n", i + 1);
				printf("produto: %s\n", produtos[i].produto);
				printf("1 Bim: %0.2f\n", produtos[i].precos[0]);
				printf("2 Bim: %0.2f\n", produtos[i].precos[1]);
				printf("3 Bim: %0.2f\n", produtos[i].precos[2]);
				printf("4 Bim: %0.2f\n", produtos[i].precos[3]);
				printf("\n------------------------\n");
			}
			
		}	
	}
}*/

//-----------------------------------------------------------------------funcção pra pesquisar um item no estoque
void pesquisar(){
	system("cls");
	char produto[MAX_PRODUTOS];
	int op;
	do
	{
		system("cls");
		printf("\n Digite nome do produto: ");
		fgets(produto, sizeof(produto), stdin);
		int i;
		for (i = 0; i < MAX_PRODUTOS; ++i)
		{
			if (strstr(produtos[i].produto, produto) != NULL)
			{
				printf("Codigo: %d\n", i + 1);
				printf("Produto: %s\n", produtos[i].produto);
				printf("Preco: %0.2f\n", produtos[i].precos);
				printf("Preco: %d\n", produtos[i].quantidade);
				printf("\n------------------------\n");
			}
		}
		printf("\n1 - Nova pesquisa\n0 - Sair\n");
		scanf("%d", &op);
		getchar();		
	} while (op != 0);


}

//----------------------------------------------------------------------- função para verificar todo o estoque
void estoque(){
	system("cls");
	printf("\nLISTA DE PRODUTOS\n");
	int op;
	do
	{	int i;
		for (i = 0; i < MAX_PRODUTOS; ++i)
		{
			if (produtos[i].disponivel == 1)
			{
				printf("Codigo: %d\n", i + 1);
				printf("Produto: %s\n", produtos[i].produto);
				printf("Preco: %0.2f\n", produtos[i].precos);
				printf("Quantidade: %d\n", produtos[i].quantidade);
				printf("\n------------------------\n");
			}
			
		}

		printf("\n0 - Sair\n");
		scanf("%d", &op);
	} while (op != 0);

}
