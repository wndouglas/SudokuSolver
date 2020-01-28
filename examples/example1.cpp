#include <string>
#include "CommandLineUI.hpp"

using namespace std;
using namespace SSLib;

int main(int argc, char *argv[])
{
    string filePath;
    if(argc == 2)
        filePath = argv[1];
    else
        filePath = string();
    
    unique_ptr<UserInterface> UI(new CommandLineUI(filePath));
    UI->Run();
    
    return 0;
}
