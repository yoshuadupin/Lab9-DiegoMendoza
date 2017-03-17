#pragma once
#include "Bender.h"
#include "WaterBender.h"
class FireBender: public Bender
{
public:
	FireBender(string , int ,int ,int , int, int);
	~FireBender();

	 void ataqueRegular(Bender*);
	 void ataqueEspecial(Bender*) ;
	 void defensa(Bender*) ;
	 void ofensa();



	
};