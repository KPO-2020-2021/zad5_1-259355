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

# Include any dependencies generated for this target.
include tests/CMakeFiles/unit_tests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/unit_tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/unit_tests.dir/flags.make

tests/CMakeFiles/unit_tests.dir/dummy.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/dummy.cpp.o: ../tests/dummy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/unit_tests.dir/dummy.cpp.o"
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/dummy.cpp.o -c /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests/dummy.cpp

tests/CMakeFiles/unit_tests.dir/dummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/dummy.cpp.i"
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests/dummy.cpp > CMakeFiles/unit_tests.dir/dummy.cpp.i

tests/CMakeFiles/unit_tests.dir/dummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/dummy.cpp.s"
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests/dummy.cpp -o CMakeFiles/unit_tests.dir/dummy.cpp.s

tests/CMakeFiles/unit_tests.dir/test1.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/test1.cpp.o: ../tests/test1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/unit_tests.dir/test1.cpp.o"
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/test1.cpp.o -c /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests/test1.cpp

tests/CMakeFiles/unit_tests.dir/test1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/test1.cpp.i"
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests/test1.cpp > CMakeFiles/unit_tests.dir/test1.cpp.i

tests/CMakeFiles/unit_tests.dir/test1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/test1.cpp.s"
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests/test1.cpp -o CMakeFiles/unit_tests.dir/test1.cpp.s

tests/CMakeFiles/unit_tests.dir/TestMat3.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/TestMat3.cpp.o: ../tests/TestMat3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/unit_tests.dir/TestMat3.cpp.o"
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/TestMat3.cpp.o -c /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests/TestMat3.cpp

tests/CMakeFiles/unit_tests.dir/TestMat3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/TestMat3.cpp.i"
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests/TestMat3.cpp > CMakeFiles/unit_tests.dir/TestMat3.cpp.i

tests/CMakeFiles/unit_tests.dir/TestMat3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/TestMat3.cpp.s"
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests/TestMat3.cpp -o CMakeFiles/unit_tests.dir/TestMat3.cpp.s

tests/CMakeFiles/unit_tests.dir/TestVec3.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/TestVec3.cpp.o: ../tests/TestVec3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tests/CMakeFiles/unit_tests.dir/TestVec3.cpp.o"
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/TestVec3.cpp.o -c /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests/TestVec3.cpp

tests/CMakeFiles/unit_tests.dir/TestVec3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/TestVec3.cpp.i"
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests/TestVec3.cpp > CMakeFiles/unit_tests.dir/TestVec3.cpp.i

tests/CMakeFiles/unit_tests.dir/TestVec3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/TestVec3.cpp.s"
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests/TestVec3.cpp -o CMakeFiles/unit_tests.dir/TestVec3.cpp.s

# Object files for target unit_tests
unit_tests_OBJECTS = \
"CMakeFiles/unit_tests.dir/dummy.cpp.o" \
"CMakeFiles/unit_tests.dir/test1.cpp.o" \
"CMakeFiles/unit_tests.dir/TestMat3.cpp.o" \
"CMakeFiles/unit_tests.dir/TestVec3.cpp.o"

# External object files for target unit_tests
unit_tests_EXTERNAL_OBJECTS = \
"/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles/program.dir/src/example.cpp.o" \
"/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.o" \
"/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles/program.dir/src/matrix3.cpp.o" \
"/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles/program.dir/src/vector3.cpp.o" \
"/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles/program.dir/src/Prostopadl.cpp.o" \
"/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles/program.dir/src/Drone.cpp.o" \
"/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles/program.dir/src/GranBlock.cpp.o" \
"/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles/program.dir/src/Block.cpp.o" \
"/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles/program.dir/src/scena.cpp.o"

unit_tests: tests/CMakeFiles/unit_tests.dir/dummy.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/test1.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/TestMat3.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/TestVec3.cpp.o
unit_tests: CMakeFiles/program.dir/src/example.cpp.o
unit_tests: CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.o
unit_tests: CMakeFiles/program.dir/src/matrix3.cpp.o
unit_tests: CMakeFiles/program.dir/src/vector3.cpp.o
unit_tests: CMakeFiles/program.dir/src/Prostopadl.cpp.o
unit_tests: CMakeFiles/program.dir/src/Drone.cpp.o
unit_tests: CMakeFiles/program.dir/src/GranBlock.cpp.o
unit_tests: CMakeFiles/program.dir/src/Block.cpp.o
unit_tests: CMakeFiles/program.dir/src/scena.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/build.make
unit_tests: tests/CMakeFiles/unit_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adam/Programowanie_Obiektowe/zad5_1-259355/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../unit_tests"
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/unit_tests.dir/build: unit_tests

.PHONY : tests/CMakeFiles/unit_tests.dir/build

tests/CMakeFiles/unit_tests.dir/clean:
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/unit_tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/unit_tests.dir/clean

tests/CMakeFiles/unit_tests.dir/depend:
	cd /home/adam/Programowanie_Obiektowe/zad5_1-259355/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adam/Programowanie_Obiektowe/zad5_1-259355 /home/adam/Programowanie_Obiektowe/zad5_1-259355/tests /home/adam/Programowanie_Obiektowe/zad5_1-259355/build /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests /home/adam/Programowanie_Obiektowe/zad5_1-259355/build/tests/CMakeFiles/unit_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/unit_tests.dir/depend

