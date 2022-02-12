#ifndef _PORT_H
#define _PORT_H
#include "../types.h"

class Port
{
    protected:
    uint16_t protnumber;
    Port(uint16_t protnumber);
    ~Port();
};


class Port8bit : public Port
{
    public:
    Port8bit(uint16_t protnumber);
    ~Port8bit();
    virtual void Write(uint8_t data);
    virtual uint8_t Read();
};
class Port8bitSlow : public Port8bit
{
    public:
    Port8bitSlow(uint16_t protnumber);
    ~Port8bitSlow();
    virtual void Write(uint8_t data);
    // virtual void Read();
};




class Port16bit : public Port
{
    public:
    Port16bit(uint16_t protnumber);
    ~Port16bit();
    virtual void Write(uint16_t data);
    virtual uint16_t Read();
};


class Port32bit : public Port
{
    public:
    Port32bit(uint16_t protnumber);
    ~Port32bit();
    virtual void Write(uint32_t data);
    virtual uint32_t Read();
};


#endif