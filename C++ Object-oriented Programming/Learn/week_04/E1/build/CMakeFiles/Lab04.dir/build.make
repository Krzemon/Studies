# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/build"

# Include any dependencies generated for this target.
include CMakeFiles/Lab04.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Lab04.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab04.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab04.dir/flags.make

CMakeFiles/Lab04.dir/main.cpp.o: CMakeFiles/Lab04.dir/flags.make
CMakeFiles/Lab04.dir/main.cpp.o: /home/fedora/Programming/Studies/C++\ Object-oriented\ Programming/Learn/week_04/E1/main.cpp
CMakeFiles/Lab04.dir/main.cpp.o: CMakeFiles/Lab04.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab04.dir/main.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Lab04.dir/main.cpp.o -MF CMakeFiles/Lab04.dir/main.cpp.o.d -o CMakeFiles/Lab04.dir/main.cpp.o -c "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/main.cpp"

CMakeFiles/Lab04.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Lab04.dir/main.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/main.cpp" > CMakeFiles/Lab04.dir/main.cpp.i

CMakeFiles/Lab04.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Lab04.dir/main.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/main.cpp" -o CMakeFiles/Lab04.dir/main.cpp.s

CMakeFiles/Lab04.dir/src/MyList.cpp.o: CMakeFiles/Lab04.dir/flags.make
CMakeFiles/Lab04.dir/src/MyList.cpp.o: /home/fedora/Programming/Studies/C++\ Object-oriented\ Programming/Learn/week_04/E1/src/MyList.cpp
CMakeFiles/Lab04.dir/src/MyList.cpp.o: CMakeFiles/Lab04.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab04.dir/src/MyList.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Lab04.dir/src/MyList.cpp.o -MF CMakeFiles/Lab04.dir/src/MyList.cpp.o.d -o CMakeFiles/Lab04.dir/src/MyList.cpp.o -c "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/src/MyList.cpp"

CMakeFiles/Lab04.dir/src/MyList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Lab04.dir/src/MyList.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/src/MyList.cpp" > CMakeFiles/Lab04.dir/src/MyList.cpp.i

CMakeFiles/Lab04.dir/src/MyList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Lab04.dir/src/MyList.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/src/MyList.cpp" -o CMakeFiles/Lab04.dir/src/MyList.cpp.s

# Object files for target Lab04
Lab04_OBJECTS = \
"CMakeFiles/Lab04.dir/main.cpp.o" \
"CMakeFiles/Lab04.dir/src/MyList.cpp.o"

# External object files for target Lab04
Lab04_EXTERNAL_OBJECTS =

Lab04: CMakeFiles/Lab04.dir/main.cpp.o
Lab04: CMakeFiles/Lab04.dir/src/MyList.cpp.o
Lab04: CMakeFiles/Lab04.dir/build.make
Lab04: CMakeFiles/Lab04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lab04"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab04.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab04.dir/build: Lab04
.PHONY : CMakeFiles/Lab04.dir/build

CMakeFiles/Lab04.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab04.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab04.dir/clean

CMakeFiles/Lab04.dir/depend:
	cd "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1" "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1" "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/build" "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/build" "/home/fedora/Programming/Studies/C++ Object-oriented Programming/Learn/week_04/E1/build/CMakeFiles/Lab04.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Lab04.dir/depend

