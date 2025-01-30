/* 
 * Provides Functions related to the VGA Text Buffer
 */

#ifndef VGA_H
#define VGA_H


void init_text_vga();

void print(const char* string);
void mvpos(int x, int y);
#endif