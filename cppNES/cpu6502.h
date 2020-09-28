#pragma once
#include <cstdint>

class bus;
class cpu6502
{
public:
	cpu6502();
	~cpu6502(); //Construct and destruct to reset memory
	

	//LETS DEFINE THE REGISTERS:
	//The 6502 has a small amount of registers to store data and different stuff for operations
	//Register list:
	
	//Program Counter (16 bit)
	uint16_t pc = 0x0000;
	//Stack Pointer (8 bit) holds the low 8 bits of the next free location on the stack
	//   (Stack mini docs: The stack is a 256 byte section of memory located between $0x0100 and $0x01FF)
	//Basically, add the pointer value to the base value of stack location in memory (0x0100) to get the address in the stack
	uint8_t  stkp = 0x00;
	//Accumulator (8 bit)
	uint8_t  a = 0x00;
	//X Register (8 bits)
	uint8_t  x = 0x00;
	//Y Register (8 bits)
	uint8_t  y = 0x00;
	//P Flag (Status Flag) (8 bits, only 6 are used)
	//   See P flag map below:

	//NVss DIZC
	//|||| ||||
	//|||| |||+- Carry
	//|||| ||+-- Zero
	//|||| |+--- Interrupt Disable
	//|||| +---- Decimal
	//||++------ No CPU effect, see: the B flag
	//|+-------- Overflow
	//+--------- Negative

	//P FLAG enum for easy reading:
	enum p_bits
	{
		C = (1 << 0),	// carry
		Z = (1 << 1),	// zero
		I = (1 << 2),	// disable interrupts
		D = (1 << 3),	// decimal
		B = (1 << 4),	// break
		//? = (1 << 5),	// ???
		V = (1 << 6),	// overflow
		N = (1 << 7),	// negative
	};

	uint8_t  p = 0x00;

	//ALL FLAGS ARE PUBLIC


	// external event funcs, hardware pins that change cpu state
	//Reset Cpu into some state
	void reset();
	//Interrupt Request, force run instruction at memory location
	void irq();
	//Non maskable irq, cannot be disabled
	void nmi();

	//Perform one full clock cycle ======================================= CLOCK
	void clock();	

	// Indicates the current instruction has completed by returning true. This is
	// a utility function to enable "step-by-step" execution, without manually 
	// clocking every cycle
	bool complete();

	//LSD = Least significant digit
	//MSD = Most significant digit

	// The read location of data can come from two sources, a memory address, or
	// its immediately available as part of the instruction. This function decides
	// depending on address mode of instruction byte
	uint8_t fetch();
	uint8_t  fetched = 0x00;   // Represents the working input value to the ALU
	uint16_t temp = 0x0000; // A convenience variable used everywhere
	uint16_t addr_abs = 0x0000; // All used memory addresses end up in here
	uint16_t addr_rel = 0x00;   // Represents absolute address following a branch
	uint8_t  opcode = 0x00;   // Is the instruction byte
	uint8_t  cycles = 0;	   // Counts how many cycles the instruction has remaining
	uint32_t clock_count = 0;	   // A global accumulation of the number of clocks



	

	//DECLARING ADRESSING MODES:
	uint8_t imp(); //implicit, Doesnt even need to be called
	uint8_t acc(); //accumulator, will return val of a
	uint8_t imm(); //immediate
	uint8_t zp(); //zero page
	uint8_t zpx(); //zero page x
	uint8_t zpy(); //zero page y
	uint8_t rel(); //relative
	uint8_t abs(); //absolute
	uint8_t abx(); //absolute x
	uint8_t aby(); //absolute y
	uint8_t ind(); //indirect
	uint8_t izx(); //indirect x
	uint8_t izy(); //indirect y
	//Fetches data used by instruction
	//Used by all addressing modes except imp
	uint8_t fetch();
	//DECLARING THE OPCODES:
	void ADC();
	void AND();
	void ASL();
	void BCC();
	void BCS();
	void BEQ();
	void BIT();
	void BMI();
	void BNE();
	void BPL();
	void BRK();
	void BVC();
	void BVS();
	void CLC();
	void CLD();
	void CLI();
	void CLV();
	void CMP();
	void CPX();
	void CPY();
	void DEC();
	void DEX();
	void DEY();
	void EOR();
	void INC();
	void INX();
	void INY();
	void JMP();
	void JSR();
	void LDA();
	void LDX();
	void LDY();
	void LSR();
	void NOP();
	void ORA();
	void PHA();
	void PHP();
	void PLA();
	void PLP();
	void ROL();
	void ROR();
	void RTI();
	void RTS();
	void SBC();
	void SEC();
	void SED();
	void SEI();
	void STA();
	void STX();
	void STY();
	void TAX();
	void TAY();
	void TSX();
	void TXA();
	void TXS();
	void TYA();

	


	//CONNECTBUS SECTION ====================
	//create connectbus function
	void connectbus(bus* n) { bus_link = n; }
	//Explained: 
	//Uh, create a function inside cpu6502 named connectbus
	//It takes a pointer as an input?
	//Privately, it takes a nullptr named bus as defined ahead, but it is instanced inside bus class?
	//in bus.cpp, it calls to connectbus with "this", this means bus.cpp = n
	//inside the function, the pointer privately stored inside cpu6502 is modified to the memory address of the instance of bus.cpp
	//I hate that this works...

	//Check in private to find the nullptr "bus_link"
	//END OF CONNECTBUS SECTION ================
private:
	bus* bus_link = nullptr; //This creates a pointer of "bus" type to nullptr, named bus_link, this is a placeholder, it will be overwritten
	//Above explained:
	//creates a pointer of type "bus" named bus_link that points to null, until overwritten by connectbus when connectbus is run
	//Basically, when connectbus is run from another function, it allows bus_link to be set as a pointer to bus (via passing in "this" in bus.cpp)

	

	//These 2 should map with the bus read write functions
	uint8_t read(uint16_t a);
	void write(uint16_t a, uint8_t d);

	uint8_t get_p(p_bits f);  // f is enum letter for the flag to get or modify
	void set_p(p_bits f, bool v);
};

