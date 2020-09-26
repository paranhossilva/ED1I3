#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
using namespace std;

struct Funcionario{
	int prontuario;
	string nome;
	double salario;	
};

struct Lista{
	struct Funcionario func;
	struct Lista *prox;
};

/********* Inicia *********/
Lista* init(){
	return NULL;
}

/********* Vazio *********/
bool Vazio(Lista* lista){
	return (lista == NULL);
}

/********* Pesquisar *********/
Lista* Pesquisar(Lista* lista, int pront){
	Lista* aux = lista;	
	
	while(aux != NULL && aux->func.prontuario != pront){
		aux = aux->prox;
	}
	
	return aux;
}

/********* Incluir *********/
Lista* Incluir(Lista* lista, int pront, string nome, double sal){
	if(Pesquisar(lista, pront) == NULL){
		Lista* novo = new Lista;
		
		novo->func.prontuario = pront;
		novo->func.nome = nome;
		novo->func.salario = sal;
		novo->prox = lista;
		
		cout << "Funcion�rio cadastrado" << endl;		
		system("pause");
		
		return novo;
	}
	else{
		cout << "O prontu�rio informado j� existe" << endl;		
		system("pause");
		return lista;
	}
}

/********* Excluir *********/
Lista* Excluir(Lista* lista, int pront){
	Lista* ant = NULL;
	Lista* aux = lista;
	
	while(aux != NULL && aux->func.prontuario != pront){
		ant = aux;
		aux = aux->prox;
	}
	
	if(aux == NULL){
		cout << "O prontu�rio informado n�o existe" << endl;		
		system("pause");
		return lista;
	}
	else{	
		if (ant == NULL)
			lista = aux->prox;
		else			
			ant->prox = aux->prox;
			
		free(aux);
		
		cout << "Funcion�rio Exclu�do" << endl;		
		system("pause");
		
		return lista;
	}
}

/********* Listar *********/
void Listar(Lista* lista){
	Lista* aux;
	aux = lista;
	
	while (aux != NULL){
		cout << "Prontu�rio: " << aux->func.prontuario << endl;
		cout << "Nome: " << aux->func.nome << endl;
		cout << "Sal�rio: R$" << aux->func.salario << endl;
		cout << "------------------------------------------" << endl;
		
		aux = aux->prox;
	}
}

/********* Sair *********/
void Sair(Lista* lista){
	Lista* aux = lista;
	
	while(aux != NULL){
		Lista *ant = aux->prox;
		
		free(aux);
		
		aux = ant;
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	
	Lista *minhaLista;
	minhaLista = init();
	int opcao,  pront;
	string nome;
	double sal;

	do{
		cout << "0. Sair \n1. Incluir \n2. Excluir \n3. Pesquisar \n4. Listar" << endl;
		cout << "Informe a op��o desejada: ";
		cin >> opcao;
		
		system("clear||cls");
		
		switch(opcao){
			/********* Sair *********/
			case 0: 
				cout << "Saindo" << endl;
				
				Sair(minhaLista);
				
				system("pause");
				break;
			
			/********* Incluir *********/
			case 1:				
				cout << "Prontu�rio: ";
				cin >> pront;
				
				cout << "Nome: ";
				cin >> nome;
				
				cout << "Sal�rio: ";
				cin >> sal;
				
				minhaLista = Incluir(minhaLista, pront, nome, sal);
				
				break;
			
			/********* Excluir *********/
			case 2:
				if(Vazio(minhaLista)){
					cout << "A lista est� vazia" << endl;					
					system("pause");
				}
				else{							
					cout << "Prontu�rio: ";
					cin >> pront;
					
					minhaLista = Excluir(minhaLista, pront);
				}
				break;
			
			/********* Pesquisar *********/
			case 3:	
				if(Vazio(minhaLista)){
					cout << "A lista est� vazia" << endl;
					system("pause");
				}
				else{							
					
					
					cout << "Prontu�rio a ser persquisado: ";
					cin >> pront;
					
					Lista *pesquisado = Pesquisar(minhaLista, pront);
					
					if (pesquisado != NULL){
						cout << "Prontu�rio: " << pesquisado->func.prontuario << endl;
						cout << "Nome: " << pesquisado->func.nome << endl;
						cout << "Sal�rio: R$" << pesquisado->func.salario << endl;
					}
					else
					cout << "N�o encontrado" << endl;
				
					system("pause");
				}				
				break;

			/********* Listar *********/
			case 4: 
				if(Vazio(minhaLista))
					cout << "A lista est� vazia" << endl;
				else
					Listar(minhaLista);	
								
				system("pause");			
				break;
			
			default:
				cout << "Op��o inv�lida" << endl;		
				system("pause");
		};
	
		system("clear||cls");
	}while(opcao != 0);
	
	return 0;
}