#include "EarthBender.h"

EarthBender::EarthBender(string nombre , int ataque , int ataqueEs, int hp , int fuerza, int suerte): Bender( nombre ,ataque, ataqueEs,hp  ,fuerza,  suerte){

}

void EarthBender::ataqueRegular(Bender* maestro){
	if(!this->smashHit()){
		maestro->setHp(maestro->getHp() - this->getNormal());	
	}else{
		maestro->setHp(maestro->getHp() - this->getNormal()-this->getNormal()*0.5);
	}

		
} 
void EarthBender::ataqueEspecial(Bender* maestro){
	if(!this->smashHit()){
		if(typeid(maestro)==typeid(AirBender)){
			maestro->setHp( maestro->getHp() - (this->getEspecial()+this->getEspecial()*0.25));
		}else{
			maestro->setHp(maestro->getHp() - (this->getEspecial()));
		}
	}else{
		if(typeid(maestro)==typeid(AirBender)){
			maestro->setHp( maestro->getHp() - (this->getEspecial()+this->getEspecial()*0.5+this->getEspecial()*0.25));
		}else{
			maestro->setHp(maestro->getHp() - (this->getEspecial()+this->getEspecial()*0.5));
		}
	}
}
void EarthBender::defensa(Bender* maestro){
	maestro->setHp(maestro->getHp()+this->fuerza*0.10);
}
void EarthBender::ofensa(){
	cout<<"Firme como la tierra"<<endl;
}

EarthBender::~EarthBender(){
}