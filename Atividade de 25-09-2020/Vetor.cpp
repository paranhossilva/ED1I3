#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
using namespace std;

#define MAX 30

struct Par{
	int qtd;
	float no[MAX];	
};

struct Impar{
	int qtd;
	float no[MAX];	
};

Par* initPar(){
	Par *par = new Par;
	
	par->qtd = 0;
	
	return par;
}

Impar* initImpar(){
	Impar *impar = new Impar;
	
	impar->qtd = 0;
	
	return impar;
}

/********* Inserir *********/ 
int Inserir(Par *par, int num){
	int empilhar = (par->qtd < MAX);
	
	if(empilhar){
		par->no[par->qtd] = num;
		par->qtd++;
	}
	return empilhar;
}

int Inserir(Impar *impar, int num){
	int empilhar = (impar->qtd < MAX);
	
	if(empilhar){
		impar->no[impar->qtd] = num;
		impar->qtd++;
	}
	return empilhar;
}

/********* Imprimir *********/
void Imprimir(Par *par){
	for(int i = par->qtd - 1; i >= 0; i--){
		cout << par->no[i] << endl;
	}
}

void Imprimir(Impar *impar){
	for(int i = impar->qtd - 1; i >= 0; i--){
		cout << impar->no[i] << endl;
	}
}

/******************************************/

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	
	Par *par = initPar();
	Impar *impar = initImpar();
	
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
	
	free(par);
	free(impar);
	
	return 0;
}