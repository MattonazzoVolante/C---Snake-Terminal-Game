#ifndef MAPPA_H
#define MAPPA_H
#include <iostream>
#include "metodiGenerali.h"
#include "Serpente.h"
#include "Corpo_serpente.h"
#include "Apple.h"
#include <vector>

const int DIMX = 30;
const int DIMY = 30;

class Mappa
{
	public:
		Mappa();
		
		void resetMap();
		void makeMap(Serpente,Apple,vector<Corpo_serpente>);
		void printMap(int,int);
		
	private:
		char mat[DIMY][DIMX];
		
		bool thereIsSnakePiece(vector<Corpo_serpente>,int,int);
};

#endif
