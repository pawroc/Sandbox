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
CMAKE_SOURCE_DIR = /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/build

# Include any dependencies generated for this target.
include CMakeFiles/scope_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/scope_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scope_test.dir/flags.make

CMakeFiles/scope_test.dir/main.cpp.o: CMakeFiles/scope_test.dir/flags.make
CMakeFiles/scope_test.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/scope_test.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/scope_test.dir/main.cpp.o -c /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/main.cpp

CMakeFiles/scope_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scope_test.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/main.cpp > CMakeFiles/scope_test.dir/main.cpp.i

CMakeFiles/scope_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scope_test.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/main.cpp -o CMakeFiles/scope_test.dir/main.cpp.s

CMakeFiles/scope_test.dir/customType.cpp.o: CMakeFiles/scope_test.dir/flags.make
CMakeFiles/scope_test.dir/customType.cpp.o: ../customType.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/scope_test.dir/customType.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/scope_test.dir/customType.cpp.o -c /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/customType.cpp

CMakeFiles/scope_test.dir/customType.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scope_test.dir/customType.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/customType.cpp > CMakeFiles/scope_test.dir/customType.cpp.i

CMakeFiles/scope_test.dir/customType.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scope_test.dir/customType.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/customType.cpp -o CMakeFiles/scope_test.dir/customType.cpp.s

# Object files for target scope_test
scope_test_OBJECTS = \
"CMakeFiles/scope_test.dir/main.cpp.o" \
"CMakeFiles/scope_test.dir/customType.cpp.o"

# External object files for target scope_test
scope_test_EXTERNAL_OBJECTS =

scope_test: CMakeFiles/scope_test.dir/main.cpp.o
scope_test: CMakeFiles/scope_test.dir/customType.cpp.o
scope_test: CMakeFiles/scope_test.dir/build.make
scope_test: CMakeFiles/scope_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable scope_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scope_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scope_test.dir/build: scope_test

.PHONY : CMakeFiles/scope_test.dir/build

CMakeFiles/scope_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/scope_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/scope_test.dir/clean

CMakeFiles/scope_test.dir/depend:
	cd /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/build /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/build /home/ANT.AMAZON.COM/epawdroz/Projects/Sandbox/private-scope-vs-c-language/cpp_code/build/CMakeFiles/scope_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/scope_test.dir/depend

