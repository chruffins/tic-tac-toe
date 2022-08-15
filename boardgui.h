#ifndef BOARDGUI_H
#define BOARDGUI_H

#include "board.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
//#include <allegro5/allegro_image.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>



#define BOARDSIZE 480
#define THIRD (BOARDSIZE / 3)

void run_board_gui();
void draw_board_lines();
void draw_x(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness);
void draw_board_moves(Board* b);

#endif