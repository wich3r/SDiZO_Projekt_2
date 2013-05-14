#include "CLI.h"
#include "Graf.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void CLI::start(){
	int wynik;
	do{
		wynik = menu();
	}while(wynik!=8);

}
int CLI::menu(){// tu jest glowne dzialanie programu ;d
	system("cls");
	int s;
	cout << "Badanie efektywnosci algorytmow grafowych.\nMenu glowne.\n[1].Dodaj nowy graf.\n[2].Wyswietl graf.\n[3].Dodaj wierzcho³ek.\n[4].Usun wierzcho³ek.\n[5].Wyznacz MST.\n[6].Wyznacz najkrotsz¹ œciezke.\n[7].Przed do trybu symulacji.\n[8].Wyjscie\n";
	cin >> s;
	switch(s){
	case 1:{ // dodaj nowy graf
		dodajGraf();
		break;}
	case 2:{// wyswietl graf
		system("cls");
		g->wyswietlGraf();
		Sleep(3000);
		break;}
	case 3:{//dodaj nowy wiwrzcholek
		if(g!=NULL){
			int k;
			do{
				unsigned v1,v2,waga;
				system("cls");
				cout << "Dodawanie sciezki\n";
				cout << "Podaj V1: "; cin >> v1;
				cout << "Podaj V2: "; cin >> v2;
				cout << "Podaj wage krawedzi: "; cin >> waga;
				g->dodajPolaczenie(v1,v2,waga);
				cout << "Dodawac dalej?[1]";
				cin >> k;
			}while(k==1);
			cout << "Wyswietlic graf?[1]/[0]\n";
			cin >> k;
			if(k==1){g->wyswietlGraf();Sleep(5000);}
		}else cout << "\nBrak grafu!"; Sleep(2000);
		break;}
	case 4:{
		int t;
		do{
			system("cls");
			cout << "Wyszukiwanie MST.\n Wybierz algorytm:\n";
			cout << "[1]. Algorymt Kruskala.\n";
			cout << "[2]. Algorytm Prima.\n";
			cout << "[3]. Do menu g³ównego.\n";
			cout << "\nWybór: "; cin >> t;
			switch(t){// akcje dla wybranych algorytmów
				case 1:{

					break;}
				case 2:{

					break;}
				default:{}
				}
			}while(t!=3);
		break;}
	case 5:{

		break;}
	case 6:{

		break;}
	case 7:{

		break;}
	default:{}
	return s;
	}
}
void CLI::dodajGraf(){
	unsigned V,typ;
	string s;
	system("cls");
	cout << "Dodawanie nowego grafu.\nWpisz potrzebne informacje.\n";
	cout << "\nWpisz ilosc wierzcholkow: "; cin >> V;
	cout << "\nReprezentacja macierzowa [1], czy listowa? [else]: "; cin >> typ;
	cout << "\nCzy graf jest prosty?[tak]/[nie]: "; cin >> s;
	g = new Graf(typ,V,s);
}
CLI::CLI(void){

}
CLI::~CLI(void)
{
}
