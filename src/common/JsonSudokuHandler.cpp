#include "JsonSudokuHandler.hpp"
#include "boost/property_tree/json_parser.hpp"
#include <fstream>
#include <iostream>

using boost::property_tree::ptree;
using namespace std;

void SSLib::JsonSudokuHandler::ReadFile(std::ifstream& jsonFile, std::vector<std::vector<int> >& elements)
{
    elements.clear();
    
    using boost::property_tree::ptree;
    boost::property_tree::ptree pt;
    
    string invalidInputMessage = "invalid input";
    try
    {
        read_json(jsonFile, pt);
    }
    catch(exception)
    {
        throw invalid_argument(invalidInputMessage);
    }
    
    ptree::const_iterator it = pt.begin();
    string element = it->first;
    
    if(element != "size")
    {
        throw invalid_argument(invalidInputMessage);
    }
    int size = std::stoi(it->second.get_value<std::string>());
    
    it++;
    element = it->first;
    if(element != "board")
    {
        throw invalid_argument(invalidInputMessage);
    }
    
    boost::property_tree::ptree row_pt = it->second;
    ptree::const_iterator row_end = row_pt.end();
    
    for (ptree::const_iterator row_it = row_pt.begin(); row_it != row_end; ++row_it)
    {
        boost::property_tree::ptree col_pt = row_it->second;
        ptree::const_iterator col_end = col_pt.end();
        std::vector<int> colVec;
        for (ptree::const_iterator col_it = col_pt.begin(); col_it != col_end; ++col_it)
        {
            element = col_it->second.get_value<std::string>();
            
            int iElement;
            try
            {
                iElement = std::stoi(element);
            }
            catch (exception)
            {
                throw invalid_argument(invalidInputMessage);
            }
            colVec.push_back(iElement);
        }
        if(colVec.size() != size)
        {
            throw invalid_argument(invalidInputMessage);
        }
        elements.push_back(colVec);
    }
    
    if(elements.size() != size)
    {
        throw invalid_argument(invalidInputMessage);
    }
}

void SSLib::JsonSudokuHandler::WriteFile(std::ofstream& jsonFile, const std::vector<std::pair<std::string, std::string> >& properties, const std::vector<std::vector<int> >& elements)
{
    
}

