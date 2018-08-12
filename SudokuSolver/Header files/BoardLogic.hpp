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
    bool CheckCell(int cellRow, int cellColumn, const SudokuBoard &board) const;
    void IncrementIndex(int &i, int &j) const;
    void DecrementIndex(int &i, int &j) const;
    void FindFirstUnfixedIndex(int &i, int &j, const SudokuBoard &board) const;
    bool FindNextUnfixedIndex(int &i, int &j, const SudokuBoard &board) const;
    void FindPreviousUnfixedIndex(int &i, int &j, const SudokuBoard &board) const;
    void RecursiveSolver(SudokuBoard &board, int i, int j) const;
    bool IsBoardComplete(const SudokuBoard &board) const;
    
public:
    bool UpdateBoard(SudokuBoard &board) const;
    void SolveBoard(SudokuBoard &board) const;
    bool IsBoardValid(const SudokuBoard &board) const;
};

#endif
