//  CLASSIC_SUDOKU_BOARD.HPP
#ifndef CLASSIC_SUDOKU_BOARD_HPP
#define CLASSIC_SUDOKU_BOARD_HPP

#include "SudokuCell.hpp"
#include "SudokuBoard.hpp"
#include "Point.hpp"

namespace SSLib
{
    class ClassicSudokuBoard : public SudokuBoard
    {
    public:
        ClassicSudokuBoard(int numRows = 9, int numCols = 9);
        void FillCell(int cellRow, int cellColumn, int value);
        int GetCellValue(int cellRow, int cellColumn) const;
        void SetCellsValidEntries(int cellRow, int  cellColumn, const std::vector<int> validEntries);
        std::vector<int> GetCellsValidEntries(int cellRow,  int cellColumn) const;
        bool IsCellAssigned(int cellRow, int cellColumn)    const;
        int getHeight() const;
        int getWidth() const;
        ~ClassicSudokuBoard() { };
        
    private:
        // Board fields
        std::vector<std::vector<SudokuCell> > mBoard;
        Point mCurrentCellCoordinates;
        const int mWidth;
        const int mHeight;
    };
}


#endif
