#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

#define RESTORE_PALETTE BGP_REG = 0b11100100
#define SCREEN_WHITE    BGP_REG = 0b00000000
#define SCREEN_BLACK    BGP_REG = 0b11111111

extern void fade_screen(bool in);

#endif