section .asm

extern int21h_handler
extern no_interrupt_handler

global int21h
global idt_load
global no_interrupt

global enable_interrupts
global disable_interrupts

global idt_load
idt_load:
    push ebp
    mov ebp, esp


    mov ebx, [ebp+8]
    lidt[ebx]
    pop ebp
    ret

int21h:     ;Keyboard Interrupt
    cli
    pushad
    call int21h_handler
    popad
    sti
    iret    ; Return from interrupt


; Routine to handle no interrupts
no_interrupt:
    cli
    pushad
    call no_interrupt_handler
    popad
    sti
    iret

enable_interrupts:
    sti
    ret

disable_interrupts:
    cli
    ret