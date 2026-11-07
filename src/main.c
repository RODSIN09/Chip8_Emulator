/**
 * Author. Rod
 * Date. November 2026
 * Filename.  main.c
 * Description. The main file of the whole project.
 */
// includes:
#include <stdio.h>
#include "config.c"
#include "debugger.c"
#include "chip8.c"
// defines:
#define MSG "1. Game X, 2.\nGame Y.\nGame, 3.\nquit ('q').\n"
// main function:
int main(void){
    char option;

    printf(MSG);
    printf("Introduce an option: ");
    scanf("%s", option);

    switch(option){
        case 1:
            // whatever.
        case 2: 
            // whatever.
        /*       N cases        */
        default: 
            // whatever. 
    }

    /*
     * Functions calls, etc.
     */
    return 0;
}