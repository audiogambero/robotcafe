#ifndef MOB_H
#define MOB_H

#include <stdint.h>
#include <stdbool.h>

enum mob_state
{
    INACTIVE = 0,
    ENTERING_CAFE,
    MOVE_TO_SEAT,
    WAIT,
    EXIT_CAFE
};

typedef struct Mob_s Mob;

struct Mob_s {
    uint8_t x_pos;
    uint8_t y_pos;

    uint8_t target_x;
    uint8_t target_y;
    
    uint8_t sprite_idx;
    uint8_t sprite_base;
    uint8_t sprite;

    uint8_t state;
    uint16_t wait_ctr;
};

extern bool mob_move_towards_target(Mob* mob, uint8_t x, uint8_t y);
extern void mob_set_position(Mob* mob, uint8_t x, uint8_t y);
extern void mob_init(Mob* mob, uint8_t sprite_idx);
extern void mob_set_state(Mob* mob, uint8_t state);
extern void mob_render(Mob* mob);
extern void mob_tick(Mob* mob);

#endif