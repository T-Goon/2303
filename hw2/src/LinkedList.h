/*
 * LinkedList.h
 *
 *  Created on: Nov 4, 2019
 *      Author: Therese
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "marker.h"


typedef Marker Payload;

struct DLLNode;
typedef struct
{
	struct DLLNode* next;
	struct DLLNode* prev;
	Payload* payP;
}DLLNode;


typedef struct
{
	Payload* mp;
	DLLNode* newQHead;
}backFromDQFIFO;

DLLNode* makeEmptyLinkedList();
DLLNode* removeFromList(DLLNode* hp, Payload* pP);
void savePayload(DLLNode* lp, Payload* mp);
bool isEmpty(DLLNode* lp);
Payload* dequeueLIFO(DLLNode* lp);
backFromDQFIFO* dequeueFIFO(DLLNode* lp);
void printHistory(DLLNode* hp);
int countLength(DLLNode* lp);

#endif /* LINKEDLIST_H_ */
