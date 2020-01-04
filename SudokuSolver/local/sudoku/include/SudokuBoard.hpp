#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP

#include <vector>

namespace SSLib
{
    class SudokuBoard
    {
    public:
        virtual void FillCell(int cellRow, int cellColumn, int value) = 0;
        virtual int GetCellValue(int cellRow, int cellColumn) const = 0;
        virtual bool IsCellAssigned(int cellRow, int cellColumn) const = 0;
        virtual void SetCellsValidEntries(int cellRow,int cellColumn, const std::vector<int>validEntries) = 0;
        virtual std::vector<int> GetCellsValidEntries(int cellRow, int cellColumn) const = 0;
        virtual int getHeight() const = 0;
        virtual int getWidth() const = 0;
        virtual ~SudokuBoard() {};
    };
}
#endif
