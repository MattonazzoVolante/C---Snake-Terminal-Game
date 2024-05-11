#ifndef APPLE_H
#define APPLE_H

#include <stdlib.h>
#include <time.h>
#include "Serpente.h"
#include "Corpo_serpente.h"
#include <vector>

const int mela = '@';

class Apple
{
	public:
		Apple(int);
		Apple(int,int,int,bool);
		
		bool getActive();
		void setActive(bool);
		
		int getX();
		int getY();
		void setX(int);
		void setY(int);
		
		bool checkIfInsideSnake(Serpente);

		void spawnApple(Serpente,int,int);
		void appleManager(Serpente,int,int);
		
		
	private:
		int x,y;
		bool active;
		int iterationDelay;
		
		int currentIterations;
};

#endif
