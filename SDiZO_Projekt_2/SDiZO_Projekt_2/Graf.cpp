#include "Graf.h"
#include <string.h>
#include <iostream>
#include <iomanip>
// funkcje dla reprezentacji macierzowej
void Graf::dodajKrawedz(unsigned v1, unsigned v2){
	Macierz[v1][v2] = 1;
}
void Graf::dodajWage(unsigned v1, unsigned v2, unsigned waga){
	Wagi[v1][v2] = waga;
}
void Graf::dodajPolaczenie(unsigned v1, unsigned v2, unsigned waga){
	if(macierzowa){
	dodajKrawedz(v1,v2);
	dodajWage(v1,v2,waga);}
	if(listy_sasiadow){
		dodajVertex(v1,v2,waga);
	}
}
void Graf::dodajVertex(unsigned v1,unsigned index, unsigned waga){
	if(listy_sasiadow){
		Vertex *nowy = new Vertex;
		nowy->index=index;
		nowy->waga=waga;
		TAB[(v1)].push_back(*nowy);
		if(prosty && v1 != index){
			Vertex *drugi = new Vertex;
			drugi->index = v1;
			drugi->waga = waga;
			TAB[(index)].push_back(*drugi);
		}
	}
};
void Graf::wyswietlMacierze(std::string info){
	system("cls");
	std::cout << "Macierz sasiedztwa: \n";
	for(int i = 0; i < V; i++){
		std::cout << std::endl << std::setw(2) << i << ":";
		for(int j = 0; j < V; j++) std::cout << std::setw(2) << Macierz[i][j];
	}
	std::cout << "\nMacierz wag: \n";
	for(int i = 0; i < V; i++){
		std::cout << std::endl << std::setw(3) << i << ":";
		for(int j = 0; j < V; j++) std::cout << std::setw(3) << Wagi[i][j];
	}
	std::cout << std::endl << info;
	char w;
	std::cin >> w;
}
void Graf::wyswietlListe(std::string info){
	for(int i=0; i < V; i++){
    std::cout << std::setw(2) << i << ":";
		for(std::list<Vertex>::iterator it = TAB[i].begin(); it != TAB[i].end(); it++){
			std::cout << " " << it->index;
		}
	std::cout << std::endl;
	}
}
void Graf::wyswietlGraf(){
	if(macierzowa){
		wyswietlMacierze(toString());}
	if(listy_sasiadow){
		wyswietlListe(toString());}
}
std::string Graf::toString(){
	std::string Informacje;
	if(macierzowa){
	Informacje = "Graf skierowany: " + skierowany;
	Informacje+= "\nGraf prosty: " + prosty;
	Informacje+= "\nCykle: " + cykle;
	return Informacje;}
	if(listy_sasiadow){
		Informacje = "cos";
		return Informacje;
	}
};
bool inline Graf::saCykle(){return cykle;}
bool inline Graf::czySkierowany(){return skierowany;}
Graf::Graf(int typ, unsigned _ilosc, std::string j){
	V =_ilosc;
	E = 0;
	if(typ==1){// rep macierzowa
		macierzowa = true;
		listy_sasiadow = false;
		if(j=="tak"){ prosty=true; skierowany=false;}else{skierowany=true;prosty=false;}
		Macierz = new unsigned *[V];//wiersze
		for(int i=0;i<=(V-1);i++){
			Macierz[i] = new unsigned [V];//kolumny
		}// macierz sasiadow
		Wagi = new unsigned *[V];//wiersze
		for(int i=0;i<=(V-1);i++){
			Wagi[i] = new unsigned [V];//kolumny
		}// macierz wag krawedzi
		for(unsigned i = 0; i < V; i++){// zerujemy macierz sasiadztwa
			for(unsigned j = 0; j < V; j++) Macierz[i][j] = 0;}
		for(unsigned i = 0; i < V; i++){// zerujemy macierz wag
			for(unsigned j = 0; j < V; j++) Wagi[i][j] = 0;}
		std::cout << "Utworzono graf w postaci macierzowej.";
	}

	else{// rep listowa
		if(j=="tak"){ prosty=true; skierowany=false;}else{skierowany=true;prosty=false;}
		TAB = new std::list<Vertex>[_ilosc];
		macierzowa = false;
		listy_sasiadow = true;
		std::cout << "Utworzono graf w postaci listowej";
	}
}
Graf::~Graf(void){
	for(int i = 0; i < V; i++)
		delete [] Macierz[i];
	delete [] Macierz;
	V=0;
}
