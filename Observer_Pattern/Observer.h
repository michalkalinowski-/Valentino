//
//  Observer.h
//  Observer_Pattern
//
//  Created by MAN Team on 22/01/15.
//  Copyright (c) 2015 MAN Team. All rights reserved.
//

#ifndef __Observer_Pattern__Observer__
#define __Observer_Pattern__Observer__

#include <stdio.h>
#include <iostream>

class Subject;

class Observer {
public:
    virtual ~Observer();
    virtual void Update(Subject* theChangedSubject) = 0;
};

#endif /* defined(__Observer_Pattern__Observer__) */
