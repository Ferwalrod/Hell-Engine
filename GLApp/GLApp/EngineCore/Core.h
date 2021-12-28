#pragma once
#include "../HTL/HTL.h"
#include "3DObjects/Objects.h"
class HellEngine {
public:
	static HArray<HEntity> Entities;
	static void RunEngine(int argc, char** argv);
};
