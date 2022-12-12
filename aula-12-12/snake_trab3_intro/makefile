all: simple_snake_c tstrutils

simple_snake_c: game.c strutils.c  actors.c level.c  
	gcc -o simple_snake_c -Wall -g game.c actors.c level.c strutils.c   -lpg
	
tstrutils: tstrutils.c strutils.c
	gcc -o tstrutils -Wall -g tstrutils.c strutils.c

clean:
	rm -rf simple_snake_c tstrutils
