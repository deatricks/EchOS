#include "../drivers/memalloc.h"
#include "../drivers/vga.h" //Ian driver go brrrrrrrrrrrrrrrrrr, also does not print int or float 
#include "../drivers/newLine.h"
void print_str(char string[]);
void main()
{
    init_text_vga();
    print("EchOS\n");
    print("Developed by deatricks");
    int a = 7;
    int *ptr = (int*)my_calloc(a, sizeof(int));
}


