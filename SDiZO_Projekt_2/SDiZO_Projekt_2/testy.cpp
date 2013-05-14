#include "Graf.h"
#include <iostream>

int main(){
	int ilosc;
	std::string j;
	std::cout << "\nPodaj ilosc krawedzi: "; std::cin >> ilosc;
	std::cout << "\nCzy graf ma byc prosty?[tak][nie]: "; std::cin >> j;
	Graf g(1,ilosc,j);
	g.wyswietlGraf();
	char t;
	int l=0;
	do{
		int v1, v2, waga;
		std::cout << "Podaj wierzcholek v1, wierzcholek v2 i wage dodawanej krawedzi: "; std::cin >> v1; std::cout << ", "; std::cin >> v2; std::cout << ", "; std::cin >> waga;
		g.dodajPolaczenie(v1,v2,waga);
		l++;
		g.wyswietlGraf();
		std::cout << "Czy dodawac dalej?: ";std::cin >> t;

	}while(t=='n'||l<=ilosc);
}