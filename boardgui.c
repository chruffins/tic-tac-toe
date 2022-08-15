#include "boardgui.h"

void draw_board_lines() {
    for (int i = 1; i < 3; i++) {
        al_draw_line(0, THIRD * i, BOARDSIZE, THIRD * i, al_map_rgb(255,255,255), 3);
        al_draw_line(THIRD * i, 0, THIRD * i, BOARDSIZE, al_map_rgb(255,255,255), 3);
    }
}

void draw_x(float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness) {
    al_draw_line(x1, y1, x2, y2, color, thickness);
    al_draw_line(x2, y1, x1, y2, color, thickness);
}

void draw_board_moves(Board* b) {
    //return;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            switch ((*b).contents[x][y])
            {
                case 1:
                    draw_x((x*THIRD)+40, (y*THIRD)+40, (x*THIRD)+120, (y*THIRD)+120, al_map_rgb(255,0,0), 10);
                    break;
                case 2:
                    al_draw_circle((x*THIRD)+(THIRD/2),(y*THIRD)+(THIRD/2), 40, al_map_rgb(0,255,0), 10);
                    break;
            }
        }
    }
}

void run_board_gui() {
    // game logic
    Board board;
    
    create_board(&board);

    // gui stuff
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 10.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_DISPLAY* disp = al_create_display(BOARDSIZE, BOARDSIZE);
    ALLEGRO_FONT* font = al_create_builtin_font();

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());

    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    while(1)
    {
        al_wait_for_event(queue, &event);

        if(event.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else if((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
            break;
        else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            //printf("%d %d %d %d\n", event.mouse.x, event.mouse.y, event.mouse.z, event.mouse.w);
            int sqx = event.mouse.x / THIRD;
            int sqy = event.mouse.y / THIRD;

            int attempt = (!check_win(board)) && advance_turn(&board, sqx, sqy);
            
            if (!attempt) {
                printf("You can't do that\n");
            }

            printf("%d %d\n", sqx, sqy);
        }

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            draw_board_lines();
            draw_board_moves(&board);
            //draw_x(40,40,120,120,al_map_rgb(255,0,0),10);

            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    printf("The lunatic is on the grass\n");
}