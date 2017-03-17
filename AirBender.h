#pragma once
#include "Bender.h"
#include "FireBender.h"

class AirBender: public Bender
{
public:
	AirBender(string , int ,int ,int , int, int);
	~AirBender();

	 void ataqueRegular(Bender*);
	 void ataqueEspecial(Bender*) ;
	 void defensa(Bender*) ;
	 void ofensa();



	
};