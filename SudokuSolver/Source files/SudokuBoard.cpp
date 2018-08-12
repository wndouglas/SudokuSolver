#include "SudokuBoard.hpp"
#include "SudokuCell.hpp"

using namespace std;

SudokuBoard::SudokuBoard() : isComplete(false)
{
}

void SudokuBoard::FillCell(const int cellValue, const int cellRow, const int cellColumn, const bool isDetermined)
{
    this->board[cellRow - 1][cellColumn - 1].SetCurrentValue(cellValue);
    this->board[cellRow - 1][cellColumn - 1].SetIsDetermined(isDetermined);
}

void SudokuBoard::SetCellsValidEntries(const int cellRow, const int cellColumn, const vector<int> validEntries)
{
    this->board[cellRow - 1][cellColumn - 1].SetValidValues(validEntries);
}

std::vector<int> SudokuBoard::GetCellsValidEntries(const int cellRow, const int cellColumn) const
{
    return this->board[cellRow - 1][cellColumn - 1].GetValidValues();
}

void SudokuBoard::SetIsCellDetermined(const int cellRow, const int cellColumn, const bool isDetermined)
{
    this->board[cellRow - 1][cellColumn - 1].SetIsDetermined(isDetermined);
}

bool SudokuBoard::GetIsCellDetermined(const int cellRow, const int cellColumn) const
{
    return this->board[cellRow - 1][cellColumn - 1].GetIsDetermined();
}

void SudokuBoard::IncrementCellValue(const int cellRow, const int cellColumn)
{
    int currentValue = this->board[cellRow - 1][cellColumn - 1].GetCurrentValue();
    this->board[cellRow - 1][cellColumn - 1].SetCurrentValue(++currentValue);
}

int SudokuBoard::GetCellValue(const int cellRow, const int cellColumn) const
{
    return this->board[cellRow - 1][cellColumn - 1].GetCurrentValue();
}

void SudokuBoard::SetCellValue(const int cellRow, const int cellColumn, int value)
{
    this->board[cellRow - 1][cellColumn - 1].SetCurrentValue(value);
}

bool SudokuBoard::GetIsComplete() const
{
    return this->isComplete;
}

void SudokuBoard::SetIsComplete(const bool isComplete)
{
    this->isComplete = isComplete;
}

