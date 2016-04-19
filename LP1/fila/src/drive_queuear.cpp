#include <iostream>

#include "QueueAr.h"

void drive_stackar() {
  QueueAr<int> fila(4);

  std::cout << ">>> Verificando se a fila esta vazia ... \n";
  !(fila.isEmpty() ) ? std::cout << ">>> A fila esta vazia.\n" : std::cout << ">>> A fila não esta vazia\n";

  fila.enqueue(2);
  fila.enqueue(10);
  fila.enqueue(3);
  fila.enqueue(5);

  fila.enqueue(7);

  std::cout << ">>> A fila agora esta assim: \n";
  fila.printQueue();

  std::cout << "o ultimo adicionado e agora removido é: " << fila.dequeue() << std::endl;
  std::cout << "o ultimo adicionado e agora removido é: " << fila.dequeue() << std::endl;

  fila.printQueue();

  fila.makeEmpty();

  fila.printQueue();

}
