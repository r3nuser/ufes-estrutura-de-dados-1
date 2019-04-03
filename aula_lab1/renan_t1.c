//---------------------------------------------------------------//
// NOME: RENAN MOREIRA GOMES                                     //
// PROFESSOR: VINICIUS                                           //
// TURMA: CCOMP T1                                               //
//---------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exercicio_01();
void exercicio_02();
void exercicio_03();
void exercicio_04();
void exercicio_05();
void exercicio_06();
void exercicio_07();

int main( void ){
	int op = 0;

	scanf("%d", &op);

	switch( op ){
		case 1:
			exercicio_01();
			break;
		case 2:
			exercicio_02();
			break;
		case 3:
			exercicio_03();
			break;
		case 4:
			exercicio_04();
			break;
		case 5:
			exercicio_05();
			break;
		case 6:
			exercicio_06();
			break;
		case 7:
			exercicio_07();
			break;
	}

	return 0;
}

void exercicio_01(){
	int a = 0;
	float b = 0;
	char c = 'a';

	int* ap = &a;
	float* bp = &b;
	char* cp = &c;

	printf("%d, %f, %c\n", a, b, c);

	*ap = 1;
	*bp = 2.5;
	*cp = 'd';

	printf("%d, %f, %c\n", a, b, c);

	return;
}

void exercicio_02(){
	int a, b;

	if( &a > &b ) printf("Endereco: %x\n", &a);
	else printf("Endereco: %x\n", &b);

	return;
}
//--------------------------------------//
int TrocaInteiros( int *n1, int *n2 ){
	int aux = *n1;

	if( *n1 > *n2 ){
		*n1 = *n2;
		*n2 = aux;
		return 1;
	}

	return 0;
}

void exercicio_03(){
	int n1, n2;

	while ( scanf("%d %d", &n1, &n2) == 2 ){
		if ( TrocaInteiros( &n1, &n2 ) ){
			printf("TROCADO: %d %d\n", n1, n2);
		} else {
			printf("ORIGINAL: %d %d\n", n1, n2);
		}
	}

	return;
}
//---------------------------------------//
void foo_04(int* array, int len, int var){
	int i = 0;

	for( i = 0 ; i < len ; i++ ){
		array[i] = var;
		printf("[%d]", array[i]);
	}
	printf("\n");
}
void exercicio_04(){
	int len = 10;
	int array[len];
	int var = 5;

	foo_04(array, len, var);

}
//-----------------------//
void exercicio_05(){}
//-----------------------//
void inverte( int n, int* vet ){
	int* aux = malloc( sizeof(int) * n );
	int i = 0;

	for( i = 0 ; i < n ; i++ ){
		aux[i] = vet[i];
	}
	for( i = 0 ; i < n ; i++ ){
		vet[n - i - 1] = aux[i];
	}
	for( i = 0 ; i < n ; i++ ){
		printf("[%d]", vet[i]);
	}

	free(aux);

	return;
}

void exercicio_06(){
	int n = 5;
	int vet[5] = { 3, 1, 3, 3, 6 };
	inverte( n, vet );
}
//---------------------------------------//
int substring(char* fst, char* snd){
	int i = 0;
	int j = 0;

	int fst_len = strlen(fst);
	int snd_len = strlen(snd);

	int recorrence = 0;

	for( i = 0 ; i < fst_len ; i++ ){
		if( fst[i] == snd[0] ){
			for( j = 0 ; j < snd_len ; j++ ){
				if( i + j >= fst_len ) break;
				if( fst[i + j] == snd[j] ) recorrence++;
			}
			if( recorrence == snd_len ) return 1;
			else{
				recorrence = 0;
				continue;
			}
		}
	}

	return 0;
}

void exercicio_07(){
	char* fst = malloc(sizeof(char) * 20);
	char* snd = malloc(sizeof(char) * 20);

	scanf("%s", fst);
	scanf("%s", snd);

	if( substring( fst, snd ) ) printf("Foo\n");

	free(fst);
	free(snd);

	return;
}





























