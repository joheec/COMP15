//
//  runList.h
//  OrderedRunners
//
//  Created by Chris Gregg on 1/31/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//
//  Changelog:
//    2015-09-11 msheldon 
//               Reorganized to make node struct private, 
//               changed head/tail to front/back,
//               made getters for front/back and insertBefore/insertAfter private
//               added getFirst/getLast for client access
//

#ifndef __OrderedRunners__runList__
#define __OrderedRunners__runList__

#include <iostream>
#include "runner.h"
using namespace std;

class RunList
{
public:
        RunList();
	~RunList();
        void insertInOrder(string runnerName, int runnerTime);
        void printList(bool reversed);
	Runner getFirst();
        Runner getLast();

private:
	struct RunnerNode {
        	Runner      aRunner;
        	RunnerNode *next;
        	RunnerNode *prev;
	};

        RunnerNode *front;
        RunnerNode *back;

        RunnerNode *getFront();
        RunnerNode *getBack();
        void insertBefore(RunnerNode *aNode, RunnerNode *newNode);
        void insertAfter (RunnerNode *aNode, RunnerNode *newNode);
};

#endif /* defined(__OrderedRunners__runList__) */
