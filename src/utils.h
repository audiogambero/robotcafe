#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdint.h>

#define RESTORE_PALETTE BGP_REG = 0b11100100
#define SCREEN_WHITE    BGP_REG = 0b00000000
#define SCREEN_BLACK    BGP_REG = 0b11111111

enum sprite_orientation
{
    SPRITE_DOWN = 0,
    SPRITE_LEFT,
    SPRITE_RIGHT,
    SPRITE_UP
};

extern void fade_screen(bool in);   //Blocking!

inline uint16_t xy_to_tile_idx(uint8_t x, uint8_t y) { return y * 18u + x; }



#endif