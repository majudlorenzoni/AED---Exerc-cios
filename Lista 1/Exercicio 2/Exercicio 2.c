#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char *adiciona_semicolon(char *nomes){
    int i = strlen(nomes) + 1;

    nomes = (char *)realloc(nomes, sizeof(char) * i + 1);
    if(!nomes){
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    nomes [i - 1] = ';';
    nomes[i] = '\0';
    return nomes;
}

char *get_nomes(char *nomes, int i){
    do{
        i++;
        nomes = (char *)realloc(nomes, sizeof(char) * i + 1);
         if(!nomes){
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    nomes[i - 1] = getchar();
    } while(nomes[i - 1] != '\n');
    nomes [i  - 1] = '\0';
    return nomes;
    }

char *adiciona_nomes(char *nomes){
    int length = strlen(nomes);
    printf("Digite um nome: \n");
    scanf("%s", nomes);
    nomes = get_nomes(nomes, length);
    nomes = adiciona_semicolon(nomes);
    return nomes;
}

char *removeNome(char *nomes){
    int i =0;
    char temp[100], temp2[100];
    char *nomes_comp = (char *)malloc(sizeof(char));
    if(!nomes_comp){
        printf("\nErro ao alocar memoria!");
        return NULL;
    }
    
    printf ("Digite o nome que deseja excluir: ");
    fflush (stdin);
    scanf("%s", nomes_comp);
    nomes_comp = get_nomes(nomes_comp, i);
    char *p = strstr(nomes, nomes_comp);

    if(!p){
        printf("Nome nao encontrado\n");
        return NULL;
    } else {
        strcpy(temp, nomes);
        temp[p - nomes] = '\0';
        strcpy(temp2, p + strlen(nomes_comp));
        strcat(temp, temp2);
        strcpy(nomes, temp);
        }

        printf("Nome excluido\n");
        free(nomes_comp);
        return nomes;
}

int lista_nomes(char *nomes){
    int i = 0;

    if(nomes[0] == '\0'){
        printf("Nenhum nome foi registrado\n");
        return 1;
    }
    printf("Lista de nomes: \n");
    printf("%s", nomes[i]);
    i++;
    return 0;
}

int main (){
int escolha = 0;
char *p = (char *)malloc(sizeof(char));
    if (!p) {
        printf("\nErro ao alocar memoria!\n");
        return 1;
    }
    *p = '\0';
while (escolha != 4) { 
     
    printf("\n MENU");
    printf("\n 1. Adicionar nome");
    printf("\n 2. Remover nome");
    printf("\n 3. Listar nomes");
    printf("\n 4. Sair");
    printf ("\n Digite um numero: ");
    fflush(stdin);
    scanf("%d", &escolha);
    system("cls");

    switch (escolha) {
    case 1:
    p = adiciona_nomes(p);
    break;

    case 2:
    p = removeNome(p);
    break;

    case 3:
    lista_nomes(p);
    break;

    case 4:
    break;

    default:
    printf("Digite uma das opcoes validas\n");
    } 
}
free(p);
return 0;
}
