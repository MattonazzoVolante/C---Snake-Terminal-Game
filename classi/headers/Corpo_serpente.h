#ifndef CORPO_SERPENTE_H
#define CORPO_SERPENTE_H

const int corpo_serpente = '§';

class Corpo_serpente
{
	public:
		
		Corpo_serpente();
		Corpo_serpente(int,int);
		
		
		int getPosX();
		int getPosY();
		void setPosX(int);
		void setPosY(int);
	private:
		int posX,posY;
	
};

#endif
