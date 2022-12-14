#include "game.h"
#include "info_zone.h"


// visual components
MsgView level_timeout_msg;
Clock level_timeout;

MsgView game_time_msg;
Clock game_time;

MsgView level_msg;
MsgView curr_level;

MsgView snake_size_view_msg;
MsgView snake_size_view;

int curr_level_num = 1;
int info_ticks = 0;


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
    int ss = snake_size( level_get_snake(level));
    mv_show_number(&snake_size_view, ss);
    return res;
}


void init_info_zone() {
    int window_width = game_get_width();
    Size fs =  graph_font_size(LARGE_FONT);
    Level *level = game_curr_level();
    
    graph_rect(0, 0, window_width, HEADER_SIZE, INFO_CLR, true);
    
    // label da dimensão da cobra
    graph_text(SNAKE_SIZE_MSG_X, SNAKE_SIZE_MSG_Y + fs.height, SNAKE_SIZE_MSG_CLR, SNAKE_SIZE_MSG, INFO_SIZE);
    
    // dimensão da cobra
    mv_create(&snake_size_view,
              SNAKE_SIZE_X, SNAKE_SIZE_Y, 
              4,
              INFO_SIZE,
              TEXT_CLR,
              BACK_TEXT_CLR);
    mv_set_margins(&snake_size_view, 4, 4);           
    mv_show_number(&snake_size_view, snake_size(&level->snake));
    
    
    // label de tempo de jogo
    graph_text(GAME_TIME_MSG_X, GAME_TIME_MSG_Y  + fs.height, GAME_TIME_MSG_CLR, GAME_TIME_MSG, INFO_SIZE);
    
   
    
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
    chrono_create(&level_timeout, LEVEL_TIMEOUT_X, LEVEL_TIMEOUT_Y,
                    lt / 60, lt % 60,  INFO_SIZE, LEVEL_TIMEOUT_CLR, BACK_TEXT_CLR);
    clk_show(&level_timeout);
}

void start_level(Level *level) {
      int lt = level->target_timeout;
      game_restart();
      chrono_restart(&level_timeout,lt / 60, lt % 60);
      clk_show(&level_timeout);
      mv_show_number(&snake_size_view, snake_size(&level->snake));
      mv_show_number(&curr_level, ++curr_level_num);
      info_ticks = 0;
      level_show(level);
}
