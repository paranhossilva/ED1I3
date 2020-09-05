#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

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

int main(int argc, char** argv){	
	setlocale(LC_ALL, "Portuguese");
	
	string str;
	int d, m, a;
	Contato contato;
		
	cout << "Nome: ";
	cin >> str;
	contato.setNome(str);
	
	cout << "Email: ";
	cin >> str;
	contato.setEmail(str);
	
	cout << "Telefone: ";
	cin >> str;
	contato.setTelefone(str);
	
	cout << "Dia de nascimento: ";
	cin >> d;
	
	cout << "Mês de nascimento: ";
	cin >> m;
	
	cout << "Ano de nascimento: " ;
	cin >> a;
	
	system("clear||cls");
	
	contato.setDtNasc(d, m, a);
	
	cout << contato.getNome() << endl;
	cout << "Email: " << contato.getEmail() << endl;
	cout << "Telefone: " << contato.getTelefone() << endl;
	contato.getDtNasc();
	cout << "Idade: " << contato.getIdade() << " Anos" <<endl;

	return 0;	
}