#include <stdio.h>
#include <stdlib.h>

 typedef struct{
    char nome[30];
    int idade;
    int altura;
}Pessoa;

int main() {
    int op=0;
    int contador=0;
    Pessoa *p;
    p=(Pessoa *)malloc(sizeof(Pessoa));
    
    printf("\n MENU \n");
    printf("\n 1) ADICIONAR PESSOA \n");
    printf("\n 2) SAIR");
    printf("\nDigite a sua opcao: ");
    scanf("%d", &op);
    
    while (op == 1) {
    contador++;
    printf("Nome: ");
    scanf("%s", &(*p).nome);
    printf("Idade: ");
    scanf("%d", &(*p).idade);
    printf("Altura (em cm): ");
    scanf("%d", &(*p).altura);
    ;
    
    printf("\n Deseja adicionar mais nomes? ");
    printf("\n 1) SIM ");
    printf("\n 2) NAO ");
    printf("\nDigite a sua opcao: ");
    scanf("%d", &op);
    }

    if (op == 2){
        if (contador > 0){
            printf ("As informacoes contidas sao: \n");
            printf("Nome: %s\n", (*p).nome );
            printf("Idade: %d\n", (*p).idade);
            printf("Altura: %d\n", (*p).altura);
       } else {
            printf("Nenhuma informacao foi inserida. Programa vazio");
        }
    free(p);
    return 0;
    }
}
