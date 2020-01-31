#ifndef COMMAND_LINE_UI_HPP
#define COMMAND_LINE_UI_HPP

#include "UserInterface.hpp"
#include <string>

namespace SSLib
{
    class CommandLineUI : public UserInterface
    {
    public:
        void Run();
        CommandLineUI(std::string filePath, int numRows = 9, int numCols = 9);

    private:
        class CommandLineUiImpl;
        std::unique_ptr<CommandLineUiImpl> pCommandLineUiImpl;
    };
}

#endif
