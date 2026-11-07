# Project - CHIP-8 Emulator
# Date. November 2026

# checklist:
[] One-Line description and a screenshot of a game running.
[] Build instructions: dependencies(raylib or SDL), make, how to run ./chip8roms/pong.ch8.
[] Key mapping table.
[] Test results: which test ROMs pass, with screenshots.
[] My learning process, and links to the references I've used. 

# General thing for all models mkI, II, and III. Now, I will use MIT license. 
# For the MkI roadmap. The emulator. 
M1 - Repo, window, ROM loading:
[x] Create the Github repo and the folder layout.
[x] Install raylib (or SDL2/SDL3) and open a 640x320 window that closes cleanly. 
[] chip-init(): zero everything, copy the font to 0x50, set pc = 0x200
[] chip8_load_rom(): read the file with fread into emm + 0x200; reject files bigger than 3584 bytes. 
[] Print the first 16 bytes of the ROM in hex to check loading. 

M2- First Picture: the IBM logo (for example):
[] 00E0 clear screen, 1NNN jump
[] 6XNN set VX, 7NNN add to VX
[] ANNN set L
[] DXYN draw sprite: N rows from mem[I], XOR onto the screen, VD = 1 if
 any pixels was erased, clip to the edges
[] platform_draw() draws each lit pixel as a scaled rectangle

When thats done, we can change it to CHIP-8. 

M3 - All the opcodes. 
[] Subroutines: 2NNN call, 00EE return (push/pop the stack, check for overflow)
[] Skips: 3XNN, 4XNN, 5XY0, 9XY0
[] Arithmetic and logic 8XY0 - 8XYE: set the result first, the VF flag last
[] BNNN jump with offset, CXNN random (rand() & NN)
[] Memory: FX1E, FX29 (font address), FX33 (BCD), FX55, FX65
[] default: prints the unknown opcode and its address, thens stops. 

Done when: the Corax+ and Flags test ROMs show all checkmarks

M4 - Timign, timers, keys, sound:
[] Main loop at 60 frames epr second, run about 11 instructions per frame, configurable.
[] Decrement delay and sound timers once per frame; FX07, FX15, XF18
[] Keymap 1234/QWER/ASDF/ZXCV -> O-F; EX9E, EXA1.
[] FX0A wait for key: repeat the instruction pc -= 2 until a key is pressed and released.
[] Beep while the sound timer is above 0 (a raylib/SDL generated square wave).
Done when: the keypad test passes and you can actually play games 

M5 - Quirks and settings:
[] Implement each Quirks flag in the opcodes it changes. 
[] Command-line options: --speed 700, --scale 10, --quirks vip|schip
[] Optional: custom colours for "on" and "off" pixels 
Done when: The Quricks test reports correct behaviour for the  CHIP-8 profile.

M6 - Release MkI.
[] test/test_opcodes.c: a handful of opcode tests with assert, no window needed.
[] GitHub Actions workflow that builds and runs the tests on every push
[] README witha  GIF of a game, the key map and the results
[] Tag mk1, create a GitHub Release, write the CHANGELOG.md entry. 


