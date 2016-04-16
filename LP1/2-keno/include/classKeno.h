#include <iostream>
#include <vector>

#ifndef classKeno
#define classKeno

using namespace std;

class KenoBet{
  public:
    //! cria uma aposta de keno. Esse construtor define o numero maximo de apostas a serem feitas
    explicit KenoBet(unsigned int _maxNumSpots = 15) : m_maxSpots( _maxNumSpots) {}
    //! adiciona um numero ao vector apenas se o valor não já não estiver
    //! @params _spot O numero que desejamos incluir na aposta
    //! @return true se o numero escolhido é inserido com sucesso e f caso contrario
    bool addNumber (int _spot);
    //! Coloca o montate de dinheiro da aposta dojogador
    //! @params _wage o montante
    //! @return verdadeiro se for maior que 0 e false caso contrario
    bool setWage(float _wage);
    //! reseta a aposta para vazio
    //! @params
    //! @return
    void reset(void);
    //! Retorna o montate da aposta do jogador
    //! @return A aposta do jogodor
    float getWage(void);
    //! Retorna o numero de numeros apostados pelo jogador
    //! @return O numero de numeros apostados na aposta
    size_t numChosen(void);
    //! Determina quantos numeros apostados combinam com os numeros sorteados
    //! @params _hits Lista com os numeros escolhidos randomicamente pelo computador
    //! @return Um vector com a lista de numeros sorteaods
    vector<int> getHits(vector<int> &_hits) const;
    //! Retorna um vector<int> com os numeros que o jogador escolheu
    //! @return O vector<int> com os numeros que o jogador escolheu
    vector<int> getSpots(void) const;
  private:
    vector<int> m_spots; //<! Os numeros escolhidos pelo jogador
    float m_wage; //<! A apostas do jogodor
    unsigned int m_maxSpots; //<! O maximo de numeros permitidos na aposta
};

bool KenoBet::addNumber(int _spot) {
  if(m_spots.size() < m_maxSpots+1) {
    m_spots.push_back(_spot);
    return true;
  }
    return false;
}

bool KenoBet::setWage(float _wage) {
  m_wage = _wage;
}

//functions get

float KenoBet::getWage(void) {
  return m_wage;
}

size_t KenoBet::numChosen(void) {
  return m_spots.size();
}

vector<int> KenoBet::getHits(vector<int> &_hits) const {
  vector<int> hitsCertos;
  for( unsigned int i = 0; i < m_spots.size(); i++) {
    for( unsigned int e = 0; e < 20; e++) {
      if(m_spots[i] == _hits[e]) {
        hitsCertos.push_back(m_spots[i]);
      }
    }
  }

  return hitsCertos;
}

vector<int> KenoBet::getSpots(void) const {
return m_spots;
}

void KenoBet::reset(void) {
  m_spots.clear();
  m_wage = 0;
}

#endif
