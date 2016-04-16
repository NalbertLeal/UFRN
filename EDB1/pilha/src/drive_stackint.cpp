#include <iostream>

#include "stackint.cpp"

void drive_stackint() {
  StackInt pilha(4);

  pilha.enqueue(2);
  pilha.enqueue(10);
  pilha.enqueue(3);
  pilha.enqueue(5);

  pilha.enqueue(7);

  pilha.printQueue();

  std::cout << "o ultimo adicionado e agora removido é: " << pilha.dequeue() << std::endl;
  std::cout << "o ultimo adicionado e agora removido é: " << pilha.dequeue() << std::endl;

}
