#ifndef COMMAND_LINE_UI_HPP
#define COMMAND_LINE_UI_HPP

#include "UserInterface.hpp"
#include "Sudoku.hpp"
#include "ClassicSudokuBoard.hpp"
#include "RecursiveSudokuSolver.hpp"
#include <string>

class CommandLineUI : public UserInterface
{
public:
    void run();
    CommandLineUI(std::string filePath, int numRows = 9, int numCols = 9) :
        mFilePath(filePath),
        mPositionInSolution(solutionPosition::start),
        mSudoku(new SSLib::ClassicSudokuBoard(numRows, numCols), new SSLib::RecursiveSudokuSolver()) { };
    
private:
    enum solutionPosition
    {
        start,
        intermediate,
        end,
    };
    
    void manPopulateSudoku();
    void autoPopulateSudoku();
    void jsonPopulateSudoku();
    void boardInvalidMessage() const;
    void displayBoard() const;
    void jsonDisplayBoard() const;
    
    SSLib::Sudoku mSudoku;
    std::string mFilePath;
    solutionPosition mPositionInSolution;
};

#endif
