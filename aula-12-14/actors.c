#include "game.h"


// UTILS
void indent(int level);


// POINT


bool point_equals(Point p1, Point p2) {
    return p1.x == p2.x && p1.y == p2.y;
}


void point_init(Point *p, int x, int y) {
    p->x = x; p ->y = y;
}


// SNAKE

// not used in this version
void snake_init(Snake *snake, int x, int y, int time_to_eat, int penalty) {
	point_init(&snake->pos, x, y);
    snake->time_to_eat = time_to_eat;
    snake->penalty = penalty;
    snake->dir = DIR_NONE;
    snake->body_count = 0;
    snake->iput = 0;
    snake->iget = 0;
    snake->to_grow = 0;
}

void snake_grow(Snake *snake, int grow) {
    snake->to_grow += grow;
}

bool snake_add_vertebra(Snake *s) {
    // TODO 
    return false;
}

bool snake_rem_vertebra(Snake *s) {
    // TO DO
    return false;
}

void snake_show(Snake *snake, Level *level) {
    Point scrPos = cell_to_screen(level, snake->pos);
	graph_pie(scrPos.x + level->cell_side/2, 
              scrPos.y + level->cell_side/2, 
              level->cell_side/2, 
              30, 330, SNAKE_HEAD_COLOR, true);
              
    // TO COMPLETE
}


void snake_change_dir(Snake *snake,  int dir) {
    snake->dir = dir;
}


int snake_move(Snake *snake) {
    Point new_pos;
    switch(snake->dir) {
        case DIR_UP:
            point_init(&new_pos, snake->pos.x, snake->pos.y - 1);
            break;
            
        case DIR_DOWN:
            point_init(&new_pos, snake->pos.x, snake->pos.y + 1);
            break;
           
        case DIR_LEFT:
           
            point_init(&new_pos, snake->pos.x - 1, snake->pos.y);
            break;
        case DIR_RIGHT:
            point_init(&new_pos, snake->pos.x + 1, snake->pos.y);
            break;
        default:
            return LEVEL_CONT;
    }
    
    Level *level = game_curr_level();
    
    // detect and process collision
  
    int type = level_actor_at(level, new_pos.x, new_pos.y);
    int res =  process_collison(type, new_pos, level);
    if (res != LEVEL_CONT) return res;
         
  
    
    snake->pos = new_pos;
    // move and change snake size
    return LEVEL_CONT;
}


int snake_size(Snake *s) {
    return s->body_count + 1;
}

// FOOD

void food_init(Food *f, int x, int y, int lifetime, int energy)  {
    point_init(&f->pos, x, y);
    f->lifetime = lifetime;
    f->baselifetime = lifetime;
    f->energy = energy;
}
 
void food_show(Food *f, Level *level) {
    Point scrPos = cell_to_screen(level, f->pos );
    
    graph_circle( scrPos.x + level->cell_side/2, 
                 scrPos.y + level->cell_side/2,
                 level->cell_side/2,
                 f->energy < 0 ? BAD_FOOD_COLOR : GOOD_FOOD_COLOR,
                 true);
}

void food_tick(Food *f) {
    // TO DO 
}

void food_random_move(Food *f) {
    // TO DO
}

// WALL

void wall_init(Wall *w, int type, int px, int py, int size) {
    w->start.x = px;
    w->start.y = py;
    w->size = size;
    w->type = type;
}

void wall_show(Wall *w, Level *level) {
    Point spos = cell_to_screen(level, w->start);
    if (w->type == VERTICAL) { //  VERTICAL_WALL 
        graph_rect(spos.x, spos.y, level->cell_side, w->size*level->cell_side, WALL_COLOR, true);
    }
    else { // HORIZONTAL_WALL
        graph_rect(spos.x, spos.y, w->size*level->cell_side, level->cell_side, WALL_COLOR, true);
    }
}


bool wall_intersects(Wall *w, Point pos) {
    // TO DO
    return false;
}

 
