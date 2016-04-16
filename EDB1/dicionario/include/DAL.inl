#ifndef _DAL_INL
#define _DAL_INL

#include <iostream>
#include <string>

#include "DAL.h"

// DAL

template < typename Key >
int DAL< Data >::_search(const Key & _x) const {
  unsigned int i;
  for( i = 0; i < mi_Length; i++) {
    if(mpt_Data[i].id == _x) {
      return i;
    }
  }
  return mi_Length + 1;
}

template < typename Key >
bool DAL< Data >::search(const Key & _x, Data & _s) const {

  if(mi_Length == 0) {
    return false;
  }

  unsigned int y = _search(_x);
  if(y > mi_Length) {
    return false;
  }
  if(mpt_Data[y].id == _x) {
    _s = mpt_Data[y].info;
    return true;
  }

  return false;
}

template < typename Key >
bool DAL< Data >::remove(const Key & _x, Data & _s) {
  unsigned int y = _search(_x);
  if(y > mi_Length) {
    return false;
  }
  _s = mpt_Data[y].info;

  for( int i = y; (i <= mi_Length - 2) && mi_Length > 0; i++) {
    mpt_Data[i] = mpt_Data[i + 1];
  }

  mi_Length = mi_Length - 1;

  return true;
}

template < typename Key >
bool DAL< Data >::insert(const Key & _newKey, const Data & _newInfo) {

  if(_newKey < 0 || (_search(_newKey) < mi_Length) ) {
    std::cout << "Desculpe mas não foi possivel adicionar esse elemento.\n";
    return false;
  }
  if(mi_Length == mi_Capacity) {
    std::cout << "Desculpe mas não foi possivel adicionar esse elemento.\n";
    return false;
  }

  mpt_Data[mi_Length].id = _newKey;
  mpt_Data[mi_Length].info = _newInfo;

  mi_Length = mi_Length + 1;

  return true;
}

template < typename Key >
Key DAL< Data >::min() const {
  int x = 0;
  for(unsigned int i = 1; i < mi_Length; i++ ) {
    if(mpt_Data[i].id < mpt_Data[x].id) {
      x = i;
    }
  }
  return mpt_Data[x].id;
}

template < typename Key >
Key DAL< Data >::max() const {
  int x = 0;
  for(unsigned int i = 1; i < mi_Length; i++ ) {
    if(mpt_Data[i].id > mpt_Data[x].id) {
      x = i;
    }
  }
  return mpt_Data[x].id;
}

template < typename Key >
bool DAL< Data >::sucessor(const Key & _x , Key & _y) const {
  if(_x >= (mi_Length - 1) ) {
    return false;
  }
  unsigned int x;
  Key menor = max();
  for(unsigned int i = 1; i < mi_Length; i++ ) {
    if(mpt_Data[i].id > _x && mpt_Data[i].id < menor ) {
      x = i;
    }
  }
  _y = mpt_Data[x].id;
  return true;
}

template < typename Key >
bool DAL< Data >::predecessor(const Key & _x , Key & _y) const {
  unsigned int y = _search(_x);
  if(0 >= y) {
    return false;
  }
  unsigned int x;
  Key maior = min();
  for(unsigned int i = 1; i < mi_Length; i++ ) {
    if(mpt_Data[i].id < _x && mpt_Data[i].id > maior ) {
      x = i;
    }
  }
  _y = mpt_Data[x].id;
  return true;
}


// DSAL


template < typename Key >
int DSAL< Data >::_search(const Key & _x) const {
  unsigned int i, mediana, inicio = 0, fim = (mi_Length - 1);
  for(i = 0; inicio < fim; i++) {
    mediana = (fim + inicio) / 2;
    // cout << "mpt_Data[" << mediana << "] = " << mpt_Data[mediana].id << endl;
    if(_x == mpt_Data[mediana].id) { return mediana; }
    else if (mpt_Data[mediana].id < _x) {fim = mediana - 1; }
    else if(_x < mpt_Data[mediana].id) {inicio = mediana + 1; }
  }
  return (mi_Length + 1);
}


template < typename Key >
bool DSAL< Data >::insert(const Key & _novaId, const Data & _novaInfo) {

  if(mi_Length == 0) {
    mpt_Data[0].id = _novaId;
    mpt_Data[0].info = _novaInfo;
    mi_Length = mi_Length + 1;
    return true;
  }

  unsigned int posicao = _search(_novaId);

  if( (posicao > (mi_Length + 1) ) || (_novaId == mpt_Data[posicao].id) ) {
    return false;
  }
  if(mi_Length >= mi_Capacity) {
    std::cout << "Desculpe mas não foi possivel adicionar esse elemento.\n";
    return false;
  }

  int x = 0;
  for( int i = mi_Length; i > 0 && mpt_Data[i - 1].id > _novaId; i--) {
    mpt_Data[i] = mpt_Data[i - 1];
    x = i;
  }

  mpt_Data[x].id = _novaId;
  mpt_Data[x].info = _novaInfo;

  mi_Length = mi_Length + 1;

  return true;
}


template < typename Key >
Key DSAL< Data >::min() const {
  return mpt_Data[0].id;
}

template < typename Key >
Key DSAL< Data >::max() const {
  return mpt_Data[mi_Length - 1].id;
}

template < typename Key >
bool DSAL< Data >::sucessor(const Key & _x , Key & _y) const {
  if(_x >= (mi_Length - 1) ) {
    return false;
  }
  else {
    unsigned int y = _search(_x);
    if(y > mi_Length) {
      return false;
    }
    _y = mpt_Data[y + 1].id;
    return true;
  }

}


template < typename Key >
bool DSAL< Data >::predecessor(const Key & _x , Key & _y) const {
  unsigned int y = _search(_x);
  if( 0 >= _x) {
    return false;
  }
  else {
    unsigned int y = _search(_x);
    if(y > mi_Length) {
      return false;
    }
    _y = mpt_Data[y - 1].id;
    return true;
  }

}

#endif
