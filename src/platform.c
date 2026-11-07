/**
 * Author. Rod
 * Date. November 2026
 * Filename.  platform.c
 * Description. everything that allows the chip8 to be played, peripherics. 
 */
// includes:
#include "include/platform.h"
#include "chip8.c"

// functions:
int platform_init(int scale){
    // window = 64*scale x 32*scale
}
void platform_read_keys(bool keys[16]){
    // functions to read keys.
}
void platform_draw(const uint8_t *display){
    return display;
}
void platform_beep(bool on){
    // beeps, per timer?
}
bool platform_should_close(void){
    // if this were true, do so.
}
void platform_shutdown(void){
    // Some option, potentially was hit, therefore, it shutdowns. 
    return true; // if certain is true. 
}