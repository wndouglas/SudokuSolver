#include "SudokuFactory.hpp"

using namespace SSLib;

Sudoku SudokuFactory::CreateSudoku(BoardType board, SolverType solver)
{
    SudokuBoard *pBoard;
    SudokuSolver *pSolver;
    
    switch (board) {
        case SudokuFactory::BoardType::ClassicBoard:
            pBoard = new ClassicSudokuBoard();
            break;
        default:
            pBoard = new ClassicSudokuBoard();
            break;
    }
    
    switch (solver) {
        case SudokuFactory::SolverType::RecursiveSolver:
            pSolver = new RecursiveSudokuSolver();
            break;
        default:
            pSolver = new RecursiveSudokuSolver();
            break;
    }
    
    return Sudoku(pBoard, pSolver);
}

Sudoku SudokuFactory::CreateSudoku()
{
    return Sudoku(new ClassicSudokuBoard(), new RecursiveSudokuSolver());
}

void SudokuFactory::ChangeBoard(SSLib::Sudoku &sudoku, BoardType board)
{
    SudokuBoard *pBoard;
    
    switch (board) {
        case SudokuFactory::BoardType::ClassicBoard:
            pBoard = new ClassicSudokuBoard();
            break;
        default:
            pBoard = new ClassicSudokuBoard();
            break;
    }
    
    sudoku.SetBoard(pBoard);
}

void SudokuFactory::ChangeSolver(SSLib::Sudoku &sudoku, SolverType solver)
{
    SudokuSolver *pSolver;
    
    switch (solver) {
        case SudokuFactory::SolverType::RecursiveSolver:
            pSolver = new RecursiveSudokuSolver();
            break;
        default:
            pSolver = new RecursiveSudokuSolver();
            break;
    }
    
    sudoku.SetSolver(pSolver);
}
