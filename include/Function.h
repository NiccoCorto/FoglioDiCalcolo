
#ifndef PROJECTS_FUNCTION_H
#define PROJECTS_FUNCTION_H
#pragma once

#include "Observer.h"
#include "Cell.h"
#include <vector>
#include <memory>

class Function : public Observer {
public:
    enum Type {
        SUM, MEAN, MIN, MAX
    };

    Function(Type type, const std::vector<std::shared_ptr<Cell>> &cells);

    int getValue() const { return value; }

    void update(Subject *subject) override;

private:
    Type type;
    int value;
    std::vector<std::shared_ptr<Cell>> cells;
};

#endif //PROJECTS_FUNCTION_H
