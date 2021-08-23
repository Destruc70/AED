#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

struct info{

	char nome[30];
    float alt;
    int age;
    struct end *prox;

};
typedef struct info data;

void insert(data *topo);
void delPointer(data *ponteiro);
int menu(void);
data *aval(void);
data *lista(void);
void print(data *aux);



int main(){
	
    data *var=NULL;
    var=lista();
    int op;
	
    for(;;){
        op=menu();
        switch(op){
            case 1:
                insert(var);
                break;
            case 2:
                print(var);
                delPointer(var);
                exit(0);  
                break;
        }
    }
    return 0;
}

void insert(data *topo){
    
    data *novo;
	
    novo=aval();
    printf("\nNome: "); 
    scanf("%s",&novo->nome);
    printf("\nIdade: ");
    scanf("%d",&novo->age);
    printf("\nAltura: ");
    scanf("%f",&novo->alt);
    novo->prox=topo->prox;
    topo->prox=novo;
}

void delPointer(data *ponteiro){
	
	data *delete;
	
	delete = ponteiro->prox;
	ponteiro->prox = delete->prox;
	free(delete);
}

int menu(void){
	
	int op = 0;
	
	do {
		printf("-- MENU:\n");
		printf("\t [ 1 ] - Cadastrar pessoa.\n");
		printf("\t [ 2 ] - Sair.\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &op);
	} while (op <= 0 || op > 2);
	getchar();
	return op;
}

data *aval(void){
	
	data *p;
	
	if((p = (data *) malloc(sizeof(data))) == NULL){
		printf("Sem memoria!");
		exit (1);
	}
	return p;
}

data *lista(void){
	
	data *start;
	
	start = (data *) malloc(sizeof(data));
	start->prox = NULL;
	return start;
}
void print(data *aux){
	
	data *p;
	
	for (p = aux->prox; p != NULL; p = p->prox){
		printf("\nNome: %s", p->nome);
        printf("\nIdade: %d",p->age);
        printf("\nAltura: %.2f\n\n",p->alt);
	}
}