//  SUDOKU_CELL.hpp
#ifndef SUDOKU_CELL_HPP
#define SUDOKU_CELL_HPP

#include <vector>

namespace SSLib
{
    class SudokuCell
    {
    private:
        // Fields
        int currentValue;
        std::vector<int> validValues;
    public:
        // Constructors
        SudokuCell();
        
        // Getters and setters
        int GetCurrentValue() const;
        void SetCurrentValue(int currentValue);
        std::vector<int> GetValidValues() const;
        void SetValidValues(std::vector<int> validValues);
        bool GetIsAssigned() const;
        
    };
}
#endif /* SUDOKU_CELL_hpp */
