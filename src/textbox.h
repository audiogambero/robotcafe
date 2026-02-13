#ifndef TEXTBOX_H
#define TEXTBOX_H

enum window_state
{
    HIDDEN = 0,
    SCROLL_UP,
    SHOWN,
    SCROLL_DOWN
};

extern void init_textbox();
extern void show_textbox();
extern void hide_textbox();
extern void update_textbox();
extern void set_textbox(const char* str);

#endif