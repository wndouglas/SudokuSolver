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
    bool isComplete;
    Point currentCellCoordinates;
    
public:
    SudokuBoard();
    void FillCell(const int cellRow, const int cellColumn, int value);
    int GetCellValue(int cellRow, int cellColumn) const;
    void SetCellsValidEntries(const std::vector<int> validEntries);
    std::vector<int> GetCellsValidEntries() const;
    bool IsCellDetermined() const;
    void SetNextValidCellValue();
    bool GetIsComplete() const;
    void SetIsComplete(const bool isComplete);
};


#endif /* SUDOKU_BOARD_HPP */
