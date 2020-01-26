#include "Sudoku.hpp"

using namespace SSLib;

void Sudoku::SetSolver(SudokuSolver* solver)
{
    mSolver.reset(solver);
    return;
}

void Sudoku::SetBoard(SudokuBoard* board)
{
    mBoard.reset(board);
    return;
}

bool Sudoku::ValidateBoard() const
{
    // To implement: Check if solver and board are compatible with each other
    return mSolver->IsBoardValid(*mBoard);
}

void Sudoku::SetCell(const int row, const int col, const int value)
{
    mBoard->FillCell(row, col, value);
}

bool Sudoku::SolveBoard()
{
    return mSolver->SolveBoard(*mBoard);
    //return *mBoard;
}

// These need to be deleted eventually
double Sudoku::GetSolveTime()
{
    return mSolver->getSolveTime();
}

long Sudoku::GetStepsTaken()
{
    return mSolver->getStepsTaken();
}

int Sudoku::GetHeight() const
{
    return mBoard->getHeight();
}

int Sudoku::GetWidth() const
{
    return mBoard->getWidth();
}

int Sudoku::GetCell(const int row, const int col) const
{
    return mBoard->GetCellValue(row, col);
}
