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
		
		cout << "Funcionário cadastrado" << endl;		
		system("pause");
		
		return novo;
	}
	else{
		cout << "O prontuário informado já existe" << endl;		
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
		cout << "O prontuário informado não existe" << endl;		
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
		cout << "Prontuário: " << aux->prontuario << endl;
		cout << "Nome: " << aux->nome << endl;
		cout << "Salário: R$" << aux->salario << endl;
		
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
		cout << "Informe a opção desejada: ";
		cin >> opcao;
		
		system("clear||cls");
		
		switch(opcao){
			case 0:
				cout << "Saindo" << endl;
				
				Sair(func);
				
				system("pause");
				break;
			
			case 1:				
				cout << "Prontuário: ";
				cin >> pront;
				
				cout << "Nome: ";
				cin >> nome;
				
				cout << "Salário: ";
				cin >> sal;
				
				Incluir(func, pront, nome, sal);
				
				break;
			
			case 2:				
				cout << "Prontuário: ";
				cin >> pront;
				
				cout << "\nNome: ";
				cin >> nome;
				
				cout << "\nSalário: ";
				cin >> sal;
				
				Excluir(func, pront);
				break;
			
			case 3:	
				if(!Vazio(func)){
					cout << "A lista está vazia" << endl;
					system("pause");
				}
				else{							
					
					
					cout << "Prontuário a ser persquisado: ";
					cin >> pront;
					
					Funcionario *pesquisado = Pesquisar(func, pront);
					
					if (pesquisado != NULL){
						cout << "Prontuário: " << pesquisado->prontuario << endl;
						cout << "Nome: " << pesquisado->nome << endl;
						cout << "Salário: R$" << pesquisado->salario << endl;
					}
					else
					cout << "Não encontrado" << endl;
				
					system("pause");
				}				
				break;
			
			case 4:
				Listar(func);				
				break;
			
			default:
				cout << "Opção inválida" << endl;		
				system("pause");
		};
	
		system("clear||cls");
	}while(opcao != 0);
	
	
	
	
	return 0;
}