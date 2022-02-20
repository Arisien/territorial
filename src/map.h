/*
 * map.h
 *
 * Structure that stores Map information with Tiles.
 *
 * Author: Arisien @ 20.2.2022
 * 
 */

#ifndef MAP_H
#define MAP_H

#include <stdlib.h>

#include "./player.h";

typedef struct {
	_Bool isWater;
	Player* owner;
} Tile;

typedef struct {
	Tile* tiles;
	int height;
	int width;
} Map;

Tile* map_get (Map* map, int x, int y);

void map_set (Map* map, int x, int y, Player* owner);

Map* map_create (int width, int height);

void map_destroy (Map* map);

#endif
