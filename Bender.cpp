#include "Bender.h"

Bender::Bender(string nombre,int ataque , int ataqueEs, int hp , int fuerza, int suerte){
	this->nombre = nombre;
	this->normal = ataque;
	this->especial = ataqueEs;
	this->hp = hp;
	this->fuerza = fuerza;
	this->suerte = suerte;
}

Bender::~Bender(){

}

string Bender::getNombre(){
	return nombre;
}	
int Bender::getHp(){
	return hp;
}	
int Bender::getNormal(){
	return normal;
}
int Bender::getEspecial(){
	return especial;
}
int Bender::getFuerza(){
	return fuerza;
}
int Bender::getSuerte(){
	return suerte;
}

void Bender::setNombre(string nombre){
	this->nombre = nombre;
}	
void Bender::setHp(int hp){
	this->hp = hp;
}	
void Bender::setNormal(int normal){
	this->normal = normal;
}
void Bender::seteEpecial(int especial){
	this->especial = especial;
}
void Bender::setFuerza(int fuerza){
	this->fuerza = fuerza;
}
void Bender::setSuerte(int suerte){
	this->suerte = suerte;
}

bool Bender::smashHit(){

	int random =1+rand()%1001;
	cout<<random<<endl;
	if(random == 50){
		return true;	
	}else if(suerte>=6 && suerte <=9){
		random = 1+rand()%101;
		if(random%5 == 0){
			return true;
		}else{
			return false;
		}
	}else if(suerte == 10){
		random = 1+rand()%10;
		if(random%3 ==0){
			return true;
		}else{
			return false;
		}

	}else{
		return false;
	}
	
}

void Bender::spiar(){
	cout<<"Nombre:"<<this->nombre<<endl; 
	cout<<"At:"<<this->normal<<endl;
	cout<<"Esp:"<<this->especial<<endl; 
	cout<<"HP:"<<this->hp<<endl; 
	cout<<"FUERZA:"<<this->fuerza<<endl; 
	cout<<"Suerte:"<<this->suerte <<endl;
}