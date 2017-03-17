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
	int opcion;
	vector<Bender*>benders;
	srand(time(NULL));
	benders.push_back(new EarthBender("Toph" ,25 ,32, 75 , 40 , 1));
	benders.push_back(new FireBender("Zuko" ,15 ,45, 100 , 50 , 7));
	benders.push_back(new WaterBender("Katara" ,20 ,60, 80 , 50 , 10));
	benders.push_back(new AirBender("Aang" ,15 ,45, 100 , 50 , 7));
	

	cout<<"1.Desea entrenar Bender o 2.Simular:"<<endl;
	cin>>opcion;
	if(opcion == 1){
		
		cout<<"Las 4 naciones desean entrenar sus guerreros:"<<endl;
		cout<<"1.Tierra 2.Fuego 3. Agua 4. Aire "<<endl;
		string nombre;	
		int hp;	
		int normal;
		int especial;
		int fuerza;
		int suerte;

		cout<<"Ingrese nombre:"<<endl;
		cin>>nombre;
		cout<<"Ingrese hp:"<<endl;
		cin>>hp;
		cout<<"Ingrese Normal:"<<endl;
		cin>>normal;	
		cout<<"Ingrese Especial:"<<endl;
		cin>>especial;
		cout<<"Ingrese Fuerza:"<<endl;
		cin>>fuerza;
		cout<<"Ingrese Suerte:"<<endl;
		cin>>suerte;
		if(opcion == 1){
			benders.push_back(new EarthBender(nombre , hp , normal , especial , fuerza , suerte));
		}else if(opcion == 2){
			benders.push_back(new FireBender(nombre , hp , normal , especial , fuerza , suerte));
		}else if(opcion == 3){
			benders.push_back(new WaterBender(nombre , hp , normal , especial , fuerza , suerte));
		}else if(opcion == 4){
			benders.push_back(new AirBender(nombre , hp , normal , especial , fuerza , suerte));
		}
	}else{
		int indice1;
		int indice2;
		cout<<"Ingrese los benders que quiere:"<<endl;
		cin>>indice1;
		cin>>indice2;

		bash(benders[indice1], benders[indice2]);
	}
	
	



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
			at->ofensa();
			if(decision == 1){
				
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
			def->ofensa();
			if(decision == 1){
				
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
			if(at->getHp()<= 0){
				cout<<"Murio " <<at->getNombre()<<endl;
			}else if(def->getHp()<= 0){
				cout<<"Murio " <<def->getNombre()<<endl;
			}
			alguienMurio = false;
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


