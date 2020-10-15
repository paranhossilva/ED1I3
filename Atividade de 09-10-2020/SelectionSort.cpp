#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

#define TAM 10

void SelectionSort(int *v) {
	int i, j, k, aux;
	
    for (i = 0; i < TAM; i++) {
        j = i;
        
        for (k = i + 1; k < TAM; k++) {
            if (v[k] < v[j])
                j = k;
        }
        
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	
	int v[TAM];
	
	for (int i = 0; i < TAM; i++){
		cout << "informe o " << i + 1 << "º número: " << endl;
		cin >> v[i];
	}
	
	SelectionSort(v);
	
	system("clear||cls");
	
	for (int i = 0; i < TAM; i++){
		cout << "[" << v[i] << "] ";
	}	
	
	return 0;
}