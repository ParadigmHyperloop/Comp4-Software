# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/73/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/73/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liam/Development/comp4-software/Examples/motorDriving

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liam/Development/comp4-software/Examples/motorDriving/build/host

# Include any dependencies generated for this target.
include CMakeFiles/motorDriving.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/motorDriving.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/motorDriving.dir/flags.make

CMakeFiles/motorDriving.dir/main.cpp.o: CMakeFiles/motorDriving.dir/flags.make
CMakeFiles/motorDriving.dir/main.cpp.o: ../../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liam/Development/comp4-software/Examples/motorDriving/build/host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/motorDriving.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motorDriving.dir/main.cpp.o -c /home/liam/Development/comp4-software/Examples/motorDriving/main.cpp

CMakeFiles/motorDriving.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motorDriving.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liam/Development/comp4-software/Examples/motorDriving/main.cpp > CMakeFiles/motorDriving.dir/main.cpp.i

CMakeFiles/motorDriving.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motorDriving.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liam/Development/comp4-software/Examples/motorDriving/main.cpp -o CMakeFiles/motorDriving.dir/main.cpp.s

# Object files for target motorDriving
motorDriving_OBJECTS = \
"CMakeFiles/motorDriving.dir/main.cpp.o"

# External object files for target motorDriving
motorDriving_EXTERNAL_OBJECTS =

motorDriving: CMakeFiles/motorDriving.dir/main.cpp.o
motorDriving: CMakeFiles/motorDriving.dir/build.make
motorDriving: CMakeFiles/motorDriving.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liam/Development/comp4-software/Examples/motorDriving/build/host/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable motorDriving"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/motorDriving.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/motorDriving.dir/build: motorDriving

.PHONY : CMakeFiles/motorDriving.dir/build

CMakeFiles/motorDriving.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/motorDriving.dir/cmake_clean.cmake
.PHONY : CMakeFiles/motorDriving.dir/clean

CMakeFiles/motorDriving.dir/depend:
	cd /home/liam/Development/comp4-software/Examples/motorDriving/build/host && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liam/Development/comp4-software/Examples/motorDriving /home/liam/Development/comp4-software/Examples/motorDriving /home/liam/Development/comp4-software/Examples/motorDriving/build/host /home/liam/Development/comp4-software/Examples/motorDriving/build/host /home/liam/Development/comp4-software/Examples/motorDriving/build/host/CMakeFiles/motorDriving.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/motorDriving.dir/depend

