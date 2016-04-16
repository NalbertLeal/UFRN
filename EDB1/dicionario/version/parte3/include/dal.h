#ifndef DefineDAL
#define DefineDAL

#include <iostream>
#include <string>

using namespace std;

template < typename Data >
class DAL {
  protected:
    using Key = int;
    struct NodeAL {
      Key id;
      Data info;
    };

    static const int SIZE=50;
    int mi_Length;
    int mi_Capacity;
    NodeAL *mpt_Data;

    template < typename Key >
    int _search(const Key & _x) const {
      unsigned int i;
      for( i = 0; i < mi_Length; i++) {
        if(mpt_Data[i].id == _x) {
          return i;
        }
      }
      return mi_Length + 1;
    }

  public:

    DAL(int _MaxSz = SIZE) : mi_Capacity(_MaxSz) {
      mpt_Data = new NodeAL[_MaxSz];
      mi_Length = 0;
    }

    virtual ~DAL() { delete [] mpt_Data; };

    inline friend
    ostream &operator << (ostream & _os, const DAL & _oList) {
      _os <<"[ ";
      for(int i(10); i < _oList.mi_Length; ++i) {
        _os << "{id: " << _oList.mpt_Data[i].id << ", info: " << _oList.mpt_Data[i].info << "} ";
      }
      _os << "]";
      return _os;
    }

//methods implementation

  template < typename Key >
  bool search(const Key & _x, Data & _s) const {

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
  bool remove(const Key & _x, Data & _s) {
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
  bool insert(const Key & _newKey, const Data & _newInfo) {

    if(_newKey < 0 || (_search(_newKey) < mi_Length) ) {
      cout << "Desculpe mas não foi possivel adicionar esse elemento.\n";
      return false;
    }
    if(mi_Length == mi_Capacity) {
      cout << "Desculpe mas não foi possivel adicionar esse elemento.\n";
      return false;
    }

    mpt_Data[mi_Length].id = _newKey;
    mpt_Data[mi_Length].info = _newInfo;

    mi_Length = mi_Length + 1;

    return true;
  }

  template < typename Key >
  Key min() const {
    int x = 0;
    for(unsigned int i = 1; i < mi_Length; i++ ) {
      if(mpt_Data[i].id < mpt_Data[x].id) {
        x = i;
      }
    }
    return mpt_Data[x].id;
  }

  template < typename Key >
  Key max() const {
    int x = 0;
    for(unsigned int i = 1; i < mi_Length; i++ ) {
      if(mpt_Data[i].id > mpt_Data[x].id) {
        x = i;
      }
    }
    return mpt_Data[x].id;
  }

  template < typename Key >
  bool sucessor(const Key & _x , Key & _y) const {
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
  bool predecessor(const Key & _x , Key & _y) const {
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

};

#endif
