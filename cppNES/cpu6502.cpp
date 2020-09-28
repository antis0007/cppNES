#include "cpu6502.h"
#include "bus.h"
cpu6502::cpu6502() {

}
cpu6502::~cpu6502() { //tilda means destructor, no use

}

uint8_t cpu6502::read(uint16_t a) {
	return bus_link->read(a, false); //Lets us run functions via using the pointer bus_link, which points to the bus file and all functions within
}
void cpu6502::write(uint16_t a, uint8_t d) {
	bus_link->write(a, d);
}
//:: is the scope resolution operator, allows to define a function for a class outside of it,
// or allows access to a global variable outside of a class for use inside, by denoting the name
// with :: as a prefix when referencing inside a class (useful if 2 vars of same name)

// Sorry for all the comments, im new to cpp

//DEFINING ADRESSING MODES
uint8_t cpu6502::imp() {} //implicit, Doesnt even need to be called
uint8_t cpu6502::acc() {
	
} //accumulator, will return val of a
uint8_t cpu6502::imm() {
	
} //immediate
uint8_t cpu6502::zp() {
	
} //zero page
uint8_t cpu6502::zpx() {} //zero page x
uint8_t cpu6502::zpy() {} //zero page y
uint8_t cpu6502::rel() {} //relative
uint8_t cpu6502::abs() {} //absolute
uint8_t cpu6502::abx() {} //absolute x
uint8_t cpu6502::aby() {} //absolute y
uint8_t cpu6502::ind() {} //indirect
uint8_t cpu6502::izx() {} //indirect x
uint8_t cpu6502::izy() {} //indirect y

//DEFINING THE OPCODES
void cpu6502::ADC() {
	//ADC - Add with Carry
	//A, Z, C, N = A + M + C


}
void cpu6502::AND() {}
void cpu6502::ASL() {}
void cpu6502::BCC() {}
void cpu6502::BCS() {}
void cpu6502::BEQ() {}
void cpu6502::BIT() {}
void cpu6502::BMI() {}
void cpu6502::BNE() {}
void cpu6502::BPL() {}
void cpu6502::BRK() {}
void cpu6502::BVC() {}
void cpu6502::BVS() {}
void cpu6502::CLC() {}
void cpu6502::CLD() {}
void cpu6502::CLI() {}
void cpu6502::CLV() {}
void cpu6502::CMP() {}
void cpu6502::CPX() {}
void cpu6502::CPY() {}
void cpu6502::DEC() {}
void cpu6502::DEX() {}
void cpu6502::DEY() {}
void cpu6502::EOR() {}
void cpu6502::INC() {}
void cpu6502::INX() {}
void cpu6502::INY() {}
void cpu6502::JMP() {}
void cpu6502::JSR() {}
void cpu6502::LDA() {}
void cpu6502::LDX() {}
void cpu6502::LDY() {}
void cpu6502::LSR() {}
void cpu6502::NOP() {}
void cpu6502::ORA() {}
void cpu6502::PHA() {}
void cpu6502::PHP() {}
void cpu6502::PLA() {}
void cpu6502::PLP() {}
void cpu6502::ROL() {}
void cpu6502::ROR() {}
void cpu6502::RTI() {}
void cpu6502::RTS() {}
void cpu6502::SBC() {}
void cpu6502::SEC() {}
void cpu6502::SED() {}
void cpu6502::SEI() {}
void cpu6502::STA() {}
void cpu6502::STX() {}
void cpu6502::STY() {}
void cpu6502::TAX() {}
void cpu6502::TAY() {}
void cpu6502::TSX() {}
void cpu6502::TXA() {}
void cpu6502::TXS() {}
void cpu6502::TYA() {}