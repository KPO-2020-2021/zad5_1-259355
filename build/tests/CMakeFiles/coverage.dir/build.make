# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adam/Programowanie_Obiektowe/zad5_1-259355

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adam/Programowanie_Obiektowe/zad5_1-259355/build

# Utility rule file for coverage.

# Include the progress variables for this target.
include tests/CMakeFiles/coverage.dir/progress.make

tests/CMakeFiles/coverage:
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && echo [31mCode\ coverage\ only\ available\ in\ coverage\ builds.
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && echo [32mMake\ a\ new\ build\ directory\ and\ rerun\ cmake\ with\ -DCMAKE_BUILD_TYPE=Coverage\ to\ enable\ this\ target.[m

coverage: tests/CMakeFiles/coverage
coverage: tests/CMakeFiles/coverage.dir/build.make

.PHONY : coverage

# Rule to build all files generated by this target.
tests/CMakeFiles/coverage.dir/build: coverage

.PHONY : tests/CMakeFiles/coverage.dir/build

tests/CMakeFiles/coverage.dir/clean:
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/coverage.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/coverage.dir/clean

tests/CMakeFiles/coverage.dir/depend:
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adam/Programowanie_Obiektowe/zad5_1-259355 /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests /home/adam/Programowanie_Obiektowe/zad5_1-259355/build /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests/CMakeFiles/coverage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/coverage.dir/depend

