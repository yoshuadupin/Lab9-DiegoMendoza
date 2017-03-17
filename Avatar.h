#pragma once
#include "AirBender.h"
#include "WaterBender.h"
#include "EarthBender.h"
#include "FireBender.h"
#include "Bender.h"

class Avatar:public AirBender :public WaterBender:public EarthBender:public FireBender{
public:
	Avatar();
	~Avatar();
	
};