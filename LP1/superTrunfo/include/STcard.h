#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef STCARD_H
#define STCARD_H

class STCard{
	public:
				STCard() {}
				explicit STCard(std::string id,std::string nome,std::string fabricante,
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
			cout << m_ID << " "
			<< " " << m_nome
			<< " " << m_fabricante
			<< " " << m_ano << " "
			<< m_velocidade << " "
			<< m_autonomia << " "
			<< m_comprimento << " "
			<< m_envergadura
			<< endl ;
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
#endif
