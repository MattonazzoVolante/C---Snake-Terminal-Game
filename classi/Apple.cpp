#include "headers/Apple.h"

Apple::Apple(int iterationDelay){
	setX(0);
	setY(0);
	active = false;
	this->iterationDelay = iterationDelay;
	currentIterations = 0;
}

Apple::Apple(int x,int y,int iterationDelay,bool active){
	setX(x);
	setY(y);
	this->iterationDelay = iterationDelay;
	currentIterations = 0;
	setActive(active);
}


bool Apple::getActive(){return active;}
void Apple::setActive(bool active){this->active = active;}


int Apple::getX(){return x;}
int Apple::getY(){return y;}
void Apple::setX(int x){this->x = x;}
void Apple::setY(int y){this->y = y;}

bool Apple::checkIfInsideSnake(Serpente serpente){
	vector<Corpo_serpente> corpo = serpente.getCorpoSerpenteArray();
	for(int i=0;i<corpo.size();i++){
		if (corpo[i].getPosX() == x && corpo[i].getPosY() == y)
			return true;
	}
	return false;
}

void Apple::spawnApple(Serpente serpente,int maxX,int maxY){
	srand(time(0));
	
	do{
		x = rand()%maxX;
		y = rand()%maxY;
	}while(checkIfInsideSnake(serpente));
	
	active = true;
}


void Apple::appleManager(Serpente serpente,int maxX,int maxY){
	if(!active){
		currentIterations++;
		if(currentIterations > iterationDelay){
			currentIterations = 0;
			spawnApple(serpente,maxX,maxY);
		}
	}
	
}
