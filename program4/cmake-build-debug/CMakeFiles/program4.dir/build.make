# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /cygdrive/c/Users/31409/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/31409/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/31409/CLionProjects/program4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/31409/CLionProjects/program4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/program4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/program4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/program4.dir/flags.make

CMakeFiles/program4.dir/driver.cpp.o: CMakeFiles/program4.dir/flags.make
CMakeFiles/program4.dir/driver.cpp.o: ../driver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/31409/CLionProjects/program4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/program4.dir/driver.cpp.o"
	/cygdrive/c/cygwin64/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/program4.dir/driver.cpp.o -c /cygdrive/c/Users/31409/CLionProjects/program4/driver.cpp

CMakeFiles/program4.dir/driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program4.dir/driver.cpp.i"
	/cygdrive/c/cygwin64/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/31409/CLionProjects/program4/driver.cpp > CMakeFiles/program4.dir/driver.cpp.i

CMakeFiles/program4.dir/driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program4.dir/driver.cpp.s"
	/cygdrive/c/cygwin64/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/31409/CLionProjects/program4/driver.cpp -o CMakeFiles/program4.dir/driver.cpp.s

CMakeFiles/program4.dir/test_map.cpp.o: CMakeFiles/program4.dir/flags.make
CMakeFiles/program4.dir/test_map.cpp.o: ../test_map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/31409/CLionProjects/program4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/program4.dir/test_map.cpp.o"
	/cygdrive/c/cygwin64/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/program4.dir/test_map.cpp.o -c /cygdrive/c/Users/31409/CLionProjects/program4/test_map.cpp

CMakeFiles/program4.dir/test_map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program4.dir/test_map.cpp.i"
	/cygdrive/c/cygwin64/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/31409/CLionProjects/program4/test_map.cpp > CMakeFiles/program4.dir/test_map.cpp.i

CMakeFiles/program4.dir/test_map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program4.dir/test_map.cpp.s"
	/cygdrive/c/cygwin64/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/31409/CLionProjects/program4/test_map.cpp -o CMakeFiles/program4.dir/test_map.cpp.s

CMakeFiles/program4.dir/test_set.cpp.o: CMakeFiles/program4.dir/flags.make
CMakeFiles/program4.dir/test_set.cpp.o: ../test_set.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/31409/CLionProjects/program4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/program4.dir/test_set.cpp.o"
	/cygdrive/c/cygwin64/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/program4.dir/test_set.cpp.o -c /cygdrive/c/Users/31409/CLionProjects/program4/test_set.cpp

CMakeFiles/program4.dir/test_set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program4.dir/test_set.cpp.i"
	/cygdrive/c/cygwin64/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/31409/CLionProjects/program4/test_set.cpp > CMakeFiles/program4.dir/test_set.cpp.i

CMakeFiles/program4.dir/test_set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program4.dir/test_set.cpp.s"
	/cygdrive/c/cygwin64/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/31409/CLionProjects/program4/test_set.cpp -o CMakeFiles/program4.dir/test_set.cpp.s

CMakeFiles/program4.dir/wordgenerator.cpp.o: CMakeFiles/program4.dir/flags.make
CMakeFiles/program4.dir/wordgenerator.cpp.o: ../wordgenerator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/31409/CLionProjects/program4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/program4.dir/wordgenerator.cpp.o"
	/cygdrive/c/cygwin64/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/program4.dir/wordgenerator.cpp.o -c /cygdrive/c/Users/31409/CLionProjects/program4/wordgenerator.cpp

CMakeFiles/program4.dir/wordgenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program4.dir/wordgenerator.cpp.i"
	/cygdrive/c/cygwin64/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/31409/CLionProjects/program4/wordgenerator.cpp > CMakeFiles/program4.dir/wordgenerator.cpp.i

CMakeFiles/program4.dir/wordgenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program4.dir/wordgenerator.cpp.s"
	/cygdrive/c/cygwin64/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/31409/CLionProjects/program4/wordgenerator.cpp -o CMakeFiles/program4.dir/wordgenerator.cpp.s

# Object files for target program4
program4_OBJECTS = \
"CMakeFiles/program4.dir/driver.cpp.o" \
"CMakeFiles/program4.dir/test_map.cpp.o" \
"CMakeFiles/program4.dir/test_set.cpp.o" \
"CMakeFiles/program4.dir/wordgenerator.cpp.o"

# External object files for target program4
program4_EXTERNAL_OBJECTS =

program4.exe: CMakeFiles/program4.dir/driver.cpp.o
program4.exe: CMakeFiles/program4.dir/test_map.cpp.o
program4.exe: CMakeFiles/program4.dir/test_set.cpp.o
program4.exe: CMakeFiles/program4.dir/wordgenerator.cpp.o
program4.exe: CMakeFiles/program4.dir/build.make
program4.exe: CMakeFiles/program4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/31409/CLionProjects/program4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable program4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/program4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/program4.dir/build: program4.exe

.PHONY : CMakeFiles/program4.dir/build

CMakeFiles/program4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/program4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/program4.dir/clean

CMakeFiles/program4.dir/depend:
	cd /cygdrive/c/Users/31409/CLionProjects/program4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/31409/CLionProjects/program4 /cygdrive/c/Users/31409/CLionProjects/program4 /cygdrive/c/Users/31409/CLionProjects/program4/cmake-build-debug /cygdrive/c/Users/31409/CLionProjects/program4/cmake-build-debug /cygdrive/c/Users/31409/CLionProjects/program4/cmake-build-debug/CMakeFiles/program4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/program4.dir/depend

