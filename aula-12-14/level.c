
#include "game.h"

int level_actor_at(Level *level, int px, int py) {
   // TO DO
   return TYPE_NONE;
}


// Not used in this version
void level_init(Level *level, int cells_x, int cells_y, int target_size, int target_timeout) {
   
    level->cell_side = game_get_width() / cells_x;
    
    int waste_x = game_get_width() % cells_x;
    int waste_y = (game_get_height() - HEADER_SIZE) - level->cell_side * cells_y;
    
    level->border_x = waste_x / 2;
    level->border_y = waste_y /2;
    
    level->nfood=0;
    level->target_size = target_size;
    level->target_timeout = target_timeout;
    level->cells_x = cells_x;
    level->cells_y = cells_y;

    // build outer walls
    wall_init(&level->walls[0], HORIZONTAL, 0, 0, level->cells_x );
    wall_init(&level->walls[1], HORIZONTAL, 0, level->cells_y -1, level->cells_x);
    wall_init(&level->walls[2], VERTICAL,   0, 1, level->cells_y -2);
    wall_init(&level->walls[3], VERTICAL, level->cells_x -1, 1, level->cells_y - 2);
    level->nwalls = 4;
}

 

void level_show(Level *level) {
    // draw background

    graph_rect(0,HEADER_SIZE, game_get_width(),game_get_height() -HEADER_SIZE, c_black, true);
   
    graph_rect(level->border_x,HEADER_SIZE+ level->border_y, 
               game_get_width()-level->border_x,
               game_get_height() -HEADER_SIZE - 2*level->border_y-1, ARENA_COLOR, true);
    
    // show walls
    for(int i=0; i < level->nwalls; ++i)
        wall_show(&level->walls[i], level);
        
    // show foods
    for(int i=0; i < level->nfood; ++i)
        food_show(&level->food[i], level);
    
    
    // show snake
    snake_show(&level->snake, level);
    
}


Snake *level_get_snake(Level *level) {
    return &level->snake;
}

 

Food* level_food_at_point(Level *level, Point pos) {
    for(int i= 0; i < level->nfood; ++i) {
        Food *food = &level->food[i];
        if (point_equals(food->pos, pos)) {
           return food;
        }
    }
    return NULL;
}
