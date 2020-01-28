#ifndef COMMAND_LINE_UI_HPP
#define COMMAND_LINE_UI_HPP

#include "UserInterface.hpp"
#include "Sudoku.hpp"
#include "SudokuFactory.hpp"
#include <string>

namespace SSLib
{
    class CommandLineUI : public UserInterface
    {
    public:
        void Run();
        CommandLineUI(std::string filePath, int numRows = 9, int numCols = 9) :
            mFilePath(filePath),
            mPositionInSolution(SolutionPosition::Start),
            mSudoku(SSLib::SudokuFactory::CreateSudoku()) { };

    private:
        enum SolutionPosition
        {
            Start,
            Intermediate,
            End,
        };

        void ManPopulateSudoku();
        void AutoPopulateSudoku();
        void JsonPopulateSudoku();
        void BoardInvalidMessage() const;
        void DisplayBoard() const;
        void JsonDisplayBoard() const;

        SSLib::Sudoku mSudoku;
        std::string mFilePath;
        SolutionPosition mPositionInSolution;
    };
}

#endif
