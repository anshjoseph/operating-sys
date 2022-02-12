as --32 -o loader.o loader/loader.s
g++ -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wwrite-strings -fpermissive -o kernel.o -c c++/kernel.cpp
g++ -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wwrite-strings  -fpermissive -o gdt.o -c c++/header/gdt/gdt.cpp
g++ -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wwrite-strings -fpermissive -o port.o -c c++/header/port/port.cpp
# g++ -m32 -ffreestanding -fno
echo "file created"
ld -melf_i386 -T linker/linker.ld -o kernel.bin kernel.o gdt.o port.o loader.o
rm kernel.o
rm loader.o
rm port.o
rm gdt.o
objdump -S kernel.bin > kernel.txt
echo "operating system is running"
qemu-system-x86_64 -kernel kernel.bin