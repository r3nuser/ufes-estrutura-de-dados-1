#include <stdio.h>
#include <stdlib.h>
#include "listahet.h"

ListaHet* cria(){
	ListaHet* lista = (ListaHet*) malloc(sizeof(ListaHet));

	lista->id_item = _U;

	return lista;
}

Cliente* cria_cliente(char* nome, int id){
	Cliente* c = (Cliente*) malloc(sizeof(Cliente));

	if( c == NULL ) return NULL;

	c->nome = nome;
	c->id = id;

	return c;
}

Movel* cria_movel(int placa, int ano, float valor){
	Movel* m = (Movel*) malloc(sizeof(Movel));

	if( m == NULL ) return NULL;

	m->placa = placa;
	m->ano = ano;
	m->valor = valor;

	return m;
}

Imovel* cria_imovel(int id, int ano, float valor){
	Imovel* i = (Imovel*) malloc(sizeof(Imovel));

	if( i == NULL ) return NULL;

	i->id = id;
	i->ano = ano;
	i->valor = valor;

	return i;
}

ListaHet* insere_movel(ListaHet* lista, Cliente* dono, Movel* item){
	if( lista == NULL ||
	    dono  == NULL ||
	    item  == NULL    ) return;

	if(lista->id_item == _U){
		lista->dono = dono;
		lista->item = (void*) item;
		lista->id_item = _M;
		lista->prox = NULL;		

		return lista;
	}
	
	ListaHet* auxiliar = lista->next;
	ListaHet* auxiliar2;
	
	while( auxiliar->next != NULL ) auxiliar = auxiliar->next;

	auxiliar2 = cria();

	auxiliar->prox = auxiliar2;

	auxiliar2->prox = NULL;
	auxiliar2->dono = dono;
	auxiliar2->item = (void*) item;
	auxiliar2->id_item = _M;	
	
	return auxiliar2;
}

ListaHet* insere_imovel(ListaHet& lista, Cliente* dono, Imovel* item){
	if( lista == NULL ||
            dono  == NULL ||
            item  == NULL    ) return;

        if(lista->id_item == _U){
                lista->dono = dono;
                lista->item = (void*) item;
                lista->id_item = _I;
                lista->prox = NULL;

                return lista;
        }

        ListaHet* auxiliar = lista->next;
        ListaHet* auxiliar2;

        while( auxiliar->next != NULL ) auxiliar = auxiliar->next;

        auxiliar2 = cria();

        auxiliar->prox = auxiliar2;

        auxiliar2->prox = NULL;
        auxiliar2->dono = dono;
        auxiliar2->item = (void*) item;
        auxiliar2->id_item = _I;

        return auxiliar2;

}

void imprime(ListaHet* lista){

}

ListaHet* retira_cliente(ListaHet* lista, int id_cliente){

}

float calcula_valor_assegurado(ListaHet* lista, Client* ono, float taxa_movel, float taxa_imovel){

}
