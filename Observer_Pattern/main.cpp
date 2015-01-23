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

enum class Event{
    START,
    KILL
};

// example subject
class Controller : public Subject {
public:
    void RaiseEvent(const Event&);
};
void Controller::RaiseEvent(const Event& e) {
    Notify(e);
}

// example receiver
class Clock : public Observer {
public:
    Clock(Controller *);
    virtual ~Clock();
    
    virtual void Update(const Event&);

private:
    Controller * _subject;
};

Clock::Clock(Controller * s) {
    _subject = s;
    _subject -> Attach(this);
}

Clock::~Clock() {
    _subject -> Detach(this);
}

void Clock::Update(const Event& e) {
    switch (e) {
        case (Event::KILL):
            std::cout << "KILL \n";
            break;
        
        default:
            std::cout << "SOMETHING ELSE \n";
            break;
    }
}


// MAIN
int main(int argc, const char * argv[]) {
    
    Controller * ctrl = new Controller;
    
    Clock * clock = new Clock(ctrl);
    
    ctrl -> RaiseEvent(Event::KILL);
    ctrl -> RaiseEvent(Event::START);
    
    return 0;
}