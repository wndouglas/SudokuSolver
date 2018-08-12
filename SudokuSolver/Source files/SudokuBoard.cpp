#include "SudokuBoard.hpp"
#include "SudokuCell.hpp"

using namespace std;

SudokuBoard::SudokuBoard() : isComplete(false)
{
}

void SudokuBoard::FillCell(const int cellRow, const int cellColumn, const int cellValue)
{
    this->board[cellRow - 1][cellColumn - 1].SetCurrentValue(cellValue);
}

int SudokuBoard::GetCellValue(int cellRow, int cellColumn) const
{
    return this->board[cellRow - 1][cellColumn - 1].GetCurrentValue();
}

void SudokuBoard::SetCellsValidEntries(const vector<int> validEntries)
{
    int cellRow = this->currentCellCoordinates.x;
    int cellColumn = this->currentCellCoordinates.y;
    
    this->board[cellRow][cellColumn].SetValidValues(validEntries);
}

std::vector<int> SudokuBoard::GetCellsValidEntries() const
{
    int cellRow = this->currentCellCoordinates.x;
    int cellColumn = this->currentCellCoordinates.y;
    
    return this->board[cellRow][cellColumn].GetValidValues();
}

bool SudokuBoard::IsCellDetermined() const
{
    int cellRow = this->currentCellCoordinates.x;
    int cellColumn = this->currentCellCoordinates.y;
    
    bool isDetermined = false;
    if(this->board[cellRow][cellColumn].GetValidValues().size() == 0)
        isDetermined = true;
    
    return isDetermined;
}

void SudokuBoard::SetNextValidCellValue()
{
    int cellRow = this->currentCellCoordinates.x;
    int cellColumn = this->currentCellCoordinates.y;
    
    int currentValue = this->board[cellRow][cellColumn].GetCurrentValue();
    this->board[cellRow][cellColumn].SetCurrentValue(++currentValue);
}

bool SudokuBoard::GetIsComplete() const
{
    return this->isComplete;
}

void SudokuBoard::SetIsComplete(const bool isComplete)
{
    this->isComplete = isComplete;
}
