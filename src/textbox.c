#include "textbox.h"

#include <gb/gb.h>

#include "../res/textbox_tiles.h"
#include "../res/textbox_map.h"

uint8_t textbox_state = HIDDEN;
uint8_t textbox_y = 160u;
#define TEXTBOX_HEIGHT 48u
#define TEXTBOX_SPEED 2u

void init_textbox()
{
    set_win_data(304u, 6u, textbox_tiles);
    set_win_tiles(0, 0, 20u, 6u, textbox_mapPLN0);
}

void show_textbox()
{
    textbox_y = SCREENHEIGHT;
    textbox_state = SCROLL_UP;
}

void hide_textbox()
{
    textbox_state = SCROLL_DOWN;
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