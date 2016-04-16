#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

/**
*	Alunos: Nalbert Gabriel Melo Leal e Rodrigo Lafayette;
*/

#include "STclasses.h"
#include "funcoes.h"

#ifndef STGAME_H
#define STGAME_H

using namespace std;

class STGame {
	public:
		void STGame(void) {}
		void readDeckFromFile(string);
		void addPLayer(STPlayer );
		int dealCards(STPlayer);
	private:
		int cartasPorJogador;
		vector<string> valores;
		vector<STPlayer> jogadores;
		vector<STCard> cartas;
		vector<STCard> cartasEmMaos;
};

//
string STGame::nomeJogadores(indice) {
	return jogadores[indice].getNome();
}

//
int STGame::NumeroCartasDeck() {
	return cartas.size();
}

void STGame::readDeckFromFile(string nomeArquivo) {
	ifstream file;
	file.open(nomeArquivo);

	if(!(file.is_open() ) ) {
		cout << ">>> Por algum motivo o arquivo não pode ser aberto.\n";
		cout << ">>> Por favor verifique se o arquivo se encontra no diretorio.\n";
		exit(1);
	}

	cout << ">>> Lendo o arquivo, por favor aguarde ...\n";

	string valor;
	int contador = 0;
	while(file.eof() ) {
		getLine(file, valor);
		valores.push_back(valor);
	}

	file.close();

	for(int i = 0; i < valores.size(); i = i + 9) {
		colocaNoVector(cartas, valores[i], valores[i+1], valores[i+2], stoi(valores[i+3]), stoi(valores[i+4]), stoi(valores[i+5]), stof(valores[i+6]), stof(valores[i+7]) );
	}

}

//
void STGame::addPLayer(STPlayer jogador) {
	jogadores.push_back(jogador);
}

void STGame::dealCards(int numeroMaxCartas) {
  for(int i = 0; i < jogadores.size(); i++) {
		for(int e = 0; e < numeroMaxCartas; e++) {
			jogadores[i].addCard(cartas[e]);
		}
	}

}

int STGame::displayDeck(STPlayer jogador) {
	cout << "O deck de cartas do super trunfo: \n";
	cout << "====+================================+==============================+===========+============+=========+=============+====================";
	cout << " ID |NOME                            | COMPANIA                     | ANO       | VELOCIDADE | ANCANCE | COMPRIMENTO |ENVERGADURA";
	cout << "====+================================+==============================+===========+============+=========+=============+=====================";
	for(int contador = 0; contador < valores.size(); contador = contador + 9) {
		cartas[contador].DisplayCard();
	}
}

#endif
