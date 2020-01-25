#ifndef SUDOKU_FACTORY_HPP
#define SUDOKU_FACTORY_HPP

#include "Sudoku.hpp"
#include "SudokuBoard.hpp"
#include "ClassicSudokuBoard.hpp"
#include "SudokuSolver.hpp"
#include "RecursiveSudokuSolver.hpp"

namespace SSLib
{
    class SudokuFactory
    {
    public:
        enum BoardType
        {
            ClassicBoard,
            UnusualBoard
        };
        
        enum SolverType
        {
            RecursiveSolver
        };
        
        Sudoku static CreateSudoku(BoardType board, SolverType solver);
        Sudoku static CreateSudoku();
        
        void static ChangeBoard(SSLib::Sudoku &sudoku, BoardType board);
        void static ChangeSolver(SSLib::Sudoku &sudoku, SolverType solver);
    };
}
#endif
