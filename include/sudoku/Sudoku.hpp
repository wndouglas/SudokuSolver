#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include "SudokuSolver.hpp"
#include "SudokuBoard.hpp"

namespace SSLib
{
    /** @brief Main sudoku class.

    This class provides the main API for the sudoku solver. It contains both a sudoku and a solver,
    along with the methods for populating and solving a sudoku.
    @author Will Douglas
    @date January 2020
    */
    class Sudoku
    {
    public:
        /** Main constructor for the sudoku class. Takes ownership of the board and solver
         * passed in as arguments.
        */
        Sudoku(std::unique_ptr<SSLib::SudokuBoard>& board, std::unique_ptr<SSLib::SudokuSolver>& solver) : mBoard(std::move(board)), mSolver(std::move(solver)) { };
    
        void SetSolver(std::unique_ptr<SSLib::SudokuSolver>& solver);
        void SetBoard(std::unique_ptr<SSLib::SudokuBoard>& board);
    
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
    };
}

#endif
