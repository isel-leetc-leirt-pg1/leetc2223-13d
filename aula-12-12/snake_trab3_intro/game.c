#include <stdio.h>
#include <string.h>
#include "strutils.h"
#include <unistd.h>
#include "game.h"

#define LEVELS_FILE_NAME "levels.txt"
#define MAX_LINE  128
#define KEY_SPACE ' '
#define SHOW_LEVEL_PERIOD 5

// globals
Game game = {
    .window_width = 1200,
    .window_height = 800,
    .nlevels = 2,
    
    .levels = {
        { 
            .cells_x = 25,
            .cells_y = 16,
            .cell_side = 1200/25,
            .target_size = 20,
            .target_timeout = 17,
            .border_x = 0,
            .border_y =16,
            .nwalls = 6,
            .walls = {
                { .start = { .x = 0, .y = 0 }, .size = 25, .type = HORIZONTAL },
                { .start = { .x = 0, .y = 15 }, .size = 25, .type = HORIZONTAL },
                { .start = { .x = 0, .y = 1 }, .size = 14, .type = VERTICAL },
                { .start = { .x = 24, .y = 1 }, .size = 14, .type = VERTICAL },
                { .start = { .x = 15, .y = 3 }, .size = 10, .type = VERTICAL },
                { .start = { .x = 10, .y = 7 }, .size = 10, .type = HORIZONTAL },
            },
            .nfood = 1,
            .food = {
                { .pos = { .x = 21, .y = 3 }, .lifetime = 20, .energy = 6 }
            },
            .snake = { .pos = { .x = 3, .y = 10 }, .time_to_eat = 10, .penalty = 5 }
        },
        {
            .cells_x = 50,
            .cells_y = 28,
            .cell_side = 1200/50,
            .border_x = 0,
            .border_y =70,
            .target_size = 10,
            .target_timeout = 15,
            .nwalls = 10,
            .walls = {
                { .start = { .x = 0, .y = 0 }, .size = 50, .type = HORIZONTAL },
                { .start = { .x = 0, .y = 27 }, .size = 50, .type = HORIZONTAL },
                { .start = { .x = 0, .y = 1 }, .size = 26, .type = VERTICAL },
                { .start = { .x = 49, .y = 1 }, .size = 26, .type = VERTICAL },
                { .start = { .x = 10, .y = 5 }, .size = 10, .type = VERTICAL },
                { .start = { .x = 3, .y = 14 }, .size = 10, .type = VERTICAL },
                { .start = { .x = 39, .y = 5 }, .size = 8, .type = VERTICAL },
                { .start = { .x = 20, .y = 25 }, .size = 16, .type = HORIZONTAL },
                { .start = { .x = 26, .y = 12 }, .size = 10, .type = VERTICAL },
                { .start = { .x = 20, .y = 5 }, .size = 10, .type = HORIZONTAL }
            },
            .nfood = 2,
            .food = {
                { .pos = { .x = 37, .y = 8 }, .lifetime = 20, .energy = 6 },
                { .pos = { .x = 46, .y = 25 }, .lifetime = 40, .energy = -2 }
            },
            .snake = { .pos = { .x = 3, .y = 10 }, .time_to_eat = 10, .penalty = 4 }
        }
            
    }
};



int curr_level_idx = 0;
int count_ticks = 0;

// utils
 

 
Point cell_to_screen(Level* level, Point cell) {
    Point scrpos;
    point_init(&scrpos, 
               level->border_x + cell.x*level->cell_side, 
               HEADER_SIZE + level->border_y  + cell.y*level->cell_side);
    return scrpos;
}

 
// game functions

void game_init(int width, int height) {
    game.window_width = width;
    game.window_height = height;
    game.nlevels = 0;
    game.curr_level_idx = 0;
}

Level *game_level(int nlevel) {
    if ( nlevel >= game.nlevels) return NULL;
    return &game.levels[nlevel];
}

int game_add_level(int width_cells, int height_cells, int target_size, int timeout) {
    if (game.nlevels == MAX_LEVELS) return TOO_MANY_LEVELS;
     // validate cell side size
    int cell_side = game.window_width / width_cells;
    if (cell_side < MIN_CELL_SIZE || cell_side > MAX_CELL_SIDE ||
         game.window_height  < cell_side * height_cells) return WRONG_CELL_SIZE;
    
    level_init(&game.levels[game.nlevels++], width_cells, height_cells, target_size, timeout);
    return SUCCESS;
}

int game_get_width() {
    return game.window_width; 
}

int game_get_height() {
    return game.window_height; 
}

int game_num_levels() {
    return game.nlevels;
}

Level *game_curr_level() {
    if (game.curr_level_idx == game.nlevels) return NULL;
    return &game.levels[game.curr_level_idx];
}

// Kbd events handler
 
void show_next_level() {
    ++curr_level_idx;
        if (curr_level_idx == game_num_levels())
            curr_level_idx = 0;
    level_show(game_level(curr_level_idx));
   
}

 

void kbd_processor_fase3(KeyEvent ke) {
    // ignore event if not KEY_PRESSED
    if (ke.state != KEY_PRESSED) return;
    show_next_level();
}

int key2dir(int key) {
     switch(key) {
        case SDLK_UP: return DIR_UP;
        case SDLK_DOWN: return DIR_DOWN;
        case SDLK_LEFT: return DIR_LEFT;
        case SDLK_RIGHT: return DIR_RIGHT;
        default: return DIR_NONE;
    }
         
}


void kbd_processor(KeyEvent ke) {
    if (ke.state != KEY_PRESSED) return;
    Level *level = game_curr_level();
    Snake *snake = level_get_snake(level);
    
    int dir = key2dir(ke.keysym);
    
    if (dir != DIR_NONE)
          snake_change_dir(snake, dir);
}

void time_processor() {
/*
   ++count_ticks;
   if (count_ticks == SHOW_LEVEL_PERIOD) {
       count_ticks = 0;
       show_next_level();
   }
*/
    Level *level = game_curr_level();
    Snake *snake = level_get_snake(level);
    
    snake_move(snake);
    level_show(level);
}


int main() {
   
   
    graph_init2("Snakes", game.window_width, game.window_height);
    
    
    graph_regist_key_handler(kbd_processor);
    graph_regist_timer_handler(time_processor, TIMER_PERIOD);
  
    
    level_show(&game.levels[0]);
    graph_start();
     
    return 0;
}
