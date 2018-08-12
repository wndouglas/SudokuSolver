#include <iostream>
#include "BoardLogic.hpp"

using namespace std;

// Public methods
bool BoardLogic::UpdateBoard(SudokuBoard &board) const
{
    /*
    bool isBoardValid = true;
    for(int i = 1; i <= BOARD_HEIGHT; i++)
    {
        for(int j = 1; j <= BOARD_WIDTH; j++)
        {
            if(!board.GetIsCellDetermined(i, j))
            {
                vector<int> validValues;
                for(int value = 1; value <= 9; value++)
                {
                    board.FillCell(value, i, j, false);
                    bool isValueValid = CheckCell(i, j, board);
                    if(isValueValid)
                    {
                        validValues.push_back(value);
                    }
                }
                board.SetCellsValidEntries(i, j, validValues);
                
                if(board.GetCellsValidEntries(i,j).size() == 0)
                {
                    isBoardValid = false;
                    break;
                }
                else if(board.GetCellsValidEntries(i,j).size() == 1)
                {
                    board.FillCell(board.GetCellsValidEntries(i,j)[0], i, j, true);
                }
                else
                {
                    board.FillCell(0, i, j, false);
                }
            }
        }
        if(!isBoardValid)
            break;
    }
    return isBoardValid;
     */
    return true;
}

void BoardLogic::SolveBoard(SudokuBoard &board) const
{
    /*
    int i = 0, j = 0;
    FindFirstUnfixedIndex(i, j, board);
    RecursiveSolver(board, i, j);
     */
}

void BoardLogic::RecursiveSolver(SudokuBoard &board, int i, int j) const
{
    /*
    // NEEDS REVISION
    if(board.GetCellValue(i, j) == 0)
    {
        board.IncrementCellValue(i, j);
    }
    while(!IsBoardValid(board) && board.GetCellValue(i, j) < 9)
    {
        board.IncrementCellValue(i, j);
    }
    if(!IsBoardValid(board) && board.GetCellValue(i, j) == 9)
    {
        while(board.GetCellValue(i, j) == 9)
        {
            board.SetCellValue(i, j, 0);
            FindPreviousUnfixedIndex(i, j, board);
        }
        board.IncrementCellValue(i, j);
        RecursiveSolver(board, i, j);
    }
    else if(IsBoardValid(board) && FindNextUnfixedIndex(i, j, board))
    {
        RecursiveSolver(board, i, j);
    }
     */
}

bool BoardLogic::IsBoardValid(const SudokuBoard &board) const
{
    /*
    bool isBoardValid = true;
    for(int i = 1; i <= BOARD_HEIGHT; i++)
    {
        for(int j = 1; j <= BOARD_WIDTH; j++)
        {
            if(board.GetIsCellDetermined(i, j) && !CheckCell(i,j,board))
            {
                isBoardValid = false;
                break;
            }
        }
        if(isBoardValid == false)
            break;
    }
    return isBoardValid;
     */
    return true;
}

// Private methods
bool BoardLogic::CheckRow(int cellRow, int cellColumn, const SudokuBoard &board) const
{
    /*
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
     */
    return true;
}

bool BoardLogic::CheckColumn(int cellRow, int cellColumn, const SudokuBoard &board) const
{
    /*
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
     */
    return true;
}

bool BoardLogic::CheckSquare(int cellRow, int cellColumn, const SudokuBoard &board) const
{
    /*
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
     */
    return true;
}

bool BoardLogic::CheckCell(int cellRow, int cellColumn, const SudokuBoard &board) const
{
    /*
    bool entryValid = false;
    if(CheckSquare(cellRow, cellColumn, board) && CheckRow(cellRow, cellColumn, board)
       && CheckColumn(cellRow, cellColumn, board))
    {
        entryValid = true;
    }
    return entryValid;
     */
    return true;
}

void BoardLogic::IncrementIndex(int &i, int &j) const
{
    /*
    if(j < 9)
    {
        j++;
    }
    else
    {
        j = 1;
        i++;
    }
     */
}

void BoardLogic::DecrementIndex(int &i, int &j) const
{
    /*
    if(j > 1)
    {
        j--;
    }
    else
    {
        j = 9;
        i--;
    }
     */
}

void BoardLogic::FindFirstUnfixedIndex(int &i, int &j, const SudokuBoard &board) const
{
    /*
    i = 1;
    j = 1;
    bool isCellDetermined = board.GetIsCellDetermined(i, j);
    while(isCellDetermined)
    {
        IncrementIndex(i, j);
        isCellDetermined = board.GetIsCellDetermined(i, j);
    }
     */
}

bool BoardLogic::FindNextUnfixedIndex(int &i, int &j, const SudokuBoard &board) const
{
    /*
    bool isCellDetermined;
    do
    {
        IncrementIndex(i, j);
        isCellDetermined = board.GetIsCellDetermined(i, j);
    }
    while(isCellDetermined);
    
    if(i > 9 || j > 9)
        return false;
    
    return true;
     */
    return true;
}

void BoardLogic::FindPreviousUnfixedIndex(int &i, int &j, const SudokuBoard &board) const
{
    /*
    bool isCellDetermined;
    do
    {
        DecrementIndex(i, j);
        isCellDetermined = board.GetIsCellDetermined(i, j);
    }
    while(isCellDetermined);
     */
}

bool BoardLogic::IsBoardComplete(const SudokuBoard &board) const
{
    /*
    for(int i = 1; i <= BOARD_HEIGHT; i++)
    {
        for(int j = 1; j <= BOARD_WIDTH; j++)
        {
            if(!board.GetIsCellDetermined(i, j))
            {
                return false;
            }
        }
    }
     */
    return true;
}
