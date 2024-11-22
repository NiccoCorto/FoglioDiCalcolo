#include "../include/Function.h"
#include <numeric>
#include <algorithm>

Function::Function(Type type, const std::vector<std::shared_ptr<Cell>> &cells) : type(type), cells(cells) {
    for (const auto &cell: cells) {
        cell->attach(this);
    }
}

void Function::update() {
    switch (type) {
        case SUM:
            value = std::accumulate(cells.begin(), cells.end(), 0, [](int sum, const std::shared_ptr<Cell> &cell) {
                return sum + cell->getValue();
            });
            break;
        case MEAN:
            value = std::accumulate(cells.begin(), cells.end(), 0, [](int sum, const std::shared_ptr<Cell> &cell) {
                return sum + cell->getValue();
            }) / cells.size();
            break;
        case MIN:
            value = (*std::min_element(cells.begin(), cells.end(),
                                       [](const std::shared_ptr<Cell> &a, const std::shared_ptr<Cell> &b) {
                                           return a->getValue() <
                                                  b->getValue();
                                       }))->getValue();
            break;
        case MAX:
            value = (*std::max_element(cells.begin(), cells.end(),
                                       [](const std::shared_ptr<Cell> &a, const std::shared_ptr<Cell> &b) {
                                           return a->getValue() <
                                                  b->getValue();
                                       }))->getValue();
            break;
    }
}

void Function::addCell(const std::shared_ptr<Cell> &cell) {

    if (std::find(cells.begin(), cells.end(), cell) != cells.end()) {
        //if i can't add cells
        return;
    }

    // add new cell
    cells.push_back(cell);
    cell->attach(this);
    update();
}

void Function::removeCell(const std::shared_ptr<Cell> &cell) {
    auto it = std::find(cells.begin(), cells.end(), cell);
    if (it != cells.end()) {
        if (cell) {
            cell->detach(this);  // Scollega la funzione come osservatore
        }
        cells.erase(it);

        //if there are more cells, update
        if (!cells.empty()) {
            update();
        } else {
            value = 0;
        }
    }
}