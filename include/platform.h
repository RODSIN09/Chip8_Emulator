/**
 * Author. Rod
 * Date. November 2026
 * Filename.  platform.h
 * Description. Header file of platform.c
 */
#ifndef PLATFORM_H
#define PLATFORM_H
#include "chip8.h"
int platform_init(int scale); /* window = 64*scale x
32*scale */
void platform_read_keys(bool keys[16]);
void platform_draw(const uint8_t *display);
void platform_beep(bool on);
bool platform_should_close(void);
void platform_shutdown(void);
#endif
