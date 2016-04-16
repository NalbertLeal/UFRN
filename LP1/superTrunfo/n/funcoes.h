#include <iostream>
#include <vector>
#include <string>

#include "STclasses.h"

using namespace std;

#ifndef FUNCOES_H
#define FUNCOES_H

void colocaNoVector(vector<STCard> &V, string id, string nome, string fabricante, int ano, int velocidade, int autonomia, float comprimento, float envergadura) {

  STCard obj(id, nome, fabricante, ano, velocidade, autonomia, comprimento, envergadura);

  V.push_back(obj);
}

int randomPlayer(int numeroJogadores) {
  random_device rd;
  mt19937 eng(rd());
  uniform_int_distribution<> distr(1, numeroJogadores);

  return distr(eng);
}

void STGame::compare( vector<STCard> &V, auto (*ptr)(void)) {
auto maior = 0;
				for(auto counter(1); counter < V.size(); counter++){
					if(V[maior].(*ptr)(void) < V[counter].(*ptr)(void){
						maior = counter;
					}
				}

				for(auto counter(0); counter < V.size(); counter++){
					jogadores[maior].addCard(V[counter]);
				}
			}
}
prtCompare = &STGame::compare;

class TMyClass
{
public:
   int DoIt(float a, char b, char c){ cout << "TMyClass::DoIt"<< endl; return a+b+c;};
   int DoMore(float a, char b, char c) const
         { cout << "TMyClass::DoMore" << endl; return a-b+c; };

   /* more of TMyClass */
};
pt2ConstMember = &TMyClass::DoIt; // note: <pt2Member> may also legally point to &DoMore

// Calling Function using Function Pointer

(*this.*pt2ConstMember)(12, 'a', 'b');
#endif
