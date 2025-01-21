#include "./vga.h"

#define TEXT_MODE_HEIGHT 25
#define TEXT_MODE_WIDTH 80

enum Color {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Purple = 5,
    Brown = 6,
    Gray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightPurple = 13,
    Yellow = 14,
    White = 15,
};

class VGATextMode {
    public:
        char* address;
        int x_pos;
        int y_pos;

        void write_byte(char byte);
};

extern VGATextMode VIDEO;

void VGATextMode::write_byte(char byte) {
    int pos = (y_pos * TEXT_MODE_WIDTH + x_pos) * 2;
    Color color = Yellow;

    address[pos] = byte;
    address[pos + 1] = color;
    if (x_pos == TEXT_MODE_WIDTH) {
        x_pos = 0;
        y_pos++;
    } else {
        x_pos++;
    }
}

VGATextMode VIDEO;

void init_text_vga() {
    VIDEO.address = (char*)0xb8000;
    VIDEO.x_pos = 0;
    VIDEO.y_pos = 0;
}

void print(const char* string) {
    while (*string != '\0') {
        VIDEO.write_byte(*string);
        string++;
    }
}