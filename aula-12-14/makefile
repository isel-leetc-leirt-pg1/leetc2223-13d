all: snake_t3 tstrutils

snake_t3: game.c strutils.c  actors.c level.c  info_zone.o
	gcc -o snake_t3 -Wall -g game.c actors.c level.c strutils.c  info_zone.o -lpg
	
tstrutils: tstrutils.c strutils.c
	gcc -o tstrutils -Wall -g tstrutils.c strutils.c

clean:
	rm -rf snake_t3 tstrutils
