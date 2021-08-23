#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printVet (int *vet, int n);
int* colMatriz(int ** mat, int m, int n, int nCol);
int lerMatriz(int **mat, int m, int n);
void printMatriz(int **mat, int m, int n);
void freeMatriz(int **mat, int nCol);
int sumMatriz(int **mat, int m, int n);
int **initMatriz(int m, int n);

int main(){
	
    int coluna=0;
    int linha=0;
    int **var;
	
    do{
        printf("Insira quantidade de linha(s) da matriz: ");
        scanf("%d",&linha);
    }while(linha<=0);
    do{
        printf("Insira a quantidade de coluna(s) da matriz: ");
        scanf("%d",&coluna);
    }while(coluna<=0);
    var=initMatriz(linha, coluna);
    var=lerMatriz(var, linha, coluna);
    sumMatriz(var, linha, coluna);
    printMatriz(var, linha, coluna);
    colMatriz(var, linha, coluna, 0);
    printVet (var, coluna); 
    freeMatriz(var, linha);
    return(0);

}

void printVet(int *vet, int n){
	
    int i;
	
    printf("\nVetor:  ");
    for(i=0; i<n; i++){
        printf(" %d  ",vet[i]);
    }
}

int *colMatriz(int ** mat, int m, int n, int nCol){
	
    int i,j;
    int *p;
	
    p=(int *)malloc(n*sizeof(int));
    if((p=(int **)malloc(n*sizeof(int)))==NULL){
        printf("\nSEM ESPACO DE MEMORIA!");
        exit(1);
    }
	
    printf("\nElementos da coluna %d:",nCol);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(i==nCol){
                printf(" -  %d ",mat[j][i]);
                p[i]=mat[j][i];
            }
        }
    }
    return p;
}

int lerMatriz(int **mat, int m, int n){
	
    int i,j;
	
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("Insira o valor na posicao [%d][%d]:  ", i, j);
            scanf("%d",&mat[i][j]);
        }
    }
    return mat;
}

void printMatriz(int **mat, int m, int n){
	
    int i,j;
	
    printf("Matriz:");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("\n[%d][%d]: %d",i,j,mat[i][j]);
        }
    }
}

void freeMatriz(int **mat, int nCol){
	
    int i;
	
    for(i=0; i<nCol; i++){
        free(mat[i]);
    }
    free(mat);
}

int sumMatriz(int **mat, int m, int n){
	
    int i,j;
    int soma=0;
	
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            soma=soma+mat[i][j];
        }
    }
    printf("\n\nSoma resultante da matriz: %d\n",soma);
}

int ** initMatriz(int m, int n){
    int i;
    int **mat;
    mat=(int **)malloc(m*sizeof(int*));
    for(i=0; i<m; i++){
        mat[i]=(int *)malloc(n*sizeof(int));
        if(((int *)malloc(n*sizeof(int)))==NULL){
            printf("\nSEM ESPACO DE MEMORIA!");
            exit(1);
        }
    }
    return mat;
}
