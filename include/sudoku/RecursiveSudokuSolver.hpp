#ifndef RECURSIVE_SUDOKU_SOLVER_HPP
#define RECURSIVE_SUDOKU_SOLVER_HPP

#include "common/Timer.hpp"
#include <vector>
#include "SudokuSolver.hpp"

class SudokuBoard;

namespace SSLib
{
    class RecursiveSudokuSolver : public SudokuSolver
    {
    public:
        bool SolveBoard(SudokuBoard &board);
        bool IsBoardValid(const SudokuBoard &board) const;
        double getSolveTime() const;
        long getStepsTaken() const;
        
    private:
        bool CheckRow(int cellRow, int cellColumn, const SudokuBoard &board) const;
        bool CheckColumn(int cellRow, int cellColumn, const SudokuBoard &board) const;
        bool CheckSquare(int cellRow, int cellColumn, const SudokuBoard &board) const;
        bool CellIsSafe(int cellRow, int cellColumn, const SudokuBoard &board) const;
        void IncrementIndex(int &i, int &j) const;
        bool FindFirstUnassignedIndex(int &i, int &j, const SudokuBoard &board) const;
        bool RecursiveSolver(SudokuBoard &board);
        bool UpdateBoard(SudokuBoard &board) const;
        bool IsBoardComplete(const SudokuBoard &board) const;
        bool CheckBoardSize(const SudokuBoard &board) const;
        
        double mSolveTime;
        long mStepsTaken;
        Timer mTimer;
    };
}

#endif
