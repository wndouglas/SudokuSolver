#include <iostream>
#include "sudoku/RecursiveSudokuSolver.hpp"
#include "sudoku/SudokuBoard.hpp"

using namespace std;
using namespace SSLib;

// Public methods
double RecursiveSudokuSolver::getSolveTime() const
{
    return mSolveTime;
}

long RecursiveSudokuSolver::getStepsTaken() const
{
    return mStepsTaken;
}

bool RecursiveSudokuSolver::UpdateBoard(SudokuBoard &board) const
{
    const int BOARD_HEIGHT = board.getHeight();
    const int BOARD_WIDTH = board.getWidth();
    
    bool isBoardValid = true;
    for(int i = 1; i <= BOARD_HEIGHT; i++)
    {
        for(int j = 1; j <= BOARD_WIDTH; j++)
        {
            if(!board.IsCellAssigned(i, j))
            {
                vector<int> validValues;
                for(int value = 1; value <= 9; value++)
                {
                    board.FillCell(i, j, value);
                    bool isValueValid = CellIsSafe(i, j, board);
                    
                    if(isValueValid)
                        validValues.push_back(value);
                }
                board.SetCellsValidEntries(i, j, validValues);
                
                if(board.GetCellsValidEntries(i,j).size() == 0)
                {
                    isBoardValid = false;
                    break;
                }
                else if(board.GetCellsValidEntries(i,j).size() == 1)
                {
                    board.FillCell(i, j, board.GetCellsValidEntries(i,j)[0]);
                }
                else
                {
                    board.FillCell(i, j, 0);
                }
            }
        }
        if(!isBoardValid)
            break;
    }
    return isBoardValid;
    
    return true;
}

bool RecursiveSudokuSolver::CheckBoardSize(const SudokuBoard &board) const
{
    int numRows = board.getHeight();
    int numCols = board.getWidth();
    
    if(numRows != numCols || numRows % 3 != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool RecursiveSudokuSolver::SolveBoard(SudokuBoard &board)
{
    if(!CheckBoardSize(board))
    {
        return false;
    }
    
    mSolveTime = 0.0;
    mStepsTaken = 0;
    
    mTimer.start();
    bool isSolved = true;
    if(!UpdateBoard(board) || !RecursiveSolver(board))
    {
        isSolved = false;
    }
    else
    {
        mTimer.finish();
    }
    mSolveTime = mTimer.getInterval();
    return isSolved;
}

bool RecursiveSudokuSolver::RecursiveSolver(SudokuBoard &board)
{
    int cellRow, cellColumn;
        
    // If there is no unassigned location, we are done
    if (!FindFirstUnassignedIndex(cellRow, cellColumn, board))
        return true; // Board is solved
        
    // consider all possible digits in the given cell
    for(int i = 0; i < board.GetCellsValidEntries(cellRow, cellColumn).size(); i ++)
    {
        int num = board.GetCellsValidEntries(cellRow, cellColumn)[i];
        
        board.FillCell(cellRow, cellColumn, num);
        mStepsTaken++;
        
        // if looks promising
        if (CellIsSafe(cellRow, cellColumn, board))
        {
            // return, if success, yay!
            if (RecursiveSolver(board))
                return true;
                
            // failure, unmake & try again
            board.FillCell(cellRow, cellColumn, 0);
        }
        else
            board.FillCell(cellRow, cellColumn, 0);
    }
        return false; // this triggers backtracking
}

bool RecursiveSudokuSolver::IsBoardValid(const SudokuBoard &board) const
{
    const int BOARD_HEIGHT = board.getHeight();
    const int BOARD_WIDTH = board.getWidth();
    
    bool isBoardValid = true;
    for(int i = 1; i <= BOARD_HEIGHT; i++)
    {
        for(int j = 1; j <= BOARD_WIDTH; j++)
        {
            if(board.IsCellAssigned(i, j) && !CellIsSafe(i, j, board))
            {
                isBoardValid = false;
                break;
            }
        }
        if(isBoardValid == false)
            break;
    }
    return isBoardValid;
    
}

// Private methods
bool RecursiveSudokuSolver::CheckRow(int cellRow, int cellColumn, const SudokuBoard &board) const
{
    const int BOARD_WIDTH = board.getWidth();
    
    bool entryValid = true;
    
    int cellValue = board.GetCellValue(cellRow, cellColumn);
    int comparisonCellValue = 0;
    for(int j = 1; j <= BOARD_WIDTH; j++)
    {
        if(j != cellColumn)
        {
            comparisonCellValue = board.GetCellValue(cellRow, j);
            if(comparisonCellValue == cellValue)
            {
                entryValid = false;
                break;
            }
        }
    }
    return entryValid;
     
    return true;
}

bool RecursiveSudokuSolver::CheckColumn(int cellRow, int cellColumn, const SudokuBoard &board) const
{
    const int BOARD_HEIGHT = board.getHeight();
    
    bool entryValid = true;
    int cellValue = board.GetCellValue(cellRow, cellColumn);
    int comparisonCellValue = 0;
    for(int i = 1; i <= BOARD_HEIGHT; i++)
    {
        if(i != cellRow)
        {
            comparisonCellValue = board.GetCellValue(i, cellColumn);
            if(comparisonCellValue == cellValue)
            {
                entryValid = false;
                break;
            }
        }
    }
    return entryValid;
    
    return true;
}

bool RecursiveSudokuSolver::CheckSquare(int cellRow, int cellColumn, const SudokuBoard &board) const
{
    
    bool entryValid = true;
    int cellValue = board.GetCellValue(cellRow, cellColumn);
    int comparisonCellValue = 0;
    
    int rowStartIndex = 0, columnStartIndex = 0;
    
    rowStartIndex = ((cellRow - 1)/3) * 3 + 1;
    columnStartIndex = ((cellColumn - 1)/3) * 3 + 1;
    
    for(int i = rowStartIndex; i < rowStartIndex + 3; i++)
    {
        for(int j = columnStartIndex; j < columnStartIndex + 3; j++)
        {
            if(i != cellRow || j != cellColumn)
            {
                comparisonCellValue = board.GetCellValue(i, j);
                if(comparisonCellValue == cellValue)
                {
                    entryValid = false;
                    break;
                }
            }
        }
        if(entryValid == false)
            break;
    }
    return entryValid;
    
    return true;
}

bool RecursiveSudokuSolver::CellIsSafe(int cellRow, int cellColumn, const SudokuBoard &board) const
{
    
    bool entryValid = false;
    if(CheckSquare(cellRow, cellColumn, board)
       && CheckRow(cellRow, cellColumn, board)
       && CheckColumn(cellRow, cellColumn, board))
    {
        entryValid = true;
    }
    return entryValid;
}

void RecursiveSudokuSolver::IncrementIndex(int &i, int &j) const
{
    
    if(j < 9)
    {
        j++;
    }
    else
    {
        j = 1;
        i++;
    }
    
}

bool RecursiveSudokuSolver::FindFirstUnassignedIndex(int &i, int &j, const SudokuBoard &board) const
{
    i = 1;
    j = 1;
    bool isCellDetermined = board.IsCellAssigned(i, j);
    while(isCellDetermined)
    {
        IncrementIndex(i, j);
        
        if(i > 9)
             return false;
        
        isCellDetermined = board.IsCellAssigned(i, j);
    }
    return true;
}

bool RecursiveSudokuSolver::IsBoardComplete(const SudokuBoard &board) const
{
    const int BOARD_HEIGHT = board.getHeight();
    const int BOARD_WIDTH = board.getWidth();
    
    for(int i = 1; i <= BOARD_HEIGHT; i++)
    {
        for(int j = 1; j <= BOARD_WIDTH; j++)
        {
            if(!board.IsCellAssigned(i, j))
            {
                return false;
            }
        }
    }
    
    return true;
}
