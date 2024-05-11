#ifndef METODIGENERALI_H
#define METODIGENERALI_H

#include "Serpente.h"
#include "Corpo_serpente.h"
#include "Apple.h"
#include <conio.h>
#include <vector>
#include "saveSystem.h"
#include "Mappa.h"


class metodiGenerali {
	public:
		
		
		static void startingTheGame(int&);
		static void closingTheGame(int);
		
		//static void mainMenu();
		
		static bool checkIfAppleEaten(Apple&,Serpente&,int&,int&);
		static void movementManager(int&,Serpente&);
		static bool checkIfGameOver(Serpente);
};


#endif
