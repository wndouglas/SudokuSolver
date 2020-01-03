#ifndef COMMAND_LINE_UI_HPP
#define COMMAND_LINE_UI_HPP

#include "UserInterface.hpp"
#include "SudokuBoard.hpp"
#include "BoardLogic.hpp"
#include <string>

class CommandLineUI : public UserInterface
{
public:
    void run();
    CommandLineUI(std::string filePath) :
        mFilePath(filePath),
        mPositionInSolution(solutionPosition::start),
        mBoard(new SudokuBoard()),
        mSolver(new BoardLogic()) { };
    
private:
    enum solutionPosition
    {
        start,
        intermediate,
        end,
    };
    
    void manPopulateSudoku() const;
    void autoPopulateSudoku() const;
    void jsonPopulateSudoku() const;
    void boardInvalidMessage() const;
    void displayBoard() const;
    void jsonDisplayBoard() const;
    
    std::unique_ptr<SudokuBoard> mBoard;
    std::unique_ptr<BoardLogic> mSolver;
    std::string mFilePath;
    solutionPosition mPositionInSolution;
};

#endif
