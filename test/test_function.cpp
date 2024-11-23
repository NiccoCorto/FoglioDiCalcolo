#include <gtest/gtest.h>
#include "../include/Function.h"
#include "../include/Cell.h"

// Test SUM Function
TEST(FunctionTest, SumFunction) {
    std::shared_ptr<Cell> cell1 = std::make_shared<Cell>(10);
    std::shared_ptr<Cell> cell2 = std::make_shared<Cell>(20);
    std::vector<std::shared_ptr<Cell>> cells = {cell1, cell2};

    Function sumFunc(Function::SUM, cells);
    sumFunc.update(); // Trigger update manually
    EXPECT_EQ(sumFunc.getValue(), 30);  // Verifica il valore della somma
}

// Test MEAN Function
TEST(FunctionTest, MeanFunction) {
    std::shared_ptr<Cell> cell1 = std::make_shared<Cell>(10);
    std::shared_ptr<Cell> cell2 = std::make_shared<Cell>(20);
    std::vector<std::shared_ptr<Cell>> cells = {cell1, cell2};

    Function meanFunc(Function::MEAN, cells);
    meanFunc.update(); // Trigger update manually
    EXPECT_EQ(meanFunc.getValue(), 15);  // Verifica il valore medio
}

// Test MIN Function
TEST(FunctionTest, MinFunction) {
    std::shared_ptr<Cell> cell1 = std::make_shared<Cell>(10);
    std::shared_ptr<Cell> cell2 = std::make_shared<Cell>(20);
    std::vector<std::shared_ptr<Cell>> cells = {cell1, cell2};

    Function minFunc(Function::MIN, cells);
    minFunc.update(); // Trigger update manually
    EXPECT_EQ(minFunc.getValue(), 10);  // Verifica il valore minimo
}

// Test MAX Function
TEST(FunctionTest, MaxFunction) {
    std::shared_ptr<Cell> cell1 = std::make_shared<Cell>(10);
    std::shared_ptr<Cell> cell2 = std::make_shared<Cell>(20);
    std::vector<std::shared_ptr<Cell>> cells = {cell1, cell2};

    Function maxFunc(Function::MAX, cells);
    maxFunc.update(); // Trigger update manually
    EXPECT_EQ(maxFunc.getValue(), 20);  // Verifica il valore massimo
}

// Test addCell Function
TEST(FunctionTest, AddCell) {
    // Inizializza alcune celle
    std::shared_ptr<Cell> cell1 = std::make_shared<Cell>(10);
    std::shared_ptr<Cell> cell2 = std::make_shared<Cell>(20);
    std::shared_ptr<Cell> cell3 = std::make_shared<Cell>(30);

    // Crea una funzione con solo due celle
    std::vector<std::shared_ptr<Cell>> cells = {cell1, cell2};
    Function sumFunc(Function::SUM, cells);

    // Aggiorna il valore iniziale
    sumFunc.update();
    EXPECT_EQ(sumFunc.getValue(), 30); // Verifica il valore iniziale della somma

    // Aggiungi una nuova cella e verifica
    sumFunc.addCell(cell3);
    EXPECT_EQ(sumFunc.getValue(), 60); // Verifica che la somma includa la nuova cella

    // Aggiungi una cella già esistente
    sumFunc.addCell(cell1);
    EXPECT_EQ(sumFunc.getValue(), 60); // Verifica che il valore non cambi
}

// Test removeCell Function
TEST(FunctionTest, RemoveCell) {
    // Inizializza alcune celle
    std::shared_ptr<Cell> cell1 = std::make_shared<Cell>(10);
    std::shared_ptr<Cell> cell2 = std::make_shared<Cell>(20);
    std::shared_ptr<Cell> cell3 = std::make_shared<Cell>(30);

    // Crea una funzione con tre celle
    std::vector<std::shared_ptr<Cell>> cells = {cell1, cell2, cell3};
    Function sumFunc(Function::SUM, cells);

    // Aggiorna il valore iniziale
    sumFunc.update();
    EXPECT_EQ(sumFunc.getValue(), 60); // Verifica il valore iniziale della somma

    // Rimuovi una cella e verifica
    sumFunc.removeCell(cell2);
    EXPECT_EQ(sumFunc.getValue(), 40); // Verifica che la somma si aggiorni correttamente

    // Rimuovi tutte le celle una alla volta
    sumFunc.removeCell(cell1);
    EXPECT_EQ(sumFunc.getValue(), 30); // Verifica che la somma si aggiorni

    sumFunc.removeCell(cell3);
    EXPECT_EQ(sumFunc.getValue(), 0); // Verifica che la somma sia 0 quando non ci sono celle
}