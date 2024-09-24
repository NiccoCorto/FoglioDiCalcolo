
#ifndef PROJECTS_CELL_H
#define PROJECTS_CELL_H
#pragma once

#include "Subject.h"

class Cell : public Subject {
public:
    // Constructor with an optional value parameter
    Cell(int value = 0);

    // Getter for the cell's value
    int getValue() const;

    // Setter for the cell's value, which also notifies observers
    void setValue(int newValue);

private:
    // The value stored in the cell
    int value;
};

#endif //PROJECTS_CELL_H
