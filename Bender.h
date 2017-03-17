#pragma once
#include <string>
#include <iostream>
#include <typeinfo>
#include <stdlib.h>

using namespace std;

class Bender
{
protected:

	string nombre;	
	int hp;	
	int normal;
	int especial;
	int fuerza;
	int suerte;

public:
	Bender(string ,int , int , int , int , int);
	~Bender();

	virtual void ataqueRegular(Bender*) = 0;
	virtual void ataqueEspecial(Bender*) = 0;
	virtual void defensa(Bender*) = 0;
	virtual void ofensa() = 0;

	string getNombre();	
	int getHp();	
	int getNormal();
	int getEspecial();
	int getFuerza();
	int getSuerte();

	void setNombre(string nombre);
	
	void setHp(int hp);
		
	void setNormal(int normal);
	
	void seteEpecial(int especial);
	
	void setFuerza(int fuerza);
	
	void setSuerte(int suerte);
	
	bool smashHit();

	void spiar();

};