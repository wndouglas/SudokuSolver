# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/willdouglas/Documents/Developer/Projects/Git/SudokuSolver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/willdouglas/Documents/Developer/Projects/Git/SudokuSolver

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.16.3/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.16.3/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target package_source
package_source:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool for source..."
	/usr/local/Cellar/cmake/3.16.3/bin/cpack --config ./CPackSourceConfig.cmake /Users/willdouglas/Documents/Developer/Projects/Git/SudokuSolver/CPackSourceConfig.cmake
.PHONY : package_source

# Special rule for the target package_source
package_source/fast: package_source

.PHONY : package_source/fast

# Special rule for the target package
package: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool..."
	/usr/local/Cellar/cmake/3.16.3/bin/cpack --config ./CPackConfig.cmake
.PHONY : package

# Special rule for the target package
package/fast: package

.PHONY : package/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/willdouglas/Documents/Developer/Projects/Git/SudokuSolver/CMakeFiles /Users/willdouglas/Documents/Developer/Projects/Git/SudokuSolver/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/willdouglas/Documents/Developer/Projects/Git/SudokuSolver/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named SudokuSolver

# Build rule for target.
SudokuSolver: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 SudokuSolver
.PHONY : SudokuSolver

# fast build rule for target.
SudokuSolver/fast:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/build
.PHONY : SudokuSolver/fast

#=============================================================================
# Target rules for targets named SudokuSolverExample

# Build rule for target.
SudokuSolverExample: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 SudokuSolverExample
.PHONY : SudokuSolverExample

# fast build rule for target.
SudokuSolverExample/fast:
	$(MAKE) -f CMakeFiles/SudokuSolverExample.dir/build.make CMakeFiles/SudokuSolverExample.dir/build
.PHONY : SudokuSolverExample/fast

examples/example1.o: examples/example1.cpp.o

.PHONY : examples/example1.o

# target to build an object file
examples/example1.cpp.o:
	$(MAKE) -f CMakeFiles/SudokuSolverExample.dir/build.make CMakeFiles/SudokuSolverExample.dir/examples/example1.cpp.o
.PHONY : examples/example1.cpp.o

examples/example1.i: examples/example1.cpp.i

.PHONY : examples/example1.i

# target to preprocess a source file
examples/example1.cpp.i:
	$(MAKE) -f CMakeFiles/SudokuSolverExample.dir/build.make CMakeFiles/SudokuSolverExample.dir/examples/example1.cpp.i
.PHONY : examples/example1.cpp.i

examples/example1.s: examples/example1.cpp.s

.PHONY : examples/example1.s

# target to generate assembly for a file
examples/example1.cpp.s:
	$(MAKE) -f CMakeFiles/SudokuSolverExample.dir/build.make CMakeFiles/SudokuSolverExample.dir/examples/example1.cpp.s
.PHONY : examples/example1.cpp.s

src/IOHandling/CommandLineUI.o: src/IOHandling/CommandLineUI.cpp.o

.PHONY : src/IOHandling/CommandLineUI.o

# target to build an object file
src/IOHandling/CommandLineUI.cpp.o:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/IOHandling/CommandLineUI.cpp.o
.PHONY : src/IOHandling/CommandLineUI.cpp.o

src/IOHandling/CommandLineUI.i: src/IOHandling/CommandLineUI.cpp.i

.PHONY : src/IOHandling/CommandLineUI.i

# target to preprocess a source file
src/IOHandling/CommandLineUI.cpp.i:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/IOHandling/CommandLineUI.cpp.i
.PHONY : src/IOHandling/CommandLineUI.cpp.i

src/IOHandling/CommandLineUI.s: src/IOHandling/CommandLineUI.cpp.s

.PHONY : src/IOHandling/CommandLineUI.s

# target to generate assembly for a file
src/IOHandling/CommandLineUI.cpp.s:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/IOHandling/CommandLineUI.cpp.s
.PHONY : src/IOHandling/CommandLineUI.cpp.s

src/common/JsonSudokuHandler.o: src/common/JsonSudokuHandler.cpp.o

.PHONY : src/common/JsonSudokuHandler.o

# target to build an object file
src/common/JsonSudokuHandler.cpp.o:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/common/JsonSudokuHandler.cpp.o
.PHONY : src/common/JsonSudokuHandler.cpp.o

src/common/JsonSudokuHandler.i: src/common/JsonSudokuHandler.cpp.i

.PHONY : src/common/JsonSudokuHandler.i

# target to preprocess a source file
src/common/JsonSudokuHandler.cpp.i:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/common/JsonSudokuHandler.cpp.i
.PHONY : src/common/JsonSudokuHandler.cpp.i

src/common/JsonSudokuHandler.s: src/common/JsonSudokuHandler.cpp.s

.PHONY : src/common/JsonSudokuHandler.s

# target to generate assembly for a file
src/common/JsonSudokuHandler.cpp.s:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/common/JsonSudokuHandler.cpp.s
.PHONY : src/common/JsonSudokuHandler.cpp.s

src/common/Timer.o: src/common/Timer.cpp.o

.PHONY : src/common/Timer.o

# target to build an object file
src/common/Timer.cpp.o:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/common/Timer.cpp.o
.PHONY : src/common/Timer.cpp.o

src/common/Timer.i: src/common/Timer.cpp.i

.PHONY : src/common/Timer.i

# target to preprocess a source file
src/common/Timer.cpp.i:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/common/Timer.cpp.i
.PHONY : src/common/Timer.cpp.i

src/common/Timer.s: src/common/Timer.cpp.s

.PHONY : src/common/Timer.s

# target to generate assembly for a file
src/common/Timer.cpp.s:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/common/Timer.cpp.s
.PHONY : src/common/Timer.cpp.s

src/sudoku/ClassicSudokuBoard.o: src/sudoku/ClassicSudokuBoard.cpp.o

.PHONY : src/sudoku/ClassicSudokuBoard.o

# target to build an object file
src/sudoku/ClassicSudokuBoard.cpp.o:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/ClassicSudokuBoard.cpp.o
.PHONY : src/sudoku/ClassicSudokuBoard.cpp.o

src/sudoku/ClassicSudokuBoard.i: src/sudoku/ClassicSudokuBoard.cpp.i

.PHONY : src/sudoku/ClassicSudokuBoard.i

# target to preprocess a source file
src/sudoku/ClassicSudokuBoard.cpp.i:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/ClassicSudokuBoard.cpp.i
.PHONY : src/sudoku/ClassicSudokuBoard.cpp.i

src/sudoku/ClassicSudokuBoard.s: src/sudoku/ClassicSudokuBoard.cpp.s

.PHONY : src/sudoku/ClassicSudokuBoard.s

# target to generate assembly for a file
src/sudoku/ClassicSudokuBoard.cpp.s:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/ClassicSudokuBoard.cpp.s
.PHONY : src/sudoku/ClassicSudokuBoard.cpp.s

src/sudoku/RecursiveSudokuSolver.o: src/sudoku/RecursiveSudokuSolver.cpp.o

.PHONY : src/sudoku/RecursiveSudokuSolver.o

# target to build an object file
src/sudoku/RecursiveSudokuSolver.cpp.o:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/RecursiveSudokuSolver.cpp.o
.PHONY : src/sudoku/RecursiveSudokuSolver.cpp.o

src/sudoku/RecursiveSudokuSolver.i: src/sudoku/RecursiveSudokuSolver.cpp.i

.PHONY : src/sudoku/RecursiveSudokuSolver.i

# target to preprocess a source file
src/sudoku/RecursiveSudokuSolver.cpp.i:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/RecursiveSudokuSolver.cpp.i
.PHONY : src/sudoku/RecursiveSudokuSolver.cpp.i

src/sudoku/RecursiveSudokuSolver.s: src/sudoku/RecursiveSudokuSolver.cpp.s

.PHONY : src/sudoku/RecursiveSudokuSolver.s

# target to generate assembly for a file
src/sudoku/RecursiveSudokuSolver.cpp.s:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/RecursiveSudokuSolver.cpp.s
.PHONY : src/sudoku/RecursiveSudokuSolver.cpp.s

src/sudoku/Sudoku.o: src/sudoku/Sudoku.cpp.o

.PHONY : src/sudoku/Sudoku.o

# target to build an object file
src/sudoku/Sudoku.cpp.o:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/Sudoku.cpp.o
.PHONY : src/sudoku/Sudoku.cpp.o

src/sudoku/Sudoku.i: src/sudoku/Sudoku.cpp.i

.PHONY : src/sudoku/Sudoku.i

# target to preprocess a source file
src/sudoku/Sudoku.cpp.i:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/Sudoku.cpp.i
.PHONY : src/sudoku/Sudoku.cpp.i

src/sudoku/Sudoku.s: src/sudoku/Sudoku.cpp.s

.PHONY : src/sudoku/Sudoku.s

# target to generate assembly for a file
src/sudoku/Sudoku.cpp.s:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/Sudoku.cpp.s
.PHONY : src/sudoku/Sudoku.cpp.s

src/sudoku/SudokuCell.o: src/sudoku/SudokuCell.cpp.o

.PHONY : src/sudoku/SudokuCell.o

# target to build an object file
src/sudoku/SudokuCell.cpp.o:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/SudokuCell.cpp.o
.PHONY : src/sudoku/SudokuCell.cpp.o

src/sudoku/SudokuCell.i: src/sudoku/SudokuCell.cpp.i

.PHONY : src/sudoku/SudokuCell.i

# target to preprocess a source file
src/sudoku/SudokuCell.cpp.i:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/SudokuCell.cpp.i
.PHONY : src/sudoku/SudokuCell.cpp.i

src/sudoku/SudokuCell.s: src/sudoku/SudokuCell.cpp.s

.PHONY : src/sudoku/SudokuCell.s

# target to generate assembly for a file
src/sudoku/SudokuCell.cpp.s:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/SudokuCell.cpp.s
.PHONY : src/sudoku/SudokuCell.cpp.s

src/sudoku/SudokuFactory.o: src/sudoku/SudokuFactory.cpp.o

.PHONY : src/sudoku/SudokuFactory.o

# target to build an object file
src/sudoku/SudokuFactory.cpp.o:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/SudokuFactory.cpp.o
.PHONY : src/sudoku/SudokuFactory.cpp.o

src/sudoku/SudokuFactory.i: src/sudoku/SudokuFactory.cpp.i

.PHONY : src/sudoku/SudokuFactory.i

# target to preprocess a source file
src/sudoku/SudokuFactory.cpp.i:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/SudokuFactory.cpp.i
.PHONY : src/sudoku/SudokuFactory.cpp.i

src/sudoku/SudokuFactory.s: src/sudoku/SudokuFactory.cpp.s

.PHONY : src/sudoku/SudokuFactory.s

# target to generate assembly for a file
src/sudoku/SudokuFactory.cpp.s:
	$(MAKE) -f CMakeFiles/SudokuSolver.dir/build.make CMakeFiles/SudokuSolver.dir/src/sudoku/SudokuFactory.cpp.s
.PHONY : src/sudoku/SudokuFactory.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... package_source"
	@echo "... SudokuSolver"
	@echo "... package"
	@echo "... SudokuSolverExample"
	@echo "... examples/example1.o"
	@echo "... examples/example1.i"
	@echo "... examples/example1.s"
	@echo "... src/IOHandling/CommandLineUI.o"
	@echo "... src/IOHandling/CommandLineUI.i"
	@echo "... src/IOHandling/CommandLineUI.s"
	@echo "... src/common/JsonSudokuHandler.o"
	@echo "... src/common/JsonSudokuHandler.i"
	@echo "... src/common/JsonSudokuHandler.s"
	@echo "... src/common/Timer.o"
	@echo "... src/common/Timer.i"
	@echo "... src/common/Timer.s"
	@echo "... src/sudoku/ClassicSudokuBoard.o"
	@echo "... src/sudoku/ClassicSudokuBoard.i"
	@echo "... src/sudoku/ClassicSudokuBoard.s"
	@echo "... src/sudoku/RecursiveSudokuSolver.o"
	@echo "... src/sudoku/RecursiveSudokuSolver.i"
	@echo "... src/sudoku/RecursiveSudokuSolver.s"
	@echo "... src/sudoku/Sudoku.o"
	@echo "... src/sudoku/Sudoku.i"
	@echo "... src/sudoku/Sudoku.s"
	@echo "... src/sudoku/SudokuCell.o"
	@echo "... src/sudoku/SudokuCell.i"
	@echo "... src/sudoku/SudokuCell.s"
	@echo "... src/sudoku/SudokuFactory.o"
	@echo "... src/sudoku/SudokuFactory.i"
	@echo "... src/sudoku/SudokuFactory.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
