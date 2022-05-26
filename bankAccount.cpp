#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;

// creare file e scriverci sopra

	/*ofstream Myfile("data.txt");
	* 
	Myfile << "Davide 1200";
	
	Myfile.close();*/

// input da file e scrive su terminale

	/*string data;

	ifstream MyReadFile("Data.txt");

	while (getline(MyReadFile, data))
	{
		cout << data;
	}

	MyReadFile.close();*/

void LogIn(string&, string&, unsigned int&, unsigned int&, unsigned int&, float&);
void MamoryAccount(string, string, unsigned int, unsigned int, unsigned int, float);
void idClient(string[][2], string, unsigned int);
void fileClient(string[][2]);

struct Dati {
	string name, surname;
	unsigned int gg = 0, mm = 0, aaaa = 0;
	float balance = 0;
};

int main()
{
	srand(time(NULL));
	string client[10][2];
	Dati persona;
	LogIn(persona.name, persona.surname, persona.gg, persona.mm, persona.aaaa, persona.balance);
	idClient(client, persona.name, 0);
	fileClient(client);
	MamoryAccount(persona.name, persona.surname, persona.gg, persona.mm, persona.aaaa, persona.balance);
}

void LogIn(string& N, string& S, unsigned int& G, unsigned int& M, unsigned int& A, float& B)
{

	cout << "Inserisci Nome Utente: ";
	cin >> N;
	cout << "Inserisci Cognome Utente: ";
	cin >> S;
	cout << "Inserisci Giorno nascita: ";
	cin >> G;
	cout << "Inserisci Mese nascita: ";
	cin >> M;
	cout << "Inserisci Anno nascita: ";
	cin >> A;
	cout << "Inserisci conto: ";
	cin >> B;
}

void MamoryAccount(string N, string C, unsigned int G, unsigned int M, unsigned int A, float B)
{
	string fileName = N + ".txt";

	ofstream Myfile(fileName);

	Myfile << N << '\n' << C << '\n' << G << '\n' << M << '\n' << A << '\n' << B << '\n';

	Myfile.close();
}

void idClient(string V[][2], string name, unsigned int p)
{

	int id = rand() % 9999 + 1000;

	string Identify = to_string(id);

	V[p][1] = name;
	V[p][2] = Identify;

	cout << name << " " << Identify;

}

void fileClient(string V[][2]) {

	ofstream Myfile("Client.txt");

	for (int i = 0; i < 10; i++)
	{
		Myfile << V[i][1] << '\t' << V[i][2] << endl;
	}

	Myfile.close();
}


