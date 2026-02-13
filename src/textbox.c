#include "textbox.h"

#include <gb/gb.h>

#include "../res/textbox_tiles.h"
#include "../res/textbox_map.h"
#include "../res/font_tiles.h"

uint8_t textbox_state = HIDDEN;
uint8_t textbox_y = 160u;
#define TEXTBOX_HEIGHT 48u
#define TEXTBOX_SPEED 2u

#define FONT_TILE_OFFSET 311u

void init_textbox()
{
    set_win_data(304u, 6u, textbox_tiles);
    set_win_tiles(0, 0, 20u, 6u, textbox_mapPLN0);

    //load font tiles
    set_win_data(FONT_TILE_OFFSET, 26u, font_tiles);
}

void show_textbox()
{
    if(textbox_state == SCROLL_UP || textbox_state == SHOWN)
        return;
    textbox_y = SCREENHEIGHT;
    textbox_state = SCROLL_UP;
}

void hide_textbox()
{
    textbox_state = SCROLL_DOWN;
}

void set_textbox(const char* string)
{
    const char* p = string;
    uint8_t x = 1u;
    uint8_t y = 1u;
    while(*p != '\0')
    {
        uint16_t tile_idx = *p - 65u + FONT_TILE_OFFSET;
        if(*p == ' ') tile_idx = 310u;
        set_win_tile_xy(x, y, tile_idx);
        if(x++ > 17u)
        {
            x = 1u;
            y++;
        }
        p++;
    }
}

void update_textbox()
{
    switch(textbox_state)
    {
        case SCROLL_UP:
            SHOW_WIN;
            if(textbox_y <= SCREENHEIGHT - TEXTBOX_HEIGHT)
            {
                textbox_state = SHOWN;
                return;
            }
            textbox_y -= TEXTBOX_SPEED;
            break;
        case SCROLL_DOWN:
            SHOW_WIN;
            if(textbox_y >= SCREENHEIGHT)
            {
                textbox_state = HIDDEN;
                HIDE_WIN;
                return;
            }
            textbox_y += TEXTBOX_SPEED;
            break;
        case SHOWN:
            SHOW_WIN;
            break;
        default:
            HIDE_WIN;
            return;
    }
    move_win(7u, textbox_y);
}