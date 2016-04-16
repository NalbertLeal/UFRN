#include <iostream>
#include <vector>
#include <string>

#ifndef FUNCOES_H
#define FUNCOES_H


#include "STcard.h"
#include "STplayer.h"

using namespace std;

void colocaNoVector(vector<STCard> &V, string id, string nome, string fabricante, int ano, int velocidade, int autonomia, float comprimento, float envergadura) {

  STCard obj(id, nome, fabricante, ano, velocidade, autonomia, comprimento, envergadura);

  V.push_back(obj);
}

void randomizer(vector<STCard> &V){
	for (unsigned int counter = 0; counter < V.size(); counter++)
	{
		int Ir = std::rand() % V.size(); ///////////////////////Gera indices randômicos e faz as trocas com elementos em indices que estão na ordem padrão

		STCard aux = V[counter];
		V[counter] = V[Ir];
		V[Ir] = aux;
	}
}

STPlayer criaJogador(string nome) {
  STPlayer jogador(nome);
  return jogador;
}
#endif
