#include "IOHandling/CommandLineUI.hpp"
#include "IOHandling/JsonSudokuHandler.hpp"
#include "sudoku/SudokuFactory.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using namespace SSLib;

class CommandLineUI::CommandLineUiImpl
{
public:
    CommandLineUiImpl(string filePath);

    enum SolutionPosition
    {
        Start,
        Intermediate,
        End,
    };

    void JsonPopulateSudoku();
    void ManPopulateSudoku();
    void AutoPopulateSudoku();
    void BoardInvalidMessage() const;
    void DisplayBoard() const;
    void JsonDisplayBoard() const;
    void Run();

    SSLib::Sudoku mSudoku;
    std::string mFilePath;
    SolutionPosition mPositionInSolution;

private:

};

CommandLineUI::CommandLineUiImpl::CommandLineUiImpl(string filePath) :
    mFilePath(filePath),
    mPositionInSolution(SolutionPosition::Start),
    mSudoku(SSLib::SudokuFactory::CreateSudoku()) { }

void CommandLineUI::CommandLineUiImpl::JsonPopulateSudoku()
{
    ifstream jsonFile(mFilePath);
    vector<vector<int> > elements;
    JsonSudokuHandler::ReadFile(jsonFile, elements);
    
    for(int i = 0; i < elements.size(); i++)
    {
        for(int j = 0; j < elements.size(); j++)
        {
            mSudoku.SetCell(i + 1, j + 1, elements[i][j]);
        }
    }
}

void CommandLineUI::CommandLineUiImpl::ManPopulateSudoku()
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
        
        mSudoku.SetCell(row, column, value);
    } while(line != "e");
}

void CommandLineUI::CommandLineUiImpl::AutoPopulateSudoku()
{
    mSudoku.SetCell(1, 1, 8);

    mSudoku.SetCell(2, 3, 3);
    mSudoku.SetCell(2, 4, 6);

    mSudoku.SetCell(3, 2, 7);
    mSudoku.SetCell(3, 5, 9);
    mSudoku.SetCell(3, 7, 2);

    mSudoku.SetCell(4, 2, 5);
    mSudoku.SetCell(4, 6, 7);
    mSudoku.SetCell(5, 5, 4);
    mSudoku.SetCell(5, 6, 5);
    mSudoku.SetCell(5, 7, 7);

    mSudoku.SetCell(6, 4, 1);
    mSudoku.SetCell(6, 8, 3);

    mSudoku.SetCell(7, 3, 1);
    mSudoku.SetCell(7, 8, 6);
    mSudoku.SetCell(7, 9, 8);
    mSudoku.SetCell(8, 3, 8);
    mSudoku.SetCell(8, 4, 5);
    mSudoku.SetCell(8, 8, 1);

    mSudoku.SetCell(9, 2, 9);
    mSudoku.SetCell(9, 7, 4);
}

void CommandLineUI::CommandLineUiImpl::BoardInvalidMessage() const
{
    cout << "The entered board was invalid." << endl;
}

void CommandLineUI::CommandLineUiImpl::DisplayBoard() const
{
    const int BOARD_HEIGHT = mSudoku.GetHeight();
    const int BOARD_WIDTH = mSudoku.GetWidth();
    
    string positionString;
    switch (mPositionInSolution)
    {
        case SolutionPosition::Start:
            positionString = "initial";
            break;
        case SolutionPosition::Intermediate:
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
            int boardEntry = mSudoku.GetCell(i, j);
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


void CommandLineUI::CommandLineUiImpl::JsonDisplayBoard() const
{
    const int BOARD_HEIGHT = mSudoku.GetHeight();
    const int BOARD_WIDTH = mSudoku.GetWidth();
    
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
            row.push_back(mSudoku.GetCell(i + 1, j + 1));
        }
        elements.push_back(row);
    }
    
    JsonSudokuHandler::WriteFile(jsonFile, properties, elements);
}

void CommandLineUI::CommandLineUiImpl::Run()
{
    cout << "Choose input type: (enter number for choice)" << endl;
    cout << "(1) : manual board population" << endl;
    cout << "(2) : automatic board population" << endl;
    cout << "(3) : JSON board population" << endl;
    cout << "Default choice is JSON" << endl;
    cout << "Type choice below: " << endl;

    int n = 3;
    cin >> n;

    switch(n)
    {
        case 1:
            ManPopulateSudoku();
        break;
        case 2:
            AutoPopulateSudoku();
        break;
        case 3:
            JsonPopulateSudoku();
        break;
        default:
        break;
    }

    DisplayBoard();
    
    if(!mSudoku.ValidateBoard() || !mSudoku.SolveBoard())
    {
        BoardInvalidMessage();
    }
    else
    {
        mPositionInSolution = SolutionPosition::End;
        
        JsonDisplayBoard();
        
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
        
        DisplayBoard();
        cout << "Time taken: " << mSudoku.GetSolveTime() << "s" << endl;
        cout << "Steps taken: " << mSudoku.GetStepsTaken() << endl;
    }
}

CommandLineUI::CommandLineUI(std::string filePath, int numRows, int numCols) : 
    pCommandLineUiImpl(new CommandLineUiImpl(filePath)) { };

void CommandLineUI::Run()
{
    pCommandLineUiImpl->Run();
}
