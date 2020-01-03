#include "SudokuBoard.hpp"
#include "SudokuCell.hpp"

using namespace std;

SudokuBoard::SudokuBoard()
{
}

void SudokuBoard::FillCell(const int cellRow, const int cellColumn, const int cellValue)
{
    this->board[cellRow - 1][cellColumn - 1].SetCurrentValue(cellValue);
    this->currentCellCoordinates.x = cellRow - 1;
    this->currentCellCoordinates.y = cellColumn - 1;
}

int SudokuBoard::GetCellValue(int cellRow, int cellColumn) const
{
    return this->board[cellRow - 1][cellColumn - 1].GetCurrentValue();
}

void SudokuBoard::SetCellsValidEntries(int cellRow, int cellColumn, const vector<int> validEntries)
{
    this->board[cellRow - 1][cellColumn - 1].SetValidValues(validEntries);
}

std::vector<int> SudokuBoard::GetCellsValidEntries(int cellRow, int cellColumn) const
{
    return this->board[cellRow - 1][cellColumn - 1].GetValidValues();
}

bool SudokuBoard::IsCellAssigned(int cellRow, int cellColumn) const
{
    return this->board[cellRow - 1][cellColumn - 1].GetIsAssigned();
}
