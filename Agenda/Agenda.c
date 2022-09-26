#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME (sizeof(char) * 10)
#define AGE (sizeof(int))
#define PHONE (sizeof(int))

#define COUNTER (sizeof(int))
#define OPTION (sizeof(int))
#define AUX_POINTER (sizeof(void **))

#define FIRST_PERSON (sizeof(int))
#define LAST_PERSON (sizeof(int) + sizeof(void **))

#define NEXT_PERSON (sizeof(char) * 10 + sizeof(int) * 2 + sizeof(void **))
#define PREVIOUS_PERSON (sizeof(char) * 10 + sizeof(int) * 2)

void addPerson(void *pBuffer, void *pAux);
void listPerson(void *pBuffer, void *pAux);
void removePerson(void *pBuffer, void *linkedList, void *pRead);
void searchPerson(void *pBuffer, void *pAux, void *pRead);
void exitProgram(void *pAux);

void addPerson(void *pBuffer, void *pAux){
		int *pCounter = (int *)(pAux); 

		void *pPersonInfo = NULL;  
		pPersonInfo = malloc(NAME + AGE + PHONE + AUX_POINTER + AUX_POINTER);

		void *pPersonInfoAux = NULL;

		if(!pPersonInfo){
			printf("Erro ao alocar memoria \n");
			exit(1);
		}
		printf("\n Adicione os dados do contato!");
		printf("\n Digite o nome:");
		scanf("%s", (char *)pPersonInfo);
		getchar();

		printf("\n Digite a idade: ");
		scanf("%d", &*(int *)(pPersonInfo + NAME));
		getchar();

		printf("\n Digite o numero de telefone: ");
		scanf("%d", &*(int *)(pPersonInfo + NAME + AGE));
		getchar();

		*(void **)(pPersonInfo + NEXT_PERSON) = NULL;
		*(void **)(pPersonInfo + PREVIOUS_PERSON) = NULL;

		if (*pCounter == 0){

			*(void **)(pAux + LAST_PERSON) = pPersonInfo;
			*(void **)(pAux + FIRST_PERSON) = pPersonInfo;

			*pCounter += 1;

			return;
		}

	pBuffer = *(void **)(pAux + FIRST_PERSON);

	while(pBuffer != NULL){
		
		if(strcmp((char *)pPersonInfo, (char *)pBuffer) < 0){ 

			*(void **)(pPersonInfo + PREVIOUS_PERSON) = *(void **)(pBuffer + PREVIOUS_PERSON);
			*(void **)(pPersonInfo + NEXT_PERSON) = pBuffer;


			if(*pCounter > 1 && *(void **)(pBuffer + PREVIOUS_PERSON) != NULL){
				pPersonInfoAux = *(void **)(pBuffer + PREVIOUS_PERSON);
				*(void **)(pPersonInfoAux + NEXT_PERSON) = pPersonInfo;
			}
			
			*(void **)(pBuffer + PREVIOUS_PERSON) = pPersonInfo;

			if(*(void **)(pPersonInfo + PREVIOUS_PERSON) == NULL){
				*(void **)(pAux + FIRST_PERSON) = pPersonInfo;
			}

			if(*pCounter == 1 && *(void **)(pBuffer + NEXT_PERSON) == NULL){
				*(void **)(pAux + LAST_PERSON) = pBuffer;
			}

			*pCounter += 1;
			return;
		}

		if(*(void **)(pBuffer +  NEXT_PERSON) == NULL){
			pPersonInfoAux = pBuffer;
		}

		pBuffer = *(void **)(pBuffer + NEXT_PERSON);
	}

	*(void **)(pPersonInfo + PREVIOUS_PERSON) = pPersonInfoAux;
	*(void **)(pPersonInfoAux + NEXT_PERSON) = pPersonInfo;
	*(void **)(pAux + LAST_PERSON) = pPersonInfo;

	*pCounter += 1;

	return;
}


void listPerson(void *pBuffer, void *pAux){
	void *pPersonInfo = NULL;
	pPersonInfo = *(void **)(pAux + FIRST_PERSON);

	int *pCounter = (int *)(pAux); 

	if(*pCounter == 0){
		printf("A lista esta vazia! Nao ha nada para ser listado\n");
	} else {
		printf("\n LISTA DE PESSOAS \n");
		while (pPersonInfo != NULL){
			printf("Nome: %s\n", (char *)pPersonInfo);
			printf("Idade: %d\n", *(int *)(pPersonInfo + NAME));
			printf("Telefone: %d\n", *(int *)(pPersonInfo + NAME + AGE));

			pPersonInfo = *(void **)(pPersonInfo + NEXT_PERSON);
		}
	}
}


void removePerson(void *pBuffer, void *pAux, void *pRead){
	int *pCounter = (int *)(pAux);

	if (*pCounter == 0){
		printf("A lista esta vazia, não tem nada para remover. \n");
	} else {
		printf("\n O primeiro nome da lista foi removido \n");
		pRead = *(void **)(pAux + FIRST_PERSON); 
		*(void **)(pAux + FIRST_PERSON) = *(void **)(pRead + NEXT_PERSON); 
		free(pRead);
		*(void **)(pBuffer + PREVIOUS_PERSON) = NULL; 

		*pCounter -= 1;
	}

}

void searchPerson(void *pBuffer, void *pAux, void *pRead){
	int *pCounter = (int *)(pAux);

	void *pSearchAux = malloc(sizeof(char) * 10);

	pRead = *(void **)(pAux + FIRST_PERSON);

	if(*pCounter == 0){
		printf("\n Nao ha nenhum contado registrado \n");

		free(pSearchAux);
		return;

	} else {
		printf("Quem voce esta procurando? \n");
		scanf("%s", (char *)pSearchAux);
		getchar();

		while(pRead != NULL){
			if(strcmp(pRead ,(char *)pSearchAux) == 0){
				printf("\n Aqui estao os dados do contado \n");
				printf("Nome: %s\n", (char *)pRead);
				printf("Idade: %d\n", *(int *)(pRead + NAME));
				printf("Telefone: %d\n", *(int *)(pRead + NAME + AGE));

				free(pSearchAux);

				return;
			} else {
				
				printf("\n Contato nao encontrado\n ");
				free(pSearchAux);
				return;
			}

			pRead = *(void **)(pRead + NEXT_PERSON);
			}
		}

		free(pSearchAux);
		return;
	}

void exitPerson(void *pAux){ 
	void *pClean = *(void **)(pAux + FIRST_PERSON); 
	int *pCounter = (int *)(pAux);

	if(*pCounter == 0){
		printf("\nA lista esta vazia"); 
	} else {
	
	while(*(void **)(pAux + FIRST_PERSON) != NULL){ 
		pClean = *(void **)(pAux + FIRST_PERSON); 
		*(void **)(pAux + FIRST_PERSON) = *(void **)(pClean + NEXT_PERSON); 
		free(pClean);

	 *pCounter-= 1;

	}

	}
}

int main(){
    
	void *pAux = NULL;
	pAux = malloc(COUNTER + AUX_POINTER + AUX_POINTER);

	*(int *)(pAux) = 0; 

	void *pBuffer = NULL;
	pBuffer = malloc(OPTION + AUX_POINTER);

	void *pRead = NULL;

	if (!pBuffer || !pAux){
		printf("\n Nao ha memoria suficiente");
		exit(1);
	}

    do{
    printf("MENU \n");
    printf("1 - Adicionar nome \n");
    printf("2 - Remover nome \n");
    printf("3 - Listar nomes \n");
    printf("4 - Buscar nome \n");
    printf("5 - Sair \n");

    printf("Opcao: \n");
    scanf("%d", (int *)(pBuffer));
    getchar ();

switch (*(int *)(pBuffer)){
		case 1:
			addPerson(pBuffer, pAux); //adiciona
			break;
		case 2:
			removePerson(pBuffer, pAux, pRead); //remove 
			break;
		case 3:
			listPerson(pBuffer, pAux); //listar
			break;
		case 4:
			searchPerson(pBuffer, pAux, pRead); //buscar
			break;
		case 5:
			printf("Agenda fechada");
			exitPerson(pAux);
			free(pBuffer);
			free(pAux);
			exit(0);
			break;
		default:
			printf("Opcao invalida, tente de novo \n");
			break;    
		}
	} while ((*(int *)(pBuffer) >= 1) || (*(int *)(pBuffer) <= 5));


}
