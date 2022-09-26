#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int top = -1;
int front = 0;

//declarei a pilha
int pilha[MAX];

//colocando uma letra na lista
void push(char letras){
	top++;
	pilha[top] = letras;
}
//retirando uma letra da lista
char pop(){
      top--;
	}


//verificacao pra ver se é palindromo ou não
void palindromo(){
	char palavra[MAX];
	char aux;
	int i;
	printf("Digite uma palavra: \n");
	scanf("%s", palavra);

	for (i = 0; palavra[i] != '\0'; i++){
		aux = palavra[i];
		push(aux);
	}

	for (i = 0; i < (strlen(palavra) / 2); i++){
		if(pilha[top] == pilha[front]){
			pop();
			front++;
		} else {
			printf("%s nao e um palindromo \n", palavra);
		}
		}
		if ((strlen(palavra) / 2) == front)
		printf("%s e palindromo \n", palavra);
		front = 0;
		top = -1;
		return;
}


int main (){
	int i;
	char palavra[MAX];
	char aux;

	int opcao;
	do { 
	printf("Deseja verificar palavras?\n");
	printf("\n1 - SIM");
	printf("\n2 - NAO");
	printf("\nOpcao: ");
	scanf("%d", &opcao);

	switch (opcao)
	{
	case 1:
		palindromo();
		break;
	
	case 2:
		exit;
		break;
	default: 
	printf("Digite uma opcao valida");
		break;
	}
} while (opcao == 1);
}

//palavras pro teste = aabccbaa
//palavras pro teste = addfdda
//palavras pro teste = pop
//palavras pro teste = arara

//palavras pro teste = abffbb
//palavras pro teste = maria
//palavras pro teste = cadeira
//palavras pro teste = parede
