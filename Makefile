all: os.bin

bin/os.bin: bin/boot.bin bin/full_kernel.bin
    cat bin/boot.bin bin/full_kernel.bin > bin/os.bin

bin/boot.bin: src/bootloader/boot.asm
    nasm -f bin src/bootloader/boot.asm -o bin/boot.bin

bin/entry.o: src/bootloader/entry.asm
    nasm src/bootloader/entry.asm -f elf -o bin/entry.o

bin/kernel.o: src/kernel/kernel.c
    i386-elf-gcc -ffreestanding -m32 -g -c src/kernel/kernel.c -o bin/kernel.o

bin/vga.o: src/drivers/vga.c src/drivers/vga.h
    i386-elf-gcc -ffreestanding -m32 -g -c src/drivers/vga.c -o bin/vga.o

bin/full_kernel.bin: bin/entry.o bin/kernel.o bin/vga.o
    i386-elf-ld -o bin/full_kernel.bin -Ttext 0x1000 bin/entry.o bin/kernel.o bin/vga.o --oformat binary

run: bin/os.bin
    qemu-system-x86_64 -drive format=raw,file=bin/os.bin,index=0,if=floppy -m 128M

clean:
    rm -f bin/*.bin bin/*.o