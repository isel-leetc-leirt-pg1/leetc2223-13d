



// INFO ZOne

#define INFO_CLR                c_gray
#define BACK_TEXT_CLR           c_black
#define TEXT_CLR                c_orange
#define INFO_SIZE               MEDIUM_FONT
#define LABELS_CLR              c_black

#define X_LEFT                  30
#define X_RIGHT                 (game_get_width() - 200)

// snake size label
#define SNAKE_SIZE_MSG          "Size: "
#define SNAKE_SIZE_MSG_X        X_LEFT
#define SNAKE_SIZE_MSG_Y        5
#define SNAKE_SIZE_MSG_CLR      LABELS_CLR

// snake size view
#define SNAKE_SIZE_X            100
#define SNAKE_SIZE_Y            10


// level label
#define LEVEL_MSG               "Level: "
#define LEVEL_MSG_X             X_LEFT
#define LEVEL_MSG_Y             45
#define LEVEL_MSG_CLR           LABELS_CLR

// level view
#define LEVEL_X                 100
#define LEVEL_Y                 50
#define LEVEL_CLR               TEXT_CLR


// level timeout label
#define LEVEL_TIMEOUT_MSG       "Timeout: " 
#define LEVEL_TIMEOUT_MSG_X     X_RIGHT
#define LEVEL_TIMEOUT_MSG_Y     45
#define LEVEL_TIMEOUT_MSG_CLR   LABELS_CLR

// label timeout view
#define LEVEL_TIMEOUT_X         (X_RIGHT + 100)
#define LEVEL_TIMEOUT_Y         50
#define LEVEL_TIMEOUT_CLR       TEXT_CLR

// game time label
#define GAME_TIME_MSG           "Time: "
#define GAME_TIME_MSG_X          X_RIGHT
#define GAME_TIME_MSG_Y          5

// game time view
#define GAME_TIME_X              (X_RIGHT + 100)
#define GAME_TIME_Y              10
#define GAME_TIME_MSG_CLR        LABELS_CLR
#define GAME_TIME_CLR            TEXT_CLR

// functions
void start_level(Level *level);
void init_info_zone();
int info_tick(Level *level);
