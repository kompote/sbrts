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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/t0m/dev/sbrts

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/t0m/dev/sbrts

# Include any dependencies generated for this target.
include CMakeFiles/sbrts.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sbrts.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sbrts.dir/flags.make

CMakeFiles/sbrts.dir/src/main.cpp.o: CMakeFiles/sbrts.dir/flags.make
CMakeFiles/sbrts.dir/src/main.cpp.o: src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/t0m/dev/sbrts/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/sbrts.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sbrts.dir/src/main.cpp.o -c /home/t0m/dev/sbrts/src/main.cpp

CMakeFiles/sbrts.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sbrts.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/t0m/dev/sbrts/src/main.cpp > CMakeFiles/sbrts.dir/src/main.cpp.i

CMakeFiles/sbrts.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sbrts.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/t0m/dev/sbrts/src/main.cpp -o CMakeFiles/sbrts.dir/src/main.cpp.s

CMakeFiles/sbrts.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/sbrts.dir/src/main.cpp.o.requires

CMakeFiles/sbrts.dir/src/main.cpp.o.provides: CMakeFiles/sbrts.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/sbrts.dir/build.make CMakeFiles/sbrts.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/sbrts.dir/src/main.cpp.o.provides

CMakeFiles/sbrts.dir/src/main.cpp.o.provides.build: CMakeFiles/sbrts.dir/src/main.cpp.o

# Object files for target sbrts
sbrts_OBJECTS = \
"CMakeFiles/sbrts.dir/src/main.cpp.o"

# External object files for target sbrts
sbrts_EXTERNAL_OBJECTS =

sbrts: CMakeFiles/sbrts.dir/src/main.cpp.o
sbrts: CMakeFiles/sbrts.dir/build.make
sbrts: src/lib/libsfml-system.so
sbrts: src/lib/libsfml-window.so
sbrts: src/lib/libsfml-graphics.so
sbrts: src/lib/libsfml-network.so
sbrts: src/lib/libsfml-audio.so
sbrts: CMakeFiles/sbrts.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable sbrts"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sbrts.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sbrts.dir/build: sbrts
.PHONY : CMakeFiles/sbrts.dir/build

CMakeFiles/sbrts.dir/requires: CMakeFiles/sbrts.dir/src/main.cpp.o.requires
.PHONY : CMakeFiles/sbrts.dir/requires

CMakeFiles/sbrts.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sbrts.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sbrts.dir/clean

CMakeFiles/sbrts.dir/depend:
	cd /home/t0m/dev/sbrts && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/t0m/dev/sbrts /home/t0m/dev/sbrts /home/t0m/dev/sbrts /home/t0m/dev/sbrts /home/t0m/dev/sbrts/CMakeFiles/sbrts.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sbrts.dir/depend

