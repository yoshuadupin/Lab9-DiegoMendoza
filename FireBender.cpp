#include "FireBender.h"

FireBender::FireBender(string nombre , int ataque , int ataqueEs, int hp , int fuerza, int suerte): Bender( nombre,ataque, ataqueEs,hp  ,fuerza,  suerte){

}

void FireBender::ataqueRegular(Bender* maestro){
	if(!this->smashHit()){
		maestro->setHp(maestro->getHp() - this->getNormal());	
	}else{
		maestro->setHp(maestro->getHp() - this->getNormal()-this->getNormal()*0.5);
	}	
} 
void FireBender::ataqueEspecial(Bender* maestro){
	if(!this->smashHit()){
		if(typeid(maestro)==typeid(WaterBender)){
			maestro->setHp( maestro->getHp() - (this->getEspecial()+this->getEspecial()*0.25));
		}else{
			maestro->setHp(maestro->getHp() - (this->getEspecial()));
		}
	}else{
		if(typeid(maestro)==typeid(WaterBender)){
			maestro->setHp( maestro->getHp() - (this->getEspecial()+this->getEspecial()*0.5+this->getEspecial()*0.25));
		}else{
			maestro->setHp(maestro->getHp() - (this->getEspecial()+this->getEspecial()*0.5));
		}
	}
}
void FireBender::defensa(Bender* maestro){
	maestro->setHp(maestro->getHp()+this->fuerza*0.07);
}
void FireBender::ofensa(){
	cout<<"La Nacion del Fuego dominara las 4 Naciones"<<endl;
}

FireBender::~FireBender(){
}