#include "headers/Serpente.h"


Serpente::Serpente(){
	setHeadPosX(0);
	setHeadPosY(0);
}
		
Serpente::Serpente(int x,int y){
	setHeadPosX(x);
	setHeadPosY(y);
}


int Serpente::getHeadPosX(){return headPosX;}
int Serpente::getHeadPosY(){return headPosY;}
void Serpente::setHeadPosX(int headPosX){this->headPosX = headPosX;}
void Serpente::setHeadPosY(int headPosY){this->headPosY = headPosY;}

vector<Corpo_serpente> Serpente::getCorpoSerpenteArray(){return corpoSerpente;}
void Serpente::updateCorpoSerpente(){
	int prevCordX[2],prevCordY[2];
	int whatPrevUse=0;
	prevCordX[1] = prevSnakeTailX;
	prevCordY[1] = prevSnakeTailY;
	
	for(int i=0;i<corpoSerpente.size();i++){
		
		if(i == corpoSerpente.size()-1){
			if(whatPrevUse == 0){whatPrevUse=1;}if(whatPrevUse == 1){whatPrevUse=0;}
			prevSnakeTailX = prevCordX[whatPrevUse];
			prevSnakeTailY = prevCordY[whatPrevUse];
		}
		
		if(i%2 == 0)
			whatPrevUse = 0;
		else
			whatPrevUse = 1;
			
		prevCordX[whatPrevUse] = corpoSerpente[i].getPosX();
		prevCordY[whatPrevUse] = corpoSerpente[i].getPosY();
		
		
		
		if(i == 0){
			corpoSerpente[i].setPosX(headPosX);
			corpoSerpente[i].setPosY(headPosY);
		}else{
			if(whatPrevUse == 0){whatPrevUse=1;}else if(whatPrevUse == 1){whatPrevUse=0;}
			
			//cout<<"Pos precedente serpente X: "<<prevCordX[whatPrevUse] <<" - ["<<whatPrevUse<<"]" <<endl;
			//cout<<"Pos precedente serpente Y: "<<prevCordY[whatPrevUse]<<" - ["<<whatPrevUse<<"]" <<endl;
			corpoSerpente[i].setPosX(prevCordX[whatPrevUse]); 
			corpoSerpente[i].setPosY(prevCordY[whatPrevUse]);
		}
		
		
			
	}
}

bool Serpente::isThereSerpe(int x,int y){
	for(int i=0;i<corpoSerpente.size();i++){
		if(corpoSerpente[i].getPosX() == x &&  corpoSerpente[i].getPosY() == y)
			return true;
	}
	
	return false;
}

int Serpente::getLastComponentX(){return corpoSerpente[corpoSerpente.size()-1].getPosX();}
int Serpente::getLastComponentY(){return corpoSerpente[corpoSerpente.size()-1].getPosY();}

int Serpente::getSnakeTailX(){return prevSnakeTailX;}
int Serpente::getSnakeTailY(){return prevSnakeTailY;}

int Serpente::getPrevSnakePosX(){return prevSnakePosX;}
int Serpente::getPrevSnakePosY(){return prevSnakePosY;}

void Serpente::move(int Mx,int My){
	prevSnakePosX = getHeadPosX();
	prevSnakePosY = getHeadPosY();
	setHeadPosX(getHeadPosX() + Mx);
	setHeadPosY(getHeadPosY() + My);
}


void Serpente::addBody(int x,int y){
	Corpo_serpente aus(x,y);
	corpoSerpente.push_back(aus);
}
