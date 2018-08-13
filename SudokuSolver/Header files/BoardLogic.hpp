#ifndef BOARD_LOGIC_HPP
#define BOARD_LOGIC_HPP

#include <stdio.h>
#include "SudokuBoard.hpp"

class BoardLogic
{
private:
    bool CheckRow(int cellRow, int cellColumn, const SudokuBoard &board) const;
    bool CheckColumn(int cellRow, int cellColumn, const SudokuBoard &board) const;
    bool CheckSquare(int cellRow, int cellColumn, const SudokuBoard &board) const;
    bool CellIsSafe(int cellRow, int cellColumn, const SudokuBoard &board) const;
    void IncrementIndex(int &i, int &j) const;
    bool FindFirstUnassignedIndex(int &i, int &j, const SudokuBoard &board) const;
    bool RecursiveSolver(SudokuBoard &board) const;
        bool UpdateBoard(SudokuBoard &board) const;
    bool IsBoardComplete(const SudokuBoard &board) const;
    
public:
    bool SolveBoard(SudokuBoard &board) const;
    bool IsBoardValid(const SudokuBoard &board) const;
};

#endif
