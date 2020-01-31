cmake_minimum_required(VERSION 3.5)
project(SudokuSolver VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)
file(GLOB_RECURSE HEADER_FILES include/*.hpp)

# Check for Boost
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.71.0) 

# ------------------------------------- Build main library ---------------------------------------------
if(Boost_FOUND)
    add_library(
    SudokuSolver STATIC 
    ${SOURCES}
    ${HEADER_FILES}
    ${Boost_INCLUDE_DIRS}) 

    target_include_directories(SudokuSolver PRIVATE include/sudoku include/IOHandling src/common)
    include_directories(${Boost_INCLUDE_DIRS}) 
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
