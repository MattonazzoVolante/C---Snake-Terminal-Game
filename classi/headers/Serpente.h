#ifndef SERPENTE_H
#define SERPENTE_H
#include <vector>
#include <iostream>
#include "Corpo_serpente.h"

using namespace std;

const char testa = '#';

class Serpente
{
	public:
		Serpente();
		Serpente(int x,int y);
		
		void addBody(int,int);
		
		int getHeadPosX();
		int getHeadPosY();
		void setHeadPosX(int);
		void setHeadPosY(int);
		
		vector<Corpo_serpente> getCorpoSerpenteArray();
		void updateCorpoSerpente();
		bool isThereSerpe(int,int);
		int getLastComponentX();
		int getLastComponentY();
		
		int getSnakeTailX();
		int getSnakeTailY();
		
		int getPrevSnakePosX();
		int getPrevSnakePosY();
		
		void move(int,int);
	private:
		int headPosX,headPosY;
		int prevSnakePosX,prevSnakePosY;
		int prevSnakeTailX,prevSnakeTailY;
		std::vector<Corpo_serpente> corpoSerpente;
		
		
		
		
};

#endif
