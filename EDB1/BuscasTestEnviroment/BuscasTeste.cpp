#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <math.h>
#include <algorithm> // sort the vector
#include <fstream> // manipulate the file
#include <cstdlib> // random integer

#include "Funcoes.h"

using namespace std;

const int valorMaximo = pow(2, 27);

template <typename T, typename U>
int compare(T *X, U *Y)
{
    if(X < Y) return -1;
    else if(X > Y) return 1;
    else
        return 0;
}

void randomFill( vector<long int> &V, const int lower, const int upper, const unsigned int seed) {

    //use the default random engine and an uniform distribution
    default_random_engine eng(seed);
    uniform_real_distribution<double> distr(lower, upper);

    for( auto &elem : V){
        elem = distr(eng);
    }
}

main(int argc, char* argv[]) {
  int numeroDoAlgoritimo, numeroDeTesteFeitos, k;
  long int potenciaDoVector, elem, tamanhoDoVector;
  double media = 0, nsecods;
  string nomeDoAlgoritimo;

  //random_device randomico;
  vector<long int> V(valorMaximo);
  cout << ">>> Preenchendo vector com elementos randomicos: " << endl;
  randomFill(V, 0, valorMaximo, 172429);

  //

  long int elemento34;
  vector<long int> A(1);

  randomFill(A, -10, 10, 123456);
  /*
  default_random_engine eng(123456);
  uniform_real_distribution<double> distr(-10, 10);

  for( auto &elem : A){
      elem = distr(eng);
  }
  */
  elemento34 = ((V.end() - V.begin())*3)/4;
  elemento34 += A[0];

  long int valorElemento = V[elemento34-1] + 1;
  V[elemento34] = valorElemento;

  //

  cout << ">>> O indice e o elemento na 3/4 posição do vector é: " << elemento34 << " " << valorElemento << endl;

  cout << ">>> Organizando o vector:" << endl;
  sort(V.begin(), V.end());

  nomeDoAlgoritimo = "BuscaSequencialInterativa";
  ofstream out;
  out.open(nomeDoAlgoritimo + ".dat");

  cout << ">>> Iniciando loop para testes: " << endl;

  for(numeroDoAlgoritimo = 1; numeroDoAlgoritimo < 17; numeroDoAlgoritimo++) {

    media = 0;

    for(potenciaDoVector = 2; potenciaDoVector < 28; potenciaDoVector++) {

      if(numeroDoAlgoritimo < 9) {
        k = -1;  // numero a ser buscado
        if(numeroDoAlgoritimo < 3) {
          V[elemento34] = -1;
        } else {
          V[elemento34] = valorElemento;
        }
      } else {
        k = valorElemento;
        if(numeroDoAlgoritimo < 11) {
          V[elemento34] = -1;
        } else {
          V[elemento34] = valorElemento;
        }
      }

      tamanhoDoVector = (long int)pow(2, potenciaDoVector);

      switch (numeroDoAlgoritimo) {
        case 1:
          cout << ">>> O teste foi iniciado no algoritimo busca sequencial interativo de tamanho 2^" << potenciaDoVector <<"\n";
            for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
              auto start = std::chrono::steady_clock::now();
                sequencialI(V, k, tamanhoDoVector);
              auto end = std::chrono::steady_clock::now();

              auto tempo = end - start;
              //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
              //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
              //media = media + nsecods / 100;
              media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
            }
          cout << ">>> O teste foi finalizado no algoritimo busca sequencial interativo de tamanho 2^" << potenciaDoVector << "\n";
          nomeDoAlgoritimo = "BuscaSequencialInterativa";

          break;
        case 2:
          if(potenciaDoVector < 18) {
            cout << ">>> O teste foi iniciado no algoritimo de busca sequencial recursiva de tamanho 2^" << potenciaDoVector <<"\n";
              for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
                auto start = std::chrono::steady_clock::now();
                  sequencialR(V, k, 0, tamanhoDoVector);
                  auto end = std::chrono::steady_clock::now();

                  auto tempo = end - start;
                  //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
                  //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
                  //media = media + nsecods / 100;
                  media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
            }
          cout << ">>> O teste foi finalizado no algoritimo busca sequencial recursiva de tamanho 2^" << potenciaDoVector <<"\n";
          nomeDoAlgoritimo = "BuscaSequencialRecursiva";

          }
          break;
        case 3:
          cout << ">>> O teste foi iniciado no algoritimo busca binaria interativa de tamanho 2^" << potenciaDoVector <<"\n";
            for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
              auto start = std::chrono::steady_clock::now();
                BinariaI(V, k, 0, tamanhoDoVector);
              auto end = std::chrono::steady_clock::now();

              auto tempo = end - start;
              //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
              //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
              //media = media + nsecods / 100;
              media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
            }
          cout << ">>> O teste foi finalizado no algoritimo busca binaria interativa de tamanho 2^" << potenciaDoVector <<"\n";
          nomeDoAlgoritimo = "BuscaBinariaInterativa";

          break;
        case 4:
          cout << ">>> O teste foi iniciado no algoritimo busca binaria recursiva de tamanho 2^" << potenciaDoVector <<"\n";
            for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
              auto start = std::chrono::steady_clock::now();
                BinariaR(V, k, 0, tamanhoDoVector);
              auto end = std::chrono::steady_clock::now();

              auto tempo = end - start;
              //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
              //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
              //media = media + nsecods / 100;
              media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
            }
          cout << ">>> O teste foi finalizado no algoritimo busca binaria recursiva de tamanho 2^" << potenciaDoVector <<"\n";
          nomeDoAlgoritimo = "BuscaBinariaRecursiva";

          break;
        case 5:
          cout << ">>> O teste foi iniciado no algoritimo busca ternaria interativa de tamanho 2^" << potenciaDoVector <<"\n";
            for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
              auto start = std::chrono::steady_clock::now();
                TernariaI(V, k, 0, tamanhoDoVector);
              auto end = std::chrono::steady_clock::now();

              auto tempo = end - start;
              //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
              //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
              //media = media + nsecods / 100;
              media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
            }
          cout << ">>> O teste foi finalizado no algoritimo busca ternaria interativa de tamanho 2^" << potenciaDoVector <<"\n";
          nomeDoAlgoritimo = "BuscaTernariaInterativa";

          break;
        case 6:
          cout << ">>> O teste foi iniciado no algoritimo busca ternaria recursiva de tamanho 2^" << potenciaDoVector <<"\n";
            for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
              auto start = std::chrono::steady_clock::now();
                TernariaR(V, k, 0, tamanhoDoVector);
              auto end = std::chrono::steady_clock::now();

              auto tempo = end - start;
              //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
              //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
              //media = media + nsecods / 100;
              media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
            }
          cout << ">>> O teste foi finalizado no algoritimo busca ternaria recursiva de tamanho 2^" << potenciaDoVector <<"\n";
          nomeDoAlgoritimo = "BuscaTernariaRecursiva";

          break;

        case 7:
          /*
          cout << ">>> O teste foi iniciado no algoritimo de busca nativa search() de tamanho 2^" << potenciaDoVector <<"\n";
            for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
              auto start = std::chrono::steady_clock::now();
                std::search(V.begin(), tamanhoDoVector, K, K);
              auto end = std::chrono::steady_clock::now();

              auto tempo = start - end;
              nsecods = std::chrono::duration <double, std::nano> (media).count();
              media = media + nsecods / 100;
            }
          cout << ">>> O teste foi finalizado no algoritimo de busca nativa search() de tamanho 2^" << potenciaDoVector <<"\n";
          */
          //nomeDoAlgoritimo = "BuscaComSearch";

          break;

        case 8:
          cout << ">>> O teste foi iniciado no algoritimo de busca nativa bsearch() de tamanho 2^" << potenciaDoVector <<"\n";
            for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
              auto start = std::chrono::steady_clock::now();
                std::bsearch( &k, &V, tamanhoDoVector, sizeof(V[0]), compare); //chamada da função nativa bsearch
              auto end = std::chrono::steady_clock::now();

              auto tempo = end - start;
              //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
              //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
              //media = media + nsecods / 100;
              media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
            }
          cout << ">>> O teste foi finalizado no algoritimo de busca nativa bsearch() de tamanho 2^" << potenciaDoVector <<"\n";
          nomeDoAlgoritimo = "BuscaComBsearch";
          break;

          case 9:
            cout << ">>> O teste foi iniciado no algoritimo busca sequencial interativo no elem 3/4 de tamanho 2^" << potenciaDoVector <<"\n";
              for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
                auto start = std::chrono::steady_clock::now();
                  sequencialI(V, k, tamanhoDoVector);
                auto end = std::chrono::steady_clock::now();

                auto tempo = end - start;
                //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
                //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
                //media = media + nsecods / 100;
                media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
              }
            cout << ">>> O teste foi finalizado no algoritimo busca sequencial interativo no elem 3/4 de tamanho 2^" << potenciaDoVector << "\n";
            nomeDoAlgoritimo = "BuscaSequencialInterativaElem34";

            break;
          case 10:
            if(potenciaDoVector < 18) {
              cout << ">>> O teste foi iniciado no algoritimo de busca sequencial recursiva no elem 3/4 de tamanho 2^" << potenciaDoVector <<"\n";
                for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
                  auto start = std::chrono::steady_clock::now();
                    sequencialR(V, k, 0, tamanhoDoVector);
                    auto end = std::chrono::steady_clock::now();

                    auto tempo = end - start;
                    //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
                    //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
                    //media = media + nsecods / 100;
                    media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
              }
            cout << ">>> O teste foi finalizado no algoritimo busca sequencial recursiva no elem 3/4 de tamanho 2^" << potenciaDoVector <<"\n";
            nomeDoAlgoritimo = "BuscaSequencialRecursivaElem34";

            }
            break;
          case 11:
            cout << ">>> O teste foi iniciado no algoritimo busca binaria interativa no elem 3/4 de tamanho 2^" << potenciaDoVector <<"\n";
              for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
                auto start = std::chrono::steady_clock::now();
                  BinariaI(V, k, 0, tamanhoDoVector);
                auto end = std::chrono::steady_clock::now();

                auto tempo = end - start;
                //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
                //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
                //media = media + nsecods / 100;
                media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
              }
            cout << ">>> O teste foi finalizado no algoritimo busca binaria interativa no elem 3/4 de tamanho 2^" << potenciaDoVector <<"\n";
            nomeDoAlgoritimo = "BuscaBinariaInterativaElem34";

            break;
          case 12:
            cout << ">>> O teste foi iniciado no algoritimo busca binaria recursiva no elem 3/4 de tamanho 2^" << potenciaDoVector <<"\n";
              for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
                auto start = std::chrono::steady_clock::now();
                  BinariaR(V, k, 0, tamanhoDoVector);
                auto end = std::chrono::steady_clock::now();

                auto tempo = end - start;
                //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
                //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
                //media = media + nsecods / 100;
                media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
              }
            cout << ">>> O teste foi finalizado no algoritimo busca binaria recursiva no elem 3/4 de tamanho 2^" << potenciaDoVector <<"\n";
            nomeDoAlgoritimo = "BuscaBinariaRecursivaElem34";

            break;
          case 13:
            cout << ">>> O teste foi iniciado no algoritimo busca ternaria interativa no elem 3/4 de tamanho 2^" << potenciaDoVector <<"\n";
              for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
                auto start = std::chrono::steady_clock::now();
                  TernariaI(V, k, 0, tamanhoDoVector);
                auto end = std::chrono::steady_clock::now();

                auto tempo = end - start;
                //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
                //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
                //media = media + nsecods / 100;
                media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
              }
            cout << ">>> O teste foi finalizado no algoritimo busca ternaria interativa no elem 3/4 de tamanho 2^" << potenciaDoVector <<"\n";
            nomeDoAlgoritimo = "BuscaTernariaInterativaElem34";

            break;
          case 14:
            cout << ">>> O teste foi iniciado no algoritimo busca ternaria recursiva no elem 3/4 de tamanho 2^" << potenciaDoVector <<"\n";
              for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
                auto start = std::chrono::steady_clock::now();
                  TernariaR(V, k, 0, tamanhoDoVector);
                auto end = std::chrono::steady_clock::now();

                auto tempo = end - start;
                //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
                //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
                //media = media + nsecods / 100;
                media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
              }
            cout << ">>> O teste foi finalizado no algoritimo busca ternaria recursiva no elem 3/4 de tamanho 2^" << potenciaDoVector <<"\n";
            cout << ">>> A media foi: " << media << endl;
            nomeDoAlgoritimo = "BuscaTernariaRecursivaElem34";

            break;
        case 15:
          /*
          cout << ">>> O teste foi iniciado no algoritimo de busca nativa search() de tamanho 2^" << potenciaDoVector <<"\n";
            for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
              auto start = std::chrono::steady_clock::now();
              std::search(V.begin(), tamanhoDoVector, K, K);
              auto end = std::chrono::steady_clock::now();

              auto tempo = start - end;
              nsecods = std::chrono::duration <double, std::nano> (media).count();
              media = media + nsecods / 100;
            }
          cout << ">>> O teste foi finalizado no algoritimo de busca nativa search() de tamanho 2^" << potenciaDoVector <<"\n";
          */
          //nomeDoAlgoritimo = "BuscaComSearchElem34";

              break;
          case 16:
            cout << ">>> O teste foi iniciado no algoritimo de busca nativa bsearch() no elem 3/4 de tamanho 2^" << potenciaDoVector <<"\n";
              for(numeroDeTesteFeitos = 0; numeroDeTesteFeitos < 100; numeroDeTesteFeitos++) {
                auto start = std::chrono::steady_clock::now();
                  std::bsearch( &k, &V, tamanhoDoVector, sizeof(V[0]), compare); //chamada da função nativa bsearch
                auto end = std::chrono::steady_clock::now();

                auto tempo = end - start;
                //nsecods = std::chrono::duration <long double, std::milli> (tempo).count();
                //auto nsecods = std::chrono::duration_cast<std::chrono::seconds>(tempo);
                //media = media + nsecods / 100;
                media += (chrono::duration <double, std::nano> (tempo).count() - media)/100;
              }
              cout << ">>>> A media foi: " << media << endl;
            cout << ">>> O teste foi finalizado no algoritimo de busca nativa bsearch() no elem 3/4 de tamanho 2^" << potenciaDoVector <<"\n";
            nomeDoAlgoritimo = "BuscaComBsearchElem34";
            break;
      }

      out << media << endl;

    }

    out.close();
    if(numeroDoAlgoritimo < 17) {
      out.open(nomeDoAlgoritimo + ".xlt");
    }
    if(numeroDoAlgoritimo == 14) {
      out.close();
    }
  }

}
