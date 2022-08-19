#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define NOME (sizeof(int))
#define NNOME (sizeof(int))
#define IDADE (sizeof(int))
#define NUMERO (sizeof(char) * 10)

void *addPerson(void *pBuffer);
void *removed (void *pBuffer);
void list(void *pBuffer);
void search(void *pBuffer);

void *addPerson(void *pBuffer){
    int totalpessoas;

    getchar(); 

    totalpessoas = *(int *)pBuffer; 

    pBuffer = realloc(pBuffer, NNOME + (NOME + IDADE + NUMERO) * (totalpessoas + 1));

    if(!pBuffer){
        printf("Memoria insuficiente!");
        exit(1);
    }

    printf("Digite o nome: \n");
    scanf("%s", (char *)pBuffer + NNOME + (NOME + IDADE + NUMERO) * totalpessoas);
    getchar();

    printf("Digite a idade: \n");
    scanf("%d", (int *)(pBuffer + NNOME + NOME + (NOME + IDADE + NUMERO) * totalpessoas));
    getchar();

    printf("Digite o telefone: \n");
    scanf("%d", (int *)(pBuffer + NNOME + NOME + IDADE + (NOME + IDADE + NUMERO) * totalpessoas));
    getchar();

    *(int *)pBuffer = totalpessoas + 1;

    return pBuffer;
}

void list(void *pBuffer){
    int totalpessoas;
    int i;
    totalpessoas = *(int *)pBuffer;

    if(totalpessoas == 0){
        printf("Nenhuma informacao foi inserida, agenda vazia. \n");
    } else {
        for (i = 0; i < totalpessoas ; i++){
            printf("Nname [%d]\n", i + 1);
            printf("Nome: %s\n", (char *)pBuffer + NNOME + (NOME + IDADE + NUMERO) * i);
            printf("Idade: %d\n", *(int *)(pBuffer + NNOME + NOME + (NOME + IDADE + NUMERO) * i));
            printf("Numero: %d\n\n", *(int *)(pBuffer + NNOME + NOME + IDADE + (NOME + IDADE + NUMERO) * i));

        }
    }
}

void search(void *pBuffer){
    int totalpessoas;
    int i;
    char aux_nome[10];

    printf("Digite o nome que deseja: \n");
    scanf("%s", aux_nome);
    getchar();

    totalpessoas = *(int *)pBuffer;

    for(i = 0; i < totalpessoas; i++){
        if(strcmp((char *)pBuffer + NNOME + (NOME + IDADE + NUMERO) * i, aux_nome) == 0){
             printf("\nName: %s\n", (char *)pBuffer + NNOME + (NOME + IDADE + NUMERO) * i);
            printf("\nIdade: %d\n", *(int *)(pBuffer + NNOME + NOME + (NOME + IDADE + NUMERO) * i));
            printf("\nNumero: %d\n", *(int *)(pBuffer + NNOME + NOME + IDADE + (NOME + IDADE + NUMERO) * i));
            return;
        }
    }
    printf("Nome não encontrado!!\n");
    return; 
}

void *removed(void *pBuffer){
    int totalpessoas, i, j;
    char aux_nome[10];

    totalpessoas = *(int *)pBuffer;
    if(totalpessoas == 0){
        printf("Nenhuma informacao foi inserida, agenda vazia. \n");
    } else {
        printf("Digite o nome que quer excluir: ");
        scanf("$s", aux_nome);
        getchar();
        for(i = 0; i < totalpessoas; i++){
            if(strcmp((char *)pBuffer + NNOME + ((NOME + IDADE + NUMERO) * i), aux_nome) == 0) {
                for (j = i; j < totalpessoas; j++){
                    strcpy((char *)pBuffer + NNOME + ((NOME + IDADE + NUMERO)* j), (char *)pBuffer + NNOME + (NOME + IDADE + NUMERO) * (j +1));
                    *(int *)(pBuffer + NNOME + NOME + ((NOME + IDADE + NUMERO) * j)) = *(int *)(pBuffer + NNOME + NOME + (NOME + IDADE + NUMERO) * (j + 1));
                    *(int *)(pBuffer + NNOME + NOME + IDADE + ((NOME + IDADE + NUMERO * j))) = *(int *)(pBuffer + NNOME + NOME + IDADE + (NOME + IDADE + NUMERO) *(j + 1));
        }
        * (int *)pBuffer = totalpessoas - 1;
        pBuffer = realloc(pBuffer, NNOME + (NOME + IDADE + NUMERO) * (totalpessoas - 1));
        return pBuffer;
        }
        }
        printf("Nome não encontrado \n");
    }
    return pBuffer;
}

int main(){
    void *pBuffer = NULL;
    
    pBuffer = malloc(NNOME);
    
    *(int *)pBuffer = 0;

    if(!pBuffer){
        printf("Erro ao alocar memoria \n");
        exit(1);
    }
    int escolha;
    do{ 
    printf("1 - Adicionar nome \n");
    printf("2 - Remover nome \n");
    printf("3 - Listar nomes \n");
    printf("4 - Buscar nome \n");
    printf("5 - Sair \n");
    printf("Opcao: \n");
    scanf("%d", &escolha);
    
    switch (escolha){
    case 1:
    pBuffer = addPerson(pBuffer);
        break;
    case 2:
    pBuffer = removed(pBuffer);
        break;
    case 3:
    list(pBuffer);
        break;
    case 4:
    search(pBuffer);
    break;
    case 5:
     free(pBuffer);
        exit(0);
    return 0;

    default:
    printf("Opcao invalida, tente de novo \n");
        break;
    }
    }  while ((escolha >= 1) || (escolha <= 5));
}
