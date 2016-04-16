#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <locale.h>

#include "funcoes.h"


using namespace std;


#define N 20 // Number of
//Fill a vector with random numbers in the range [lower, upper] Esse N está sendo usado? era do código de Selan.
#define testes 100


/**
*   Função compare que retorna 1, -1 ou 0 para que a função bsearch e search possam funcionar coretamente.
*/
template <typename T, typename U>
int compare(T *X, U *Y)
{
    if(X < Y) return -1;//essa compare funciona
    else if(X > Y) return 1;
    else
        return 0;
}

void randomFill( std::vector<long int> &V, const long int lower, const long int upper, const unsigned int seed) {

    //use the default random engine and an uniform distribution
    std::default_random_engine eng(seed);
    std::uniform_real_distribution<double> distr(lower, upper);

    for( auto &elem : V){
        elem = distr(eng);
    }
}


int main( /*int argc, char * argv[] */)		//Argc Ã© o counter dos elementos de argv, a posiÃ§Ã£o 0 do argv contÃ©m o
										//nome do programa, a partir da p1 hÃ¡ os valores atribuidos int pre exec
{
	setlocale(LC_ALL,"Portuguese");
    /*
	auto arrSz( 0ul );

    auto media = 0;

    if ( argc > 1 )
    {
        std::stringstream( argv[1] ) >> arrSz;
    }
    else
    {
   		//arrSz = N;
   		//n = arrSz;
    }
	*/

	double/* pode ser auto também,veremos */ media;// = 0; //teste media já está sendo iniciada em 0 no primeiro for
	unsigned long int arrSz=2; ///teste

    std::cout << ">>> Required array size is: " << arrSz << std::endl;

    // Store the data.
    std::vector< long int > V( pow(2, 27) );

    // Seed with a real random value, if available.
    std::random_device r;
    // Fill it up with random integers.
    randomFill( V, 0, 1000000, r() );  // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<> Varie o tamanho do intervalo!!!!!
    sort(V.begin(), V.end());

    //Printint out the array, just to make sure we've got random integers.
    /*std::cout << ">>> Vet = [ ";
    for( const auto &e : V )
        std::cout << e << " ";
    std::cout << "]\n";

	std::cout << "\n\n";
	*/

	for(; arrSz <= pow(2, 27); arrSz*=2){
	//Ordenar(V);    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Se não precisar de ordenação deixe a chamada da função como comentário.
        media = 0;

	    for(int counter = 0; counter < testes; counter++){
//    std::cout << ">>> STARTING computation that needs timing <<<\n";
            auto start = std::chrono::steady_clock::now();
    //================================================================================

    ///////////////////////////////////Chame a função aqui, em baixo:

	        TernariaR(V,-1,0,arrSz-1);



    //================================================================================
            auto end = std::chrono::steady_clock::now();
  //  std::cout << ">>> ENDING computation that needs timing <<<\n";

    //Store the time difference between start and end
            auto diff = end - start;

	        media += (chrono::duration <double, std::nano> (diff).count() - media)/testes;

    // Nanoseconds (10^-9)

            //std::cout << " \t\t\tTeste de  número " << counter <<" >>> " << std::chrono::duration <double, std::nano> (diff).count() << " ns" << std::endl;


    //std::cout << "/t>>>Resultado = " << resultado << "\n\n";
        }

    //deve dar certo assim,fazendo cast na média,nós não precisamos alterar a representação da média,só a exibição,pois é isso que importa para o GnuPlot
	        std::cout << "\n\nA m�dia de tempo para " << arrSz << " elementos : " << /*std::chrono::duration <double, std::nano> (media).count()*/media << " ns" << "\n";

	}

    return EXIT_SUCCESS;

}
