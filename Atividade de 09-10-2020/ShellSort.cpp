#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

#define TAM 10

void ShellSort(int *v) {

    int h = 1, i, j, rep = 0, aux;

    while (h < TAM) {
       h = h*3+1;
    }

    while (h > 1) {
        h /= 3;

        for (i = h; i < TAM; i++) {
            aux = v[i];
            j = i;

            while (j >= h && aux < v[j-h]) {
                v[j] = v[j-h];
                j -= h;
                rep++;
            }

            v[j] = aux;
        }
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
	
	ShellSort(v);
	
	system("clear||cls");
	
	for (int i = 0; i < TAM; i++){
		cout << "[" << v[i] << "] ";
	}	
	
	return 0;
}