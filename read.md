# sys boot in 32 bit

as --32 -o loader.o loader/loader.s

gcc -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -o kernel.o -c c++/kernel.cpp


ld -melf_i386 -T linker/linker.ld -o kernel.bin kernel.o loader.o

qemu-system-x86_64 -kernel kernel.bin