#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *memAlloc(void);
int *memRealloc(int *x, int quant);
int menu();

int main(){
	
    int *vArray;
    vArray=memAlloc();
    int i, qtd=0;
	
    switch(menu()){
        case 1:
            do{
                printf("Quantos valores voce quer inserir?");
                scanf("%d",&qtd);
            }while(qtd<=0);
            vArray=memRealloc(vArray, qtd);
            for(i=0; i<qtd; i++){
                printf("Valor %d:  ",i+1);
                scanf("%d",&vArray[i]);
            }
            printf("\nValores inseridos:  ");
            for(i=0; i<qtd; i++){
                printf(" %d -",vArray[i]);
            }
            free(vArray);
            break;
        case 2:    
            free(vArray);
            exit(1);
            break;
    }
}

int *memAlloc(void){
	
	int *begin;
	
	begin = (int *) malloc(sizeof(int));
	return begin;
}

int menu(){
	
    int temp = 0;
	
    do{
        printf("Bem-vindo, escolha sua opcao.\n[ 1 ] - Para add valor.\n[ 2 ] - Para SAIR.\nInforme sua opcao:  ");
        scanf("%d",&temp);
    }while(temp<=0);
    return temp;
}

int *memRealloc(int *x, int quant){
	
    x=(int *)realloc(x, quant*sizeof(int));
	
    if(x==NULL){
        printf("\nSem memoria!");
        free(x);
        exit(1);
    }
    return x;
}
