#pragma once
#include "Bender.h"
#include "EarthBender.h"

class WaterBender: public Bender
{
public:
	WaterBender(string , int ,int ,int , int, int);
	~WaterBender();

	 void ataqueRegular(Bender*);
	 void ataqueEspecial(Bender*) ;
	 void defensa(Bender*) ;
	 void ofensa();



	
};