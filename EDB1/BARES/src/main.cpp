#include <iostream>
#include <string>
#include <fstream>

#include "drive_BARES.cpp"
#include "StackAr.h"
#include "QueueAr.h"

main(int argc, char const * argv[]) {

  if(argc < 2) {
    std::cout << ">>> Porfavor digite o nome do arquivo de entrada e do arquivo saida saida\n";
    std:: cout << ">>> ./Bares arquivo_entrada arquivo_saida \n";
    exit(1);
  }

  std::string namefileIn = argv[1];
  std::string namefileOut = argv[2];

  std::ifstream fileIn;
  fileIn.open(namefileIn);

  if( !(fileIn.is_open() ) ) {
    std::cout << ">>> Por algum motivo o arquivo " << namefileIn << " não pode ser aberto.\n" <<
    ">>> Por favor verifique se o arquivo encontra-se no diretorio de Bares.\n";
  }

  std::ofstream fileOut;
  fileOut.open("saida.txt");

  drive_BARES(fileIn);

  return EXIT_SUCCESS;
}
