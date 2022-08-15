#include"board.h"

void create_board(Board* b) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            (*b).contents[i][j] = 0;
        }
    }
    (*b).plrTurn = 1;
    (*b).turn = 0;
}

int make_move(Board* b, int x, int y) {
    if ((*b).contents[x][y] != 0) {
        return 0;
    }
    (*b).contents[x][y] = (*b).plrTurn;
    
    (*b).plrTurn = 3-(*b).plrTurn;
    (*b).turn += 1;
    return 1;
}

int check_win(Board b) {
    // check rows
    for (int y = 0; y < 3; y++) {
        if (b.contents[0][y] == b.contents[1][y] && b.contents[0][y] == b.contents[2][y]) {
            return b.contents[0][y];
        }
    }

    // check columns
    for (int x = 0; x < 3; x++) {
        if (b.contents[x][0] == b.contents[x][1] && b.contents[x][0] == b.contents[x][2]) {
            return b.contents[x][0];
        }
    }

    // check 1st diag
    if (b.contents[0][0] == b.contents[1][1] && b.contents[0][0] == b.contents[2][2]) {
        return b.contents[0][0];
    }
    // check 2nd diag
    if (b.contents[2][0] == b.contents[1][1] && b.contents[2][0] == b.contents[0][2]) {
        return b.contents[0][0];
    }

    if (b.turn == 9) {
        return -1;
    }

    return 0;
}

int advance_turn(Board* b, int x, int y) {
    int valid_move = make_move(b, x, y);
    if (valid_move) {
        int victory = check_win(*b);
        if (victory) {
            printf("Player %d won!\n", victory);
        }
        return 1;
    } else {
        return 0;
    }
}

void print_board(Board b) {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            switch(b.contents[x][y]) {
                case 0:
                    printf("*");
                    break;
                case 1:
                    printf("%c", PLR1CHAR);
                    break;
                case 2:
                    printf("%c", PLR2CHAR);
                    break;
            }
            //printf("%d ", b.contents[x][y]);
        }
        printf("\n");
    }
}

void test1() {
    Board b;
    create_board(&b);

    advance_turn(&b, 0, 0);
    print_board(b);

    advance_turn(&b, 1, 0);
    print_board(b);

    advance_turn(&b, 1, 1);
    print_board(b);

    advance_turn(&b, 2, 0);
    print_board(b);

    advance_turn(&b, 2, 2);
    print_board(b);
}