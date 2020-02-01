#include "sudoku/SudokuFactory.hpp"

using namespace SSLib;

Sudoku SudokuFactory::CreateSudoku(BoardType board, SolverType solver)
{
    std::unique_ptr<SudokuBoard> pBoard;
    std::unique_ptr<SudokuSolver> pSolver;
    
    switch (board) {
        case SudokuFactory::BoardType::ClassicBoard:
            pBoard.reset(new ClassicSudokuBoard());
            break;
        default:
            pBoard.reset(new ClassicSudokuBoard());
            break;
    }
    
    switch (solver) {
        case SudokuFactory::SolverType::RecursiveSolver:
            pSolver.reset(new RecursiveSudokuSolver());
            break;
        default:
            pSolver.reset(new RecursiveSudokuSolver());
            break;
    }
    
    return Sudoku(pBoard, pSolver);
}

Sudoku SudokuFactory::CreateSudoku()
{
    std::unique_ptr<SudokuBoard> pBoard(new ClassicSudokuBoard());
    std::unique_ptr<SudokuSolver> pSolver(new RecursiveSudokuSolver());
    return Sudoku(pBoard, pSolver);
}

void SudokuFactory::ChangeBoard(SSLib::Sudoku &sudoku, BoardType board)
{
    std::unique_ptr<SudokuBoard> pBoard;
    
    switch (board) {
        case SudokuFactory::BoardType::ClassicBoard:
            pBoard.reset(new ClassicSudokuBoard());
            break;
        default:
            pBoard.reset(new ClassicSudokuBoard());
            break;
    }
    
    sudoku.SetBoard(pBoard);
}

void SudokuFactory::ChangeSolver(SSLib::Sudoku &sudoku, SolverType solver)
{
    std::unique_ptr<SudokuSolver> pSolver;
    
    switch (solver) {
        case SudokuFactory::SolverType::RecursiveSolver:
            pSolver.reset(new RecursiveSudokuSolver());
            break;
        default:
            pSolver.reset(new RecursiveSudokuSolver());
            break;
    }
    
    sudoku.SetSolver(pSolver);
}
