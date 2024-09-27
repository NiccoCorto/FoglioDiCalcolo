#include <gtest/gtest.h>
#include "../include/Function.h"
#include "../include/Cell.h"

// Test SUM Function
TEST(FunctionTest, SumFunction) {
    std::shared_ptr<Cell> cell1 = std::make_shared<Cell>(10);
    std::shared_ptr<Cell> cell2 = std::make_shared<Cell>(20);
    std::vector<std::shared_ptr<Cell>> cells = {cell1, cell2};

    Function sumFunc(Function::SUM, cells);
    sumFunc.update(nullptr); // Trigger update manually
    EXPECT_EQ(sumFunc.getValue(), 30);  // Verifica il valore della somma
}

// Test MEAN Function
TEST(FunctionTest, MeanFunction) {
    std::shared_ptr<Cell> cell1 = std::make_shared<Cell>(10);
    std::shared_ptr<Cell> cell2 = std::make_shared<Cell>(20);
    std::vector<std::shared_ptr<Cell>> cells = {cell1, cell2};

    Function meanFunc(Function::MEAN, cells);
    meanFunc.update(nullptr); // Trigger update manually
    EXPECT_EQ(meanFunc.getValue(), 15);  // Verifica il valore medio
}

// Test MIN Function
TEST(FunctionTest, MinFunction) {
    std::shared_ptr<Cell> cell1 = std::make_shared<Cell>(10);
    std::shared_ptr<Cell> cell2 = std::make_shared<Cell>(20);
    std::vector<std::shared_ptr<Cell>> cells = {cell1, cell2};

    Function minFunc(Function::MIN, cells);
    minFunc.update(nullptr); // Trigger update manually
    EXPECT_EQ(minFunc.getValue(), 10);  // Verifica il valore minimo
}

// Test MAX Function
TEST(FunctionTest, MaxFunction) {
    std::shared_ptr<Cell> cell1 = std::make_shared<Cell>(10);
    std::shared_ptr<Cell> cell2 = std::make_shared<Cell>(20);
    std::vector<std::shared_ptr<Cell>> cells = {cell1, cell2};

    Function maxFunc(Function::MAX, cells);
    maxFunc.update(nullptr); // Trigger update manually
    EXPECT_EQ(maxFunc.getValue(), 20);  // Verifica il valore massimo
}