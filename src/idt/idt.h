#ifndef IDT_H
#define IDT_H

#include <stdint.h>
struct idt_descriptor
{
    uint16_t offset_1; // offset bits 0..15
    uint16_t selector; // a code segment selector in GDT or LDT
    uint8_t zero;      // unused, set to 0
    uint8_t type_attr; // type and attributes, see below
    uint16_t offset_2; // offset bits 16..31

} __attribute__((packed));

struct idtr_descriptor
{
    uint16_t limit; // size of the interrupt descriptor table
    uint32_t base;  // base address of the interrupt descriptor table

} __attribute__((packed));

void idt_init();

#endif