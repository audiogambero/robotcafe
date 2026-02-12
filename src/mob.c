#include "mob.h"
#include "utils.h"
#include <gb/gb.h>
#include <rand.h>

#define MOB_MOVE_SPEED 1 //pixel per frame
bool mob_move_towards_target(Mob* mob, uint8_t x, uint8_t y)
{
    if(x > mob->x_pos)
    {
        mob->sprite = mob->sprite_base + SPRITE_RIGHT;
        mob->x_pos += MOB_MOVE_SPEED;
    }
    
    if(x < mob->x_pos)
    {
        mob->sprite = mob->sprite_base + SPRITE_LEFT;
        mob->x_pos -= MOB_MOVE_SPEED;
    }

    if(y > mob->y_pos)
    {
        mob->sprite = mob->sprite_base + SPRITE_DOWN;
        mob->y_pos += MOB_MOVE_SPEED;
    }

    if(y < mob->y_pos)
    {
        mob->sprite = mob->sprite_base + SPRITE_UP;
        mob->y_pos -= MOB_MOVE_SPEED;
    }
    
    return (x == mob->x_pos) & (y = mob->y_pos);
}

void mob_set_position(Mob* mob, uint8_t x, uint8_t y)
{
    mob->x_pos = x;
    mob->y_pos = y;
}

void mob_init(Mob* mob, uint8_t sprite_idx)
{
    mob->sprite_base = (((uint16_t)rand()) % 6u + 1u) * 4u;
    mob->sprite_idx = sprite_idx;
    mob->target_x = ((uint16_t)rand()) % 160u;
    mob->target_y = ((uint16_t)rand()) % 160u;
    mob->wait_ctr = (((uint16_t)rand()) % 5u) * 60u;
}

void mob_set_state(Mob* mob, uint8_t state)
{
    mob->state = state;
}

void mob_render(Mob* mob)
{
    // Assumes sprite tiles are already loaded
    set_sprite_tile(mob->sprite_idx, mob->sprite);
    move_sprite(mob->sprite_idx, mob->x_pos, mob->y_pos);
}

void mob_tick(Mob* mob)
{
    switch(mob->state)
    {
        case INACTIVE:
            mob->wait_ctr -= 1;
            if(mob->wait_ctr == 0)
            {
                mob->state = ENTERING_CAFE;
            }
            break;
        case ENTERING_CAFE:
            mob_set_position(mob, 76u, 160u);
            mob->state = MOVE_TO_SEAT;
            break;
        case MOVE_TO_SEAT:
            if(mob_move_towards_target(mob, mob->target_x, mob->target_y))
            {
                mob->wait_ctr = (((uint16_t)rand()) % 12u + 8u) * 60u;
                mob->state = WAIT;
            }
            break;
        case WAIT:
            mob->wait_ctr -= 1;
            if(mob->wait_ctr == 0)
            {
                mob->state = EXIT_CAFE;
            }
            break;
        case EXIT_CAFE:
            //move to exit
            if(mob_move_towards_target(mob, 76u, 160u))
            {
                mob->state = INACTIVE;
                mob->wait_ctr = (((uint16_t)rand()) % 5u) * 60u;
            }
            break;
    }
    mob_render(mob);
}
