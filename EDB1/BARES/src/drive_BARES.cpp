#include <iostream>
#include <string>
#include <fstream>

#include "BARES.hpp"

void drive_BARES(std::ifstream & fileIn) {
  QueueAr<char> *queueInfx = new QueueAr<char>;
  QueueAr<char> *queuePosfx = new QueueAr<char>;
  std::string line;
  char elemet;

  BARES bares;

  while( !(fileIn.eof()) ) {
    getline(fileIn, line); // get a line of the file and push into the line string variable
    if ( (line == "") || (line == " ") ) {
      continue;
    }
    bares.analizeLine(line);
    queueInfx->enqueue(elemet); // push re return of analizeLine to queueInfx
    bares.infxToPosfx(queueInfx, queuePosfx); // receive queue with a line of the file and create a posfix expresion
  }
  fileIn.close();
}
