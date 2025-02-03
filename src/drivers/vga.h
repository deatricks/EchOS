
#ifndef VGA_H
#define VGA_H


void init_text_vga();

void print(const char* string);
void printint(int num);
void mvpos(int x, int y);
#endif