#####
# Author. Rod
# Date. November 2026
#####

The program will pretend to be a tiny 1970 computer. It reads a file (a ROM) byte by byte and runs it, drawing 
to a 64x32 pixel windows. Three versions:

**MkI-Emulator**.`Runs real CHIP-8 games with graphics, sound and keyboard`. With the intent of learning bitwise,
hex,fetch-decode-execute, a graphics library and timing.
**MkII-Debugger**.`Pause, step one instruction, see registers and memory, load ROMs from a menu`. With the intent
of learning tooling, UI state, reading my own emulators internals.
**MkIII-Assembler**.`A tool that turns your text code into a ROM your emulator runs`. And again, with the intent
of learning lexing, parsing, symbol tables, two-pass assembly:the interpreter part.

Key things, the machine fits in one struct: 4KG of memory, 16 small registers, a stack, two timers, a 64x32
screen and a 16-key keypad. Allow me to break each down:

*Memory*. 4096 bytes - Programs load at 0x200; everything below is free for your font. 
*Font*. 16 sprites x 5 bytes - Hex digits 0-F; most people store them at 0x050-0x09F
*Registers V0-VF*. 8 bit each - VF doubles as the carry/collision flag.
*Index I*. 16-bits (12 used) - Points into memory, mainly at sprites. 
*Program counter*. 16-bit - Starts at 0x200
*Stack*. 16 entries x 16-bit - Only for subroutine returns addresses.
*Delay timer*. 8-bit - Counts down at 60Hz to 0.
*Sound timer*. 8-bit - Counts down at 60 Hz; beep while above 0.
*Display*. 64x32, 1 bit - Sprites are drawn with XOR; erasing a pixel sets VF.
*Keypad*. 16 keys, 0-F - Usually mapped to 1234 / QWER / ASDF / ZXCV
*Instructions* 35 opcodes, 2 bytes each - Big-endian: read mem[pc] << 8 | mem[pc+1]

With everything explained. Allow me to explain the Repo Structure. 
chip8/
|-src/
|    |- main.c	     // parse args, load ROM, run the main loop.
|    |-chip8.c       // the machine: init, load_rom, step (fetch-decode-execute), timers.
|    |-platform.c    // window, drawing pixels, keyboard, beep (raylib/SDL lives only HERE). 
|    |-config.c      // quirks, speed (instructions per frame), colours, key map.
|    |-debugger.c    // Mk II: pause, step, register/memory view.
|-include/
|    |-chip8.h
|    |-platform.h
|    |-config.h
|    |-debugger.h
|-asm/
|    |-src/
|    |    |-main.c    // c8asm input.c8s -o output.ch8
|    |    |-lexer.c   // text -> tokens
|    |    |-parser.c  // tokens -> instructions
|    |    |-emit.c    // instructions -> bytes, label resolution
|    |-include/
|    |-examples/      // my own .cs8 programs
|-tests/
|    |-test_opcodes.c // run opcodes on a Chip8 struct, assert the result, no window.
|-roms/		      // ROMs I download (git-ignored, see below)
|-scripts/
|    |-screenshots/   // for the README
|-docs/
|    |-screenshots/   // for me the README
|-.github/workflows/
|    |-build.yml      // CI: build + run texts on every push
|-Makefile
|-README.md
|-CHANGELOG.md
|-LICENSE
|-.gitignore


#### Some references for stuff I have looked:

Cloned raylib rep, from CLI: gh repo clone raysan5/raylib --> link: https://github.com/raysan5/raylib
SDL2 link https://wiki.libsdl.org/SDL2, there you can see the downloading procedure depending on your OS.
Also the docs for certain functions, as for the ones in chip8.h, are:
https://pubs.opengroup.org/onlinepubs/9799919799/ --> stdint.h
https://pubs.opengroup.org/onlinepubs/9799919799/ --> stdbool.h

