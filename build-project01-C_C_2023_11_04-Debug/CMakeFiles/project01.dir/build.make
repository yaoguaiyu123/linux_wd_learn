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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /run/media/root/study/SystemProgram/01/project01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /run/media/root/study/SystemProgram/01/build-project01-C_C_2023_11_04-Debug

# Include any dependencies generated for this target.
include CMakeFiles/project01.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project01.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project01.dir/flags.make

CMakeFiles/project01.dir/main.c.o: CMakeFiles/project01.dir/flags.make
CMakeFiles/project01.dir/main.c.o: /run/media/root/study/SystemProgram/01/project01/main.c
CMakeFiles/project01.dir/main.c.o: CMakeFiles/project01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/run/media/root/study/SystemProgram/01/build-project01-C_C_2023_11_04-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/project01.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/project01.dir/main.c.o -MF CMakeFiles/project01.dir/main.c.o.d -o CMakeFiles/project01.dir/main.c.o -c /run/media/root/study/SystemProgram/01/project01/main.c

CMakeFiles/project01.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/project01.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /run/media/root/study/SystemProgram/01/project01/main.c > CMakeFiles/project01.dir/main.c.i

CMakeFiles/project01.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/project01.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /run/media/root/study/SystemProgram/01/project01/main.c -o CMakeFiles/project01.dir/main.c.s

# Object files for target project01
project01_OBJECTS = \
"CMakeFiles/project01.dir/main.c.o"

# External object files for target project01
project01_EXTERNAL_OBJECTS =

project01: CMakeFiles/project01.dir/main.c.o
project01: CMakeFiles/project01.dir/build.make
project01: CMakeFiles/project01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/run/media/root/study/SystemProgram/01/build-project01-C_C_2023_11_04-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable project01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project01.dir/build: project01
.PHONY : CMakeFiles/project01.dir/build

CMakeFiles/project01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project01.dir/clean

CMakeFiles/project01.dir/depend:
	cd /run/media/root/study/SystemProgram/01/build-project01-C_C_2023_11_04-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /run/media/root/study/SystemProgram/01/project01 /run/media/root/study/SystemProgram/01/project01 /run/media/root/study/SystemProgram/01/build-project01-C_C_2023_11_04-Debug /run/media/root/study/SystemProgram/01/build-project01-C_C_2023_11_04-Debug /run/media/root/study/SystemProgram/01/build-project01-C_C_2023_11_04-Debug/CMakeFiles/project01.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/project01.dir/depend

