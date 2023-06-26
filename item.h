#define MAX_PRODUTOS 20
#define MAX_LETRAS 20

typedef struct {	
	char nome[MAX_PRODUTOS];		//vetor de strings que armazena os nomes dos produtos
	float preco;
	int quantidade;
	int disponivel;
} Produto;

typedef struct {
    char nome[MAX_PRODUTOS];
    int quantidade;
} Venda;

void menu();
void cadastrar();
void vender();
void historico();
void pesquisar();
void estoque();
void liberar_memoria();