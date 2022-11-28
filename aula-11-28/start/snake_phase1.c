#include <stdio.h>
#include "strutils.h"
#include <string.h>

// globals constants

#define LEVELS_FILE_NAME "levels.txt"
#define MAX_LINE 256
#define MAX_CMD_NAME 20

// errors constants

#define STATUS_OK 0
#define ERROR_INT_EXPECTED -1
#define ERROR_EOL_EXPECTED -2
#define ERROR_INVALID_CMD  -3

// show error function

void show_error(int error, int line, int col) {
    printf("error on line %d, col %d: ", line, col);
    switch(error) {
        case ERROR_EOL_EXPECTED:
            printf(" end of line expected!\n");
            break;
        case ERROR_INT_EXPECTED:
            printf("int expected!\n");
            break;
        case ERROR_INVALID_CMD:
            printf("invalid cmd!\n");
            break;
        default:
            printf("unknown error!\n");
            break;
    }
}

// commands processing

int cmd_game_config(const char line[], int *pos) {
    int window_size_x, window_size_y;
    
    if (str_next_int(line, pos, &window_size_x) != STR_OK)
        return ERROR_INT_EXPECTED;
        
    if (str_next_int(line, pos, &window_size_y) != STR_OK) 
        return ERROR_INT_EXPECTED;
    
    // if we can read more from in an error
    char w[2];
    if (str_next(line, pos, w, 2) != EOL) 
        return ERROR_EOL_EXPECTED;
    printf("\twindow_size_x = %d\n", window_size_x);
    printf("\twindow_size_y = %d\n", window_size_y);
    return STATUS_OK;
}

void load_snake_config(const char levels_filename[]) {
    
    FILE *flevels = fopen(levels_filename, "r");
    
    if (flevels == NULL) {
        printf("erro ao abrir o ficheiro de connfiguração!\n");
        return;
    }
    
    char line[MAX_LINE];
    int line_number = 0; // current line number
    
    while(fgets(line, MAX_LINE, flevels) != NULL) {
        char cmdname[MAX_CMD_NAME];
        int pos = 0;
        
        // new line
        line_number++;
        
        int res = str_next(line, &pos, cmdname, MAX_CMD_NAME);
        
        if (res == EOL) continue; // on empty line, reevaluate while condition
        if (cmdname[0] == '#') continue; // on comment line, do the same
        str_toupper(cmdname);
        
        printf("%s\n", cmdname);
        if (strcmp(cmdname, "GAME") == 0) {
            int res = cmd_game_config(line, &pos);
            if (res != STATUS_OK) {
                show_error(res, line_number, pos);
                break; // leave the while
            }
            
        }
        else if (strcmp(cmdname, "LEVEL") == 0) {
            // call cmd_level_config
        }
        else if (strcmp(cmdname, "WALL") == 0) {
            // call cmd_wall_config
        }
        // ...
        else {
            // show invalid command error
            show_error(ERROR_INVALID_CMD, line_number, pos);
            break;
        }
    }
    
    // close the file before return
    fclose(flevels);
}



int main() {
    load_snake_config(LEVELS_FILE_NAME);
    return 0;
}

