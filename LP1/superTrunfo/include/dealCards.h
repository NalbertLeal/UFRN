

void STGame::dealCards(int numeroMaxCartas) {
	
	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(0, cartas.size()-1);
	
	int indice;
	int escape = 0;
	bool teste;
  
	for(int i=0; i < cartas.size(); i++) {
		teste = 0;
		while(teste == 0 || escape!=100){
			indice = distr(eng);
			if(jogadores[indice].nCards() < numeroMaxCartas){
				jogadores[indice].addCard(cartas[i]);
				teste = 1;
			}
			else escape++;
		}	
	}
}