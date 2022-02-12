#ifndef _GDT_H
#define _GDT_H
#include "../types.h"

class GlobalDescriptorTable{
    public:
    class SegmentDescriptor{
        uint16_t limit_lo;
        uint16_t base_lo;
        uint8_t base_hi;
        uint8_t type;
        uint8_t flag_limit_hi;
        uint8_t base_vhi;
        public:
        SegmentDescriptor(uint32_t base,uint32_t limit, uint8_t flags);
        uint32_t Base();
        uint32_t Limit();
    }__attribute__((packed));


    SegmentDescriptor nullSegmentSelector;
    SegmentDescriptor unsedSegmentSelector;
    SegmentDescriptor codeSegmentSelector;
    SegmentDescriptor dataSegmentSelector;
    public:
    GlobalDescriptorTable();
    ~GlobalDescriptorTable();

    uint16_t CodeSegmentSelector();//send off set of code segment
    uint16_t DataSegmentSelector();//send off set of data segment
};


#endif