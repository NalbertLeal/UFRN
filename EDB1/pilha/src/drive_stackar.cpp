#include <iostream>

#include "stackar.h"

void drive_stackar() {
  StackAr<int> pilha(4);

  pilha.enqueue(2);
  pilha.enqueue(10);
  pilha.enqueue(3);
  pilha.enqueue(5);

  pilha.enqueue(7);

  std::cout << "o ultimo adicionado e agora removido é: " << pilha.dequeue() << std::endl;
  std::cout << "o ultimo adicionado e agora removido é: " << pilha.dequeue() << std::endl;

  pilha.printStack();

  pilha.makeEmpty();

  pilha.printStack();

}
