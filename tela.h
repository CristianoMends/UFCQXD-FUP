#include "funcoes.h"

void menu(){
	system("cls"); //limpar tela
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

