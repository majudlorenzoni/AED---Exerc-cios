

#include <stdio.h>
#include <stdlib.h>
//Uma arvore binaria de busca
//No fim do código, dizer se a arvore é avl ou não 
//pra ser avl, o balanceamento tem que dar -1 e 1 

//1) estrutura OK
//2) novo nó OK
//3) balanceamento OK
//4) inserir função de busca OK
//5) inserindo pra esquerda e inserindo pra direita OK
//6) printar no final se é avl ou não  OK
//7) MENU

typedef struct node {
    int valor;
    struct node *esquerda;
    struct node *direita;
    int altura;
};

//esse é a raiz
struct node novo_node(struct node){
    struct node *tmp;
    tmp->valor = NULL;
    tmp->esquerda = NULL;
    tmp->direita = NULL;

    return;
}

int balence;
int alturaEsquerda = 0;
int alturaDireita = 0;
void *arvore;

struct node *insert_node(struct node){

    arvore = malloc(sizeof(struct node));
    node->tmp;
    tmp->valor;

    if(valor < node->valor){
        tmp->esquerda;
        alturaEsquerda++;
    }

    if(valor > node->valor){
        tmp->direita;
        alturaDireita++;
    }
    return;
}

struct node *busca(struct node, char *valor){
   if(strcmp(node->valor, buscando)){
      }}
      //TEM QUE DAR UM PRINT DIZENDO QUE ENCONTROU
      //ELSE IF SE NÃO ENCONTROU E RETORNAR

int balanceamento(balence, alturaEsquerda, alturaDireita){
    balence == ((alturaEsquerda) - (alturaDireita));
    return balence;
}


int main(){
    int opcao;
    struct node = NULL;
    printf(" MENU \n");
    printf(" 1 - Adicionar elementos na arvore");
    printf(" 2 - Buscar elementos na arvore");
    printf(" 3 - Sair");

    switch (opcao){ 
        case 1:
        if (node = NULL){
            struct node novo_node(struct node);
        } else {
            struct node *insert_node(struct node);}
        break;

        case 2:
        printf("Digite o elemento que esta procurando: ");
        scanf("%d", &buscando);

        case 3:
        if(balence >= -1 && balence <= 1){
            printf("A arvore é AVL");
        } else {
            printf("A arvore não é AVL");
            return 0;
        }
        break;
    
    
}
}
