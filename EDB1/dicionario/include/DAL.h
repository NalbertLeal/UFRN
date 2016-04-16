#ifndef _DAL_H
#define _DAL_H

#include <iostream>
#include <string>

#include "DAL.inl"

using namespace std;

template < typename Data >
class DAL {
  protected:
    using Key = int;
    // using Data = string;
    struct NodeAL {
      Key id;
      Data info;
    };

    static const int SIZE=50;
    int mi_Length;
    int mi_Capacity;
    NodeAL *mpt_Data;

    int _search(const Key & _x) const;

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

  bool search(const Key & _x, Data & _s) const;
  bool remove(const Key & _x, Data & _s);
  bool insert(const Key & _newKey, const Data & _newInfo);
  Key min() const;
  Key max() const;
  bool sucessor(const Key & _x , Key & _y) const;
  bool predecessor(const Key & _x , Key & _y) const;

};


template < typename Data >
class DSAL: public DAL< Data > {
  protected:

    using Key = int;

    using DAL<Data>::mi_Length;
    using DAL<Data>::mi_Capacity;
    using DAL<Data>::mpt_Data;

    int _search(const Key & _x) const;

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

    bool insert(const Key & _novaId, const Data & _novaInfo);
    Key min() const;
    Key max() const;
    bool sucessor(const Key & _x , Key & _y) const;
    bool predecessor(const Key & _x , Key & _y) const;

};


#endif
