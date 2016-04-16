#include <iostream>
#include <fstream>

#include "classKeno.h"
#include "funcoes2.h"

using namespace std;

/**
* Na função main é aonde o codigo é rodado
* @params argc é uma constante com a quantidate de valores no array argv
* @params argv é um array com o nome do programa e os valores pasados por parametro
* @return EXIT_SUCCESS que significa que o programa terminou sem problemas
*/

main(int argc, char * argv[]) {

  double dollars, i, ganho;
  int rodadas, elementoAleatorio;
  vector<int> apostas;
  vector<int> _hits;
  vector<int> hitsCertos;

  vector<vector<double> > valorAcertos = {{0, 3},
                                 {0, 1, 9},
                                 {0, 1, 2, 16},
                                 {0, 0.5, 2, 6, 12},
                                 {0, 0.5, 1, 3, 15, 50},
                                 {0, 0.5, 1, 2, 3, 30, 75},
                                 {0, 0.5, 0.5, 1, 6, 12, 36, 100},
                                 {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720},
                                 {0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200},
                                 {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800},
                                 {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000},
                                 {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000},
                                 {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000},
                                 {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500},
                                 {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}};


  openFile(argc, argv, dollars, rodadas, apostas);

  cout << ">>> A sua aposta foi lida com sucesso.\n";

  KenoBet game(rodadas);

  game.setWage(dollars);

  cout << ">>> Serão " << rodadas << "rodadas.\n";
  cout << ">>> Em cada round voce apostara " << game.getWage() << " dolares\n";

  cout << "+---------------+\n";
  cout << "|- hits -- pay -|\n";

  for(int ro = 0; ro < game.numChosen(); ro++) {
    cout << "|- " << ro << " -|- "<< valorAcertos[game.numChosen()-1][ro] <<" -\n";
  }

  cout << "+---------------+\n";

  // jogo iniciado

  for(int e = 1; e <= rodadas; e++) {

    cout << "------------------------------------------------------------------\n";
    cout << ">>> Rodada " << e << ", sua aposta é " << game.getWage() / rodadas << endl;

    for( i = 0; i < apostas.size(); i++ ) {
      game.addNumber(apostas[i]);
    }

    gerarHit(_hits);

    hitsCertos = game.getHits(_hits);

    cout << ">>> os numeros sorteados nessa rodada foram [ ";
    for(i = 0; i < 20; i++) {
      cout << _hits[i] << " ";
    }
    cout << " ]\n";

    cout << ">>> Voce acertou os numero: [ ";
    for(i = 0; i < hitsCertos.size(); i++) {
      cout << hitsCertos[i] << " ";
    }
    cout << " ]\n";

    ganho += (game.getWage() / rodadas * valorAcertos[game.numChosen()][hitsCertos.size()] - (game.getWage() / rodadas));

    cout << ">>> Nessa rodada você recebe " << valorAcertos[game.numChosen()][hitsCertos.size()] << "dolares\n";
    cout << "Até agora você ganhou " << -ganho << "dolares\n";

    cout << "------------------------------------------------------------------\n";

  }

  cout << "Apos esse jogo você recebe " << ganho << "dolares\n";

  return EXIT_SUCCESS;

}
