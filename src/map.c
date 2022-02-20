/*
 * map.c
 *
 * Functions relating to Map and Tile structures.
 *
 * Author: Arisien @ 20.2.2022
 * 
 */

#include "./map.h";

Tile* map_get (Map* map, int x, int y) {
	return (map->tiles + y*map->width + x);
}

void map_set (Map* map, int x, int y, Player* owner) {
	Tile* tile = map_get(map, x, y);
	tile->owner = owner;
}

Map* map_create (int width, int height) {
	Map* map = malloc(sizeof(Map));
	
	map->tiles = malloc(height * width * sizeof(Tile));
	map->height = height;
	map->width = width;

	for (int i = 0; i < width * height; i++) {
		map->tiles[i]->isWater = false;
		map->tiles[i]->owner = NULL;
	}

	return map;
}

void map_destroy (Map* map) {
	free(map->tiles);
	free(map);
}
