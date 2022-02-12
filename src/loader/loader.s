#boot section
.set MAGIC ,0x1badb002
.set FLAG ,(1<<0 | 1<<1)
.set CHECKSUM , -(MAGIC + FLAG)
.section .multiboot
    .long MAGIC
    .long FLAG
    .long CHECKSUM


    
#code execution section
.section .text
.extern KernelMain
#asm for CallConstructors from kernel.cpp
.extern CallConstructors
.global start
start:
    mov $kernel_stack,%esp

    call CallConstructors

    push %eax
    push %ebx
    call KernelMain
_loop:
    cli
    hlt 
    jmp _loop

.section .bss
    #it protect to over write the suff..
    .space 2*1024*1024 #about 2 mb
    kernel_stack: