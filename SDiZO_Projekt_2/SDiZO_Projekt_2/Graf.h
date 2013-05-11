#ifndef Klasa_Grafu_Header
#define Klasa_Grafu_Header

#include <string>

class Graf
{
private:
	int **Macierz,**Wagi;
	int _iloscW;
	bool skierowany, prosty, cykle;
	int typ;
	void dodajKrawedz(int v1,int v2);
	void dodajWage(int v1, int v2, int waga);
public:
	// funkcje dla grafu w postaci macierzy
	void dodajPolaczenie(int v1, int v2, int waga);
	void wyswietlMacierze(std::string info);
	bool sprawdzCykle();
	std::string toString();

	// funkcje dla frafu w postaci listy


	// pozostale funkcje wspolne
	inline bool czySkierowany();
	inline bool saCykle();
	Graf(int typ, int _ilosc, std::string j);
	~Graf(void);
};
#endif
