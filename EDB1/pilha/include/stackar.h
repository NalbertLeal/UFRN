#ifndef _STACKAR_H_
#define _STACKAR_H_

#include <iostream>

#include "AbsStack.h"

template < class Data >
class StackAr : public AbsQueue < Data > {
  public:

    StackAr(int tamanho = 50) {
      theStack = new Data[tamanho];
      capacity = tamanho;
      theTop = 0;
    }

    ~StackAr() {
      delete [] theStack;
    }

    void enqueue(const Data & _x);
    Data dequeue();
    Data getFront() const;

    bool isEmpty() const;
    void makeEmpty();

    void printStack();

  private:
    int capacity;
    Data *theStack;
    int theTop;
};

#include "stackar.inl"

#endif
