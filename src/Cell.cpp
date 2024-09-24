#include "../include/Cell.h"

// Constructor definition
Cell::Cell(int value) : value(value) {}

// Getter method definition
int Cell::getValue() const {
    return value;
}

// Setter method definition that notifies observers on value change
void Cell::setValue(int newValue) {
    value = newValue;
    notify();
}