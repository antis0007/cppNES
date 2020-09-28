#pragma once
#include <cstdint>
#include <array>
#include "cpu6502.h"
class bus //Bus class is made here, added functions in buss.cpp
{
//public:
	//bus();
	//~bus();

public: //Devices
	//6502 cpu
	cpu6502 cpu; //Create an instance of cpu6502 for use in bus
	//Emulated Ram
	//An array of uint8_t type data, (1 byte each), 64 * 1024
	std::array<uint8_t, 64 * 1024> ram;
public:
	void write(uint16_t addr, uint8_t data);
	uint8_t read(uint16_t addr, bool readonlybool = false);
};

