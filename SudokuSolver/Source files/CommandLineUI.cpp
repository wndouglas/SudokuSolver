#include "CommandLineUI.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void CommandLineUI::ManPopulateSudoku(SudokuBoard &board)
{
    cout << "Please enter the occupied sudoku cells in the following format: " << endl;
    cout << "row column value" << endl;
    cout << "When you are finished, type the e key and press enter." << endl;
    
    string line;
    do
    {
        getline(cin, line);

        int row(0), column(0), value(0);
        stringstream ss(line);
        int number(0), count(0);

        while (ss >> number && count < 3)
        {
            switch (count) {
                case 0:
                    row = number;
                    break;
                case 1:
                    column = number;
                    break;
                case 2:
                    value = number;
                    break;
            }
            if (ss.peek() == ',' || ss.peek() == ' ')
                ss.ignore();
            count++;
        }
        
        board.FillCell(value, row, column);
    } while(line != "e");
}

void CommandLineUI::AutoPopulateSudoku(SudokuBoard &board)
{
    board.FillCell(2, 1, 3);
    board.FillCell(1, 1, 4);
    board.FillCell(3, 1, 6);
    
    board.FillCell(8, 2, 1);
    board.FillCell(4, 2, 5);
    board.FillCell(2, 2, 8);
    
    board.FillCell(7, 3, 1);
    board.FillCell(4, 3, 3);
    board.FillCell(6, 3, 4);
    board.FillCell(8, 3, 5);
    board.FillCell(2, 3, 6);
    board.FillCell(3, 3, 8);
    board.FillCell(1, 3, 9);
    
    board.FillCell(6, 4, 1);
    board.FillCell(9, 4, 3);
    board.FillCell(1, 4, 7);

    board.FillCell(1, 5, 2);
    board.FillCell(8, 5, 3);
    board.FillCell(7, 5, 5);
    board.FillCell(6, 5, 7);
    board.FillCell(5, 5, 8);
    
    board.FillCell(7, 6, 3);
    board.FillCell(8, 6, 7);
    board.FillCell(2, 6, 9);
    
    board.FillCell(1, 7, 1);
    board.FillCell(8, 7, 2);
    board.FillCell(7, 7, 4);
    board.FillCell(3, 7, 5);
    board.FillCell(4, 7, 6);
    board.FillCell(2, 7, 7);
    board.FillCell(9, 7, 9);

    board.FillCell(2, 8, 2);
    board.FillCell(5, 8, 5);
    board.FillCell(7, 8, 9);
    
    board.FillCell(2, 9, 4);
    board.FillCell(8, 9, 6);
    board.FillCell(4, 9, 7);
}

void CommandLineUI::BoardInvalidMessage() const
{
    cout << "The entered board was invalid." << endl;
}

void CommandLineUI::DisplayBoard(const SudokuBoard &board) const
{
    cout << "Here is the current state of the board:" << endl;
    string lineSeparator = "+-----+-----+-----+";
    cout << lineSeparator << endl;
    for(int i = 1; i <= BOARD_HEIGHT; i++)
    {
        cout << "|";
        for(int j = 1; j <= BOARD_WIDTH; j++)
        {
            int boardEntry = board.GetCellValue(i, j);
            if(j % 3 != 0)
            {
                cout << boardEntry << " ";
            }
            else
            {
                cout << boardEntry << "|";
            }
        }
        cout << endl;
        if(i % 3 == 0)
        {
            cout << lineSeparator << endl;
        }
    }
    cout << endl;
}
