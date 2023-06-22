#define MAX_PRODUTOS 10
typedef struct {	
	char produto[MAX_PRODUTOS];		//vetor de strings que armazena os nomes dos produtos
	float precos;
	int quantidade;
	int disponivel;
	int status; 				//status 1 na loja, status 0 vendido

} Produto;

