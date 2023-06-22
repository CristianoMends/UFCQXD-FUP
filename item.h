#define MAX_PRODUTOS 20
#define MAX_LETRAS 20

typedef struct {	
	char nome[MAX_LETRAS];		//vetor de strings que armazena os nomes dos produtos
	float preco;
	int quantidade;
	int disponivel;
	int status; 				//status 1 na loja, status 0 vendido
} Produto;

