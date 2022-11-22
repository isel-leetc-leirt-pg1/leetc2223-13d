/**
 * Apresenta um rectângulo centrado na janela gráfica
 * 
 * build: gcc -o hello_graph -Wall hello_graph.c -lpg
 * 
 */
 
 
#include "pg/pglib.h"
#include <stdbool.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define RECT_WIDTH 300
#define RECT_HEIGHT 200


int main() {
    graph_init2("Hello", WINDOW_WIDTH, WINDOW_HEIGHT);
    
    int xro, yro;
    
    xro = (WINDOW_WIDTH - RECT_WIDTH) /2;
    yro = (WINDOW_HEIGHT - RECT_HEIGHT) /2;
    
    graph_rect(xro, yro, RECT_WIDTH,  RECT_HEIGHT, c_red, true);
    
    graph_start();
    return 0;
    
}

