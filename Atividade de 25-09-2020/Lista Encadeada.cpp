#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
using namespace std;

#define MAX 30

struct Par{
	int num;
	struct Par *prox;
};

struct Impar{
	int num;
	struct Impar *prox;
};

struct PilhaPar{
	Par *topo;
};

struct PilhaImpar{
	Impar *topo;
};

PilhaPar* initPar(){
	PilhaPar *p = new PilhaPar;
	p->topo = NULL;
	return p;	
}

PilhaImpar* initImpar(){
	PilhaImpar *p = new PilhaImpar;
	p->topo = NULL;
	return p;	
}

/********* Inserir *********/ 
void Inserir(PilhaPar *p, int num){
	Par *par = new Par;
	par->num = num;
	par->prox = p->topo;
	p->topo = par;
}

void Inserir(PilhaImpar *p, int num){
	Impar *impar = new Impar;
	impar->num = num;
	impar->prox = p->topo;
	p->topo = impar;
}

/********* Imprimir *********/
void Imprimir(PilhaPar *p){
	Par *par;
	par->prox = p->topo;
	
	while(par != NULL)
	{
		cout << par->num << endl;
		par = par->prox;
	}
}

void Imprimir(PilhaImpar *p){
	Impar *impar;
	impar->prox = p->topo;
	
	while(impar != NULL)
	{
		cout << impar->num << endl;
		impar = impar->prox;
	}
}

void Limpar(PilhaPar* p){
	Par *par = p->topo;
	
	while(par != NULL){
		Par *temp = par->prox;
		free(par);
		
		par = temp;
	}
	
	free(p);
}

void Limpar(PilhaImpar* p){
	Impar *impar = p->topo;
	
	while(impar != NULL){
		Impar *temp = impar->prox;
		free(impar);
		
		impar = temp;
	}
	
	free(p);
}

/******************************************/

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	
	PilhaPar *par = initPar();
	PilhaImpar *impar = initImpar();
	
	int num, aux;
	
	cout << "1º Número: ";
	cin >> num;
	
	if(num%2 == 0)
			Inserir(par, num);
		else
			Inserir(impar, num);
	
	for (int i = 2; i <= MAX; i++){
		aux = num;
		
		do{		
			cout << i << "º Número: ";
			cin >> num; 
		}while(num <= aux);
		
		if(num%2 == 0)
			Inserir(par, num);
		else
			Inserir(impar, num);
	}
	
	cout << "--------- Números Pares ---------" << endl;
	Imprimir(par);
	cout << "--------- Números Impares ---------" << endl;
	Imprimir(impar);
	
	Limpar(par);
	Limpar(impar);
	
	return 0;
}

