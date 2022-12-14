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
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 900


Game game = {
    .window_width = WINDOW_WIDTH,
    .window_height = WINDOW_HEIGHT,
    .nlevels = 2,
    
    .levels = {
        { 
            .cells_x = 25,
            .cells_y = 16,
            .cell_side = WINDOW_WIDTH/25,
            .target_size = 20,
            .target_timeout = 70,
            .border_x = 0,
            .border_y = ((WINDOW_HEIGHT - HEADER_SIZE) - (WINDOW_WIDTH /25)*16)/2,
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
            .cell_side = WINDOW_WIDTH/50,
            .border_x = 0,
            .border_y = 64,
            .target_size = 20,
            .target_timeout = 90,
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




// utils

 
Point cell_to_screen(Level* level, Point cell) {
    Point scrpos;
    point_init(&scrpos, 
               level->border_x + cell.x*level->cell_side, 
               HEADER_SIZE + level->border_y  + cell.y*level->cell_side);
    return scrpos;
}

// pseudo-random generator initialization
void rand_init() {
     srand(time(NULL));
}

// returns a random number between min and max
int rand_range(int min, int max) {
    int range = (max - min) + 1;
    return rand() % range + min;
}


// game functions

void game_init(int width, int height) {
    game.window_width = width;
    game.window_height = height;
    game.nlevels = 2;
    game.curr_level_idx = 0;
    game.ticks_to_sec = TICKS_PER_SEC;
    game.end = false;
    game.paused = false;
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

void game_restart() {
    game.paused= false;
}

Level *game_next_level() {
    if (game.curr_level_idx == game.nlevels-1) return NULL;
    return &game.levels[++game.curr_level_idx];
}

int game_tick() {
    //Level *level = game_curr_level();
    //Snake *snake  = level_get_snake(level);
    
    // TO COMPLETE
    return LEVEL_CONT;
}

// Kbd events handler

#define MSG_LEVEL_WIN "Congrats, you win the level! Press a key to continue..."
#define MSG_GAME_LOOSE "You loose the game. Press a key to end... "
#define MSG_GAME_WIN "Congrats, you win the game! Press a key to continue..."


void show_msg(char *msg) {
   // TO CHANGE
   printf("%s\n", msg);
}

void process_loose() {
     show_msg(MSG_GAME_LOOSE);
     game.end = true;
}

void process_win() {
    // TO DO
    printf("GAME OR LEVEL WINNED!\n");
}

int process_collison(int colision_type, Point p, Level *level) {
     // TO DO
     return LEVEL_CONT;
}

int update_level(Level *level) {
    int res;
    if ((res = game_tick()) != LEVEL_CONT) return res;
    if (info_tick(level) == CHRON_TIMEOUT) return LEVEL_LOOSE;
    return LEVEL_CONT;
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

void on_key(KeyEvent ke) {
    // TO COMPLETE
    if (ke.state != KEY_PRESSED) return;
    Level *level = game_curr_level();
    Snake *snake = level_get_snake(level);
    
    int dir = key2dir(ke.keysym);
    
    if (dir != DIR_NONE)
          snake_change_dir(snake, dir);
}

void on_timer() {
    // TO_CHANGE
    Level *level = game_curr_level();
    Snake *snake = level_get_snake(level);
    
    snake_move(snake);
    level_show(level);
}



int main() {
    
    game_init(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    graph_init2("Snakes", game.window_width, game.window_height);
    init_info_zone();
    
    graph_regist_key_handler(on_key);
    graph_regist_timer_handler(on_timer, TIMER_PERIOD);
    
    level_show(&game.levels[0]);
   
	graph_start();
     
    return 0;
}
