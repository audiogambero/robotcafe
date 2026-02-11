#include "utils.h"
#include <gb/gb.h>

static const uint8_t fade_palette_values[4] = {0b11100100, 0b10010000, 0b01000000, 0b00000000};    //Fade to white

#define SCREEN_FADE_FRAMES 8    // Frames per each palette
void fade_screen(bool in)
{
    uint8_t c = 0;
    while(c < 4)
    {
        BGP_REG = in ? fade_palette_values[3 - c] : fade_palette_values[c];
        uint8_t f = 0;
        while(f < SCREEN_FADE_FRAMES)
        {
            f++;
            vsync();
        }
        c++;
    }
}