 /*
 ============================================================================
 Name        : Room.h
 Author      : Timothy Goon, Patrick Houlihan
 Version     :
 Copyright   : Your copyright notice
 Description : The header for the Room.c file
 ============================================================================
*/
#ifndef ROOM_H
#define ROOM_H

#include <stdbool.h>

bool open();

bool haveTreasure();

typedef struct {
    int index;
    char type [20];
    bool open;
    bool treasure;
}
Room;


#endif //ROOM_H
