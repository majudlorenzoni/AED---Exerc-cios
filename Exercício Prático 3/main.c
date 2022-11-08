#include <stdio.h>
#include <stdlib.h>

struct Node {
	int valor;
	struct Node *esquerda;
	struct Node *direita;
};
typedef struct Node Node;


int alturaArvore(struct Node *raiz);
Node *inicializacao(int valor);
Node *cria_node(int valor);
void limpeza(Node *raiz);
int alturaArvore(struct Node *raiz);
int balanceamento(struct Node *raiz);


Node *inicializacao(int valor){
	Node *raiz = (Node *) malloc(sizeof(Node));
	raiz->esquerda = NULL;
	raiz->direita = NULL;
	raiz->valor = valor;
	return raiz;
}

Node *cria_node(int valor){
	Node *node = (Node *) malloc (sizeof(Node));
	node->valor = valor;
	node->esquerda = NULL;
	node->direita = NULL;
	return node;
}

void limpeza(Node *raiz){
	Node *temp = raiz;
	if(!temp){
		limpeza(temp->esquerda);
		limpeza(temp->direita);
		if(!temp->esquerda && !temp->direita){
			free(temp);
			return;
		}
	}
	printf("Arvore excluida! Programa finalizado");
}

int alturaArvore(struct Node *raiz){
	int alturaEsquerda = 0;
	int alturaDireita = 0;
	if(raiz != NULL){
	alturaEsquerda = alturaArvore(raiz->esquerda);  //Calcula altura da esquerda
	alturaDireita = alturaArvore(raiz->direita);    //Calcula altura da direita
	if(alturaEsquerda > alturaDireita){
		return alturaEsquerda + 1;
	} else {
		return alturaDireita + 1;
	}
}
}

int balanceamento(struct Node *raiz){
	if(raiz == NULL){
		return 0;
	}
	int AVL = (alturaArvore(raiz->esquerda) - alturaArvore(raiz->direita));
	if( AVL >= -1 && AVL <= 1){
		printf("SIM! A arvore feita neste programa e AVL\n");
    } else {
        printf("NÃO! A arvore feita neste programa nao e AVL\n");
    }
}  

void print(struct Node *raiz){
	if (raiz != NULL) {
		print(raiz->esquerda);
		printf("%d\n", raiz->valor);
		print(raiz->direita);
	}
}

int main(){
	int opcao;
	int contador = 0;
	int valor, altura;
	Node *raiz = NULL;
	Node *percorreArvore = NULL;
	do {
		printf(" MENU \n");
    	printf(" 1 - Adicionar elementos na arvore\n");
		printf(" 2 - Mostrar arvore\n");
		printf(" 3 - Sair\n");
    	scanf("%d", &opcao);

		switch (opcao){
		case 1:
			printf("Digite o valor que deseja adicionar: \n");
			scanf("%d", &valor);
			contador++;
			
			if (contador == 1){ //Caso não tenha sido adicionado nenhum nodo na arvore ainda
			raiz = inicializacao(valor); 

			} else if(contador > 1){
				percorreArvore = raiz;
			} while (percorreArvore != NULL){
				if(valor < percorreArvore->valor){
					if(percorreArvore->esquerda == NULL){  //É um nó folha, pode adicionar
						percorreArvore->esquerda = cria_node(valor);
						break;
					} else { //Não é um nó folha, precisa andar para a esquerda para poder adicionar
						percorreArvore = percorreArvore->esquerda;
					}
				} else if(valor > percorreArvore->valor){
					if(percorreArvore->direita == NULL){//É um nó folha, pode adicionar
						percorreArvore->direita = cria_node(valor);
						break;
					}
				}
			}

		case 2:
		print(raiz);
		break;

		case 3:
			altura = alturaArvore(raiz);
			balanceamento(raiz);
			limpeza(raiz);
			return 0;
		break;
		}  
	}   while ((opcao >= 1) && (opcao <= 3));
} 
