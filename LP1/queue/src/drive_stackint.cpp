#include <iostream>

#include "stackint.cpp"

void drive_stackint() {
  StackInt pilha(4);

  pilha.push(2);
  pilha.push(10);
  pilha.push(3);
  pilha.push(5);

  pilha.push(7);

  pilha.printStack();

  std::cout << "o ultimo adicionado e agora removido é: " << pilha.dequeue() << std::endl;
  std::cout << "o ultimo adicionado e agora removido é: " << pilha.dequeue() << std::endl;

}
