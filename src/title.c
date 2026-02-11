#include <gb/gb.h>

#include "title.h"
#include "utils.h"

#include "../res/dungeon_tiles.h"
#include "../res/dungeon_map.h"

void title_setup_gfx()
{
    DISPLAY_OFF;
    set_bkg_data(0, 79u, dungeon_tiles);
    set_bkg_tiles(0, 0, 32u, 32u, dungeon_mapPLN0);
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