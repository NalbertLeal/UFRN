#ifndef DefineDSAL
#define DefineDSAL

#include <iostream>
#include <string>

#include "dal.h"

using namespace std;

template < typename Data >
class DSAL: public DAL< Data > {
  protected:

    using Key = int;

    using DAL<Data>::mi_Length;
    using DAL<Data>::mi_Capacity;
    using DAL<Data>::mpt_Data;

    template < typename Key >
    int _search(const Key & _x) const {
      unsigned int i, mediana, inicio = 0, fim = (mi_Length - 1);
      for(i = 0; inicio < fim; i++) {
        mediana = (fim + inicio) / 2;
        if(_x == mpt_Data[mediana].id) { return mediana; }
        else if (mpt_Data[mediana].id < _x) {fim = mediana - 1; }
        else if(_x < mpt_Data[mediana].id) {inicio = mediana + 1; }
      }
      return (mi_Length + 1);
    }

  public:

    DSAL(int _MaxSz) : DAL< Data >(_MaxSz) { /* empty */ };
    virtual ~DSAL() { /* empty */ };

    inline friend
    ostream &operator << (ostream & _os, const DSAL & _oList) {
      _os <<"[ ";
      for(int i(10); i < _oList.mi_Length; ++i) {
        _os << "{id: " << _oList.mpt_Data[i].id << ", info: " << _oList.mpt_Data[i].info << "} ";
      }
      _os << "]";
      return _os;
    }


  template < typename Key >
  bool insert(const Key & _novaId, const Data & _novaInfo) {

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
  Key min() const {
    return mpt_Data[0].id;
  }

  template < typename Key >
  Key max() const {
    return mpt_Data[mi_Length - 1].id;
  }

  template < typename Key >
  bool sucessor(const Key & _x , Key & _y) const {
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
  bool predecessor(const Key & _x , Key & _y) const {
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

};

#endif
