//  SUDOKU_BOARD.HPP
#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP

#include "SudokuCell.hpp"
#include "Point.hpp"
#include <vector>

const int BOARD_WIDTH = 9;
const int BOARD_HEIGHT = 9;

class SudokuBoard
{
private:    
    // Board fields
    SudokuCell board[BOARD_HEIGHT][BOARD_WIDTH];
    Point currentCellCoordinates;
    
public:
    SudokuBoard();
    void FillCell(int cellRow, int cellColumn, int value);
    int GetCellValue(int cellRow, int cellColumn) const;
    
    void SetCellsValidEntries(int cellRow, int cellColumn, const std::vector<int> validEntries);
    std::vector<int> GetCellsValidEntries(int cellRow, int cellColumn) const;
    
    bool IsCellAssigned(int cellRow, int cellColumn) const;
};


#endif /* SUDOKU_BOARD_HPP */
