#ifndef COMMAND_LINE_UI_HPP
#define COMMAND_LINE_UI_HPP

#include <stdio.h>
#include "SudokuBoard.hpp"

class CommandLineUI
{
public:
    void ManPopulateSudoku(SudokuBoard &board);
    void AutoPopulateSudoku(SudokuBoard &board);
    void BoardInvalidMessage() const;
    void DisplayBoard(const SudokuBoard &board) const;
};

#endif
