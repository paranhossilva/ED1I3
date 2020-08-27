#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

using namespace std;

/******************************************************************************/

int m1[3][3], m2[3][3];
bool iguais = true;

/******************************************************************************/

int EntraValor(int n, int i, int j){
	int ret; 
	
	cout << "Digite o valor da Matriz" << n <<"[" << i << "][" << j << "]: " <<endl;
	cin >> ret;
	
	system("clear||cls");
	
	return ret;
}

/******************************************************************************/

void Imprime(int n){
	printf(" [%i] ", n);
}

/******************************************************************************/

bool Verifica(int n1, int n2){
	if (n1 != n2)
		return false;
	else
		return true;	
}

/******************************************************************************/

int main(int argc, char** argv){
	setlocale(LC_ALL, "Portuguese");
	
	for	(int i = 0; i < 3; i++){
		for	(int j = 0; j < 3; j++){
		m1[i][j] = EntraValor(1, i, j);
		}
	}
		
	for	(int i = 0; i < 3; i++){
		for	(int j = 0; j < 3; j++){
			m2[i][j] = EntraValor(2, i, j);
		}
	}
	
	cout << "Matriz1" <<endl;
	
	for	(int i = 0; i < 3; i++){
		for	(int j = 0; j < 3; j++){
			Imprime(m1[i][j]);
		}
		printf("\n");
	}
	
	cout << "\nMatriz2" <<endl;
	
	for	(int i = 0; i < 3; i++){
		for	(int j = 0; j < 3; j++){
			Imprime(m2[i][j]);
		}
		printf("\n");
	}
			
	for	(int i = 0; i < 3; i++){
		for	(int j = 0; j < 3; j++){
			iguais = Verifica(m1[i][j], m2[i][j]);
		}
	}
	
	if(iguais)
		cout << "\nA Matriz1 é igual a Matriz2" <<endl;
	else
	{
		cout << "\nA Matriz1 é diferente da Matriz2" <<endl;
	}
}