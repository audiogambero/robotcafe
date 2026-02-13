#include <gb/gb.h>

#include "title.h"
#include "utils.h"

#include "../res/titlescreen.h"

void title_setup_gfx()
{
    SCREEN_WHITE;
    DISPLAY_OFF;
    set_bkg_data(0, titlescreen_TILE_COUNT, titlescreen_tiles);
    set_bkg_tiles(0, 0, 20u, 18u, titlescreen_map);
    SHOW_BKG;
    DISPLAY_ON;
}

void run_title()
{
    title_setup_gfx();
    fade_screen(true);
    waitpad(J_START);
    fade_screen(false);
}