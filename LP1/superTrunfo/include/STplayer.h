#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <random>
#include <time.h>


//Alunos: Rodrigo Lafayette e Nalbert Gabriel.

#include "STcard.h"

#ifndef STPLAYER_H
#define STPLAYER_H

using namespace std;


class STPlayer{
	public:

		explicit STPlayer(std::string nome = "player1") : m_nome(nome){}

		std::string getNome(void) const{
			return m_nome;
		}

		STCard popCard(void){
			STCard Aux = m_Deck[m_Deck.size()-1];

			if(m_Deck.size() > 0){
				this->m_Deck.pop_back();
				return Aux;
			}
		}

		std::string chooseRandomAttrib(void){
			srand((unsigned)time(NULL));
			auto sorteio = std::rand() % 5;

			switch(sorteio){
				case 0:
					return "Ano";
				case 1:
					return "Velocidade";
				case 2:
					return "Autonomia";
				case 3:
					return "Comprimento";
				case 4:
					return "Envergadura";
			}
		}

		void addCard(STCard ganho){
			this->m_Deck.push_back(ganho);
		}

		void displayCards(void){
			for(auto counter(0); counter < m_Deck.size(); counter++){
				std::cout << "\nCarta " << counter+1 << ": \n";
				m_Deck[counter].DisplayCard();
			}
		}

		size_t nCards(void){
			return m_Deck.size();
		}


	private:
		std::string m_nome;
		std::vector<STCard> m_Deck;
};

#endif
