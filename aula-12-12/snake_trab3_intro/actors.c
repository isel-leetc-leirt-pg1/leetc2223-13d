#include "game.h"


// POINT


bool point_equals(Point p1, Point p2) {
    return p1.x == p2.x && p1.y == p2.y;
}


void point_init(Point *p, int x, int y) {
    p->x = x; p ->y = y;
}


// SNAKE

void snake_init(Snake *snake, int x, int y, int time_to_eat, int penalty) {
	point_init(&snake->pos, x, y);
    snake->time_to_eat = time_to_eat;
    snake->penalty = penalty;
   
}

void snake_show(Snake *snake, Level *level) {
   // To Implement
}

void snake_change_dir(Snake *snake,  int dir) {
    snake->dir = dir;
}
 
void snake_move(Snake *snake) {
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
            return;
    }
    snake->pos = new_pos;
}


// FOOD

void food_init(Food *f, int x, int y, int lifetime, int energy)  {
    point_init(&f->pos, x, y);
    f->lifetime = lifetime;
    f->energy = energy;
}
 
 
void food_show(Food *f, Level *level) {
   // To Implement
}

// WALL

void wall_init(Wall *w, int type, int px, int py, int size) {
    w->start.x = px;
    w->start.y = py;
    w->size = size;
    w->type = type;
}


void wall_show(Wall *w, Level *level) {
    // To Implement
}



/**
 * retorna true se o ponto "pos"
 * corresponde à posição de uma das quadrículas da parede apontada por "w"
 */
bool wall_intersects(Wall *w, Point pos) {
    // To implement
    return false;
}

 
