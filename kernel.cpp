#include "../drivers/memalloc.h"// My first (Sucessful) attempt of using ai to code
#include "../drivers/vga.h" //SCP 049 driver go brrrrrrrrrrrrrrrrrr, also does not print int or float 
#include "../drivers/inpt.h"//mine(Nothing rn)
void print_str(char string[]);

void main(){
    init_text_vga();
    print("EchOS \n");
    int a = 7;
    /*print(a);
    int *ptr = (int*)my_calloc(a, sizeof(int));
    print("%p", ptr);*/


}
void print_str(char string[]) {
    char *vga = (char *) 0xb8000;
    int index = 0;
    int pos = 0;
    do {
        vga[pos] = string[index];
        pos += 2;
        index += 1;
    } while (string[index] != '\0');
}


