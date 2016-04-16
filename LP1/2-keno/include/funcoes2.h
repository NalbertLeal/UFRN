#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#include "classKeno.h"

#ifndef funcoes2
#define funcoes2

using namespace std;

//! Verifica se um vector possui um certo elemento
//! @params V Vector aonde a busca ṕelo elemento sera efetuada
//! @params fim É o indice fim do vector + 1
//! @params elementoBuscado É o elemento que será procurado no vector
//! @return
bool busca(vector<int> &V, int fim, int elementoBuscado) {
  int i;
  for( i = 0; i < fim; i++) {
    if(elementoBuscado == V[i]) {
      return false;
    }
  }
  return true;
}

//! Cria valores aleatorios e os armazena em um vector passado por referencia
//! @params V É uma vector passado por referencia, nele sera armazenado os valores rendomicos
//! @return não possui retorno
void gerarHit(vector<int> &V) {
  int i;
  random_device rd; // obtain a random number from hardware
  mt19937 eng(rd()); // seed the generator
  uniform_int_distribution<> distr(1, 81); // define the range
  for( i = 0; i < 20; ++i) {
    V.resize(V.size()+1, 0);
    V[i] = distr(eng);
  }
}

//! Testa se uma string passui elementos diferentes de um digito ou ponto
//! @params dado É uma string que sera testada se possui apenas digitos e ponto
//! @return Retorna false caso tenha algo diferente de um ponto ou de digito e true caso contrario
bool stringSoNumeros(string dado) {
  int i;
  for(i = 0; i < dado.length(); i++) {
    if( !( isdigit(dado[i]) )  && (dado != ".") ) {
      return false;
    }
  }
  return true;
}

//! Abre o arquivo que teve seu nome passado por parrametro
//! @params argc é uma constante com a quantidate de valores no array argv
//! @params argv é um array com o nome do programa e os valores pasados por parametro
//! @params dollars passado por referencia, é a veriavel double que armazenará a aposta do jogador para depois passa-la para a classe
//! @params rounds passado por referencia, é a veriavel int que armazenará a quantidade de rounds
//! @params apostas passado por referencia, é um vector que armazenará cada um dos numeros apostados do jogador
//! @return Retorna 0 caso ocorra tudo bem ou exit(1) caso ocorra um erro na leitura do arquivo
int openFile(int &argc, char *argv[], double &dollars, int &rounds, vector<int> &apostas) {
  int i, count, contadorApostas, aposta;
  bool soLetras;
  string fileToOpen, dado;

  if(argc > 1) {
    fileToOpen = argv[1];
  } else {
    cout << ">>> É necessario passar o nome arquivo (não escreva a extenção .dat) como parametro, com a aposta, rounds e numeros de cada round.\n";
    exit(1);
  }

  ifstream file;
  file.open(fileToOpen+".dat");

  if ( !(file.is_open()) ) { // testa se o arquivo está aberto
    cout << "Por algum motivo o arquivo não pode ser aberto.\n";
    exit(1);
  }

  cout << ">>> Lendo arquivo passado com a aposta ...\n";

  count = 0;
  contadorApostas = 0;
//  bool existe;
  while(file >> dado) {
    soLetras = stringSoNumeros(dado);
    if(!soLetras) {
      cout << ">>> O arquivo não deve conter letras, virgula ou qualg=quer caractere diferente de numeros ou ponto, por favor retire o(os) caractere(es) estranho(os) e depois tente novamente submeter a aposta.\n";
      exit(1);
    }
    if (count  == 0 && soLetras) {
      dollars = stod(dado);
    } else if(count == 1 && soLetras) {
      rounds = stoi(dado);
    } else if(count > 1 && soLetras) {
      if(count < 17){
        if( 0 < stoi(dado) && stoi(dado) < 81){
          aposta = stoi(dado);
          //existe = busca(apostas, apostas.end(), aposta );
          //if(existe) {
            apostas.resize(apostas.size()+1, 0);
            apostas[contadorApostas] = aposta;
            contadorApostas++;
          //}
        }
      }
    }
    count++;
  }
  return 0;

}

#endif
