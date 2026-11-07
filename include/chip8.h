/**
 * Author. Rod
 * Date. November 2026
 * Filename.  chip8.h
 * Description. header file of chip8.c
 */

#ifndef CHIP8_H
#define CHIP8_H
#include <stdint.h>
#include <stdbool.h>
#define MEM_SIZE 4096
#define START_ADDR 0x200
#define FONT_ADDR 0x050
#define SCREEN_W 64
#define SCREEN_H 32
#define STACK_SIZE 16
typedef struct {
bool shift_uses_vy; /* 8XY6/8XYE: original VIP copies VY first */
bool jump_uses_vx; /* BNNN: SUPER-CHIP uses BXNN + VX */
bool load_store_inc_i; /* FX55/FX65: original VIP increments I */
bool logic_resets_vf; /* 8XY1-8XY3: original VIP sets VF = 0 */
} Quirks;
typedef struct {
uint8_t mem[MEM_SIZE];
uint8_t v[16]; /* V0..VF */
uint16_t i;
uint16_t pc;
uint16_t stack[STACK_SIZE];
uint8_t sp;
uint8_t delay_timer;
uint8_t sound_timer;
uint8_t display[SCREEN_W * SCREEN_H]; /* 0 or 1 per pixel */
bool keys[16];
bool draw_flag; /* screen changed this frame */
Quirks quirks;
} Chip8;
void chip8_init(Chip8 *c); /* zero all, load font, pc
= 0x200 */
int chip8_load_rom(Chip8 *c, const char *path); /* 0 ok, -1 error
(missing/too big) */
int chip8_step(Chip8 *c); /* one instruction; -1 on
bad opcode */
void chip8_tick_timers(Chip8 *c); /* call 60 times per
second */
#endif
