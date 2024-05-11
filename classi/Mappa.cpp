#include "headers/Mappa.h"
#include <iostream>

using namespace std;

const char border = '+';
const char nothing = ' ';

Mappa::Mappa(){
	resetMap();
}

void Mappa::resetMap(){
	for(int i=0;i<DIMY;i++){
		for(int j=0;j<DIMX;j++)
			mat[i][j] = nothing;
	}
}


void Mappa::makeMap(Serpente serpente,Apple apple,vector<Corpo_serpente> corpo_Serp){
	for(int i=0;i<DIMY;i++){
		for(int j=0;j<DIMX;j++){
			if(i == serpente.getHeadPosY() && j == serpente.getHeadPosX())
				mat[i][j] = testa;
			else if((i == apple.getY() && j == apple.getX()) && apple.getActive())
				mat[i][j] = mela;
			else if(thereIsSnakePiece(corpo_Serp,j,i))
				mat[i][j] = corpo_serpente;
			else
				mat[i][j] = nothing;		
		}
	}
}

void Mappa::printMap(int punteggio, int migliorPunteggio){
	cout<<"Points :  "<< punteggio << "   || ||   " <<"Best: "<< migliorPunteggio<<endl;
	for(int i= 0;i<DIMX+2;i++)
		cout<<border;
		
	cout<<endl;
		
		
	for(int i=0;i<DIMY;i++){
		cout<<border;
		for(int j=0;j<DIMX;j++){
			cout<<mat[i][j];		
		}
		cout<<border;
		cout<<endl;
	}
	
	for(int i= 0;i<DIMX+2;i++)
		cout<<border;
	
	cout<<endl;
}

bool Mappa::thereIsSnakePiece(vector<Corpo_serpente> corpo,int x,int y){
	for(int i=0;i<corpo.size();i++){
		if(corpo[i].getPosX() == x && corpo[i].getPosY() == y)
			return true;
	}
	return false;
}
