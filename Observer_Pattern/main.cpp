//
//  main.cpp
//  Observer_Pattern
//
//  Created by MAN Team on 22/01/15.
//  Copyright (c) 2015 MAN Team. All rights reserved.
//

#include <iostream>
#include "Observer.h"
#include "Subject.h"

// example subject
class Timer : public Subject {
public:
    void Tick();
};

void Timer::Tick() {
    Notify();
}

// example receiver
class Clock : public Observer {
public:
    Clock(Timer*);
    virtual ~Clock();
    
    virtual void Update(Subject *);

private:
    Timer * _subject;
};

Clock::Clock(Timer * s) {
    _subject = s;
    _subject -> Attach(this);
}

Clock::~Clock() {
    _subject -> Detach(this);
}

void Clock::Update(Subject * theChangedSubject) {
    std::cout << "dupdupdup";
}


// MAIN
int main(int argc, const char * argv[]) {
    
    Timer * timer = new Timer;
    Clock * clock = new Clock(timer);
    
    timer -> Tick();
    
    return 0;
}