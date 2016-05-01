#ifndef _infxToPosfx_HPP_
#define _infxToPosfx_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

#include "StackAr.h"
#include "QueueAr.h"

class BARES {
  public:
    BARES() {}
    ~BARES() {}
    bool prcd(char);
    void infxToPosfx(QueueAr<char> *, QueueAr<char> *);
    int avaliacaoPosfix(QueueAr<char> *);
    void analizeLine(std::string);
  private:
    std::string validOperators = {'+', '-', '*', '/', '%', '^', '(', ')'};
};

// implementação das funções da classe BARES

void analizeLine(std::string line) {
  long int numberInt;
  std::string numberString;
  bool lastSymbNumber, isValid;
  unsigned int now, brackets;

  while(now < line.length()) {
    numberString = "";
    if(line[next] == " " || line[next] == "    ") {}
    if(isdigit(line[now])) {
      for(int i = now; i < line.length(); i++ ) {
        if(isdigit(line[i])) {
          numberString = numberString + line[i]
        }
      }
      numberInt = stoi(numberString);
      if(32767 < numberInt) {
        // erro numero maior doque 32767
      }
    }
    else {
      isValid = false;
      for(int e = 0; e < validOperators.length(); e++) {
        if(line[now] == validOperators[e]) {
          isValid = true;
          break;
        }
      }
      if(isValid == false) {
        // erro de caractere estranho
      }
      else {
        // o simbolo é valido e deve ser tratado como tal, um switch talvez deva ser suficiente
      }
    }
  }
}

bool BARES::prcd(char symb) {
  switch(symb) {
    case '+':
      return 3;
      break;
    case '-':
      return 3;
      break;
    case '/':
      return 2;
      break;
    case '*':
      return 2;
      break;
    case '^':
      return 2;
      break;
    case '%':
      return 1;
      break;
  }
  return 0;
}

void BARES::infxToPosfx(QueueAr<char> *queueInfx, QueueAr<char> *queuePosfx) {
  char symb;
  StackAr<char> stack;

  while( !queueInfx->isEmpty() ) {
    symb = queueInfx->dequeue();

    if( isdigit(symb) ) {
      queuePosfx->enqueue(symb);
    }
    else {
      while( !(stack.isEmpty()) && (prcd(stack.top() ) >= prcd(symb) ) ) {
        queuePosfx->enqueue(stack.pop());
      }
      stack.push(symb);
    }
  }
  while( !(stack.isEmpty()) ) {
    queuePosfx->enqueue(stack.pop());
  }

}

int BARES::avaliacaoPosfix(QueueAr<char> * queuePosfx) {
  char symb;
  StackAr<int> stackInt;
  char opnd1, opnd2;
  bool isValid = false;
  unsigned int result;
  while( !(queuePosfx->isEmpty()) ) {
    symb = queuePosfx->dequeue();
    if(isdigit(symb) ) {
      stackInt.push(symb);
    }
    else {
      opnd1 = stackInt.pop();
      opnd2 = stackInt.pop();
      switch(symb){
        case '+':
          result = opnd1 + opnd2;
          break;
        case '-':
          result = opnd1 - opnd2;
          break;
        case '*':
          result = opnd1 * opnd2;
          break;
        case '/':
          result = opnd1 / opnd2;
          break;
        case '%':
          result = opnd1 % opnd2;
          break;
        case '^':
          result = pow(opnd1, opnd2);
          break;
      }
      stackInt.push(result);
    }
  }
  return stackInt.pop();
}

#endif
