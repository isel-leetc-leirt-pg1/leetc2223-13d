/**
 * Apresenta um "fatia de círculo" centrada na janela gráfica
 * a imitar a cabeça da cobra
 * 
 * build: gcc -o pies -Wall pies.c -lpg
 * 
 */

#include "pg/pglib.h"
#include <stdbool.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
 
#define PIE_CENTER_X (WINDOW_WIDTH/2)
#define PIE_CENTER_Y (WINDOW_HEIGHT/2)
#define PIE_RADIUS 150
#define PIE_COLOR c_orange

#define TIME_BASE 50

void timer_handler() {
    printf("timer!\n");
}


int main() {
    graph_init2("Pies", WINDOW_WIDTH, WINDOW_HEIGHT);
    
    int psa = 30;
    int pea = 330;
    
    int x1 = PIE_CENTER_X;
    int y1 = PIE_CENTER_Y;
    
    int x2 = x1 + PIE_RADIUS;
    int y2 = y1 - PIE_RADIUS;
    
    int x = (x1 + x2) /2;
    int y = (y1 + y2) /2;
    int eye_radius = 20;
    
    graph_pie(PIE_CENTER_X, PIE_CENTER_Y, PIE_RADIUS, psa, pea, PIE_COLOR, true);
    
    graph_circle(x, y, eye_radius, c_black, true);


    graph_regist_timer_handler(timer_handler, TIME_BASE);
    graph_start();
    return 0;
    
}
