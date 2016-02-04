//
//  runList.cpp
//  OrderedRunners
//
//  Created by Chris Gregg on 1/31/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#include "runList.h"
#include "runner.h"
#include <iostream>
using namespace std;

// Want to do this, but can't:  using RunList::RunnerNode;

RunList::RunList()
{
        front = NULL;
        back  = NULL;
}

RunList::~RunList()
{
	RunnerNode *tempNode1 = front;
	RunnerNode *tempNode2 = NULL;
	while(tempNode1 != NULL) {
		tempNode2 = tempNode1->next;
		delete tempNode1;
		tempNode1 = tempNode2;
	}

}

RunList::RunnerNode *RunList::getFront()
{
        return front;
}

RunList::RunnerNode *RunList::getBack()
{
        return back;
}

Runner RunList::getFirst()
{
        return getFront()->aRunner;
}

Runner RunList::getLast()
{
        return getBack()->aRunner;
}

void RunList::insertInOrder(string runnerName, int runnerTime)
{
        RunnerNode *newNode = new RunnerNode();
        newNode->aRunner    = Runner(runnerName, runnerTime);
        
        RunnerNode *tempNode = front;
        if (tempNode == NULL) { // there aren't any nodes yet
                insertBefore(front, newNode);
        } else {
                while(tempNode != NULL) {
                	if(newNode->aRunner.getTime() < tempNode->aRunner.getTime()){
                		insertBefore(tempNode, newNode);
                		break;
                	}
                	tempNode = tempNode->next;
                }
        }
}
void RunList::insertBefore(RunList::RunnerNode *aNode,
                           RunList::RunnerNode *newNode)
{
	if (aNode == NULL) { // empty list
		front = newNode;
	        back  = newNode;
	}else if (aNode->prev == NULL) {
		newNode->prev = NULL;
		newNode->next = aNode;
		aNode->prev = newNode;
		front = newNode;
	}else {
		newNode->prev = aNode->prev;
		newNode->next = aNode;
		aNode->prev->next = newNode;
		aNode->prev = newNode;
	}
}

void RunList::insertAfter(RunList::RunnerNode *aNode,
                          RunList::RunnerNode *newNode)
{
        if (aNode == NULL) { // empty list
                front = newNode;
                back  = newNode;
        } else {
                newNode->prev = aNode;
                newNode->next = aNode->next;

                if (newNode->next == NULL) { // at the back
                        back = newNode;
                } else {
                        newNode->next->prev = newNode;
                }
                aNode->next = newNode;
        }

}

void RunList::printList(bool reversed)
{
        RunList::RunnerNode *iterator;
        
        if (reversed) {
                iterator = back;
        } else {
                iterator = front;
        }
        
        while (iterator != NULL) {
                cout << iterator->aRunner.getName() << ": ";
                cout << iterator->aRunner.getTime() << "\n";
                if (reversed) {
                        iterator = iterator->prev;
                } else {
                        iterator = iterator->next;
                }
        }
}
