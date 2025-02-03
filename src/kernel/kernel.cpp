#include "../drivers/memalloc.h"
#include "../drivers/vga.h" //Ian driver go brrrrrrrrrrrrrrrrrr, also does not print int or float 
#include "../drivers/newLine.h"
void print_str(char string[]);
void main()
{
    init_text_vga();
    print("EchOS\n");
    print("Developed by deatricks \n");
    /*int* a;
    int n, i;*/
     int n = 20;
    /*a = (int*)my_calloc(n, sizeof(int));
    for (i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    for (i = 0; i < n; ++i) {
        printint(a[i]);
    }*/
    print("\n"); 
    printint(n);
}