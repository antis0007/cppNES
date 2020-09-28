#include "bus.h"
bus::bus() {
	//Clear ram at start
	for (auto& i : ram) i = 0x00;  //auto& i : ram iterates through the entire ram array
	
	cpu.connectbus(this); //runs the connectbus func (defined in cpu6502.h)
}
bus::~bus() {
}
void bus::write(uint16_t addr, uint8_t data) {
	if (addr >= 0x0000 && addr <= 0xFFFF)
		ram[addr] = data;
}
uint8_t bus::read(uint16_t addr, bool readonlybool = false) {
	if (addr >= 0x0000 && addr <= 0xFFFF)
		return ram[addr];
	//If read is attempted out of ram range, return 0x00
	return 0x00;
}
