#ifndef DefineDALinl
#define DefineDALinl

#include <iostream>
#include <string>

    template < typename Key >
    int DAL<Data>::_search(const Key & _x) {
      unsigned int i;
      for( i = 0; i < mi_Length; i++) {
        if(mpt_Data[i].id == _x) {
          return i;
        }
      }
      return mi_Length + 1;
    }

  //methods implementation

  template < typename Key >
  bool DAL<Data>::search(const Key & _x, Data & _s)  {
    unsigned int y = _search(_x);
    if(y > mi_Length) {
      return false;
    }
    if(mpt_Data[y].id == _x) {
      _s = mpt_Data[y].info;
      return true;
    }

    for( int i = 0; i < mi_Length ; i++) {
      cout << mpt_Data[i].id << "  ";
    }
    cout << endl << endl;

    return false;
  }

  template < typename Key >
  bool DAL<Data>::remove(const Key & _x, Data & _s) {
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
  bool DAL<Data>::insert(const Key & _newKey, const Data & _newInfo) {

    if(_newKey < 0 || (_search(_newKey) < mi_Length) ) { return false; }
    if(mi_Length == mi_Capacity) {return false; }

    mpt_Data[mi_Length].id = _newKey;
    mpt_Data[mi_Length].info = _newInfo;

    mi_Length = mi_Length + 1;

    return true;
  }

  template < typename Key >
  Key DAL<Data>::min() {
    Key x = mpt_Data[0].id;
    for(int i = 1; i < mi_Length; i++ ) {
      if(mpt_Data[i].id < x) {
        x = mpt_Data[i].id;
      }
    }
    return x;
  }

  template < typename Key >
  Key DAL<Data>::max() {
    Key x = mpt_Data[0].id;
    for(int i = 1; i < mi_Length; i++ ) {
      if(mpt_Data[i].id > x) {
        x = mpt_Data[i].id;
      }
    }
    return x;
  }

  template < typename Key >
  bool DAL<Data>::sucessor(const Key & _x , Key & _y) {
    if(_x <= mi_Length) {
      return false;
    }
    _y = (_x + 1);
    return true;
  }

  template < typename Key >
  bool DAL<Data>::predecessor(const Key & _x , Key & _y) {
    if(_x >= 0) {
      return false;
    }
    _y = (_x - 1);
    return true;
  }

#endif
