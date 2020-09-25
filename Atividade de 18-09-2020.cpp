#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
using namespace std;

struct Funcionario{
	int prontuario;
	string nome;
	double salario;
	struct Funcionario *prox;	
};

/********* Inicia *********/
Funcionario* init(){
	return NULL;
}

/********* Vazio *********/
bool Vazio(Funcionario* f){
	if(f == NULL)
		return true;
	else
		return false;
}

/********* Pesquisar *********/
Funcionario* Pesquisar(Funcionario* f, int pront){
	Funcionario* aux = f;	
	
	while(aux != NULL && aux->prontuario != pront){
		aux = aux->prox;
	}
	
	return aux;
}

/********* Incluir *********/
Funcionario* Incluir(Funcionario* f, int pront, string nome, double sal){
	if(Pesquisar(f, pront) == NULL){
		Funcionario* novo = new Funcionario;
		
		novo->prontuario = pront;
		novo->nome = nome;
		novo->salario = sal;
		novo->prox = f;
		
		cout << "Funcion�rio cadastrado" << endl;		
		system("pause");
		
		return novo;
	}
	else{
		cout << "O prontu�rio informado j� existe" << endl;		
		system("pause");
		return f;
	}
}

/********* Excluir *********/
Funcionario* Excluir(Funcionario* f, int pront){
	Funcionario* ant = NULL;
	Funcionario* aux = f;
	
	while(aux != NULL && aux->prontuario != pront){
		ant = aux;
		aux = aux->prox;
	}
	
	if(aux == NULL){
		cout << "O prontu�rio informado n�o existe" << endl;		
		system("pause");
		return f;
	}
	else{	
		if (ant == NULL)
			f = aux->prox;
		else			
			ant->prox = aux->prox;
			
		free(aux);
		
		return f;
	}
}

/********* Listar *********/
void Listar(Funcionario* f){
	Funcionario* aux;
	aux = f;
	
	while (aux != NULL){
		cout << "Prontu�rio: " << aux->prontuario << endl;
		cout << "Nome: " << aux->nome << endl;
		cout << "Sal�rio: R$" << aux->salario << endl;
		
		aux = aux->prox;
	}
}

/********* Sair *********/
void Sair(Funcionario* f){
	Funcionario* aux = f;
	
	while(aux != NULL){
		Funcionario *ant = aux->prox;
		
		free(aux);
		
		aux = ant;
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	
	Funcionario *func;
	func = init();
	int opcao,  pront;
	string nome;
	double sal;

	do{
		cout << "0. Sair \n1. Incluir \n2. Excluir \n3. Pesquisar \n4. Listar" << endl;
		cout << "Informe a op��o desejada: ";
		cin >> opcao;
		
		system("clear||cls");
		
		switch(opcao){
			case 0:
				cout << "Saindo" << endl;
				
				Sair(func);
				
				system("pause");
				break;
			
			case 1:				
				cout << "Prontu�rio: ";
				cin >> pront;
				
				cout << "Nome: ";
				cin >> nome;
				
				cout << "Sal�rio: ";
				cin >> sal;
				
				Incluir(func, pront, nome, sal);
				
				break;
			
			case 2:				
				cout << "Prontu�rio: ";
				cin >> pront;
				
				cout << "\nNome: ";
				cin >> nome;
				
				cout << "\nSal�rio: ";
				cin >> sal;
				
				Excluir(func, pront);
				break;
			
			case 3:	
				if(!Vazio(func)){
					cout << "A lista est� vazia" << endl;
					system("pause");
				}
				else{							
					
					
					cout << "Prontu�rio a ser persquisado: ";
					cin >> pront;
					
					Funcionario *pesquisado = Pesquisar(func, pront);
					
					if (pesquisado != NULL){
						cout << "Prontu�rio: " << pesquisado->prontuario << endl;
						cout << "Nome: " << pesquisado->nome << endl;
						cout << "Sal�rio: R$" << pesquisado->salario << endl;
					}
					else
					cout << "N�o encontrado" << endl;
				
					system("pause");
				}				
				break;
			
			case 4:
				Listar(func);				
				break;
			
			default:
				cout << "Op��o inv�lida" << endl;		
				system("pause");
		};
	
		system("clear||cls");
	}while(opcao != 0);
	
	
	
	
	return 0;
}