prog:main.o mouvement.o collision.o personnages_init.o
	gcc main.o mouvement.o collision.o personnages_init.o -o prog  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
