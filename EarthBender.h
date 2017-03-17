#pragma once
#include "Bender.h"
#include "AirBender.h"

class EarthBender: public Bender
{
public:
	EarthBender(string , int ,int ,int , int, int);
	~EarthBender();

	 void ataqueRegular(Bender*);
	 void ataqueEspecial(Bender*) ;
	 void defensa(Bender*) ;
	 void ofensa();



	
};