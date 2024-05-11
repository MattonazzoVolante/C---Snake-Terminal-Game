#include "headers/saveSystem.h"

void saveSystem::saveInBinaryFile(int dato){
	fstream dat;
    dat.open("saveFile.dat",ios::out|ios::binary);
    
    if(dat.fail())
		return;
    
	dat.write((char*) &dato,sizeof(int));
    dat.close();
}


int saveSystem::readBinaryFile(){
	fstream dat;
    dat.open("saveFile.dat",ios::in|ios::binary);
    
    if(dat.fail())
		return 0;
    
    int dato = 0;
    dat.read((char*)  &dato,sizeof(int));
    dat.close();
    
    return dato;
}
