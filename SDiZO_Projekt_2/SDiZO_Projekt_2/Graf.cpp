#include "Graf.h"
#include <string.h>
#include <iostream>
#include <iomanip>
// funkcje dla reprezentacji macierzowej
void Graf::dodajKrawedz(int v1, int v2){
	Macierz[v1][v2] = 1;
}
void Graf::dodajWage(int v1, int v2, int waga){
	Wagi[v1][v2] = waga;
}
void Graf::dodajPolaczenie(int v1, int v2, int waga){
	dodajKrawedz(v1,v2);
	dodajWage(v1,v2,waga);
}
void Graf::wyswietlMacierze(std::string info){
	system("cls");
	std::cout << "Macierz sasiedztwa: \n";
	for(int i = 0; i < _iloscW; i++){
		std::cout << std::endl << std::setw(2) << i << ":";
		for(int j = 0; j < _iloscW; j++) std::cout << std::setw(2) << Macierz[i][j];
	}
	std::cout << "\nMacierz wag: \n";
	for(int i = 0; i < _iloscW; i++){
		std::cout << std::endl << std::setw(3) << i << ":";
		for(int j = 0; j < _iloscW; j++) std::cout << std::setw(3) << Wagi[i][j];
	}
	std::cout << std::endl << info;
	char w;
	std::cin >> w;
}
std::string Graf::toString(){
	std::string Informacje;
	Informacje = "Graf skierowany: " + skierowany;
	Informacje+= "Graf prosty: " + prosty;
	Informacje+= "Cykle: " + cykle;
	return Informacje;
};
bool inline Graf::saCykle(){return cykle;}
bool inline Graf::czySkierowany(){return skierowany;}
Graf::Graf(int typ, int _ilosc, std::string j){
	_iloscW=_ilosc;
	if(typ==1){
		if(j=="tak"){ prosty=true; skierowany=false;}else skierowany=true;prosty=false;
		Macierz = new int *[_iloscW];//wiersze
		for(int i=0;i<=(_iloscW-1);i++){
			Macierz[i] = new int [_iloscW];//kolumny
		}// macierz incydencji
		Wagi = new int *[_iloscW];//wiersze
		for(int i=0;i<=(_iloscW-1);i++){
			Wagi[i] = new int [_iloscW];//kolumny
		}// macierz wag krawedzi
		for(int i = 0; i < _iloscW; i++){// zerujemy macierz incydencji
			for(int j = 0; j < _iloscW; j++) Macierz[i][j] = 0;}
		for(int i = 0; i < _iloscW; i++){// zerujemy macierz wag
			for(int j = 0; j < _iloscW; j++) Wagi[i][j] = 0;}
	}

	else{

	}
}
Graf::~Graf(void){
	for(int i = 0; i < _iloscW; i++)
		delete [] Macierz[i];
	delete [] Macierz;
	_iloscW=0;
}
