#include "pg/pglib.h"



// Timer Period
#define TIMER_PERIOD  250

#define MIN_CELL_SIZE 10
#define MAX_CELL_SIDE 50

#define HEADER_SIZE  0
 

// colors
#define SNAKE_HEAD_COLOR    c_orange
#define SNAKE_BODY_COLOR    graph_rgb(207, 169, 135)
#define FLOWER_GOOD         graph_rgb(188, 255, 190)
#define FLOWER_BAD          graph_rgb(195, 0, 0)
#define ARENA_COLOR         graph_rgb(0, 118, 58)
#define WALL_COLOR          c_dgray


// errors 
#define SUCCESS              0
#define NUMBER_EXPECTED     -1
#define WORD_EXPECTED       -2
#define EOL_EXPECTED        -3
#define TARGET_EXPECTED     -4
#define ORIENT_EXPECTED     -5
#define INVALID_CMD         -6
#define GAME_WRONG_PLACE    -7
#define WALL_WRONG_PLACE    -8

#define WRONG_CELL_SIZE     -20
#define TOO_MANY_LEVELS     -21
#define BAD_COORDINATES     -22
#define TOO_MANY_WALLS      -24
#define TOO_MANY_FOOD       -25
#define BAD_WALL_SIZE       -26
#define TOO_MANY_SNAKES     -28
#define EMPTY_LEVEL_FILE    -29

// ENTITIES


// actors types
#define TYPE_WALL   1
#define TYPE_FOOD   2
#define TYPE_SNAKE  3
#define TYPE_NONE   0


// snake directions
#define DIR_UP      1
#define DIR_DOWN    2
#define DIR_LEFT    3
#define DIR_RIGHT   4
#define DIR_NONE    0

typedef struct {
    Point pos;                  // head position on grid coordinates
    int dir;                    // snake direction
    int time_to_eat;            // a penalty occurrs if snake doesn't eat before this time
    int penalty;                // the penalty size if the snake doesn't eat in time
} Snake;


#define HORIZONTAL  1           // horizontal wall
#define VERTICAL    2           // vertical wall

typedef struct {
    Point start;                // wall start localtion
    int type;                   // horizontal or vertical wall
    int size;                   // wall size
} Wall;


typedef struct {
    Point pos;
    int energy;                 // define the snake grow if eaten
                                // if negative tell the snake reduction if eaten
    int lifetime;               // time to life in seconds
} Food;


#define MAX_WALLS  15
#define MAX_FOOD 4
typedef struct {
    int cells_x;                // width cells number
    int cells_y;                // height cells number
    int cell_side;              // level side size in pixels
    int border_x, border_y;     // borders in presentation
    int target_size;            // snake size to reach in level
    int target_timeout;         // max time to reach target
    int  nwalls;                // number of level words
    Wall walls[MAX_WALLS];
    int  nfood;                 // number of level food items
    Food food[MAX_FOOD];
    Snake snake;                // the snake
} Level;


#define MAX_LEVELS 10
typedef struct {
    int curr_level_idx;             // current level index
    int nlevels;                // number of game levels
    Level levels[MAX_LEVELS];   // the levels
    int window_width;           // the game window width  
    int window_height;          // the game windows height
} Game;


/**
 *  FUNCTIONS
 */
 
//UTILS
Point cell_to_screen(Level* level, Point cell);

// POINT
void point_init(Point *p, int x, int y);
bool point_equals(Point p1, Point p2);

// GAME
void game_init(int width, int height);
Level *game_level(int nlevel);
int game_add_level(int width_cells, int height_cells, int target_size, int timeout);
int game_get_width();
int game_get_height();
void game_show();
int game_num_levels();
Level *game_curr_level();

// LEVEL
void level_init(Level *level, int width_cells, int height_cells, int target_size, int timeout);
int level_actor_at(Level *level, int px, int py);
int level_add_wall(Level *level, int p1x, int p1y, int type, int size);
int level_add_food(Level *level, int px, int py, int lifetime, int energy);
int level_put_snake(Level *level,int px, int py, int time_to_eat, int penalty);
void level_show(Level *level);
Snake *level_get_snake(Level *level);

// SNAKE
void snake_init(Snake *snake, int x, int y, int time_to_eat, int hungry_penalty);
void snake_show(Snake *snake, Level *level);
void snake_move(Snake *snake);
void snake_change_dir(Snake*snake, int dir);
 
// FOOD
void food_init(Food *f, int x, int y, int lifetime, int energy);
void food_show(Food *f, Level *level);     

// WALL
void wall_init(Wall *w, int p1x, int p1y, int p2x, int p2y);
bool wall_intersects(Wall *w, Point pos);
void wall_show(Wall *w, Level *level);
