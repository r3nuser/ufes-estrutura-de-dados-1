/*
*********************************
* Programa testador do TAD Matriz
*********************************
*/
#include <stdio.h>
#include "matriz.h"

//definindo constantes para o número de linhas e colunas da matriz
#define NLINHAS 5
#define NCOLUNAS 5

int main() {
	Matriz* mat = NULL;
	Matriz* mlt = NULL;
	Matriz* trp = NULL;
	//chamando a funcao do TAD Matriz que inicializa a matriz 
	mat = inicializaMatriz(NLINHAS, NCOLUNAS);
	int i, j;
	//preenchendo a matriz com valores para teste
	for (i=0;i<NLINHAS;i++)
		for (j=0;j<NCOLUNAS; j++)
			//chamando a funcao do TAD matriz para modificar um dado elemento da matriz
			modificaElemento(mat, i, j, i+j);
	//chamando a funcao do TAD matriz para imprimir os elementos da matriz
	imprimeMatriz(mat);

	//chamando a função do TAD para gerar a matriz transposta
	trp = transposta(mat);
	printf("A matriz transposta e:\n");
	imprimeMatriz(trp);

	//chamando a funcao do TAD para gerar a matriz multiplicacao
	
	mlt =  multiplicacao(mat,trp);
	printf("A matriz multiplicacao e:\n");
	imprimeMatriz(mlt);
	printf("A matriz girada 90o eh:\n");
	giraMatriz(mat);
	imprimeMatriz(mat);

        destroiMatriz(mat);
        destroiMatriz(trp);
	destroiMatriz(mlt);
}
