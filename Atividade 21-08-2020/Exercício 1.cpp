#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

using namespace std;
	
/******************************************************************************/

int maior = 0;
double num[10], media = 0;

/******************************************************************************/

void EntraValor(int i){
	
	cout << "Digite o "<< i + 1 << "º valor: " <<endl;
	cin >> num[i];
	
	media += num[i];
	
	system("clear||cls");

}

/******************************************************************************/

void VerificaValor(int i){
	if (num[i] > media)
		maior ++;
}

/******************************************************************************/

int main(int argc, char** argv){
	setlocale(LC_ALL, "Portuguese");
	for	(int i = 0; i < 10; i++){
		EntraValor(i);
	}
	
	media /= 10;
	cout << "Média Aritimética :  "<< media << endl;
	
	for	(int i = 0; i < 10; i++){
		VerificaValor(i);
	}
	
	cout << "Quantidade de valores maiores que a média: "<< maior << endl;
		
	return 0;
}