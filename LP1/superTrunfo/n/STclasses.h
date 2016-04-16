#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <random>
#include <time.h>


//Alunos: Rodrigo Lafayette e Nalbert Gabriel.
using namespace std;

#ifndef STCLASSES_H
#define STCLASSES_H
#endif


class STCard{
	public:
		STCard(std::string id,std::string nome,std::string fabricante,
						int ano,int velocidade,int autonomia, float comprimento,
						float envergadura) : m_ID(id),m_nome(nome), m_fabricante(fabricante),
						m_ano(ano), m_velocidade(velocidade), m_comprimento(comprimento),m_envergadura(envergadura) {}

		std::string getID(void){
			return m_ID;
		}

		std::string getNome(void){
			return m_nome;
		}

		std::string getFabricante(void){
			return m_fabricante;
		}

		int getAno(void){
			return m_ano;
		}

		int getVelocidade(void) const{
			return m_velocidade;
		}

		int getAutonomia(void) const{
			return m_autonomia;
		}

		float getComprimento(void) const{
			return m_comprimento;
		}

		float getEnvergadura(void) const{
			return m_envergadura;
		}


		void DisplayCard(void){
			cout << m_ID << " " << " " << m_nome << " " << m_fabricante << " " << m_ano << " " << m_velocidade << " " << m_autonomia << " " << m_comprimento << " " << m_envergadura << endl ;
		}

	private:
		std::string m_ID;
		std::string m_nome;
		std::string m_fabricante;
		int m_ano;
		int m_velocidade;
		int m_autonomia;
		float m_comprimento;
		float m_envergadura;
};


class STPlayer{
	public:

		STPlayer(std::string nome = "player1") : m_nome(nome){}

		std::string getNome(void) const{
			return m_nome;
		}

		STCard popCard(void){
			STCard Aux = m_Deck[m_Deck.size()-1];

			m_Deck.resize(m_Deck.size()-1);

			return Aux;
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

		void addCard(STCard &ganho){
			m_Deck.push_back(ganho);
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
