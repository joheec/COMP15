//
//  runner.h
//  OrderedRunners
//
//  Created by Chris Gregg on 1/31/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#ifndef __OrderedRunners__runner__
#define __OrderedRunners__runner__

using std::string;

class Runner
{
public:
        Runner();
        Runner(string runnerName, int timeInSeconds);
        
        string getName();
        int    getTime();
        void   setName(string runnerName);
        void   setTime(int timeInSeconds);
        bool   isFasterThan(Runner anotherRunner);
private:
        string name;
        int    time;
        
};

#endif /* defined(__OrderedRunners__runner__) */
