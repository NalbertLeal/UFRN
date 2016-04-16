#include <iostream>
#include <vector>

#include "STGame2.h"
#include "STcard.h"
#include "STplayer.h"
#include "funcoes.h"

using namespace std;

int main(int argc, char const *argv[]) {

  if(argc < 4) {
		cout << ">>> Por favor passe como parametro o arquivo .dat com as cartas, o numero de jogadores e numero de cartas por jogador.\n";
		cout << ">>> O arquivo deve ser passado da seguinte maneira: (exemplo) \n";
		cout << ">>> $ ./superTrunfo arquivo.dat 3 4\n";
		cout << ">>> Sendo 3 o numero de jogadores\n";
		exit(1);
	}

  string fileToOpen = argv[1];

  STGame game;
  game.readDeckFromFile(fileToOpen);

  int numeroJogadores = stoi(argv[2]);
  int numeroMaxCartas = stoi(argv[3]);

  if(game.NumeroCartasDeck() * numeroJogadores < numeroMaxCartas) {
    cout << ">>> O numero de cartas lidas do arquivo deveria ser ao menos "
     << (int)(game.NumeroCartasDeck() * numeroJogadores) << " entretanto a entrada foi " << numeroMaxCartas <<
     " e esse numero é insuficiente."<< endl;
    exit(1);
  }

  for(int i = 0; i < numeroJogadores; i++) {
    string nome = "jogador"+ to_string(i);
    game.addPLayer(criaJogador(nome) );
  }

   //game.dealCards(numeroMaxCartas);

  STPlayer vencedor = game.winner(numeroMaxCartas);

  cout << vencedor.getNome() << endl;

  return EXIT_SUCCESS;
}
