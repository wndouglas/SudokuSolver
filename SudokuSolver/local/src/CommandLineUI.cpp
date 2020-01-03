#include "CommandLineUI.hpp"
#include "SudokuBoard.hpp"
#include "JsonSudokuHandler.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void CommandLineUI::run()
{
    jsonPopulateSudoku();
    displayBoard();
    
    if(!mSolver->IsBoardValid(*mBoard) || !mSolver->SolveBoard(*mBoard))
    {
        boardInvalidMessage();
    }
    else
    {
        mPositionInSolution = solutionPosition::end;
        
        jsonDisplayBoard();
        
        cout << "Solve board? (y/n)";
        string entry;
        bool stay = true;
        while(stay)
        {
            getline(cin, entry);
            if(entry == "y")
            {
                stay = false;
            }
            
            if(entry == "n")
            {
                return;
            }
        }
        
        displayBoard();
        cout << "Time taken: " << (mSolver->getSolveTime()/1000) << "s" << endl;
        cout << "Steps taken: " << mSolver->getStepsTaken() << endl;
    }
}

void CommandLineUI::jsonPopulateSudoku() const
{
    ifstream jsonFile(mFilePath);
    vector<vector<int> > elements;
    JsonSudokuHandler::read_file(jsonFile, elements);
    
    for(int i = 0; i < elements.size(); i++)
    {
        for(int j = 0; j < elements.size(); j++)
        {
            mBoard->FillCell(i + 1, j + 1, elements[i][j]);
        }
    }
}

void CommandLineUI::manPopulateSudoku() const
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
        
        mBoard->FillCell(row, column, value);
    } while(line != "e");
}

void CommandLineUI::autoPopulateSudoku() const
{
    mBoard->FillCell(1, 1, 8);

    mBoard->FillCell(2, 3, 3);
    mBoard->FillCell(2, 4, 6);

    mBoard->FillCell(3, 2, 7);
    mBoard->FillCell(3, 5, 9);
    mBoard->FillCell(3, 7, 2);

    mBoard->FillCell(4, 2, 5);
    mBoard->FillCell(4, 6, 7);
    mBoard->FillCell(5, 5, 4);
    mBoard->FillCell(5, 6, 5);
    mBoard->FillCell(5, 7, 7);

    mBoard->FillCell(6, 4, 1);
    mBoard->FillCell(6, 8, 3);

    mBoard->FillCell(7, 3, 1);
    mBoard->FillCell(7, 8, 6);
    mBoard->FillCell(7, 9, 8);
    mBoard->FillCell(8, 3, 8);
    mBoard->FillCell(8, 4, 5);
    mBoard->FillCell(8, 8, 1);

    mBoard->FillCell(9, 2, 9);
    mBoard->FillCell(9, 7, 4);
}

void CommandLineUI::boardInvalidMessage() const
{
    cout << "The entered board was invalid." << endl;
}

void CommandLineUI::displayBoard() const
{
    string positionString;
    switch (mPositionInSolution)
    {
        case solutionPosition::start:
            positionString = "initial";
            break;
        case solutionPosition::intermediate:
            positionString = "intermediate";
            break;
        default:
            positionString = "final";
            break;
    }
    
    cout << "Here is the " + positionString + " board:" << endl;
    string lineSeparator = "+-----+-----+-----+";
    cout << lineSeparator << endl;
    for(int i = 1; i <= BOARD_HEIGHT; i++)
    {
        cout << "|";
        for(int j = 1; j <= BOARD_WIDTH; j++)
        {
            int boardEntry = mBoard->GetCellValue(i, j);
            string outputEntry = to_string(boardEntry);
            if(boardEntry == 0)
            {
                outputEntry = " ";
            }
            if(j % 3 != 0)
            {
                cout << outputEntry << " ";
            }
            else
            {
                cout << outputEntry << "|";
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

void CommandLineUI::jsonDisplayBoard() const
{
    size_t lastindex = mFilePath.find_last_of(".");
    string rawname = mFilePath.substr(0, lastindex);
    string extension = mFilePath.substr(lastindex, mFilePath.end() - mFilePath.begin());
    
    string outputFilePath = rawname + "_output" + extension;
    ofstream jsonFile(outputFilePath);
    std::vector<std::pair<std::string, std::string> > properties;
    
    vector<vector<int> > elements;
    for(int i = 0; i < BOARD_HEIGHT; i++)
    {
        vector<int> row;
        for(int j = 0; j < BOARD_WIDTH; j++)
        {
            row.push_back(mBoard->GetCellValue(i + 1, j + 1));
        }
        elements.push_back(row);
    }
    
    JsonSudokuHandler::write_file(jsonFile, properties, elements);
}
