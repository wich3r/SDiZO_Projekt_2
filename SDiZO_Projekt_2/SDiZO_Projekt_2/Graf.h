#ifndef Klasa_Grafu_Header
#define Klasa_Grafu_Header

#include <string>
#include <vector>
#include <list>

class Graf
{
private:
	// ogolne dane
	unsigned V,E; // ilosc wierzcho³ków w zdefiniowanym grafie i ilosc krawedzi
	bool skierowany, prosty, cykle; // podstawowe dane o grafie
	bool macierzowa, listy_sasiadow;
	// rep macierzowa
	int **Macierz,**Wagi; // reprezentacja macierzowa
	void wyswietlMacierze(std::string info);
	void dodajKrawedz(unsigned v1,unsigned v2);
	void dodajWage(unsigned v1, unsigned v2, unsigned waga);
	// rep listowa
	struct Vertex{
		unsigned index; // index wierzcholka
		unsigned waga; // waga krawedzi do niego prowadzacej
	};// struktura elementu listy (wierzcholek oraz waga krawedzi prowadzacej do niego)
	void dodajVertex(unsigned v1, unsigned index, unsigned waga);
	void wyswietlListe(std::string info);
	std::list<Vertex> *TAB; // tablica list z wierzcholkami
public:
	// funkcje dla grafu w postaci macierzy
	void dodajPolaczenie(unsigned v1, unsigned v2, unsigned waga);
	bool sprawdzCykle();
	void wyswietlGraf();
	std::string toString();

	// funkcje dla grafu w postaci listy


	// pozostale funkcje wspolne
	inline bool czySkierowany();
	inline bool saCykle();
	Graf(int typ, int _ilosc, std::string j);
	~Graf(void);
};
#endif
