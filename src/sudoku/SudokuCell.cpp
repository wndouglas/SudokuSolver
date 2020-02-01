#include "sudoku/SudokuCell.hpp"
#include <vector>

using namespace SSLib;

SudokuCell::SudokuCell() : currentValue(0)
{}

int SudokuCell::GetCurrentValue() const
{
    return this->currentValue;
}

void SudokuCell::SetCurrentValue(int currentValue)
{
    this->currentValue = currentValue;
}

std::vector<int> SudokuCell::GetValidValues() const
{
    return this->validValues;
}

void SudokuCell::SetValidValues(std::vector<int> validValues)
{
    for(auto i:validValues)
    {
        this->validValues.push_back(i);
    }
}

bool SudokuCell::GetIsAssigned() const
{
    bool isAssigned = false;
    
    if(currentValue != 0)
        isAssigned = true;
    
    return isAssigned;
}
