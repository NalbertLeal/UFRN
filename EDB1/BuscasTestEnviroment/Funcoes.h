#include <iostream>
#include <vector>
#include <cstdlib>

void Ordenar(std::vector<long int> &A){

	unsigned int slow,fast;
	long int permutador;

	for(slow=0; slow < A.size(); slow++){
		for(fast=slow+1; fast < A.size(); fast++){
			if(A[fast] < A[slow]){
				permutador = A[fast];
				A[fast] = A[slow];
				A[slow] = permutador;
			}
		}
	}
}

int sequencialR(std::vector<long int> &A, long int x, long int inicial, long int final){
    if(inicial >= final) { return -1; }
    else if(x == A[inicial]) { return inicial; }
    else { return sequencialR(A, x, inicial+1, final); }
}

int sequencialI(std::vector<long int> &A, long int x, long int final ){

	for(unsigned int counter = 0; counter < final ; counter++){
		if(A[counter] == x) return counter;
	}

	return -1;
}

int BinariaR(std::vector<long int> &A, long int x, long int inicial, long int final){

    if(inicial > final) return -1;

	auto m = (inicial+final) / 2;

	if(x == A[m]) return m;
	else if( x > A[m]) return BinariaR(A, x, m+1, final);
	else return BinariaR(A, x, inicial, m-1);
}


int BinariaI(std::vector<long int> &A, long int x, long int inicial, long int final){

	while(inicial <= final){
		auto m = (inicial+final)/2;
		if(A[m] == x) return m;
		else if(x > A[m]) inicial = m+1;
		else final = m-1;
	}
	return -1;
}

int TernariaR(std::vector<long int> &A, long int x, long int inicial, long int final){

  if(inicial > final) return -1;

	auto t1 = inicial + (final - inicial)/3;
	auto t2 = t1 + (final - inicial)/3;

	if(x == A[t1]) return t1;
	else if(x == A[t2]) return t2;
	else if( x > A[t1] && x < A[t2]) return TernariaR(A, x, t1+1, t2-1);
	else if( x < A[t1]) return TernariaR(A, x, inicial, t1-1);
	else return TernariaR(A, x, t2+1, final);
}

int TernariaI(std::vector<long int> &A, long int x, long int inicial, long int final){

	while(inicial <= final){
		auto t1 = inicial + (final - inicial)/3;
		auto t2 = t1 + (final - inicial)/3;

		if(A[t1] == x) return t1;
		else if(A[t2] == x) return t2;
		else if( x > A[t1] && x < A[t2]){
			inicial = t1+1;
			final = t2-1;
		}
		else if(x < A[t1]) final = t1-1;
		else inicial = t2+1;
	}

	return -1;
}
