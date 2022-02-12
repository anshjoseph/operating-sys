#include "port.h"
//implementation

Port::Port(uint16_t protnumber)
{
    this->protnumber = protnumber;
}
Port::~Port()
{}



//--------------------- 8bit
Port8bit::Port8bit(uint16_t protnumber):Port(protnumber){}
Port8bit::~Port8bit()
{}
uint8_t Port8bit::Read()
{
    uint8_t result;
    __asm__ volatile("inb %1, %0": "=a" (result) : "Nd" (protnumber));
    return result;
}
void Port8bit::Write(uint8_t data)
{
    __asm__ volatile("outb %0, %1":: "a"(data), "Nd"(protnumber));
}

//-------------------Slow 8bit
Port8bitSlow::Port8bitSlow(uint16_t protnumber):Port8bit(protnumber){}
Port8bitSlow::~Port8bitSlow()
{}

void Port8bitSlow::Write(uint8_t data)
{
    __asm__ volatile("outb %0, %1\njmp 1f\n1: jmp 1f\n1:":: "a"(data), "Nd"(protnumber));
}


//--------------------- 16bit
Port16bit::Port16bit(uint16_t protnumber):Port(protnumber){}
Port16bit::~Port16bit()
{}
uint16_t  Port16bit::Read()
{
    uint16_t result;
    __asm__ volatile("inw %1, %0": "=a" (result) : "Nd" (protnumber));
    return result;
}
void Port16bit::Write(uint16_t data)
{
    __asm__ volatile("outw %0, %1":: "a"(data), "Nd"(protnumber));
}


//--------------------- 32bit
Port32bit::Port32bit(uint16_t protnumber):Port(protnumber){}
Port32bit::~Port32bit()
{}
uint32_t  Port32bit::Read()
{
    uint32_t result;
    __asm__ volatile("inl %1, %0": "=a" (result) : "Nd" (protnumber));
    return result;
}
void Port32bit::Write(uint32_t data)
{
    __asm__ volatile("outl %0, %1":: "a"(data), "Nd"(protnumber));
}
