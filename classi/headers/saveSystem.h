#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class saveSystem
{
	public:
		
		static void saveInBinaryFile(int);
		static int readBinaryFile();
};

#endif
