#include <gb/gb.h>
#include <rand.h>

#include "gameloop.h"
#include "utils.h"
#include "mob.h"
#include "textbox.h"

#include "../res/cafe_map.h"
#include "../res/cafe_tiles.h"
#include "../res/sprites_tiles.h"

#define PLAYER_SPRITE_IDX 0
#define P_SPRITE_DOWN 0
#define P_SPRITE_LEFT 1
#define P_SPRITE_RIGHT 2
#define P_SPRITE_UP 3
uint8_t player_x = 70;
uint8_t player_y = 70;
uint8_t player_sprite;

uint8_t joypad_state;

#define NUM_MOBS 5
Mob mobs[NUM_MOBS];

void gameloop_setup_gfx()
{
    DISPLAY_OFF;
    // BKG
    set_bkg_data(0, 127u, cafe_tiles);
    set_bkg_tiles(0, 0, 20u, 18u, cafe_mapPLN0);
    SHOW_BKG;
    // OBJs
    set_sprite_data(0, 28u, sprites_tiles);
    SHOW_SPRITES;
    DISPLAY_ON;
    RESTORE_PALETTE;
}

void handle_input()
{
    if(joypad_state & J_RIGHT)
    {
        player_x += 1u;
        player_sprite = P_SPRITE_RIGHT;
    }
    if(joypad_state & J_LEFT)
    {
        player_x -= 1u;
        player_sprite = P_SPRITE_LEFT;
    }
    if(joypad_state & J_UP)
    {
        player_y -= 1u;
        player_sprite = P_SPRITE_UP;
    }
    if(joypad_state & J_DOWN)
    {
        player_y += 1u;
        player_sprite = P_SPRITE_DOWN;
    }

    if(joypad_state & J_A)
    {
        show_textbox();
    }
    if(joypad_state & J_B)
    {
        hide_textbox();
    }
}

void update_player()
{
    set_sprite_tile(PLAYER_SPRITE_IDX, player_sprite);
    move_sprite(PLAYER_SPRITE_IDX, player_x, player_y);
}

void run_gameloop()
{
    init_textbox();
    Mob* mob = mobs;
    for(int m = 0; m < NUM_MOBS; m++)
    {
        mob_init(mob++, m + 1);
    }

    while(1)
    {
        joypad_state = joypad();
        handle_input();
        update_player();

        mob = mobs;
        for(int m = 0; m < NUM_MOBS; m++)
        {
            mob_tick(mob++);
        }

        update_textbox();
        vsync();
    }
}