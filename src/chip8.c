/**
 * Author. Rod
 * Date. November 2026
 * Filename. chip8.c
 * Description. the machine itself. 
 */
// Libraries and the header:
#include "include/chip8.h"
// Defines *if they were required*:

// Functions:
void chip8_init(Chip8 *c){
    // zero all, load font, pc = 0x200
    // initialise function.
    // allocate memory for such initialisation
    //load the font, of the screen we call..
    chip8_load_rom; 
    // return whatever the value must it be..
    // free the memory. 
}
int chip8_load_rom(Chip8 *c, const char *path){
    // 0 is ok, -1 error
    // receive c
    // some functions where we are.
    // call timers and step:
    chip8_step();
    chip8_tick_timers();
    return true if (ok());
    return false if(error());
    // style. 
}
int chip8_step(Chip8 *c){
    // one instruction, -1 bad opcode.
    // whatever functions are thee.
    // returns one instruction
    // returns -1 if bad opcode.
}
void chip8_tick_timers(Chip8 *c){
    // call 60 times per second.
    // calc math for timings. 
    // return delay_timer
}
