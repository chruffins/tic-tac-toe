#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include "boardgui.h"

int main()
{
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_primitives_addon();
    //al_init_image_addon();

    run_board_gui();

    return 0;
}