#include <iostream>
#include <string> 
#include <locale.h>

using namespace std;

struct data {
	int dia;
	int mes;
	int ano;
};

class Contato {
    private:
        string email;
        string nome;
        string telefone;
        data dtnasc;
    public:
        void setEmail(string email) {
            this->email = email;
        }
        void setNome(string nome) {
            this->nome = nome;
        }
        void setTelefone(string telefone) {
            this->telefone = telefone;
        }
        void setDtnasc(data dtnasc) {
            this->dtnasc = dtnasc;
        }
        
        
        string getEmail() {
            return this->email;
        }
        string getNome() {
            return this->nome;
        }
        string getTelefone() {
            return this->telefone;
        }
        string getDtnasc() {
            string dataFormatada;
            dataFormatada += to_string(this->dtnasc.dia) + "/";
            dataFormatada += to_string(this->dtnasc.mes) + "/";
            dataFormatada += to_string(this->dtnasc.ano);
            
            return dataFormatada;
        }
        
        int idade () {
            return (2023 - this->dtnasc.ano);
        }
};

int main() {
	setlocale(LC_ALL, "");
	
    Contato arrContatos[10];
    int numClasses = 0;
    while (numClasses < 10) {
     string nome;
            string email;
            string telefone;
            string dia;
            string mes;
            string ano;
            struct data nascimento;
            
            cout << "Digite o seu nome: ";
            getline(cin, nome);
            cout << "Digite o seu email: ";
            getline(cin, email);
            cout << "Digite o seu telefone: ";
            getline(cin, telefone);
            cout << "Digite o seu dia de nascimento: ";
            getline(cin, dia);
            cout << "Digite o seu m�s de nascimento: ";
            getline(cin, mes);
            cout << "Digite o seu ano de nascimento: ";
            getline(cin, ano);
            
            nascimento.dia = stoi(dia);
            nascimento.mes = stoi(mes);
            nascimento.ano = stoi(ano);
            
            arrContatos[numClasses].setNome(nome);
            arrContatos[numClasses].setEmail(email);
            arrContatos[numClasses].setTelefone(telefone);
            arrContatos[numClasses].setDtnasc(nascimento);
            
            numClasses++;
    }
   	float somaIdades = 0;
   	int idadeVelho = 0;
   	int numVelho = 0;
   	int numAdultos = 0;
    
    for (int i = 0; i < numClasses; i++) {
		somaIdades += arrContatos[i].idade();
		if (arrContatos[i].idade() > idadeVelho) {
			idadeVelho = arrContatos[i].idade();
			numVelho = i;
		}
		if (arrContatos[i].idade() >= 18) {
			numAdultos++;
		}
	}
	float idadeMedia = somaIdades / numClasses;
	
	string nomeMaioresMedia = "";
	
	for (int i = 0; i < numClasses; i++) {
		if (arrContatos[i].idade() > idadeMedia) {
			nomeMaioresMedia += arrContatos[i].getNome() + ", ";
		}
	}
    
    cout << "A m�dia das idades dos contatos �: " << idadeMedia << endl;
    cout << "Os nomes dos contatos com idade maior que a m�dia �: " << nomeMaioresMedia << endl;
	cout << "A quantidade de maiores de idade �: " << numAdultos << endl;
    cout << "O contato mais velho � " << arrContatos[numVelho].getNome() << ", do email " << arrContatos[numVelho].getEmail() << " e do telefone " << arrContatos[numVelho].getTelefone() << endl;
    
	
    return 0;
}