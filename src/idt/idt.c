#include "idt.h"
#include "config.h"
#include "memory/memory.h"
#include "kernel.h"
#include "io/io.h"

struct idt_descriptor idt_descriptors[ryOS_TOTAL_INTERRUPTS];
struct idtr_descriptor idtr_descriptor;

extern void idt_load(struct idtr_descriptor* ptr);
void idt_zero(){

    print("Division by zero exception\n");

}

extern void int21h();
extern void no_interrupt();

void int21h_handler()
{
    print("Keyboard pressed!\n");
    out_byte(0x20, 0x20);
}

void no_interrupt_handler()
{
    out_byte(0x20, 0x20);
}

void idt_set(int interrupt_no, void* address)
{
    struct idt_descriptor* desc = &idt_descriptors[interrupt_no];
    desc->offset_1 = (uint32_t)address & 0x0000FFFF;
    desc->selector = KERNEL_CODE_SELECTOR;
    desc->zero = 0x00;
    desc->type_attr = 0xEE;
    desc->offset_2 = (uint32_t)address >> 16;

}


void idt_init()
{

    // Create a bunch of null descriptors
    memory_set(idt_descriptors, 0, sizeof(idt_descriptors) );
    idtr_descriptor.limit = sizeof(idt_descriptors) - 1;
    idtr_descriptor.base = (uint32_t) idt_descriptors;

    // Set all interrupts to no_interrupt
    for(int i=0; i<ryOS_TOTAL_INTERRUPTS; i++)
    {
        idt_set(i, no_interrupt);
    }

    idt_set(0, idt_zero);
    idt_set(0x20, int21h);

    // Load the interrupt descriptor table
    idt_load(&idtr_descriptor);
}
