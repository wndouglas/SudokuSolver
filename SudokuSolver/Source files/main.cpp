#include <iostream>
#include "SudokuCell.hpp"
#include "SudokuBoard.hpp"
#include "CommandLineUI.hpp"
#include "BoardLogic.hpp"

int main()
{
    SudokuBoard board;
    CommandLineUI userInterface;
    BoardLogic solver;
    
    userInterface.AutoPopulateSudoku(board);
    userInterface.DisplayBoard(board);
    
    return 0;
}
