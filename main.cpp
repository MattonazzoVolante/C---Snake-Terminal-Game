#include <iostream>
#include <windows.h>
#include "classi/headers/saveSystem.h"
#include "classi/headers/Apple.h"
#include "classi/headers/Mappa.h"
#include "classi/headers/Serpente.h"
#include "classi/headers/metodiGenerali.h"



int main(int argc, char** argv) {
	Mappa mappa;
	Serpente serpente;
	Apple mela(10);
	int miglior_punteggio = 0;
	int punteggio=0;
	int currentMovement = 3;
	
	bool gameRunning = true;
	
	miglior_punteggio = saveSystem::readBinaryFile();
	
	do{
		Sleep(200);
		system("cls");
		mela.appleManager(serpente,DIMX,DIMY);
		serpente.updateCorpoSerpente();
		metodiGenerali::movementManager(currentMovement,serpente);
		metodiGenerali::checkIfAppleEaten(mela,serpente,punteggio,miglior_punteggio);
		gameRunning = !metodiGenerali::checkIfGameOver(serpente);
		mappa.makeMap(serpente,mela,serpente.getCorpoSerpenteArray());
		mappa.printMap(punteggio,miglior_punteggio);
	}while(gameRunning);
	
	saveSystem::saveInBinaryFile(miglior_punteggio);
	
	
	return 0;
}
