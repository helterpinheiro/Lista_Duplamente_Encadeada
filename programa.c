#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadupla.h"

typedef struct _carro_{
		char marca[50];
		char placa[7];
		int chassi;
}Carro;

void listaMenu(Dllist *l);
Dllist* criarLista();
void inserirListaFirst(Dllist *l);
void inserirListaLast(Dllist *l);
void removerListaChassi(Dllist *l);
void removerListaPlaca(Dllist *l);
void removerListaMarca(Dllist *l);
void procurarPlacaLista(Dllist *l);
void procurarMarcaLista(Dllist *l);
void procurarChassiLista(Dllist *l);
void listarLista(Dllist *l);
void imprimeData(void* a);
void numElm(Dllist *l);
int compPlacaCarro(void *a, void *b);
int compMarcaCarro(void *a, void *b);
int compChassiCarro(void *a, void *b);
void inserirAposNo(Dllist *l);
void insetirAntesNo(Dllist *l);

int main()
{
	Dllist *l=NULL;

	listaMenu(l);
	return 0;
}
//=====================
//MENU
//=====================
void listaMenu(Dllist *l)
{
	char ch,placa,chassi;
	int opc;
	void *aux;
	while(opc!=11){
		printf("\n======== LISTA DE AUTOMOVEIS ==========\n");
		printf("1 - Criar uma lista\n");
		printf("2 - Inserir na primeira posicao um automovel\n");
		printf("3 - Inserir na ultima posicao um automovel(PRA SACANEAR)\n");
		printf("4 - Listar o numero de automoveis dentro da lista\n");
		printf("5 - Remover um automovel\n");
		printf("6 - Procurar na lista um automovel\n");
		printf("7 - Destruir a lista\n");
		printf("8 - Imprimir os elementos na lista\n");
		printf("9 - Inserir apos o no\n");
		printf("10 - Inserir antes o no\n");
		printf("11 - EXIT\n");
		scanf("%d",&opc);

		switch(opc)
		{
			case 1:
				if(l==NULL){
					system("cls");
					l = criarLista();
				}else{
					printf("Ja existe uma lista\n");
				}
			break;

			case 2:
				system("cls");
				inserirListaFirst(l);
			break;

			case 3:
				system("cls");
				inserirListaLast(l);
			break;

			case 4:
				system("cls");
				numElm(l);
			break;

			case 5:
				system("cls");
				printf("\n ======= SISTEMA DE REMOCAO DE AUTOMOVEIS =======\n");
				printf("1 - Remover pela PLACA\n");
				printf("2 - Remover pelo chassi\n");
				printf("\n ENTER YOUR CHOICE\n");
				scanf("%s", &ch);
				switch(ch)
				{
					case '1':
						system("cls");
						removerListaPlaca(l);
					break;

					case '2':
						system("cls");
						removerListaChassi(l);
					break;

					default:
						if(ch!='2'){
							printf("\nOpcao invalida\n");
						}
				}
				break;

			case 6:
				system("cls");
				printf("\n ====== SISTEMA DE BUSCAS =======\n\n");
				printf("1 - Placa\n");
				printf("2 - Chassi\n");
				printf("Enter your choice\n");
				scanf("%s",&ch);
				switch(ch)
				{
                	case '1':
                    	system("cls");
                    	printf("Informe a placa do automovel: ");
                    	scanf("%s",&placa);
                    	aux = dllQuery(l,(void*)&placa,compPlacaCarro);
                    	if(aux!=NULL){
                       		Carro *c;
                       		c=(Carro*)aux;
                       		printf("\n --------------- \n");
                       		printf("\nPLACA: ""%s",c->placa);
                       		printf("\nMARCA: ""%s",c->marca);
                       		printf("\nCHASSI: ""%d",c->chassi);
                       		printf("\n --------------- \n");
                    	}else{
                        	printf("\nInforme uma placa valida\n");
                    	}
                    break;

                	case '2':
                		system("cls");
                    	printf("Informe o chassi do automovel: ");
                    	scanf("%d",&chassi);
                    	aux = dllQuery(l,(void*)&chassi,compChassiCarro);
                    	if(aux!=NULL){
                       		Carro *c;
                      	 	c=(Carro*)aux;
                       		printf("\n --------------- \n");
                       		printf("\nPLACA: ""%s",c->placa);
                       		printf("\nMARCA: ""%s",c->marca);
                       		printf("\nCHASSI: ""%d",c->chassi);
                       		printf("\n --------------- \n");
                    	}else{
                        	printf("\nInforme um chassi valido\n");
                    	}
                	break;

                	default:
                    	if(ch!='2'){
                    		printf("\n Opcao invalisa");
                    	}
                }
			break;

			case 7:
				system("cls");
				if(dllDestroy(l) == TRUE){
					l = NULL;
					printf("Lista destruida\n");
				}
			break;
				
			case 8:
				system("cls");
				listarLista(l);
			break;

			case 9:
				system("cls");
				inserirAposNo(l);
            break;

            case 10:
                system("cls");
                insetirAntesNo(l);
            break;

            case 11:
                exit(0);
			default:
				if(opc!=11){
					printf("\nOpcao Invalida\n");
				}
			break;
		}
	}
}
// a funcao cria uma lista duplamente encadeada
Dllist* criarLista()
{
	Dllist *l;
	l = dllCreate();
	printf("SUCEFULL");
	return l;
}
// a funcao insere no primeiro elemento da lista
void inserirListaFirst(Dllist *l)
{
	Carro *c;
	if(l!=NULL){
		c=(Carro*)malloc(sizeof(Carro));
		if(c!=NULL){
			printf("Insira a marca do veiculo: \n");
	 		scanf("%s",c->marca);
	 		printf("Insira os digitos da placa: \n");
	 		scanf("%s",c->placa);
	 		printf("Insira o numero do seu chassi: \n");
	 		scanf("%d",&c->chassi);

	 		if(dllInsertFirst(l,(void*)c)==TRUE){
	 			printf("\n-------------------------------");
	 			printf("\nVeiculo inserido com sucesso!\n");
	 			printf("-------------------------------\n");
	 		}else{
	 			printf("\nErro na insercao!\n");
	 		}
		}else{
			free(c);
		}
	}
}
// a funcao insere o elemento na ultima posicao
void inserirListaLast(Dllist *l)
{
	Carro *c;
	if(l!=NULL){
		c=(Carro*)malloc(sizeof(Carro));
		if(c!=NULL){
			printf("Insira a marca do veiculo: \n");
	 		scanf("%s",c->marca);
	 		printf("Insira os digitos da placa: \n");
	 		scanf("%s",c->placa);
	 		printf("Insira o numero do seu chassi: \n");
	 		scanf("%d",&c->chassi);

	 		if(dllInsertLast(l,(void*)c) == TRUE){
	 			printf("\n----------------------------------");
	 			printf("\nCarro inserido com sucesso!\n");
	 			printf("----------------------------------\n");
	 		}else{
	 			printf("\n----------------------------------");
	 			printf("\nErro na insercao!\n");
	 			printf("----------------------------------\n");
	 		}
		}else{
			free(c);
		}
	}
}
//remove qualquer elemento em qualquer posicao valida da lista pelo chassi
void removerListaChassi(Dllist *l)
{
	int chassi;
	printf("Informe o chassi do seu veiculo \n");
	scanf("%d",&chassi);
	if(dllRemoveSpec(l,(void*)chassi,compChassiCarro)==TRUE){
		printf("Carro removido com sucesso!\n");
	}else{
		printf("ERRO! Informe um chassi valido!\n");
	}
}
// remove qualquer elemento em qualquer posicao valoda da lista pela PLACA
void removerListaPlaca(Dllist *l)
{
	char placa;
	printf("Informe a placa do seu veiculo: \n");
	scanf("%s",&placa);
	if(dllRemoveSpec(l,(void*)&placa,compPlacaCarro)!=NULL){
		printf("Carro removido com sucesso!\n");
	}else{
		printf("ERRO! Informe uma placa valida!\n");
	}
}
// remove qualquer elemento emqualquer posivao valida da lista pela MARCA
void removerListaMarca(Dllist *l)
{
	char marca[50];
	printf("Informe a marca do seu veiculo: \n");
	scanf("%s",marca);
	if(dllRemoveSpec(l,(void*)marca,compMarcaCarro)!=NULL){
		printf("Carro removido com sucesso!\n");
	}else{
		printf("ERRO! Informe um id valido!\n");
	}
}

// procura elementos na lista pela placa
void procurarPlacaLista(Dllist *l)
{
	if(l!=NULL){
		char placa[50];
		printf("Informe a placa do veiculo: \n");
		scanf("%s", placa);
		if(dllQuery(l,(void*)placa,compPlacaCarro) == TRUE){
			printf("Veiculo encontrado!");
		}else{
			printf("Veiculo nao encontrado!");
		}
	}
}

// procura elementos na lista pela Marca
void procurarMarcaLista(Dllist *l)
{
	if(l!=NULL){
		char marca[50];
		printf("Informe a placa do veiculo: \n");
		scanf("%s", marca);
		if(dllQuery(l,(void*)marca,compMarcaCarro) == TRUE){
			printf("Veiculo encontrado!");
		}else{
			printf("Veiculo nao encontrado!");
		}
	}
}

// procura eleementos na lista pelo chassi
void procurarChassiLista(Dllist *l)
{
	if(l!=NULL){
		int chassi;
		printf("Informe a placa do veiculo: \n");
		scanf("%i",&chassi);
		if(dllQuery(l,(void*)chassi,compChassiCarro) == TRUE){
			printf("Veiculo encontrado!");
		}else{
			printf("Veiculo não encontrado!");
		}
	}
}
// retorna o numedo de elementos da lista
void numElm(Dllist *l)
{
	int aux;
	aux = dllNumElm(l);
	if(aux!=NULL){
        printf("\n-------------------------------");
		printf("\nNumero de carros atual:""%d",aux);
        printf("\n-------------------------------\n");
	}else{
		printf("\nLista vazia!");
	}
}

//fucao que insere um elemento depois do no especificado
void inserirAposNo(Dllist *l){
    Carro *c;
    int chassi;
	if(l!=NULL){
		c=(Carro*)malloc(sizeof(Carro));
		if(c!=NULL){
			printf("Insira a marca do veiculo: \n");
	 		scanf("%s",c->marca);
	 		printf("Insira os digitos da placa: \n");
	 		scanf("%s",c->placa);
	 		printf("Insira o numero do seu chassi: \n");
	 		scanf("%d",&c->chassi);
	 		printf("Informe o chassi do veiculo que voce gostaria de inserir o novo veiculo depois dele\n");
	 		scanf("%d",&chassi);

	 		if(dllInsertAfterSpec(l,(void*)chassi,compChassiCarro,(void*)c) == TRUE){
	 			printf("\n----------------------------------");
	 			printf("\nCarro inserido com sucesso!\n");
	 			printf("----------------------------------\n");
	 		}else{
	 			printf("\n----------------------------------");
	 			printf("\nErro na insercao!\n");
	 			printf("----------------------------------\n");
	 		}
		}else{
			free(c);
		}
	}
}

void insetirAntesNo(Dllist *l)
{
    Carro *c;
    int chassi;
	if(l!=NULL){
		c=(Carro*)malloc(sizeof(Carro));
		if(c!=NULL){
			printf("Insira a marca do veiculo: \n");
	 		scanf("%s",c->marca);
	 		printf("Insira os digitos da placa: \n");
	 		scanf("%s",c->placa);
	 		printf("Insira o numero do seu chassi: \n");
	 		scanf("%d",&c->chassi);
	 		printf("Informe o chassi do veiculo que voce gostaria de inserir o novo veiculo antes dele\n");
	 		scanf("%d",&chassi);

	 		if(dllInsertBeforeSpec(l,(void*)chassi,compChassiCarro,(void*)c)==TRUE){
                printf("\n----------------------------------");
	 			printf("\nCarro inserido com sucesso!\n");
	 			printf("----------------------------------\n");
	 		}else{
	 			printf("\n----------------------------------");
	 			printf("\nErro na insercao!\n");
	 			printf("----------------------------------\n");
	 		}
		}else{
           free(c);
		}
	}
}

//======================
//funcoes de comparacao
//======================
int compPlacaCarro(void *a, void *b)
{
	char *pa; Carro *pb;
	pa=(char *)a;
	pb=(Carro *)b;
	if(strcmp(pa, pb->placa) == TRUE){
		return TRUE;
	}else{
		return FALSE;
	}
}

int compMarcaCarro(void *a, void *b)
{
	char* pa; Carro *pb;
	pa=(char *)a;
	pb=(Carro *)b;
	if(strcmp(pa, pb->marca) == 0){
		return TRUE;
	}else{
		return FALSE;
	}
}

int compChassiCarro(void *a, void *b)
{
	int *pa; Carro *pb;
	pa=(int *)a;
	pb=(Carro *)b;
	if(pb->chassi==pa){
		return TRUE;
	}else{
		return FALSE;
	}
}

//=================================
// funcao que imita um arraylist
//=================================
void listarLista(Dllist *l)
{
    void *data;
    if(l!=NULL){
        data = dllFirst(l);
        while(data!=NULL){
            imprimeData(data);
            data=dllGetNext(l);
        }
    }
}
// imprime dados do elemento
void imprimeData(void* a)
{
    Carro *pb;
    pb=(Carro*)a;
        printf("\n Marca: ""%s",pb->marca);
        printf("\n Placa: ""%s",pb->placa);
        printf("\n Chassi: ""%d",pb->chassi);
        printf("\n---------------------\n");

}
