 
/**
 * Apresenta um "fatia de círculo" a rodar no centro da janela gráfica
 * 
 * build: gcc -o pie_rotate -Wall pie_rotate.c -lpg
 * 
 */

#include "pg/pglib.h"
#include <stdbool.h>
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
 
#define PIE_CENTER_X (WINDOW_WIDTH/2)
#define PIE_CENTER_Y (WINDOW_HEIGHT/2)

#define PIE_RADIUS 150
#define PIE_COLOR c_orange

#define TIME_BASE 50
#define PIE_ROTATE_STEP 20


// variáveis globais

int psa = 20;
int pea = 340;

double degree2rad(int a) {
    return (M_PI * a) / 180;
}

int rad2degree(double ar) {
    return (ar*180) / M_PI;
}

void draw_eye(int ea, int cx, int cy, int radius) {
    double ar = degree2rad(360 - ea + 50);
    int y = cy - radius * sin(ar);
    int x = cx + radius * cos(ar);
    
    int ex = (cx + x) / 2;
    int ey = (cy + y) / 2;
    graph_circle( ex, ey , 20, c_black, true);
    printf("(%d,%d, %d)\n", x, y, rad2degree(ar));
}


void timer_handler() {
    // apagar o ecrâ a partir da linha 50
    graph_rect(0,50, WINDOW_WIDTH, WINDOW_HEIGHT, c_white, true);
  
    graph_pie(PIE_CENTER_X, PIE_CENTER_Y, PIE_RADIUS, psa, pea, PIE_COLOR, true);
    draw_eye(pea, PIE_CENTER_X, PIE_CENTER_Y, PIE_RADIUS);
    
    psa = (psa +  PIE_ROTATE_STEP) % 360;
    pea = (pea +  PIE_ROTATE_STEP) % 360;
    
    // apresentar na consola de texto o ângulo inicial e final do pie
    // printf("(%d,%d)\n", psa, pea);
 
}



int main() {
    // é sempre necessário chamar esta função antes de mais
    graph_init2("Pies", WINDOW_WIDTH, WINDOW_HEIGHT);
    
    Size text_size = graph_font_size(LARGE_FONT);
 
 
    graph_text(0, text_size.height, c_blue, "Start!", LARGE_FONT);
    
     
    
    graph_regist_timer_handler(timer_handler, TIME_BASE);
    
    // toda a execução se processa dentro de graph_start
    graph_start();
    return 0;
    
}
 
