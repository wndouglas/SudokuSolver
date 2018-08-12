//  SUDOKU_BOARD.HPP
#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP

#include "SudokuCell.hpp"
#include <vector>

const int BOARD_WIDTH = 9;
const int BOARD_HEIGHT = 9;

class SudokuBoard
{
private:    
    // Board fields
    SudokuCell board[BOARD_HEIGHT][BOARD_WIDTH];
    bool isComplete;
    
public:
    SudokuBoard();
    void FillCell(const int cellValue, const int cellRow, const int cellColumn, const bool isDetermined);
    void SetCellsValidEntries(const int cellRow, const int cellColumn, const std::vector<int> validEntries);
    std::vector<int> GetCellsValidEntries(const int cellRow, const int cellColumn) const;
    void SetIsCellDetermined(const int cellRow, const int cellColumn, const bool isDetermined);
    bool GetIsCellDetermined(const int cellRow, const int cellColumn) const;
    void IncrementCellValue(const int cellRow, const int cellColumn);
    int GetCellValue(const int cellRow, const int cellColumn) const;
    void SetCellValue(const int cellRow, const int cellColumn, int value);
    bool GetIsComplete() const;
    void SetIsComplete(const bool isComplete);
};


#endif /* SUDOKU_BOARD_HPP */
