#include <gb/gb.h>
#include <stdint.h>

#include "title.h"
#include "gameloop.h"

void main(void)
{
    run_title();
    gameloop_setup_gfx();

    // Loop forever
    while(1) {


		// Game main loop processing goes here


		// Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}
