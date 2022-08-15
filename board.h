#ifndef BOARD_H
#define BOARD_H

#include<stdlib.h>
#include<stdio.h>

struct Board {
    char contents[3][3];
    char plrTurn;
    unsigned char turn;
} typedef Board;

#define PLR1CHAR 'X'
#define PLR2CHAR 'O'

void create_board(Board* b);
int make_move(Board* b, int x, int y);
int check_win(Board b);
int advance_turn(Board* b, int x, int y);
void print_board(Board b);

#endif