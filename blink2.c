// Adapted from:
// https://github.com/hexagon5un/AVR-Programming/blob/master/Chapter02_Programming-AVRs/blinkLED/blinkLED.c

// Decent compiler instructions:
// https://www.nongnu.org/avr-libc/user-manual/group__demo__project.html

// Compile:
// avr-gcc -mmcu=attiny85 -o blink2 blink2.c -Os
// -mmcu sets MCU
// -Os is optimization
//    "The -Os option will tell the compiler to optimize the code for efficient space usage
//    (at the possible expense of code execution speed)."

// F_CPU
// https://www.nongnu.org/avr-libc/user-manual/group__util__delay.html#ga43bafb28b29491ec7f871319b5a3b2f8
//   "The macro F_CPU specifies the CPU frequency to be considered by the delay macros.
//   This macro is normally supplied by the environment (e.g. from within a project header,
//   or the project's Makefile). The value 1 MHz here is only provided as a "vanilla" fallback
//   if no such user-provided definition could be found."

//    /* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>     /* Defines pins, ports, etc */
#include <util/delay.h> /* Functions to waste time */

#define BLINK_ON 100
#define BLINK_OFF 900

int main(void)
{

    // -------- Inits --------- //
    DDRB |= 0b00000001; /* Data Direction Register B:
                                   writing a one to the bit
                                   enables output. */

    // ------ Event loop ------ //
    while (1)
    {

        PORTB = 0b00000001;  /* Turn on first LED bit/pin in PORTB */
        _delay_ms(BLINK_ON); /* wait */

        PORTB = 0b00000000;   /* Turn off all B pins, including LED */
        _delay_ms(BLINK_OFF); /* wait */

    }         /* End event loop */
    return 0; /* This line is never reached */
}