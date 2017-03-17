#include "WaterBender.h"

WaterBender::WaterBender(string nombre , int ataque , int ataqueEs, int hp , int fuerza, int suerte): Bender( nombre ,ataque, ataqueEs,  hp  ,fuerza,  suerte){

}

void WaterBender::ataqueRegular(Bender* maestro){
	if(!this->smashHit()){
		maestro->setHp(maestro->getHp() - this->getNormal());	
	}else{
		maestro->setHp(maestro->getHp() - this->getNormal()-this->getNormal()*0.5);
	}	
} 
void WaterBender::ataqueEspecial(Bender* maestro){
	if(!this->smashHit()){
		if(typeid(maestro)==typeid(EarthBender)){
			maestro->setHp( maestro->getHp() - (this->getEspecial()+this->getEspecial()*0.25));
		}else{
			maestro->setHp(maestro->getHp() - (this->getEspecial()));
		}
	}else{
		if(typeid(maestro)==typeid(EarthBender)){
			maestro->setHp( maestro->getHp() - (this->getEspecial()+this->getEspecial()*0.25+this->getEspecial()*0.5));
		}else{
			maestro->setHp(maestro->getHp() - (this->getEspecial()+this->getEspecial()*0.5));
		}
	}
}
void WaterBender::defensa(Bender* maestro){
	maestro->setHp(maestro->getHp()+this->fuerza*0.08);
}
void WaterBender::ofensa(){
	cout<<"El agua calmara tu fuego"<<endl;
}

WaterBender::~WaterBender(){
}