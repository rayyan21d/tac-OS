#ifndef IO_H
#define IO_H

extern unsigned char in_byte(unsigned short port);
extern unsigned short in_word(unsigned short port);

extern void out_byte(unsigned short port, unsigned char data);
extern void out_word(unsigned short port, unsigned short data);

#endif