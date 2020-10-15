#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

#define TAM 10

void QuickSort(int *v, int ini, int fim)
{
	int i = ini, j = fim - 1, aux, pivo = v[(ini + fim) / 2];
	
	while(i <= j)
	{
		while(v[i] < pivo && i < fim)
		{
			i++;
		}
		while(v[j] > pivo && j > ini)
		{
			j--;
		}
		if(i <= j)
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
	}
	if(j > ini)
		QuickSort(v, ini, j+1);
	if(i < fim)
		QuickSort(v, i, fim);
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	
	int v[TAM];
	
	for (int i = 0; i < TAM; i++){
		cout << "informe o " << i + 1 << "º número: " << endl;
		cin >> v[i];
	}
	
	QuickSort(v, 0, TAM);
	
	system("clear||cls");
	
	for (int i = 0; i < TAM; i++){
		cout << "[" << v[i] << "] ";
	}	
	
	return 0;
}