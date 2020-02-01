project(SudokuSolverExample)

add_executable(${PROJECT_NAME} example1.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE SudokuSolver)