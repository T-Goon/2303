/*
 * Tests.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_

class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();

private:
    bool testRoom();
    bool testLinkedList();
    bool testAdjacencyMatrix();

};

#endif /* TESTS_H_ */