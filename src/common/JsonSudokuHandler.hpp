#ifndef JSON_HANDLER_hpp
#define JSON_HANDLER_hpp

#include "boost/property_tree/ptree.hpp"

namespace SSLib
{
    class JsonSudokuHandler
    {   
    public:
        static void ReadFile(std::ifstream& jsonFile, std::vector<std::vector<int> >& elements);
        static void WriteFile(std::ofstream& jsonFile, const std::vector<std::pair<std::string, std::string> >& properties, const std::vector<std::vector<int> >& elements);
    };
}

#endif
