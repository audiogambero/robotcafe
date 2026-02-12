#include <gb/gb.h>

#include "title.h"
#include "utils.h"

#include "../res/cafe_map.h"
#include "../res/cafe_tiles.h"

void title_setup_gfx()
{
    SCREEN_WHITE;
    DISPLAY_OFF;
    set_bkg_data(0, 127u, cafe_tiles);
    set_bkg_tiles(0, 0, 20u, 18u, cafe_mapPLN0);
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