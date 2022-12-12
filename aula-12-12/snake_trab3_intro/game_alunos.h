#include "pg/pglib.h"
 

// ENTITIES
 
 
typedef struct {
    Point pos;                  // head position on grid coordinates
    int time_to_eat;            // a penalty occurrs if snake doesn't eat before this time
    int penalty;                // the penalty size if the snake doesn't eat in time
} Snake;


#define HORIZONTAL  1           // horizontal wall
#define VERTICAL    2           // vertical wall

typedef struct {
    Point start;                // wall start location
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
    int target_size;            // snake size to reach in level
    int target_timeout;         // max time to reach target
    int  nwalls;                // number of level walls
    Wall walls[MAX_WALLS];
    int  nfood;                 // number of level food items
    Food food[MAX_FOOD];
   
    Snake snake;                // the snake
} Level;


#define MAX_LEVELS 10
typedef struct {
    int nlevels;                // number of game levels
    Level levels[MAX_LEVELS];   // the levels
    int window_width;           // the game window width  
    int window_height;          // the game windows height
} Game;

