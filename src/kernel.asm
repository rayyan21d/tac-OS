[BITS 32]

global _start
extern kernel_main
global problem 

CODE_SEG equ 0x08
DATA_SEG equ 0x10

_start:
    mov ax, DATA_SEG ; Data Segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov ebp, 0x00200000
    mov esp, ebp

    ;Enabling the A20 Line using Fast A20 Gate
    in al, 0x92
    or al, 2
    out 0x92, al

    ; Remap the master PIC
    mov al, 00010001b
    out 0x20, al ; Tell master PIC

    ; Interrupt 0x20 is where master ISR should start
    mov al, 0x20 
    out 0x21, al

    mov al, 00000001b
    out 0x21, al
    ; End remap of the master PIC
    
    call kernel_main
    jmp $



times 512-($-$$) db 0