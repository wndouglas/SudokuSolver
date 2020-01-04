#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include "SudokuSolver.hpp"
#include "SudokuBoard.hpp"

namespace SSLib
{
    // this class forms our API for the sudoku solver, all public usage of the sudoku solving library comes through this class.
    class Sudoku
    {
    public:
        Sudoku(SSLib::SudokuBoard* board, SSLib::SudokuSolver* solver) : mBoard(board), mSolver(solver) { };
    
        void SetSolver(SSLib::SudokuSolver* solver);
        void SetBoard(SSLib::SudokuBoard* board);
    
        bool ValidateBoard() const;
    
        void SetCell(const int row, const int col, const int value);
        int GetCell(const int row, const int col) const;
    
        double GetSolveTime();
        long GetStepsTaken();
    
        bool SolveBoard();
    
        int GetHeight() const;
        int GetWidth() const;
    
        // solve board: returns a results page containing: whether the board was solvable, the board, the deltas, the time taken,   the number of steps taken, + any other useful info.
    private:
        // these are both abstract classes which can be changed at runtime, injected as dependencies
        std::unique_ptr<SSLib::SudokuBoard> mBoard;
        std::unique_ptr<SSLib::SudokuSolver> mSolver;
        Sudoku() { } ;
    };
}

#endif
