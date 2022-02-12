as --32 -o loader.o loader/loader.s
gcc -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wwrite-strings -o kernel.o -c c++/kernel.cpp
gcc -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wwrite-strings -o gdt.o -c c++/header/gdt/gdt.cpp
gcc -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wwrite-strings -o port.o -c c++/header/port/port.cpp
echo "file created"
ld -melf_i386 -T linker/linker.ld -o kernel.bin kernel.o gdt.o port.o loader.o
rm kernel.o
rm loader.o
rm port.o
rm gdt.o
objdump -S kernel.bin > kernel.txt
cat kernel.txt