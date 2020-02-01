cmake_minimum_required(VERSION 3.5)
project(SudokuSolver VERSION 0.1.0)

set_property( GLOBAL PROPERTY USE_FOLDERS ON)
set (CMAKE_CXX_STANDARD 14)

# This is bad
file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)
file(GLOB_RECURSE HEADER_FILES include/*.hpp)

# Should do manual addition
#set(SOURCES src/mainapp.cpp src/Student.cpp)

# ------------------------------------- Build main library ---------------------------------------------
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC include/ PRIVATE src/)

# Check for Boost
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.71.0) 

if(Boost_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
else()
    MESSAGE(FATAL_ERROR "Cannot find boost libraries")
endif()
# ------------------------------------------------------------------------------------------------------

add_subdirectory(examples)
add_subdirectory(docs)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
