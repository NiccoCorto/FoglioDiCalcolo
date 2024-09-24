#include "../include/Function.h"
#include <numeric>
#include <algorithm>

Function::Function(Type type, const std::vector<std::shared_ptr<Cell>> &cells) : type(type), cells(cells) {
    for (const auto &cell: cells) {
        cell->attach(this);
    }
}

void Function::update(Subject *subject) {
    switch (type) {
        case SUM:
            value = std::accumulate(cells.begin(), cells.end(), 0, [](int sum, const std::shared_ptr<Cell> &cell) {
                return sum + cell->getValue();  // Dereference shared_ptr to access Cell's value
            });
            break;
        case MEAN:
            value = std::accumulate(cells.begin(), cells.end(), 0, [](int sum, const std::shared_ptr<Cell> &cell) {
                return sum + cell->getValue();  // Dereference shared_ptr to access Cell's value
            }) / cells.size();
            break;
        case MIN:
            value = (*std::min_element(cells.begin(), cells.end(),
                                       [](const std::shared_ptr<Cell> &a, const std::shared_ptr<Cell> &b) {
                                           return a->getValue() <
                                                  b->getValue();  // Dereference shared_ptr to access Cell's value
                                       }))->getValue();
            break;
        case MAX:
            value = (*std::max_element(cells.begin(), cells.end(),
                                       [](const std::shared_ptr<Cell> &a, const std::shared_ptr<Cell> &b) {
                                           return a->getValue() <
                                                  b->getValue();  // Dereference shared_ptr to access Cell's value
                                       }))->getValue();
            break;
    }
}