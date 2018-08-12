//  SUDOKU_CELL.hpp
#ifndef SUDOKU_CELL_HPP
#define SUDOKU_CELL_HPP

#include <stdio.h>
#include <vector>

class SudokuCell
{
private:
    // Fields
    int currentValue;
    std::vector<int> validValues;
    bool isDetermined;
public:
    // Constructors
    SudokuCell();
    
    // Getters and setters
    int GetCurrentValue() const;
    void SetCurrentValue(int currentValue);
    std::vector<int> GetValidValues() const;
    void SetValidValues(std::vector<int> validValues);
    
};
#endif /* SUDOKU_CELL_hpp */
