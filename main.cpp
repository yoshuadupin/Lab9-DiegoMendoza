#include "Bender.h"
#include "AirBender.h"
#include "FireBender.h"
#include "EarthBender.h"
#include "WaterBender.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <typeinfo>


using namespace std;
bool run();
void bash(Bender* , Bender*);

int main(){
	srand(time(NULL));
	Bender* maestro1 = new EarthBender("Aang" ,10 ,50, 1000 , 50 , 5);
	Bender* maestro2 = new FireBender("Suko" ,10 ,50, 100 , 50 , 7);
	
	maestro1->ofensa();
	
	bash(maestro1, maestro2);	


	//cout<<maestro1->smashHit()<<endl;
	return 0;
}

void bash(Bender* at, Bender* def){
	bool huyo = false;
	bool turno = true;
	bool alguienMurio = true;
	cout<<"Naciones Enfrentadas!!!"<<endl;
	int decision;

	do{
		if(turno){
			cout<<"Primer Maestro ataca"<<endl;
			at->spiar();
			cout<<">>1.Normal\n>>2.Especial\n>>3.Recovery[Solo Maestros Aguas]\n>>4.Espiar[Maestros Tierras]\n>>5.RUN NIGGA MASTER"<<endl;
			cin>>decision;
			if(decision == 1){
				at->ofensa();
				at->ataqueRegular(def);
				def->defensa(at);
			}else if(decision == 2){	
				at->ataqueEspecial(def);
				def->defensa(at);
			}else if(decision == 3){
				if(typeid(at) == typeid(WaterBender)){
					//SUMAR
					at->setHp(at->getHp()+75);
				}
			}else if(decision == 4){
				if(typeid(at) == typeid(EarthBender)){
					//SUMAR
					at->spiar();
				}
			}else if(decision == 5){
				huyo = run();
			}
			
		}else{
			cout<<"Segundo Maestro ataca"<<endl;
			def->spiar();
			cout<<">>1.Normal\n>>2.Especial\n>>3.Recovery[Solo Maestros Aguas]\n>>4.Espiar[Maestros Tierras]"<<endl;
			cin>>decision;
			if(decision == 1){
				def->ofensa();
				def->ataqueRegular(at);
				at->defensa(def);
			}else if(decision == 2){	
				def->ataqueEspecial(at);
				at->defensa(def);
			}else if(decision == 3){
				if(typeid(at) == typeid(WaterBender)){
					//SUMAR
					def->setHp(def->getHp()+75);
				}
			}else if(decision == 4){
				if(typeid(def) == typeid(EarthBender)){
					//SUMAR
					def->spiar();
				}
			}else if(decision == 5){
				huyo = run();
			}
			
		}
		if(turno){
			turno = false;
		}else{
			turno = true;
		}
		if(at->getHp()<=0 || def->getHp()<=0){
			alguienMurio = false;
		}else{
			alguienMurio = true;
		}
	}while(alguienMurio && !huyo );

}

bool run(){
	int random = 1+rand()%10000;
	if(random<=10){
		return true;
	}
	return false;
}


