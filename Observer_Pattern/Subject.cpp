//
//  Subject.cpp
//  Observer_Pattern
//
//  Created by MAN Team on 22/01/15.
//  Copyright (c) 2015 MAN Team. All rights reserved.
//

#include <stdio.h>
#include "Subject.h"


void Subject::Attach (Observer * o) {
    _observers = new std::list<Observer *>();
    _observers->push_back(o);
}

void Subject::Detach (Observer * o) {
    _observers->remove(o);
}

void Subject::Notify (const Event& e) {
    std::list<Observer *>::const_iterator i;
    for (i = _observers->begin(); i != _observers->end(); ++i) {
        (*i)->Update(e);
    }
}

Subject::~Subject() {
    
}