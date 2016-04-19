#include <iostream>

#include "stackar.h"

void drive_stackar() {
  StackAr<int> pilha(4);

  pilha.push(2);
  pilha.push(10);
  pilha.push(3);
  pilha.push(5);

  pilha.push(7);

  std::cout << "o ultimo adicionado e agora removido é: " << pilha.pop() << std::endl;
  std::cout << "o ultimo adicionado e agora removido é: " << pilha.pop() << std::endl;

  pilha.printStack();

  pilha.makeEmpty();

  pilha.printStack();

}
