
#ifndef PROJECTS_OBSERVER_H
#define PROJECTS_OBSERVER_H
#pragma once

class Subject;

class Observer {
public:
    virtual void update(Subject *subject) = 0;
};

#endif //PROJECTS_OBSERVER_H
