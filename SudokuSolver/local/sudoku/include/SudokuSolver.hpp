#ifndef SUDOKU_SOLVER_HPP
#define SUDOKU_SOLVER_HPP

#include "SudokuBoard.hpp"

namespace SSLib
{
    class SudokuSolver
    {
    public:
        virtual bool SolveBoard(SSLib::SudokuBoard &board) = 0;
        virtual bool IsBoardValid(const SSLib::SudokuBoard &board) const = 0;
        virtual double getSolveTime() const = 0;
        virtual long getStepsTaken() const = 0;
        
        virtual ~SudokuSolver() {};
    };
}

#endif
