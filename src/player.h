/*
 * player.h
 *
 * Structure that stores Player information.
 *
 * Author: Arisien @ 20.2.2022
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
	size_t id;
	char name[16];
	unsigned int balance;
	unsigned float rate;
} Player;

#endif
