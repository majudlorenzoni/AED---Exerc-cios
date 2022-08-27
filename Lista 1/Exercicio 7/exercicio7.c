#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int idade;
    int altura;
}Pessoa;

//item 1 - variavel global
Pessoa pessoas[10];
void *pBuffer; //ponteiro que armazena tudo
int *quantidade; //ponteiro que aponta para contar a quantidade de pessoas

void adiciona(int *quantidade){
    if(*quantidade == 10){
        printf("Numero máximo de pessoas armazenado");
        return;
    } else {
        printf("\n Nome: ");
        scanf("%s", &pessoas[*quantidade].nome);
        printf("\n Idade: ");
        scanf("%d", &pessoas[*quantidade].idade);
        printf("\n Altura (em cm): ");
        scanf("%d", &pessoas[*quantidade].altura);

        *quantidade = *quantidade + 1; //aumenta o tamanho do armazenamento
    }
}

void ler(int *quantidade){
    int *i;
    i = pBuffer + (sizeof(int) * 2);
    *i = 0;
    for (;*i < *quantidade;){
        printf("\n  Pessoa %d:", *i + 1);
        printf("\nNome:%s", pessoas[*i].nome);
        printf("\nIdade:%d", pessoas[*i].idade);
        printf("\nAltura:%d", pessoas[*i].altura);
        *i = *i + 1;
    }
}

void adiciona(int *quantidade);
void ler(int *quantidade);

int main(){
    int *op;

    pBuffer = malloc(sizeof(int ) * 3);
    op = pBuffer;
    quantidade = pBuffer + sizeof(int);
    *quantidade = 0;

    do{
        printf("\n MENU");
        printf("\n 1) Adicionar pessoas");
        printf("\n 2) Sair");
        printf("\n Digite a sua opcao: ");
        scanf("%d", op);

        if(*op == 1){
            adiciona(quantidade);
        } 
        else if (*op == 2){
            ler(quantidade);
        }
    } while(*op != 2);
    return 0;
}
