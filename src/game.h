/*
 * game.h
 *
 * Structure that stores Game information.
 *
 * Author: Arisien @ 20.2.2022
 * 
 */

#ifndef GAME_H
#define GAME_H

#include <stdlib.h>

#include "./player.h";
#include "./map.h";

typedef struct {
	Player* players;
	Map* map;
} Game;

Game* game_create (char* name, char* filename, int bots, int x, int y);

void game_destroy (Game* map);

#endif
