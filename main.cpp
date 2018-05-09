#include <iostream>
#include <string>
#include <stddef.h>
#include <iomanip>
#include <ctype.h>
#include <time.h>
#include <sstream>
using namespace std;

#define NOME_TAM 40
#define NUM_TURMA_TAM 4
#define NUM_ALUNOS 20
#define NUM_MINI_TESTES 4
#define NUM_TURMAS 10
#define IGNORE 10

struct FREQ {
	// posicao 0 para o 1º MT, posicao 1 para o 2ºMT . . .
	int miniteste[NUM_MINI_TESTES];
	int trabalho;
};
struct ALUNO {
	long numero;
	char nome[NOME_TAM];
	FREQ frequencia;
	int exame;
	int faltas;
};
struct TURMA {
	char numero[NUM_TURMA_TAM];
	char professor[NOME_TAM];
	int num_alunos;
	ALUNO alunos[NUM_ALUNOS];
	int aulas_dadas;
};
int menuAlunos();
int menuTurmas();
int menu();

void manutencaoAlunos(TURMA t[], int &n);
void manutencaoTurma(TURMA t[], int &n);
void inserirTurma(TURMA t[], int &n);
void consultarTurmas(TURMA t[], int &n);

void main() {
	TURMA turmas[NUM_TURMAS];
	int num_turmas = 0;
	int opcao;
	do {
		opcao = menu();
		switch (opcao)
		{
		case 1: manutencaoTurma(turmas, num_turmas);
			break;
		case 2: manutencaoAlunos(turmas, num_turmas);
			break;
		}
	} while (opcao);
}

int menuAlunos() {
	int opcao;
	do {
		cout << "\n\nALUNOS" << endl;
		cout << " 1 -Inserir Aluno\n";
		cout << " 2 -Listar Aluno\n";
		cout << " 3 -Inserir Faltas Classificacoes\n";
		cout << " 4 -Eliminar Aluno\n";
		cout << " 5 -Calcular Classificacao\n";
		cout << " 0 -Voltar\n";
		cout << " Opcao -> ";
		cin >> opcao;
	} while (opcao < 0 || opcao >5);
	cin.ignore(IGNORE, '\n');
	return opcao;
}
int menuTurmas() {
	int opcao;
	do {
		cout << "\n\nTURMAS" << endl;
		cout << " 1 -Inserir Turma\n";
		cout << " 2 -Listar Turmas(Todas)\n";
		cout << " 3 -Listar Turma(Uma)\n";
		cout << " 4 -Inserir Aulas Dadas\n";
		cout << " 0 -Voltar\n";
		cout << " Opcao -> ";
		cin >> opcao;
	} while (opcao < 0 || opcao >4);
	cin.ignore(IGNORE, '\n');
	return opcao;
}

int menu() {
	int opcao;
	do {
		cout << "\n\nRedes de Computadores" << endl;
		cout << " 1 -Turmas\n";
		cout << " 2 -Alunos\n";
		cout << " 0 -Sair\n";
		cout << " Opcao -> ";
		cin >> opcao;
	} while (opcao < 0 || opcao >2);
	cin.ignore(IGNORE, '\n');
	return opcao;
}

void manutencaoAlunos(TURMA t[], int &n) {
	int opcao;
	do {
		opcao = menuTurmas();
		switch (opcao)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		}
	} while (opcao);
}
void manutencaoTurma(TURMA t[], int &n) {
	int opcao;
	do {
		opcao = menuTurmas();
		switch (opcao)
		{
		case 1: inserirTurma(t, n);
			break;
		case 2: consultarTurmas(t, n);
			break;
		case 3:
			break;
		case 4:
			break;
		}
	} while
		(opcao);
}

void inserirTurma(TURMA t[], int &n) {
	int nTurma;
	//string nProfessor = "";
	char nProfessor[NOME_TAM];
	int nAlunos;
	int nquantos;

	cout << "\n\nInsercao de Turmas" << endl;
	cout << "Ordem de insercao => Numero Turma - Professor - Numero de Alunos\n";
	cout << "Quantos turmas quer inserir?";
	cin >> nquantos;

	for (int i = 0; i < nquantos; i++) {
		//não para na segunda ronda
		if ((sizeof(t) / sizeof(t[0])) == 0) {
			cout << "Turma Numero: ";
			cin >> nTurma;
			cin.ignore(IGNORE, '\n');

			cout << "Nome do Professor: ";
			//cin.getline(nProfessor, NOME_TAM);
			cin >> t[i].professor;

			cout << "Numero de Alunos: ";
			cin >> nAlunos;
			cin.ignore(IGNORE, '\n');

			*t[i].numero = (char)nTurma;
			//t[i].professor = nProfessor; 
			t[i].num_alunos = nAlunos;
			t[i].aulas_dadas = 0;

			cout << int(*t[i].numero) << " - " << t[i].professor << " - " << t[i].num_alunos;
		}
		else {
			cout << "OLA MUNDO ";
			i = nquantos;
		}

	}



}

void consultarTurmas(TURMA t[], int &n) {

	cout << "Listagem de Turmas\n";
	for (int i = 0; i < (sizeof(t) / sizeof(t[0])) + 1; i++) {
		int numero = *t[i].numero;
		char professor = *t[i].professor;
		int nAlunos = t[i].num_alunos;
		int nAulas = t[i].aulas_dadas;

		cout << "Turma " << numero << ":\nDocente: " << professor << "\nCom " << nAlunos << " alunos" << " e " << nAlunos << " lecionadas\n";
	}

}

