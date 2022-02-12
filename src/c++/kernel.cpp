#include "header/types.h"
#include "display/main.cpp"
#include "header/gdt/gdt.h"
void halt(){
    while(1);
}
extern "C" void KernelMain(void* Data_from_bootloader,uint32_t magic_number)
{
    clear();
    print("hello world ");
    print("yup");
    // GlobalDescriptorTable gdt;
    halt();
}
//bisically for objconstructor
typedef void (*constructor)();
extern "C" constructor start_ctors;//array start function pointer
extern "C" constructor end_ctors;//array end function pointer

extern "C" void CallConstructors(){
    for(constructor *i = &start_ctors; i != end_ctors;i++){
        (*i)();
    }
    return 0;
}
//gcc -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -fpermissive -o kernel.o -c c++/kernel.cpp