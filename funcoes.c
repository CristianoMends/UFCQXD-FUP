#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "item.h"


Produto produtos[MAX_PRODUTOS];		//vetor de produtos
Produto guardarVendas[MAX_PRODUTOS]; //vetor de vendas

void menu(){
	int op;
	do{
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
		case 3:
			historico();
			break;
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
	
	char nome[MAX_PRODUTOS];
	float preco;
	int quantidade;
	int op;
do
	{
		system("cls");
        printf("\n----------Cadastro de produtos----------\n");
		printf("Nome do produto: ");
		fgets(nome, sizeof(nome), stdin);

		//nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n' da string produto
		//************ o codigo acima impede a busca do produto*******//

		printf("Digite o preco: ");
		scanf("%f", &preco);
		getchar();
		printf("Digite a quantidade: ");
		scanf("%d", &quantidade);
		getchar();
	
		//---------------------------------------------- enviando os lancamentos para o vetor produtos
		int i;
		for (i = 0; i < MAX_PRODUTOS; ++i){
			if (produtos[i].disponivel == 0){
				produtos[i].preco = preco;
				produtos[i].quantidade = quantidade;
				strcpy(produtos[i].nome, nome);
				produtos[i].disponivel = 1;
				produtos[i].status = 1;
				break;
			}
		}
		//---------------------------------------------- menu de opcoess que fica embaixo
		printf("\nSTATUS: [%d] item(s) de [%s] cadastrado(s) ao estoque!\n",quantidade,nome);
		printf("\n1 - Cadastrar novo produto\n0 - Menu principal\n");
		scanf("%d", &op);
		getchar(); //irá consumir o caractere de nova linha restante no buffer de entrada após a leitura da variavel op com scanf
	} while (op != 0);
}

//---------------------------------------------------------------funcao vender
void vender(){

	int codigo;
	int qtde, qVendas = 0;

	estoque();
	printf("\n Digite o codigo do produto para vender: ");
	scanf("%d", &codigo);
	printf("\n Digite a quantidade: ");
	scanf("%d", &qtde);
	--codigo;

	if (qtde <= produtos[codigo].quantidade )           // se a qtde for menor ou igual do que estoque entao da pra vender
	{
		produtos[codigo].quantidade -= qtde;

		qVendas++;
		vendidos(&codigo, &qtde);						//Atribui no historico de vendas
		printf("\n Produto vendido!\n");
	}
	else printf("\nProduto sem estoque");

	if (produtos[codigo].quantidade == 0)
	{
		produtos[codigo].disponivel = 0;			//Qtde zerada retira o produto do estoque
	}
	getchar();

}

//----------------------------------------------------------funcao pra retornar o historico de vendas
void vendidos(int *codigo, int *qtde){

	for(int i = 0; i < MAX_PRODUTOS; i++){

		guardarVendas[i].nome = produtos[codigo].nome;
		guardarVendas[i].preco = produtos[codigo].preco;
		guardarVendas[i].qtde = qtde;
		break;
	}

}
//----------------------------------------------------------------------- mostrar historico
void historico(){

	system("cls");
	printf("\nPRODUTOS VENDIDOS\n");
	int op;
	do{	
		int i;
		for (i = 0; i < MAX_PRODUTOS; ++i){
	
			printf("Codigo: %d\n", i + 1);
			printf("Produto: %s\n", guardarVendas[i].nome);
			printf("Preco: %0.2f\n", guardarVendas[i].preco);
			printf("Quantidade: %d\n", guardarVendas[i].quantidade);
			printf("\n------------------------\n");
			
		}

		printf("\n0 - Sair\n");
		scanf("%d", &op);
	} while (op != 0);

}



//-----------------------------------------------------------------------funcao pra pesquisar um item no estoque
void pesquisar(){
	system("cls");
	char produto[MAX_PRODUTOS];
	int op;
	do{
		system("cls");
		printf("\n----------Pesquisa de produtos----------\n");

		printf("\n Digite nome do produto: ");
		fgets(produto, sizeof(produto), stdin);
		int i;

		for (i = 0; i < MAX_PRODUTOS; ++i)
		{
			if (strstr(produtos[i].nome, produto) != NULL)
			{
				printf("Codigo: %d\n", i + 1);
				printf("Produto: %s\n", produtos[i].nome);
				printf("Preco: %0.2f\n", produtos[i].preco);
				printf("Preco: %d\n", produtos[i].quantidade);
				printf("\n------------------------\n");
			}
		}
		printf("\n1 - Nova pesquisa\n0 - Sair\n");
		scanf("%d", &op);
		getchar();		
	} while (op != 0);


}

//----------------------------------------------------------------------- funcao para verificar todo o estoque
void estoque(){
	system("cls");
	printf("\nLISTA DE PRODUTOS\n");
	int op;
	do{	
		int i;
		for (i = 0; i < MAX_PRODUTOS; ++i){
			if (produtos[i].disponivel == 1){
				printf("Codigo: %d\n", i + 1);
				printf("Produto: %s\n", produtos[i].nome);
				printf("Preco: %0.2f\n", produtos[i].preco);
				printf("Quantidade: %d\n", produtos[i].quantidade);
				printf("\n------------------------\n");
			}
			
		}

		printf("\n0 - Sair\n");
		scanf("%d", &op);
	} while (op != 0);

}
