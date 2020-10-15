#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

#define TAM 10

void MergeSort(int *v, int ini, int meio, int fim){
    int i = ini, j = meio + 1, k = ini;
    int aux[TAM];
    
    while(i <= meio && j <= fim){
        if(v[i] < v[j]){
			aux[k] = v[i];
            i++;
        }
        else{
            aux[k] = v[j];
            j++;
        }
        k++;
    }

    while(i <= meio){
        aux[k] = v[i];
        i++;
        k++;
    }

    while(j <= fim){
        aux[k] = v[j];
        j++;
        k++;
    }
    
    for(i = ini; i <= fim; i++){
        v[i] = aux[i];
	}
}

void MergeSort(int *v, int ini, int fim){
    if(ini < fim){
        int meio = (ini + fim) / 2;
        MergeSort(v, ini, meio);
        MergeSort(v, meio + 1, fim);
        MergeSort(v, ini, meio, fim);
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
	
	MergeSort(v, 0, TAM);
	
	system("clear||cls");
	
	for (int i = 0; i < TAM; i++){
		cout << "[" << v[i] << "] ";
	}	
	
	return 0;
}