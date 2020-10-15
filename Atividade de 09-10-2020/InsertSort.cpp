#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

#define TAM 10

void InsertSort(int *v) {
	int i, j, num;
	
    for (i = 1; i < TAM; i++) {
		num = v[i];
		j = i - 1;
		
		while ((j >= 0) && (v[j] > num)) {
			v[j + 1] = v[j];
			j--;
		}
		
		v[j + 1] = num;
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
	
	InsertSort(v);
	
	system("clear||cls");
	
	for (int i = 0; i < TAM; i++){
		cout << "[" << v[i] << "] ";
	}	
	
	return 0;
}