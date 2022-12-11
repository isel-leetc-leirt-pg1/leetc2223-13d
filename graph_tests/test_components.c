#include <pg/graphics.h>
#include <pg/components.h>
#include <stdbool.h>

// dimensões da janela gráfica
#define GRAPH_WIDTH 1024
#define GRAPH_HEIGHT 768

/*
 * Este programa ilustra a utilização de componente gráfico
 * util para apresentar mensagens na consola gráfica com determinado 
 * formato e apresentação (MsgView) e de componentes adicionais que 
 * utilizam MsgView. Um relógio com minutos e segundos (Clock) e 
 * Contador númerico (Counter)
 * 
 * Compilação:
 * 		gcc -o test_components -Wall  test_components.c -lpg
 *
 */
 
  
// CORES 
#define BACK_COLOR graph_rgb(36,128,75)
#define C_YELLOW graph_rgb(255, 255, 0)

// teclas 
#define PAUSE 		'p'
#define CONTINUE 	'c'

// teclas de direção

#define UP 	  SDLK_UP
#define LEFT  SDLK_LEFT
#define DOWN  SDLK_DOWN
#define RIGHT SDLK_RIGHT

// posições e dimensões dos componentes
#define CLOCK_X (GRAPH_WIDTH-150)
#define CLOCK_Y  20

#define E_VIEWER_X 50
#define KE_VIEWER_Y 200

#define ME_VIEWER_Y 350

#define E_VIEWER_MAX_CHARS 100
#define E_VIEWER_MARGIN	20

#define UP_X	50
#define DOWN_X	200
#define LEFT_X	350
#define RIGHT_X	500

#define COUNTER_Y 500

#define COUNTER_DIGITS 4

#define CMARGIN_X 10
#define CMARGIN_Y 10
 

/* Variáveis globais */

Clock theClock;					// componente relógio
MsgView kEventView;				// para visualização do evento de teclado
MsgView mEventView;             // para visualização dos eventos de rato


// contadores de teclas de direção
Counter countUp, countLeft, countRight, countDown; 

bool paused = false;			// indica se o relógio está pausado


/**
 * Handler de passagem de tempo
 */
void process_time() {
	if (!paused) {
		clk_tick(&theClock);
		clk_show(&theClock);
	}
}


/**
 * Apresentação do evento de teclado
 */
void showKeyEvent(KeyEvent ke) {
	char msg[128];
	sprintf(msg, "state=%s, kscan=%d, ksym=%d, keyName=%s",  
		ke.state == KEY_PRESSED ? "Key Pressed" : "Key Released", ke.keyscan, ke.keysym, ke.keyName);
	mv_show_text(&kEventView, msg, ALIGN_LEFT);
}


/**
 * Apresentação do evento de rato
 */
void showMouseEvent(MouseEvent me) {
	char msg[128];
    
    char *state;
    if (me.state == BUTTON_PRESSED) state = "BUTTON_PRESSED";
    else if (me.state == BUTTON_RELEASED) state = "BUTTON_RELEASED";
    else if (me.state == BUTTON_CLICK) state = "BUTTON_CLICK";
    else state = "BUTTON_NOT_PRESSED";
    
    
    char *button;
    if (me.button == BUTTON_LEFT) button = "BUTTON_LEFT";
    else if (me.button == BUTTON_RIGHT) button = "BUTTON_RIGHT";
    else button = "BUTTON_NONE";
 
    switch(me.type) {
        case MOUSE_MOTION_EVENT:
          
            
            sprintf(msg, "type=MOUSE_MOTION_EVENT, button=%s, state=%s, x=%d, y=%d, dx=%d, dy=%d", 
                          button, state, me.x, me.y, me.dx, me.dy);
            break;
        case MOUSE_BUTTON_EVENT:
             sprintf(msg, "type=MOUSE_BUTTON_EVENT, button=%s, state=%s, x=%d, y=%d", 
                          button, state, me.x, me.y);
            break;
    }              
	mv_show_text(&mEventView, msg, ALIGN_LEFT);	 
}


/**
 *  Handler de eventos de teclado
 */
void process_mouse(MouseEvent me) {
    showMouseEvent(me);
}




/**
 *  Handler de eventos de teclado
 */
void process_keys(KeyEvent ke) {
	
	// mostrar o evento na caixa de texto correspondente
	showKeyEvent(ke);
	
	// só produz efeito se for evento de tecla premida
	if (ke.state != KEY_PRESSED) return;
	
	
	// ajustar os contadores de teclas de direção
	// e definir ou retirar o estado de pausa
	switch(ke.keysym) {
		case UP:
			ct_inc(&countUp);
			break;
		case LEFT:
			ct_inc(&countLeft);
			break;
		case DOWN:
			ct_inc(&countDown);
			break;
		case RIGHT:
			ct_inc(&countRight);
			break;
		case PAUSE:
			paused = true;
			break;
		case CONTINUE:
			paused = false;
			break;
			
		default:
			break;
	}	 
}

/**
 * preenchimento do background com a respetiva côr
 */
void fill_background() {
	graph_rect(0,0, GRAPH_WIDTH, GRAPH_HEIGHT, BACK_COLOR, true);
}

/**
 * função de criação e apresentação inicial dos componentes gráficos
 */
void create_components() {
	// criação do relógio
	clk_create(&theClock, CLOCK_X, CLOCK_Y, LARGE_FONT, C_YELLOW, BACK_COLOR);
	
	// criação da área de visualização dos eventos de teclado
	mv_create(&kEventView, E_VIEWER_X, KE_VIEWER_Y, E_VIEWER_MAX_CHARS, 
						   MEDIUM_FONT, 
						   c_orange, c_dgray);
	
    // criação da área de visualização dos eventos de rato
	mv_create(&mEventView, E_VIEWER_X, ME_VIEWER_Y, E_VIEWER_MAX_CHARS, 
						   MEDIUM_FONT, 
						   c_orange, c_dgray);	
                           				   
	// criação dos contadores
	ct_create(&countUp, UP_X, COUNTER_Y, 0, "Up", MEDIUM_FONT);
	ct_create(&countLeft, LEFT_X, COUNTER_Y, 0, "Left", MEDIUM_FONT);
	ct_create(&countDown, DOWN_X, COUNTER_Y, 0, "Down", MEDIUM_FONT);
    ct_create(&countRight, RIGHT_X, COUNTER_Y, 0, "Right", MEDIUM_FONT);
	
	// apresentação inicial
    
    graph_text(E_VIEWER_X, KE_VIEWER_Y-30, c_gray, "Eventos de Teclado", MEDIUM_FONT);
	mv_show_text(&kEventView, "To show key Events", ALIGN_CENTER);
    
    graph_text(E_VIEWER_X, ME_VIEWER_Y-30, c_gray, "Eventos de Rato", MEDIUM_FONT);
    mv_show_text(&mEventView, "To show mouse Events", ALIGN_CENTER);
    
    graph_text(E_VIEWER_X, COUNTER_Y-30, c_gray, "Contadores de teclas de direcao", SMALL_FONT);
	ct_show(&countUp);
	ct_show(&countLeft);
	ct_show(&countDown);
	ct_show(&countRight);
    clk_show(&theClock);
}
 

/**
 * função main
 */
int main() {
  
	graph_init2("Test Components", GRAPH_WIDTH, GRAPH_HEIGHT);
	fill_background();
	create_components();
	
		
	graph_regist_key_handler(process_keys);
    graph_regist_mouse_handler(process_mouse);
	graph_regist_timer_handler(process_time, 1000);
	
	graph_start();
}


