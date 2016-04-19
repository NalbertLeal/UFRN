#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cassert>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
bool Binaria(std::vector<long int> &A, long int x, int l, int r){

    if(l > r) return false;
    
	auto m=(l+r)/2;
	
	if(x == A[m]) return true;
	else if( x > A[m]) return BinariaR(A,x,m+1,r);
	else return BinariaR(A,x,l,m-1);	
}
*/

void randomizer(std::vector<int> &V){
	for (int counter = 0; counter < V.size(); counter++)
	{
		int Ir = std::rand() % V.size();

		int aux = V[counter];
		V[counter] = V[Ir];
		V[Ir] = aux;
	}
}

class KenoBet {
public:
	explicit KenoBet(unsigned int _maxNumSpots = 15) : m_maxSpots(_maxNumSpots) {
		if (_maxNumSpots < 15 || _maxNumSpots <= 0) {
			cout << "Invalid number of bets.";
			return;
		}

		m_maxSpots = _maxNumSpots;
	}

	bool addNumber(int _spot) {
  		
  		if(_spot >=1 && _spot <=80){
  			bool Existe = false;
			for(unsigned int counter=0; counter < m_spots.size(); counter++){
				if(m_spots[counter] == _spot) Existe = true;
			}
		
    		if(!Existe && m_spots.size()<15){	
				m_spots.push_back(_spot);

    			return true;
  			}
    		return false;
    	}
	}

	bool setRounds(unsigned int _spots) {
		if(_spots >= 1 && _spots <= 15){
			m_maxSpots = _spots;
			return true;
		}
		return false;
	}

	unsigned int getRounds(void) {
		return m_maxSpots;
	}

	bool setWage(float _wage) {
		if (_wage > 0) {
			m_wage = _wage;
			return true;
		}
		return false;
	}

	void reset(void) {
		m_spots.clear();
		m_wage = 0;
	}

	float getWage(void) const {
		return m_wage;
	}

	size_t numChosen(void) const {
		return m_spots.size();
	}
	
	void printSpots(void){
		std::copy(m_spots.begin(), m_spots.end(), std::ostream_iterator<int>(std::cout, " "));
	}

	std::vector<int> getHits(std::vector<int> _hits) const {
		std::vector<int> hits;
		auto hitsSz(0);
		
		for (unsigned int counter = 0; counter < m_spots.size(); counter++) {
			for(unsigned int counter2 = 0; counter2 < 20; counter2++){ 
				if(m_spots[counter] == _hits[counter2]){	
					hits[hitsSz++] = m_spots[counter];
				}
			}
		}	
		return hits;
	}

	void OrderSpots(void) {
		sort(m_spots.begin(), m_spots.end());
	}

	std::vector<int> getSpots(void) const {
		return m_spots;
	}


private:
	std::vector < int > m_spots;
	float m_wage;
	unsigned int m_maxSpots;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char * argv[]) {

	std::string NomeDoArquivo;
	if (argc > 1) {
		std::stringstream(argv[1]) >> NomeDoArquivo;
	}

	std::string Conteudo;

	////////////////////////////////////////////
	auto numberWage(0.0);
	unsigned int numberSpots;
	int Number;
	//////////////////////////////////////////	

	KenoBet Aposta;

	std::vector<int> sorteios ={ 1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
								21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
								41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
								61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80};

	std::vector<std::vector<float>> tabela = { 
	{ 0, 3 },
	{ 0, 1, 9 },
	{ 0, 1, 2, 16 },
	{ 0, 0.5, 2, 6, 12 },
	{ 0, 0.5, 1, 3, 15, 50 },
	{ 0, 0.5, 1, 2, 3, 30, 75 },
	{ 0, 0.5, 0.5, 1, 6, 12, 36, 100 },
	{ 0, 0.5, 0.5, 1, 3, 6, 19, 90, 720 },
	{ 0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200 },
	{ 0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800 },
	{ 0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000 },
	{ 0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000 },
	{ 0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000 },
	{ 0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500 },
	{ 0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000 } };
	
	bool X1 = false;
	bool X2 = false;
	std::vector<int> teste;
	//////////////////////////////////////////////////////////////////////////////////////////// Leitura do arquivo.
	std::ifstream Arquivo;
	Arquivo.open(NomeDoArquivo);

	if (Arquivo.is_open()) {
		cout << "\n>>> Preparing to read bet file [" << NomeDoArquivo << "], please wait...\n-----------------------------------------------------------\n";
		while (!Arquivo.eof()) {
	
			if(X2 == false){
				std::getline(Arquivo, Conteudo);
			}
			
			if (X1 == false) {
				std::stringstream(Conteudo) >> numberWage;
				X1 = Aposta.setWage(numberWage);
			}


			if (X2 == false && X1 == true) {
				std::stringstream(Conteudo) >> numberSpots;
				X2 = Aposta.setRounds(numberSpots);
				
			}

			if (X2 == true) {
				while(Arquivo >> Conteudo || !Arquivo.eof()){
					std::stringstream( Conteudo ) >> Number;
					Aposta.addNumber(Number);
					if(Conteudo == "\0")std::getline(Arquivo,Conteudo);
				}///////////////////////////////////////////
			}	
		}
			Arquivo.close();
			cout << ">>> Bet was read!!!\n";	
	}	
	else {
		cout << "Problem when is tried to open the file.";
		return -1;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////// Fim da leitura do arquivo.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////// The game will start now...
	///Brief:

	cout << "You're going to wage a total of $" << Aposta.getWage() << " dollars.\n";
	cout << "Going for a total of " << Aposta.getRounds() << " rounds, waging $" << Aposta.getWage() / Aposta.getRounds() << " per round.\n\n";

	Aposta.OrderSpots();

	cout << "You bet has " << Aposta.numChosen() << " numbers. They are: [ ";
	Aposta.printSpots();
	cout << " ]\n";

	cout << "--------+---------\n Hits   |   Payout  \n--------+---------\n";
	for (unsigned int counter = 0; counter <= Aposta.numChosen(); counter++) {
		cout << counter << "       |       " << tabela[Aposta.numChosen()-1][counter] << "\n";
	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////// O jogo será começado agora, finalmente...
	float TotalGain = Aposta.getWage();
	std::vector <int> hits;

	for (unsigned int counter = 1; counter <= Aposta.getRounds(); counter++) {
		cout << "---------------------------------------------------------------------------------------------------------\n";
		cout << "This is the round #" << counter << " of " << Aposta.getRounds() << ", and your wage is $" << (Aposta.getWage() / Aposta.getRounds()) << ". Good look!\n";

		randomizer(sorteios);
		sort(sorteios.begin(), sorteios.end()-61); //////////////////////////////////Preciso para o get hits
		hits = Aposta.getHits(sorteios);

		cout << "The hits are: [ ";
		std::copy(sorteios.begin(), sorteios.end()-61, std::ostream_iterator<int>(std::cout, " "));
		cout << " ]\n\n";

		cout << "You hit the following number(s) [ ";
		std::copy(hits.begin(), hits.end(), std::ostream_iterator<int>(std::cout, " "));
		cout << " ], a total of " << hits.size() << " out of " << Aposta.numChosen() << endl;
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		TotalGain += ((Aposta.getWage() / Aposta.getRounds()) * tabela[Aposta.numChosen()-1][hits.size()]) - (Aposta.getWage() / Aposta.getRounds());
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		cout << "Payout rate is " << tabela[Aposta.numChosen()-1][hits.size()] << ", thus you came out with: $" << (Aposta.getWage() / Aposta.getRounds()) * tabela[Aposta.numChosen()][hits.size()];
		cout << "\nYou net balance so far is: $" << TotalGain << " dollars.\n";
	}

	cout << "\nEnd of Rounds!\n---------------------------------------------------------------------------------------------------------\n";
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// The game ends at this moment	
	cout << "========== SUMMARY =========\n>>> You spend in this game a total of $" << Aposta.getWage() << " dollars.\n";

	if (TotalGain > Aposta.getWage()) {
		cout << "Hey! You won $" << TotalGain - Aposta.getWage() << " dollars. In the next time i'll make you lose(without corruption). (:))\n";
	}
	else {
		cout << "Hey! You lose $" << Aposta.getWage() - TotalGain << " dollars. Now... you money is mine, loser! HAHAHAHAHA (:p)\n";
	}
	cout << ">>> You're leaving this game with $" << TotalGain << " dollars.\n\n";


	return 0;
}
