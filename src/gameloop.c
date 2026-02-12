#include <gb/gb.h>

#include "gameloop.h"
#include "utils.h"

#include "../res/cafe_map.h"
#include "../res/cafe_tiles.h"
#include "../res/sprites_tiles.h"

void gameloop_setup_gfx()
{
    // BKG
    DISPLAY_OFF;
    set_bkg_data(0, 127u, cafe_tiles);
    set_bkg_tiles(0, 0, 20u, 18u, cafe_mapPLN0);
    SHOW_BKG;
    set_sprite_data(0, 28u, sprites_tiles);
    SHOW_SPRITES;
    DISPLAY_ON;
    RESTORE_PALETTE;
}
