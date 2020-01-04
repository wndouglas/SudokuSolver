#include "ClassicSudokuBoard.hpp"
#include "SudokuCell.hpp"

using namespace std;
using namespace SSLib;

ClassicSudokuBoard::ClassicSudokuBoard(int numRows, int numCols) : mWidth(numRows), mHeight(numCols)
{
    this->mBoard.resize(mHeight);
    for (auto& row : this->mBoard)
    {
        row.resize(mWidth);
    }
}

void ClassicSudokuBoard::FillCell(const int cellRow, const int cellColumn, const int cellValue)
{
    this->mBoard[cellRow - 1][cellColumn - 1].SetCurrentValue(cellValue);
    this->mCurrentCellCoordinates.x = cellRow - 1;
    this->mCurrentCellCoordinates.y = cellColumn - 1;
}

int ClassicSudokuBoard::GetCellValue(int cellRow, int cellColumn) const
{
    return this->mBoard[cellRow - 1][cellColumn - 1].GetCurrentValue();
}

void ClassicSudokuBoard::SetCellsValidEntries(int cellRow, int cellColumn, const vector<int> validEntries)
{
    this->mBoard[cellRow - 1][cellColumn - 1].SetValidValues(validEntries);
}

std::vector<int> ClassicSudokuBoard::GetCellsValidEntries(int cellRow, int cellColumn) const
{
    return this->mBoard[cellRow - 1][cellColumn - 1].GetValidValues();
}

bool ClassicSudokuBoard::IsCellAssigned(int cellRow, int cellColumn) const
{
    return this->mBoard[cellRow - 1][cellColumn - 1].GetIsAssigned();
}

int ClassicSudokuBoard::getHeight() const
{
    return mHeight;
}

int ClassicSudokuBoard::getWidth() const
{
    return mWidth;
}
