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
CMAKE_SOURCE_DIR = /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/library.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/library.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/library.dir/flags.make

lib/CMakeFiles/library.dir/lib.cpp.o: lib/CMakeFiles/library.dir/flags.make
lib/CMakeFiles/library.dir/lib.cpp.o: ../lib/lib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/library.dir/lib.cpp.o"
	cd /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/library.dir/lib.cpp.o -c /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/lib/lib.cpp

lib/CMakeFiles/library.dir/lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/library.dir/lib.cpp.i"
	cd /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/lib/lib.cpp > CMakeFiles/library.dir/lib.cpp.i

lib/CMakeFiles/library.dir/lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/library.dir/lib.cpp.s"
	cd /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/lib/lib.cpp -o CMakeFiles/library.dir/lib.cpp.s

# Object files for target library
library_OBJECTS = \
"CMakeFiles/library.dir/lib.cpp.o"

# External object files for target library
library_EXTERNAL_OBJECTS =

lib/liblibrary.a: lib/CMakeFiles/library.dir/lib.cpp.o
lib/liblibrary.a: lib/CMakeFiles/library.dir/build.make
lib/liblibrary.a: lib/CMakeFiles/library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblibrary.a"
	cd /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/library.dir/cmake_clean_target.cmake
	cd /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/library.dir/build: lib/liblibrary.a

.PHONY : lib/CMakeFiles/library.dir/build

lib/CMakeFiles/library.dir/clean:
	cd /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/library.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/library.dir/clean

lib/CMakeFiles/library.dir/depend:
	cd /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/lib /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/build /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/build/lib /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/link-lib-with-higher-cpp-standard/build/lib/CMakeFiles/library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/library.dir/depend

