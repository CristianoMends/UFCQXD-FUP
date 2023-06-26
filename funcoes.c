#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Produto* produtos[MAX_PRODUTOS];    //vetor de produtos tipo ponteiro
Venda* historico_vendas[MAX_PRODUTOS]; //vetor de vendas tipo ponteiro
int num_vendas = 0; // Variável para rastrear o número de vendas realizadas

void menu() {
    int op;
    do {
        system("cls");
        printf("\n----------Menu----------\n");
        printf("\n1 - Cadastrar produto\n2 - Vender item\n3 - Produtos vendidos\n4 - Pesquisar produtos\n5 - Estoque disponivel\n0 - Sair\n");
        printf("\n------------------------\n");

        scanf("%d", &op);
        getchar();

        switch (op) {
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
//----------------------------------------------------------------funcao cadastrar
void cadastrar() {
    char nome[MAX_LETRAS];
    float preco;
    int quantidade;
    int op;
    do {
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

        Produto* novo_produto = (Produto*) malloc(sizeof(Produto));  //vetor do tipo produto para guardar os novos produtos
        strcpy(novo_produto->nome, nome);
        novo_produto->preco = preco;
        novo_produto->quantidade = quantidade;
        novo_produto->disponivel = 1;
        //---------------------------------------------- enviando os lancamentos para o vetor produtos
        int i;
        for (i = 0; i < MAX_PRODUTOS; ++i) {
            if (produtos[i] == NULL) {
                produtos[i] = novo_produto;
                break;
            }
        }

        printf("\nSTATUS: %d item(s) de %s cadastrado(s) ao estoque!\n", quantidade, nome);
        printf("\n1 - Cadastrar novo produto\n0 - Menu principal\n");
        scanf("%d", &op);
        getchar(); //irá consumir o caractere de nova linha restante no buffer de entrada após a leitura da variavel op com scanf
    } while (op != 0);
}
//---------------------------------------------------------------funcao vender
void vender() {
    int codigo;
    int qtde;
    int op;
    do{   	
		estoque();
	    printf("\nDigite o codigo do produto para vender: ");
	    scanf("%d", &codigo);
	    printf("\nDigite a quantidade: ");
	    scanf("%d", &qtde);
	    --codigo;
	
	
	    if (produtos[codigo] != NULL && qtde <= produtos[codigo]->quantidade) { //se a qtde for <= do que estoque entao da pra vender
	        produtos[codigo]->quantidade -= qtde;
	
	        Venda* nova_venda = (Venda*) malloc(sizeof(Venda));
	
	        // Adiciona a venda ao histórico
	        strcpy(nova_venda->nome, produtos[codigo]->nome);
	        nova_venda->quantidade = qtde;
	
	        historico_vendas[num_vendas] = nova_venda;
	        num_vendas++;
	
	        printf("\nProduto vendido!\n");
	    } else {
	        printf("\nProduto sem estoque\n");
	    }
	    if (produtos[codigo]->quantidade == 0){
	        produtos[codigo]->disponivel = 0;            //Qtde zerada retira o produto do estoque
	    }
		printf("\n1 - Realizar nova Venda\n0 - Menu principal\n");
	    scanf("%d", &op);
	    getchar();
	    
	}while(op != 0);
}
//----------------------------------------------------------------------- mostrar historico
void historico() {
    system("cls");
    printf("\nHISTORICO DE VENDAS\n");

    if (num_vendas == 0) {
        printf("Nenhuma venda realizada.\n");
    } else {
    	int i;
        for (i = 0; i < num_vendas; i++) {
            printf("Produto: %s\n", historico_vendas[i]->nome);
            printf("Quantidade: %d\n", historico_vendas[i]->quantidade);
            printf("------------------------\n");
        }
    }

    printf("\nPressione Enter para voltar ao menu principal\n");
    getchar();
}
//-----------------------------------------------------------------------funcao pra pesquisar um item no estoque
void pesquisar() {
    system("cls");
    char produto[MAX_LETRAS];
    int op;
    do {
        system("cls");
        printf("\n----------Pesquisa de produtos----------\n");

        printf("\nDigite o nome do produto: ");
        fgets(produto, sizeof(produto), stdin);

        int i;
        for (i = 0; i < MAX_PRODUTOS; ++i) {
            if (produtos[i] != NULL && strstr(produtos[i]->nome, produto) != NULL) {

                if (produtos[i]->disponivel == 0)
                {
                    printf("\nProduto sem estoque!\n");
                }
                else{
                    printf("Codigo: %d\n", i + 1);
                    printf("Produto: %s\n", produtos[i]->nome);
                    printf("Preco: %0.2f\n", produtos[i]->preco);
                    printf("Quantidade: %d\n", produtos[i]->quantidade);
                    printf("\n------------------------\n");
                }
                
            }
        }
        printf("\n1 - Nova pesquisa\n0 - Sair\n");
        scanf("%d", &op);
        getchar();
    } while (op != 0);
}
//----------------------------------------------------------------------- funcao para verificar todo o estoque
void estoque() {
    system("cls");	
    printf("\nESTOQUE DISPONIVEL\n");

    int i;
    for (i = 0; i < MAX_PRODUTOS; ++i) {
        if (produtos[i] != NULL && produtos[i]->quantidade != 0) {
            printf("Codigo: %d\n", i + 1);
            printf("Produto: %s\n", produtos[i]->nome);
            printf("Preco: %0.2f\n", produtos[i]->preco);
            printf("Quantidade: %d\n", produtos[i]->quantidade);
            printf("\n------------------------\n");
        }
    }

    printf("\nPressione Enter para continuar\n");
    getchar();
}
//-------------------------------------------------------funcao liberar a memoria
void liberar_memoria() {
	int i;
    for (i = 0; i < MAX_PRODUTOS; i++) {
        free(produtos[i]);
        free(historico_vendas[i]);
    }
    printf("Sistema desligado!");
}
