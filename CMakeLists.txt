cmake_minimum_required(VERSION 3.5)
project(SudokuSolver VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 14)

# this is bad - TODO - remove recursive file find instead specify the files manually
file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)
file(GLOB_RECURSE HEADER_FILES include/*.hpp)

# ------------------------------------- Build main library ---------------------------------------------
add_library(SudokuSolver STATIC ${SOURCES} ${HEADER_FILES})
target_include_directories(SudokuSolver PRIVATE include/sudoku include/IOHandling src/common)

# Check for Boost
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.71.0) 

if(Boost_FOUND)
    target_include_directories(SudokuSolver PRIVATE ${Boost_INCLUDE_DIRS})
else()
    MESSAGE(FATAL_ERROR "Cannot find boost libraries")
endif()
# ------------------------------------------------------------------------------------------------------


# ---------------------------------- Example executable file -------------------------------------------
add_executable(SudokuSolverExample examples/example1.cpp)
target_link_libraries(SudokuSolverExample PRIVATE SudokuSolver)
include_directories(include/IOHandling)
# ------------------------------------------------------------------------------------------------------

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
