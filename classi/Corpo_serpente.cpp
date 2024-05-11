#include "headers/Corpo_serpente.h"

Corpo_serpente::Corpo_serpente(){
	posX = 0;
	posY = 0;
}
		
Corpo_serpente::Corpo_serpente(int x,int y){
	setPosX(x);
	setPosY(y);
}
		
		
int Corpo_serpente::getPosX(){return posX;}
int Corpo_serpente::getPosY(){return posY;}
void Corpo_serpente::setPosX(int posX){this->posX = posX;}
void Corpo_serpente::setPosY(int posY){this->posY = posY;}
