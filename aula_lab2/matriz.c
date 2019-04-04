#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct matriz {
	int row;
	int col;
	int **mat;
} Matriz;

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
	

	Matriz* mat = (Matriz*) malloc(sizeof(Matriz));
	
	if( mat == NULL ) return NULL;

	mat->mat = (int**) malloc(sizeof(int*) * nlinhas);

	if( mat->mat == NULL ) return NULL;

	mat->row = nlinhas;
	mat->col = ncolunas;
	
	int i = 0;
	
	for( i = 0 ; i < ncolunas ; i++ ){
		mat->mat[i] = (int*) malloc(sizeof(int) * ncolunas);
	}

	return mat;

}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
	
	if( mat == NULL ) return;
	if( linha > recuperaNLinhas(mat) - 1 || linha < 0 ) return;
	if( coluna > recuperaNColunas(mat) -1 || coluna < 0 ) return;

	mat->mat[linha][coluna] = elem;

}

int recuperaElemento(Matriz* mat, int linha, int coluna){ return mat->mat[linha][coluna]; }

int recuperaNColunas (Matriz* mat){ return mat->col; }

int recuperaNLinhas (Matriz* mat){ return mat->row; }

Matriz* transposta (Matriz* mat){ 

	Matriz* transposta = inicializaMatriz( recuperaNColunas(mat), recuperaNLinhas(mat) );

	if( transposta == NULL ) return NULL;

	int i = 0;
	int j = 0;

	int k = recuperaNLinhas(mat);
	int l = recuperaNColunas(mat);

	for( i = 0 ; i < k ; i++ )
		for( j = 0 ; j < l ; j++ )
			transposta->mat[j][i] = mat->mat[i][j];

	return transposta;

}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){

	int i = 0;
	int j = 0;
	int k = 0;

	int l = recuperaNLinhas(mat1);
	int m = recuperaNColunas(mat2);
	int n = recuperaNColunas(mat1);

	Matriz* multiplicada = inicializaMatriz( recuperaNLinhas(mat1), recuperaNColunas(mat2) );

	if( multiplicada == NULL ) return NULL;

	for( i = 0 ; i < l ; i++ ){
		
		multiplicada->mat[i][j] = 0;
		
		for( j = 0 ; j < m ; j++ )
			for( k = 0 ; k < n ; k++ )
				multiplicada->mat[i][j] +=  mat1->mat[i][k] * mat2->mat[k][j];	
	
	}
	
	return multiplicada;

}

void imprimeMatriz(Matriz* mat){

	if( mat == NULL ) return;

	int i = 0;
	int j = 0;

	int k = recuperaNLinhas(mat);
	int l = recuperaNColunas(mat);

	printf("\n");
	for( i = 0 ; i < k ; i++ ){
		for( j = 0 ; j < l ; j++ )
			printf("[%d]", mat->mat[i][j]);
		printf("\n");
	}
	printf("\n");

}

void destroiMatriz(Matriz* mat){
	
	if( mat == NULL ) return;
	
	int i = 0;
	int k = recuperaNLinhas(mat);

	for( i = 0 ; i < k ; i++ )
		free(mat->mat[i]);

	free(mat->mat);

	free(mat);

}

void trocaElemento(Matriz* mat, int a, int b, int c, int d){
	int aux = mat->mat[a][b];
	mat->mat[a][b] = mat->mat[c][d];
	mat->mat[c][d] = aux;
}

void giraMatriz(Matriz* mat){

	int i = 0;
	int j = 0;
	int k = recuperaNLinhas(mat);
	int l = recuperaNColunas(mat);

	for( i = 0 ; i < k ; i++ )
		for( j = 0 ; j < l ; j++ ){
			 
		}

	
	return;
}

