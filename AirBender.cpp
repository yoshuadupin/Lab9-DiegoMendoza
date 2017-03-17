#include "AirBender.h"

AirBender::AirBender(string nombre , int ataque , int ataqueEs, int hp , int fuerza, int suerte): Bender( nombre,ataque, ataqueEs,hp  ,fuerza,  suerte){

}

void AirBender::ataqueRegular(Bender* maestro){
	if(!this->smashHit()){
		maestro->setHp(maestro->getHp() - this->getNormal());	
	}else{
		maestro->setHp(maestro->getHp() - this->getNormal()-this->getNormal()*0.5);
	}	
} 
void AirBender::ataqueEspecial(Bender* maestro){
	if(!this->smashHit()){
		if(typeid(maestro)==typeid(FireBender)){
			maestro->setHp( maestro->getHp() - (this->getEspecial()+this->getEspecial()*0.15));
		}else{
			maestro->setHp(maestro->getHp() - (this->getEspecial()));
		}
	}else{
		if(typeid(maestro)==typeid(FireBender)){
			maestro->setHp( maestro->getHp() - (this->getEspecial()+this->getEspecial()*0.5+this->getEspecial()*0.15));
		}else{
			maestro->setHp(maestro->getHp() - (this->getEspecial()+this->getEspecial()*0.5));
		}
	}
}
void AirBender::defensa(Bender* maestro){
	maestro->setHp(maestro->getHp()+this->fuerza*0.05);
}
void AirBender::ofensa(){
	cout<<"La paz es el unico camino , por eso la defendere hazta la muerte"<<endl;
}

AirBender::~AirBender(){
}