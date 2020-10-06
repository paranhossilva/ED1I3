#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

	int qtdSenha = 0;

    void setQtdSenha(int s) {
      qtdSenha = s;
    }
    
    int getQtdSenha() {
      return qtdSenha;
    }

struct Senha{
	int senha;
	struct Senha* prox;
};

struct SenhasGeradas{
	   Senha* ini;
	   Senha* fim;	
};

struct SenhasAtendidas{
	   Senha* ini;
	   Senha* fim;	
};

SenhasGeradas* initGeradas(){
	SenhasGeradas *ge = new SenhasGeradas;
	ge->ini = NULL;
	ge->fim = NULL;
	return ge;
}

SenhasAtendidas* initAtendidas(){
	SenhasAtendidas *at = new SenhasAtendidas;
	at->ini = NULL;
	at->fim = NULL;
	return at;
}

bool VazioGeradas(SenhasGeradas* ge){
	return (ge->ini == NULL);
}

bool VazioAtendidas(SenhasAtendidas* at){
	return (at->ini == NULL);
}

void GeraSenha(SenhasGeradas* geradas, int s){
	Senha* senha = new Senha;
	senha->senha = s;
	senha->prox = NULL;
	
	if(VazioGeradas(geradas))
		geradas->ini = senha;
	else
		geradas->fim->prox = senha;
	
	geradas->fim = senha;
}

int AtendeSenha(SenhasGeradas* geradas, SenhasAtendidas* atendidas){
	int ret;
	
	/********** Remove SenhaGerada **********/
	Senha *aux;
	aux = geradas->ini;
	
	ret = aux->senha;
	
	geradas->ini = aux->prox;
	
	if(geradas->ini == NULL)
		geradas->fim == NULL;
	
	free(geradas);
	
	/********** Adiciona SenhaAtendida **********/
	
	Senha* senha = new Senha;
	senha->senha = ret;
	senha->prox = NULL;
	
	if(VazioAtendidas(atendidas))
		atendidas->ini = senha;
	else
		atendidas->fim->prox = senha;
	
	atendidas->fim = senha;
	
	setQtdSenha(getQtdSenha() + 1);
	
	return ret;
}

int Conta(SenhasGeradas *geradas){
	int qtd = 0;
	
	Senha *senha;
	senha = geradas->ini;
	
	while(senha != NULL){
		senha = senha->prox;
		qtd++;
	}
	
	return qtd;
}


int main(int argc, char** argv){
	setlocale(LC_ALL, "Portuguese");
	
	SenhasGeradas* geradas = initGeradas();
	SenhasAtendidas* atendidas = initAtendidas();
	
	int opcao, senha = 0;
	
	do{
		cout << "0. Sair \n1. Gerar Senha \n2. Realizar Atendimento" << endl;
		cout << "Informe a opção desejada: ";
		cin >> opcao;
		
		system("clear||cls");
		
		switch(opcao){
			case 0: 				
				if (VazioGeradas(geradas))
					cout << "Senhas Atendidas: " << getQtdSenha() << endl;
				else
					cout << "Ainda há senhas aguardando atendimento" << endl;
									
				system("pause");
				system("clear||cls");
				
				break;
			
			case 1:
				senha++;
				
				GeraSenha(geradas, senha);
				
				cout << "Senha " << senha << " aguardando atendimento" << endl;
				system("pause");
				system("clear||cls");
				
				break;
			
			case 2:
				if (VazioGeradas(geradas))
					cout << "Não há senhas aguardando atendimento" << endl;
				else				
					cout << "Senha Atendida: " << AtendeSenha(geradas, atendidas) << endl;
				
				system("pause");
				system("clear||cls");
				
				break;
			
			default:
				cout << "Opção inválida" << endl;		
				system("pause");
				system("clear||cls");
				
				break;		
		}
		
		cout << "Quantidade de senhas aguardando atendimento: " << Conta(geradas) << endl;
		
		system("pause");
		system("clear||cls");
				
	}while(!VazioGeradas(geradas) && opcao != 0);
	
	return 0;
}