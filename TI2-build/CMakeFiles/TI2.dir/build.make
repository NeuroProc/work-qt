# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/home/Neuron/work/qt/TI2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/home/Neuron/work/qt/TI2-build

# Include any dependencies generated for this target.
include CMakeFiles/TI2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TI2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TI2.dir/flags.make

CMakeFiles/TI2.dir/main.cpp.o: CMakeFiles/TI2.dir/flags.make
CMakeFiles/TI2.dir/main.cpp.o: /usr/home/Neuron/work/qt/TI2/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /usr/home/Neuron/work/qt/TI2-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TI2.dir/main.cpp.o"
	/usr/bin/CC   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TI2.dir/main.cpp.o -c /usr/home/Neuron/work/qt/TI2/main.cpp

CMakeFiles/TI2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TI2.dir/main.cpp.i"
	/usr/bin/CC  $(CXX_DEFINES) $(CXX_FLAGS) -E /usr/home/Neuron/work/qt/TI2/main.cpp > CMakeFiles/TI2.dir/main.cpp.i

CMakeFiles/TI2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TI2.dir/main.cpp.s"
	/usr/bin/CC  $(CXX_DEFINES) $(CXX_FLAGS) -S /usr/home/Neuron/work/qt/TI2/main.cpp -o CMakeFiles/TI2.dir/main.cpp.s

CMakeFiles/TI2.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/TI2.dir/main.cpp.o.requires

CMakeFiles/TI2.dir/main.cpp.o.provides: CMakeFiles/TI2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TI2.dir/build.make CMakeFiles/TI2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TI2.dir/main.cpp.o.provides

CMakeFiles/TI2.dir/main.cpp.o.provides.build: CMakeFiles/TI2.dir/main.cpp.o

# Object files for target TI2
TI2_OBJECTS = \
"CMakeFiles/TI2.dir/main.cpp.o"

# External object files for target TI2
TI2_EXTERNAL_OBJECTS =

TI2: CMakeFiles/TI2.dir/main.cpp.o
TI2: CMakeFiles/TI2.dir/build.make
TI2: CMakeFiles/TI2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable TI2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TI2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TI2.dir/build: TI2
.PHONY : CMakeFiles/TI2.dir/build

CMakeFiles/TI2.dir/requires: CMakeFiles/TI2.dir/main.cpp.o.requires
.PHONY : CMakeFiles/TI2.dir/requires

CMakeFiles/TI2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TI2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TI2.dir/clean

CMakeFiles/TI2.dir/depend:
	cd /usr/home/Neuron/work/qt/TI2-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/home/Neuron/work/qt/TI2 /usr/home/Neuron/work/qt/TI2 /usr/home/Neuron/work/qt/TI2-build /usr/home/Neuron/work/qt/TI2-build /usr/home/Neuron/work/qt/TI2-build/CMakeFiles/TI2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TI2.dir/depend
