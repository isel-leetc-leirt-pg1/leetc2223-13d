#include <pg/pglib.h>
#include <string.h>
#include "strutils.h"
#include "snake.h"
 
// globals
Game game;
bool game_end = false;
bool game_paused = false;
int curr_level_num = 1;

// visual components
MsgView level_timeout_msg;
Clock level_timeout;

MsgView game_time_msg;
Clock game_time;

MsgView level_msg;
MsgView curr_level;

MsgView snake_size_msg;
MsgView snake_size;





#define MAX_LINE  128

bool str_eol(char line[], int pos) {
    char c;
    return str_next_char(line, &pos, &c) == -1;
}


Level* cmd_level(char line[], int pos) {
    int target_size;
    int timeout;
    int width_cells;
    int height_cells;
    char target[7];
    
    if (str_next_int(line, &pos, &width_cells) < 0) return false;
    if (str_next_int(line, &pos, &height_cells)< 0) return false;
    
    if (str_next_word(line, &pos, target, 7) < 0) return false;
    if (strcmp("target", target) != 0) return false;
    
    if (str_next_int(line, &pos, &target_size) < 0) return false;
    if (str_next_int(line, &pos, &timeout) < 0) return false;
    // check no more chars in line
    if (!str_eol(line, pos)) return false;
    
    return game_add_level(width_cells, height_cells, target_size, timeout);
  
}



bool cmd_wall(Level* level, char line[], int pos) {
    
    if (level == NULL) return false;
    
    char parm[10];
    
    if (str_next_word(line, &pos, parm, 9) < 0) return false;
      
    int p1x, p1y, size;

    
    if (str_next_int(line, &pos, &p1x) < 0) return false;
    
    if (str_next_int(line, &pos, &p1y) < 0) return false;
      
    int p2x, p2y;
    
    if (strcmp("tilted", parm) == 0) {
        if (str_next_int(line, &pos, &p2x) < 0) return false;
        if (str_next_int(line, &pos, &p2y) < 0) return false;
    }
    else {
        if (str_next_int(line, &pos, &size) < 0) return false;
        if (strcmp("vert", parm) == 0) {
            p2x = p1x;
            p2y = p1y + size -1;
        }
        else if (strcmp("horiz", parm) == 0) {
            p2x = p1x + size -1;
            p2y = p1y;
        }
        else {
           return false;
        }
    }
    // check no more chars in line
    if (!str_eol(line, pos)) return false;
    
    return level_add_wall(level, p1x, p1y, p2x, p2y) >= 0;
}


bool cmd_food(Level* level, char line[], int pos) {
    if (level == NULL) return false;
    
    int px, py, lifetime, energy;
    if (str_next_int(line, &pos, &px) < 0) return false;
    if (str_next_int(line, &pos, &py) < 0) return false;
    if (str_next_int(line, &pos, &lifetime) < 0) return false;
    if (str_next_int(line, &pos, &energy) < 0) return false;
    // check no more chars in line
    if (!str_eol(line, pos)) return false;
    return level_add_food(level, px, py, lifetime, energy) >= 0;
}


bool cmd_snake(Level *level, char line[], int pos) {
    if (level == NULL) return false;
      
    int px, py, time_to_eat, hungry_penalty;
 
    if (str_next_int(line, &pos, &px) < 0) return false;
    if (str_next_int(line, &pos, &py) < 0) return false;
    if (str_next_int(line, &pos, &time_to_eat) < 0) return false;
    if (str_next_int(line, &pos, &hungry_penalty) < 0) return false;
    
    // check no more chars in line
    if (!str_eol(line, pos)) return false;
    return level_put_snake(level, px, py, time_to_eat, hungry_penalty);
}

bool cmd_window(char line[], int pos) {
    int ww, wh;
 
    if (str_next_int(line, &pos, &ww) < 0) return false;
    if (str_next_int(line, &pos, &wh) < 0) return false;
    // check no more chars in line
    if (!str_eol(line, pos)) return false;
    game.window_width = ww;
    game.window_height = wh + LEVEL_BASE_Y-1;
    return true;
}


bool cmd_portal(Level *level, char line[], int pos) {
    if (level == NULL) return false;
    
    int p1x, p1y, p2x, p2y;
    char parm[10];
    
    if (str_next_word(line, &pos, parm, 6) < 0) return false;
    int orientation = 0;
    
    if (strcmp("vert", parm) == 0) {
        orientation = VERTICAL_PORTAL;
    }
    else if (strcmp("horiz", parm) == 0) {
        orientation = HORIZONTAL_PORTAL;
    }
    else {
        return false;
    }
   
    if (str_next_int(line, &pos, &p1x) < 0) return false;
    if (str_next_int(line, &pos, &p1y) < 0) return false;
    if (str_next_int(line, &pos, &p2x) < 0) return false;
    if (str_next_int(line, &pos, &p2y) < 0) return false;
    
    // check no more chars in line
    if (!str_eol(line, pos)) return false;
    return level_put_portal(level, p1x, p1y, p2x, p2y, orientation);
}


#define MAX_CMD 10
bool load_levels() {
    char fileName[64];
    char line[MAX_LINE];
    
    
    sprintf(fileName, "/home/isel/pg1/testes/snake4/levels.txt");
    FILE *levelFile = fopen(fileName, "r");
    if (levelFile == NULL) {
        printf("erro ao abrir o ficheiro de nível\n");
        return false;
    }
    
    char cmd[MAX_CMD];
    Level* curr_level = NULL;
    
    while (fgets(line, MAX_LINE, levelFile) != NULL) {
        int pos= 0;
        
        str_trim(line);
        str_tolower(line);
        
        if (str_next_word(line, &pos, cmd, MAX_CMD) == 0 
            && line[0] != '#') { // no comment
            if (strcmp(cmd, "window") == 0) {
                if (!cmd_window(line, pos)) {
                    printf("error loading window info('%s')\n", line);
                    return false;
                }
            }
            else if (strcmp(cmd, "level") == 0) {
               if ((curr_level = cmd_level(line, pos)) == NULL) {
                    printf("error loading level info\n");
                    return false;
               }
            }
            else if (strcmp(cmd, "wall") == 0) {
               if (!cmd_wall(curr_level, line, pos)) {
                    printf("error loading wall info('%s')\n", line);
                    return false;
               }
            }
            else if (strcmp(cmd, "food") == 0) {
               if (!cmd_food(curr_level, line, pos)) {
                    printf("error loading food info\n");
                    return false;
               }
            }
            else if (strcmp(cmd, "portal") == 0) {
                if (!cmd_portal(curr_level, line, pos)) {
                    printf("error loading portal info\n");
                    return false;
                }
            }
            else if (strcmp(cmd, "snake") == 0) {
                if (!cmd_snake(curr_level, line, pos)) {
                    printf("error loading snake info\n");
                    return false;
                }
            }
        }
    }
    return true;
            
}


void game_init() {
    game.window_width = WINDOW_WIDTH;
    game.window_height = WINDOW_HEIGHT;
    game.ticks_to_sec = 1000/TIMER_PERIOD;
    game.nlevels = 0;
}


void game_tick() {
    game.ticks_to_sec--;
    if (game.ticks_to_sec == 0) {
          game.ticks_to_sec = 1000/TIMER_PERIOD;
     
        level_process_timed_actors(&game.levels[game.current_level]);
    }
}

Level *game_add_level(int width_cells, int height_cells, int target_size, int timeout) {
    level_init(&game.levels[game.nlevels++], width_cells, height_cells, target_size, timeout);
    return &game.levels[game.nlevels-1];
}

int game_get_width() {
    return game.window_width; 
}

int game_get_height() {
    return game.window_height; 
}

void game_show_points() {
    char text[32];
    int points_x = game.window_width/2 - 20;
    graph_rect(0,0, game.window_width, LEVEL_BASE_Y-1, BOARD_SCORE_COLOR, true);
    sprintf(text, "%d", game.npoints);
    graph_text( points_x, POINTS_Y, c_orange, text, LARGE_FONT );
}

void game_show() {
    if (game.current_level < game.nlevels)
        level_show(&game.levels[game.current_level]);
}

Level *game_curr_level() {
    return &game.levels[game.current_level];
}

Level *game_next_level() {
    if (game.current_level == game.nlevels-1) return NULL;
    return &game.levels[++game.current_level];
}


// EVENT HANDLERS


void process_collison(int colision_type, Level *level) {
    switch(colision_type) {
        case TYPE_WALL :
            printf("wall colision!\n");
            game.end = true;
            break;
         case TYPE_SNAKE:
            printf("snake colision!\n");
            game.end = true;
            break;
        case TYPE_FOOD:
            printf("food colision!\n");
            Food *fc = level_food_at_point(level, level->snake.head.pos);
            game.npoints += fc->energy;
            level->snake.to_grow = fc->energy;
          
            food_random_move(fc);
          
            break;
        case TYPE_PORTAL:
            printf("portal colision!\n");
            Point dst;
            
            if (portal_intersects(&level->portal, level->snake.head.pos, &dst)) {
                snake_moveto(&level->snake, dst);
            }
            break;
        default:
            break;
            
    }
}

/*
MsgView level_timeout_msg;
Clock level_timeout;

MsgView game_time_msg;
Clock game_time;

MsgView level_msg;
Counter curr_level;

MsgView snake_size_msg;
MsgView snake_size;
*/


#define INFO_CLR                c_gray
#define BACK_TEXT_CLR           c_black
#define TEXT_CLR                c_orange
#define INFO_SIZE               MEDIUM_FONT
#define LABELS_CLR              c_black

#define SNAKE_SIZE_MSG          "Size: "
#define SNAKE_SIZE_MSG_X        10
#define SNAKE_SIZE_MSG_Y        10
#define SNAKE_SIZE_MSG_CLR      LABELS_CLR

#define SNAKE_SIZE_X            100
#define SNAKE_SIZE_Y            10


#define LEVEL_MSG               "Level: "
#define LEVEL_MSG_X             10
#define LEVEL_MSG_Y             50
#define LEVEL_MSG_CLR           LABELS_CLR


#define LEVEL_X                 100
#define LEVEL_Y                 50
#define LEVEL_CLR               TEXT_CLR

#define LEVEL_TIMEOUT_MSG       "Timeout: " 
#define LEVEL_TIMEOUT_MSG_X     400
#define LEVEL_TIMEOUT_MSG_Y     50
#define LEVEL_TIMEOUT_MSG_CLR   LABELS_CLR
#define LEVEL_TIMEOUT_X         500
#define LEVEL_TIMEOUT_Y         50
#define LEVEL_TIMEOUT_CLR       TEXT_CLR

#define GAME_TIME_MSG           "Time: "
#define GAME_TIME_MSG_X          400
#define GAME_TIME_MSG_Y          10

#define GAME_TIME_X              500
#define GAME_TIME_Y              10
#define GAME_TIME_MSG_CLR        LABELS_CLR
#define GAME_TIME_CLR            TEXT_CLR

void init_components() {
    int window_width = game_get_width();
    Size fs =  graph_font_size(LARGE_FONT);
    Level *level = game_curr_level();
    
    graph_rect(0, 0, window_width, LEVEL_BASE_Y, INFO_CLR, true);
    // label da dimensão da cobra
    graph_text(SNAKE_SIZE_MSG_X, SNAKE_SIZE_MSG_Y + fs.height, SNAKE_SIZE_MSG_CLR, SNAKE_SIZE_MSG, INFO_SIZE);
    
    /*
    mv_create(&snake_size_msg, 
              SNAKE_SIZE_MSG_X, SNAKE_SIZE_MSG_Y, 
              strlen(SNAKE_SIZE_MSG),
              LARGE_FONT, SNAKE_SIZE_MSG_CLR, INFO_CLR);
    mv_set_margins(&snake_size_msg, 0, 0); 
    mv_show_text(&snake_size_msg, SNAKE_SIZE_MSG, ALIGN_RIGHT);
    */
    
    // dimensão da cobra
    mv_create(&snake_size,
              SNAKE_SIZE_X, SNAKE_SIZE_Y, 
              4,
              INFO_SIZE,
              TEXT_CLR,
              BACK_TEXT_CLR);
    mv_set_margins(&snake_size, 4, 4);           
    mv_show_number(&snake_size, snake_body_size(&level->snake));
    
    
    // label de tempo de jogo
    graph_text(GAME_TIME_MSG_X, GAME_TIME_MSG_Y  + fs.height, GAME_TIME_MSG_CLR, GAME_TIME_MSG, INFO_SIZE);
    
  
    /*
    mv_create(&game_time_msg,
              GAME_TIME_MSG_X, GAME_TIME_MSG_Y, 
              strlen(GAME_TIME_MSG),
              LARGE_FONT,
              GAME_TIME_MSG_CLR,
              INFO_CLR);
    mv_set_margins(&game_time_msg, 0, 0);   
    mv_show_text(&game_time_msg,GAME_TIME_MSG, ALIGN_RIGHT);
    */
    
    // label do número de nível
    graph_text(LEVEL_MSG_X, LEVEL_MSG_Y  + fs.height, LEVEL_MSG_CLR, LEVEL_MSG, INFO_SIZE);
  
    // número de nível
   
     
     mv_create(&curr_level,
              LEVEL_X, LEVEL_Y, 
              4,
              INFO_SIZE,
              TEXT_CLR,
              BACK_TEXT_CLR);
     mv_show_number(&curr_level, curr_level_num);
    
    
    
    // tempo de jogo
    clk_create(&game_time, GAME_TIME_X, GAME_TIME_Y, INFO_SIZE, GAME_TIME_CLR, BACK_TEXT_CLR);
    clk_show(&game_time);
    
    
    // label do timeout
    graph_text(LEVEL_TIMEOUT_MSG_X, LEVEL_TIMEOUT_MSG_Y  + fs.height, LEVEL_TIMEOUT_MSG_CLR, LEVEL_TIMEOUT_MSG,INFO_SIZE);
  
    int lt = level->target_timeout;
    
    // timeout
    clk_create_cron(&level_timeout, LEVEL_TIMEOUT_X, LEVEL_TIMEOUT_Y,
                    lt / 60, lt % 60,  INFO_SIZE, LEVEL_TIMEOUT_CLR, BACK_TEXT_CLR);
    clk_show(&level_timeout);
  
}

int info_ticks = 0;

#define LEVEL_CONT  0
#define LEVEL_WIN   1
#define LEVEL_LOOSE 2
int level_result;


#define TICKS_PER_SEC (1000/TIMER_PERIOD)
int info_tick(Level *level) {
    int res = 0;
    info_ticks++;
    if (info_ticks == TICKS_PER_SEC) {
        clk_tick(&game_time);
        clk_show(&game_time);
        res = clk_down_tick(&level_timeout);
     
        clk_show(&level_timeout);
        info_ticks = 0;
    }
    int body = game.npoints;
    mv_show_number(&snake_size, body);
    if (body >= level->target_size) return LEVEL_WIN;
    if (res == TIMEOUT) return LEVEL_LOOSE;
    return LEVEL_CONT;
}

int update_level(Level *level) {
    
    game_tick();
    return info_tick(level);
}

void show_end_game_msg(int res) {
    if (res == LEVEL_LOOSE) printf("game loosed!\n");
    else printf("game winned!\n");
}

#define MSG_LEVEL_WIN "Congrats, you win the level! Press a key to continue..."
#define MSG_GAME_LOOSE "You loose the game. Press a key to end... "
#define MSG_GAME_WIN "Congrats, you win the game! Press a key to continue..."


void show_end_level_msg(int res) {
    MsgView end_level_msg;
    char *msg;
 
    Level *next = game_next_level(); 
    if (res == LEVEL_LOOSE) { game_end = true; msg = MSG_GAME_LOOSE; }
    else if (next == NULL) { game_end = true; msg = MSG_GAME_WIN; }
    else { game_paused = true; msg = MSG_LEVEL_WIN; }
    Size sz = graph_text_size(msg, INFO_SIZE);
    
    int x = (game_get_width() - sz.width) /2;
    int y = (game_get_height() - sz.height) /2;
    mv_create(&end_level_msg,
              x, y,  
              strlen(msg),
              INFO_SIZE,
              TEXT_CLR,
              BACK_TEXT_CLR);
    mv_show_text(&end_level_msg, msg, ALIGN_CENTER);
}
    
void on_timer() {
    if (game_paused) return;
    if (game_end) return;
    if (game.end) return;
    //printf("ON TIMER!\n");
    //printf("show snake dir = %d!\n", snake.head.dir);
    game_show();
    ++game.nmoves;
    Level *level = game_curr_level();
    
    int res = update_level(level);
    
    switch(res) {
        case LEVEL_LOOSE:
      
            show_end_level_msg(res);
            break;
        case LEVEL_WIN:
            show_end_level_msg(res);
            printf("LEVEL WINNED!\n");
            break;
        default:
            process_collison(snake_move(&level->snake), level);
            break;
    }
            
}
 
 
        
void on_mouse(MouseEvent me) {
    if (me.type != MOUSE_MOTION_EVENT) return;
    uint code = 0;
   
    if (abs(me.dy) > abs(me.dx) ) {
        if (abs(me.dy) <3) return;
        if (me.dy < 0) code = SDLK_UP;
        else code = SDLK_DOWN;
    }
    else {
        if (abs(me.dx) <3) return;
        if (me.dx < 0) code = SDLK_LEFT;
        else code = SDLK_RIGHT;
    }
    Level *level = game_curr_level();
    snake_changedir(&level->snake,code);
        
}

void start_level(Level *level) {
      int lt = level->target_timeout;
      game_paused= false;
      clk_create_cron(&level_timeout, LEVEL_TIMEOUT_X, LEVEL_TIMEOUT_Y,
                    lt / 60, lt % 60,  INFO_SIZE, LEVEL_TIMEOUT_CLR, BACK_TEXT_CLR);
      clk_show(&level_timeout);
      mv_show_number(&snake_size, snake_body_size(&level->snake));
      mv_show_number(&curr_level, ++curr_level_num);
      info_ticks = 0;
      game.npoints = 0;
      level_show(level);
}

void on_key(KeyEvent ke) {
   
    Level *level = game_curr_level();
    if (ke.state == KEY_PRESSED) {
        if (game_end || game.end) graph_exit();
        if (game_paused) {
          
            start_level(level);
        }
        else {
            snake_changedir(&level->snake, ke.keysym);
        }
    }
}



int main() {
      
    game_init();
  
    if (!load_levels()) {
        printf("error loading levels!\n");
        return 0;
    }
   
    graph_init2("Snakes", game.window_width, game.window_height);
    init_components();
    
    graph_regist_key_handler(on_key);
    graph_regist_mouse_handler(on_mouse);
    graph_regist_timer_handler(on_timer, TIMER_PERIOD);
    
    level_show(&game.levels[0]);
    game.current_level = 0;
	graph_start();
}
