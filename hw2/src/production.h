/*
 * production.h
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol
#include "LinkedList.h"


#define FILENAMELENGTHALLOWANCE 50

DLLNode* moveMarker(int* board, int bSize, int numMarkers, DLLNode* listHead);
void production();



#endif /* PRODUCTION_H_ */
