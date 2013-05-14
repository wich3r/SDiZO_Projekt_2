#ifndef CLI_HEADER_
#define CLI_HEADER_

#include "Graf.h"
#include "Kruskal.h"
#include "Prim.h"

class CLI{
private:
	Graf *g;
	void nowyGraf();
	void dodajGraf();
public:
	void start();
	int menu();
	CLI(void);
	~CLI(void);
};
#endif
