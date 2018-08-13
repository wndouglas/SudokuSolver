#include <iostream>
#include "BoardLogic.hpp"

using namespace std;

// Public methods
bool BoardLogic::UpdateBoard(SudokuBoard &board) const
{
    
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

bool BoardLogic::SolveBoard(SudokuBoard &board) const
{
    if(!UpdateBoard(board) || !RecursiveSolver(board))
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool BoardLogic::RecursiveSolver(SudokuBoard &board) const
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

bool BoardLogic::IsBoardValid(const SudokuBoard &board) const
{
    
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
bool BoardLogic::CheckRow(int cellRow, int cellColumn, const SudokuBoard &board) const
{
    
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

bool BoardLogic::CheckColumn(int cellRow, int cellColumn, const SudokuBoard &board) const
{
    
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

bool BoardLogic::CheckSquare(int cellRow, int cellColumn, const SudokuBoard &board) const
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

bool BoardLogic::CellIsSafe(int cellRow, int cellColumn, const SudokuBoard &board) const
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

void BoardLogic::IncrementIndex(int &i, int &j) const
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

bool BoardLogic::FindFirstUnassignedIndex(int &i, int &j, const SudokuBoard &board) const
{
    i = 1;
    j = 1;
    bool isCellDetermined = board.IsCellAssigned(i, j);
    while(isCellDetermined)
    {
        IncrementIndex(i, j);
        isCellDetermined = board.IsCellAssigned(i, j);
        
        if(i > 9)
            return false;
    }
    return true;
}

bool BoardLogic::IsBoardComplete(const SudokuBoard &board) const
{
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
