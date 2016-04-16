#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <time.h>

/**
*	Alunos: Nalbert Gabriel Melo Leal e Rodrigo Lafayette;
*/

#ifndef STGAME2_H
#define STGAME2_H


#include "STcard.h"
#include "STplayer.h"
#include "funcoes.h"

using namespace std;

class STGame {
	public:
		explicit STGame(void) {}
		void readDeckFromFile(string);
		void addPLayer(STPlayer );
		void dealCards(int);
		int displayDeck(STPlayer);
		void displayPlayers(void);
		int run(int);
		void displayStatusRound(std::vector<STCard>&, std::string &);
		void displayCardsOnTable(std::vector<STCard> &);
		STPlayer winner(int);
		int NumeroCartasDeck(void);
	private:
		int cartasPorJogador;
		int numeroDeCartas;
		vector<string> valores;
		vector<STPlayer> jogadores;
		vector<STCard> cartas;
};

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
	string conteudo;
	while(!file.eof() ) {
		getline(file, valor);
		//stringstream(valor) >> conteudo;
		valores.push_back(valor);
	}

	file.close();

	for(int i = 0; i < valores.size(); i = i + 9) {
		colocaNoVector(cartas, valores[i], valores[i+1], valores[i+2], stoi(valores[i+3]),
		stoi(valores[i+4]), stoi(valores[i+5]), stof(valores[i+6]), stof(valores[i+7]) );
	}

}

void STGame::addPLayer(STPlayer jogador) {
	jogadores.push_back(jogador);
}

//As funções abaixo serão terminadas hoje a tarde e enviadas junto a 2ª parte do trabalho

void STGame::dealCards(int numeroMaxCartas) {

	int indice;
	int escape = 0;
	bool teste;
	int distribuidos =0;

	randomizer(cartas);
	for(int counter = 0; counter < jogadores.size(); counter++){
		for(int i=0; i < numeroMaxCartas; i++) {
				jogadores[counter].addCard(cartas[distribuidos++]);
		}
	}
}

int STGame::displayDeck(STPlayer jogador) {
	cout << "O Deck de cartas do super trunfo: \n";
	cout << "====+================================+==============================+===========+============+=========+=============+====================" << endl;
	cout << " ID |NOME                         | COMPANIA                      | ANO       | VELOCIDADE | ANCANCE | COMPRIMENTO |ENVERGADURA" << endl;
	cout << "====+================================+==============================+===========+============+=========+=============+====================" << endl;
	for(int counter = 0; counter < cartas.size(); counter++) {
		cartas[counter].DisplayCard();
	}
}

void STGame::displayPlayers(){
	for(int counter = 0; counter < jogadores.size(); counter++){
		std::cout <<"\nJogador "<< counter+1 << ": " << jogadores[counter].getNome() << "\nCartas:\n";
		jogadores[counter].displayCards();
	}
}

int STGame::run(int numeroMaxCartas ){

	std::vector<STCard> round;
	std::string atributo;
	std::string ID;
	int maior;
	bool flag = true;
	bool ST = 0;
	bool X1 = 0;
	dealCards(numeroMaxCartas);

	srand(unsigned(time(NULL)));
	int iniciador = std::rand() % jogadores.size();
	while(flag){
		for(int ie = 0; ie < jogadores.size(); ie++) {
		}
		for(auto counter(0); counter < jogadores.size(); counter++){
			if(jogadores[counter].nCards() == cartas.size() ){
				flag=false;
				return counter;
			}
		}
		for(auto counter(0); counter < jogadores.size(); counter++){
			if(jogadores[counter].nCards() < 0) {
				round[counter] = jogadores[counter].popCard();
			}
		}


		atributo = jogadores[iniciador].chooseRandomAttrib();


		for(auto counter(0); counter < round.size(); counter++){
			if(round[counter].getID() == "ST") ST = 1;
			ID = round[counter].getID();
			if(ID[1] == 1) X1 = 1;
		}

		if( (ST == 0 && X1 == 0) || (ST==1 && X1 == 1) || (ST==0 && X1 ==1) ){

			if(atributo == "Ano"){ ///////////////////////////////////////////Caso o atributo for o ano
				maior = 0;
				for(auto counter(1); counter < round.size(); counter++){
					if(round[maior].getAno() < round[counter].getAno()){
						maior = counter;
					}
				}

				for(auto counter(0); counter < round.size(); counter++){
					if(round[counter].getID() != "VO")
						jogadores[maior].addCard(round[counter]);
					}
		}

			else if(atributo == "Velocidade"){//////////////////////////////////////////////Caso velocidade
				maior = 0;
				for(auto counter(1); counter < round.size(); counter++){
					if(round[maior].getVelocidade() < round[counter].getVelocidade()){
						maior = counter;
					}
				}

				for(auto counter(0); counter < round.size(); counter++){
					jogadores[maior].addCard(round[counter]);
				}
			}///////////////////////////////////////////////////////////////////

			else if(atributo == "Autonomia"){///////////////////////////////Caso autonomia
				maior = 0;
				for(auto counter(1); counter < round.size(); counter++){
					if(round[maior].getAutonomia() < round[counter].getAutonomia()){
						maior = counter;
					}
				}

				for(auto counter(0); counter < round.size(); counter++){
					jogadores[maior].addCard(round[counter]);
				}
			}////////////////////////////////////////////////////

			else if(atributo == "Comprimento"){//Caso comprimento
				maior = 0;
				for(auto counter(1); counter < round.size(); counter++){
					if(round[maior].getComprimento() < round[counter].getComprimento()){
						maior = counter;
					}
				}

				for(auto counter(0); counter < round.size(); counter++){
					jogadores[maior].addCard(round[counter]);
				}
			}//////////////////////////////////////////////////

			else if(atributo == "Envergadura"){ //Caso envergadura
				maior = 0;
				for(auto counter(1); counter < round.size(); counter++){
					if(round[maior].getEnvergadura() < round[counter].getEnvergadura()){
						maior = counter;
					}
				}

				for(auto counter(0); counter < round.size(); counter++){
					jogadores[maior].addCard(round[counter]);
				}
			}/////////////////////

			ST = 0;
			X1 = 0;
			iniciador = maior;
			round.clear();

		}
		else{
			for(auto counter(0); counter < round.size(); counter++){
				if(round[counter].getID() == "ST"){
					for(auto counter2(0); counter2 < round.size(); counter2++){
						jogadores[counter].addCard(round[counter2]);
					}
					iniciador = counter;
				}
			}

			ST = 0;
			round.clear();
		}
	}
}

void STGame::displayStatusRound(std::vector<STCard> &round, std::string &atributo){
	std::cout << "Atributo escolhido na rodada: " << atributo << endl;

	for(auto counter(0); counter < round.size(); counter++){
		if(jogadores[counter].nCards() > 0){
			cout << jogadores[counter].getNome() << endl << "Carta: \n";
			round[counter].DisplayCard();
			cout << "\n";
		}
	}
}

void STGame::displayCardsOnTable(std::vector<STCard> &round){
	std::cout << "\nCartas da rodada: \n";
	for(auto counter(0); counter < round.size(); counter++){
		round[counter].DisplayCard();
	}
}

STPlayer STGame::winner(int numeroMaxCartas){
	int indice = run(numeroMaxCartas);

	return jogadores[indice];
}
#endif
