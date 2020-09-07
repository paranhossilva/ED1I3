#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <cstdlib>

using namespace std;

/******************************************************************************/

struct Data{
   int dia, mes, ano;	
};

/******************************************************************************/

class Contato{
	private: 
		string email;
		string nome;
		string telefone;
	private: 
		Data dtNasc;
	
	public:
		/**** Email ****/
		void setEmail(string e){
			email = e;
		}
		string getEmail(){
			return email;
		}
		
		/**** Nome ****/
		void setNome(string n){
			nome = n;
		}
		string getNome(){
			return nome;
		}
		
		/**** Telefone ****/
		void setTelefone(string t){
			telefone = t;
		}
		string getTelefone(){
			return telefone;
		}
		
		/**** Nascimento ****/
		void setDtNasc(int d, int m, int a){
			dtNasc.dia = d;
			dtNasc.mes = m;
			dtNasc.ano = a;
		}
		void getDtNasc(){
			printf("Data de Nacimento: %i/%i/%i\n", dtNasc.dia, dtNasc.mes, dtNasc.ano);
		}
		
		int getIdade(){
			int idade;
			time_t myTime = time(NULL);
    		struct tm tm = *localtime(&myTime);    
			
			idade = (tm.tm_year + 1900) - dtNasc.ano;
			
			if((dtNasc.mes > (tm.tm_mon + 1)) || (dtNasc.mes == (tm.tm_mon + 1) && dtNasc.dia < tm.tm_mday))
				idade--;
			
			return idade;
		}
};

/******************************************************************************/

void Pausa(){
	system("pause");
	system("clear||cls");
}

/******************************************************************************/

void Imprime(string nome, string email, string telefone, int idade){
	cout << nome << endl;
	cout << "Email: " << email << endl;
	cout << "Telefone: " << telefone << endl;
	cout << "Idade: " << idade << " Anos" << endl;
}

/******************************************************************************/

int main(int argc, char** argv){	
	setlocale(LC_ALL, "Portuguese");
	
	string str;
	int d, m, a, maisVelho = 0, maiorIdade = 0;
	double media;
	Contato contato[10];
	
	/**** Entrada ****/	
	for(int i = 0; i < 10; i++){	
		cout << "Nome do Contato " << i + 1 << ": ";
		cin >> str;
		contato[i].setNome(str);
		
		cout << "Email do Contato " << i + 1 << ": ";
		cin >> str;
		contato[i].setEmail(str);
		
		cout << "Telefone do Contato " << i + 1 << ": ";
		cin >> str;
		contato[i].setTelefone(str);
		
		cout << "Dia de nascimento do Contato " << i + 1 << ": ";
		cin >> d;
		
		cout << "Mês de nascimento do Contato " << i + 1 << ": ";
		cin >> m;
		
		cout << "Ano de nascimento do Contato " << i + 1 << ": " ;
		cin >> a;
		
		system("clear||cls");
		
		contato[i].setDtNasc(d, m, a);
	}
	
	/**** Todos os contatos ****/
	for(int i = 0; i < 10; i++){
		Imprime(contato[i].getNome(), contato[i].getEmail(), contato[i].getTelefone(), contato[i].getIdade());
		
		contato[i].getDtNasc();
		cout << "\n--------------------------------------------------------\n" << endl;
		
		media += contato[i].getIdade();
		
		if(contato[i].getIdade() > maisVelho)
			maisVelho = contato[i].getIdade();
		if(contato[i].getIdade() >= 18)
			maiorIdade++;
	}
	
	Pausa();
	
	media /= 10;
	
	/**** Média de idade ****/
	cout << "\nMédia de idade: " << media << endl;
	
	Pausa();
	
	/**** Idade maior que a média ****/
	cout << "Contatos cuja idade é maior que a média\n" << endl;
	
	for(int i = 0; i < 10; i++){
		if(contato[i].getIdade() > media){
			Imprime(contato[i].getNome(), contato[i].getEmail(), contato[i].getTelefone(), contato[i].getIdade());
		
			contato[i].getDtNasc();
			cout << "\n--------------------------------------------------------\n" << endl;
		}
	}
	
	Pausa();
	
	/**** Maiores de idade ****/	
	cout << "\nQuatidade de contatos maiores de idade: " << maiorIdade << endl;
	cout << "Contatos maiores de idade\n" << endl;
	
	for(int i = 0; i < 10; i++){
		if(contato[i].getIdade() >= 18){
			Imprime(contato[i].getNome(), contato[i].getEmail(), contato[i].getTelefone(), contato[i].getIdade());
		
			contato[i].getDtNasc();
			cout << "\n--------------------------------------------------------\n" << endl;
		}
	}
	
	Pausa();
	
	/**** Mais velho ****/
	cout << "Contato(s) mais velho(s)\n" << endl;
	
	for(int i = 0; i < 10; i++){
		if(contato[i].getIdade() == maisVelho){
			Imprime(contato[i].getNome(), contato[i].getEmail(), contato[i].getTelefone(), contato[i].getIdade());
		
			contato[i].getDtNasc();
			cout << "\n--------------------------------------------------------\n" << endl;
		}
	}
	
	return 0;	
}