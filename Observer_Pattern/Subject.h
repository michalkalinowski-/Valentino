//
//  Subject.h
//  Observer_Pattern
//
//  Created by MAN Team on 22/01/15.
//  Copyright (c) 2015 MAN Team. All rights reserved.
//

#ifndef __Observer_Pattern__Subject__
#define __Observer_Pattern__Subject__

#include <stdio.h>
#include <list>
#include "Observer.h"

enum class Event;

class Subject {
public:
    virtual ~Subject();
    
    virtual void Attach(Observer *);
    virtual void Detach(Observer *);
    virtual void Notify(const Event&);

private:
    std::list<Observer*> *_observers;
    
};

#endif /* defined(__Observer_Pattern__Subject__) */
