#include <gtest/gtest.h>
#include "../include/Cell.h"

// Test Cell constructor
TEST(CellTest, Constructor) {
    Cell cell(5);
    EXPECT_EQ(cell.getValue(), 5);
}

// Test Cell getter and setter
TEST(CellTest, SetValue) {
    Cell cell(10);
    EXPECT_EQ(cell.getValue(), 10);

    cell.setValue(20);
    EXPECT_EQ(cell.getValue(), 20);
}