#include "SudokuCell.hpp"
#include <vector>

SudokuCell::SudokuCell() : currentValue(0), isDetermined(false)
{}

bool SudokuCell::GetIsDetermined() const
{
    return this->isDetermined;
}

void SudokuCell::SetIsDetermined(bool isDetermined)
{
    this->isDetermined = isDetermined;
}

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
