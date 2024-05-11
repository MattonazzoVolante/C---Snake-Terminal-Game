#include "headers/metodiGenerali.h"

void metodiGenerali::startingTheGame(int &m_punteggio){
	m_punteggio = saveSystem::readBinaryFile();
	
	if(m_punteggio == 0)
		cout<<"C'è stato un errore nel leggere il file!";
}
/*
void metodiGenerali::mainMenu(){
                                                                    
   ...  ..     .....                                          
......  ....   ......     .....        ..   . .....  ...   ...
....    ....   ......     .......      ... ........  ..    ...
....    ...... ......     ..... :.      .. ......   ......    
......  .............   ............    .. ....     .....     
  ..... .............  .......... ...   .. ....     ........  
....... ....  ........ .....    ..   ..  .. .... ..  ...::::.  
.:....  ....   ... ... ....      ..   ..... .... ........      
        ....    ..........        ... .......  ..... ..........
        ....         ....          ..........    ..  ......... 
                                                              
                                                              
                                                              
                                                              
                                            
                                            
                                            
    cout<<endl<<endl<<endl<<endl<<endl;
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
}*/

void metodiGenerali::closingTheGame(int m_punteggio){
	saveSystem::saveInBinaryFile(m_punteggio);
}

bool metodiGenerali::checkIfAppleEaten(Apple &apple, Serpente &serpente,int &punteggio, int &m_Punteggio){
	if(apple.getX() == serpente.getHeadPosX() && apple.getY() == serpente.getHeadPosY()){
		punteggio += 100;
		cout<<"\a";
		
		if(punteggio > m_Punteggio)
			m_Punteggio = punteggio; 
			
		apple.setActive(false); 
		if(serpente.getCorpoSerpenteArray().size() == 0)
			serpente.addBody(serpente.getPrevSnakePosX(),serpente.getPrevSnakePosY());
		else
			serpente.addBody(serpente.getSnakeTailX(),serpente.getSnakeTailY());
	}
}

void metodiGenerali::movementManager(int &currentMovement,Serpente &serpente){
	if(_kbhit()){
		char tasto = getch();
		
		switch(tasto){
			case 'W':
			case 'w':
				currentMovement = 1; //SOPRA
			break;
			case 'A':
			case 'a':
				currentMovement = 2; //SINISTRA
			break;
			case 'S':
			case 's':
				currentMovement = 3; //SOTTO
			break;
			case 'D':
			case 'd':
				currentMovement = 4; //DESTRA
		}
	}
	
	switch(currentMovement){
		case 1:
			serpente.move(0,-1);
			break;
		case 2:
			serpente.move(-1,0);
			break;
		case 3:
			serpente.move(0,1);
			break;
		case 4:
			serpente.move(1,0);
	}
	
	if(serpente.getHeadPosX() < 0)
		serpente.setHeadPosX(DIMX-1);
	else if(serpente.getHeadPosX() > DIMX)
		serpente.setHeadPosX(0);
		
	if(serpente.getHeadPosY() < 0)
		serpente.setHeadPosY(DIMY-1);
	else if(serpente.getHeadPosY() > DIMX)
		serpente.setHeadPosY(0);
		
	vector<Corpo_serpente> aus = serpente.getCorpoSerpenteArray();
	for(int i=0;i<aus.size();i++){
		if(aus[i].getPosX() > DIMX)
			aus[i].setPosX(0);
		else if(aus[i].getPosX() < 0)
			aus[i].setPosX(DIMX-1);
		
		if(aus[i].getPosY() > DIMY)
			aus[i].setPosY(0);
		else if(aus[i].getPosY()<0)
			aus[i].setPosY(DIMY-1);
	}	
	
		
	
}

bool metodiGenerali::checkIfGameOver(Serpente serpente){
	return serpente.isThereSerpe(serpente.getHeadPosX(),serpente.getHeadPosY());
}
