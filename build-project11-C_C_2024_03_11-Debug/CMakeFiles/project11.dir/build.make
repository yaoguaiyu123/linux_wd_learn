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
CMAKE_SOURCE_DIR = /run/media/root/study/github_repository/linux_wd_learn/project11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /run/media/root/study/github_repository/linux_wd_learn/build-project11-C_C_2024_03_11-Debug

# Include any dependencies generated for this target.
include CMakeFiles/project11.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project11.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project11.dir/flags.make

CMakeFiles/project11.dir/main.c.o: CMakeFiles/project11.dir/flags.make
CMakeFiles/project11.dir/main.c.o: /run/media/root/study/github_repository/linux_wd_learn/project11/main.c
CMakeFiles/project11.dir/main.c.o: CMakeFiles/project11.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/run/media/root/study/github_repository/linux_wd_learn/build-project11-C_C_2024_03_11-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/project11.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/project11.dir/main.c.o -MF CMakeFiles/project11.dir/main.c.o.d -o CMakeFiles/project11.dir/main.c.o -c /run/media/root/study/github_repository/linux_wd_learn/project11/main.c

CMakeFiles/project11.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/project11.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /run/media/root/study/github_repository/linux_wd_learn/project11/main.c > CMakeFiles/project11.dir/main.c.i

CMakeFiles/project11.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/project11.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /run/media/root/study/github_repository/linux_wd_learn/project11/main.c -o CMakeFiles/project11.dir/main.c.s

# Object files for target project11
project11_OBJECTS = \
"CMakeFiles/project11.dir/main.c.o"

# External object files for target project11
project11_EXTERNAL_OBJECTS =

project11: CMakeFiles/project11.dir/main.c.o
project11: CMakeFiles/project11.dir/build.make
project11: CMakeFiles/project11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/run/media/root/study/github_repository/linux_wd_learn/build-project11-C_C_2024_03_11-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable project11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project11.dir/build: project11
.PHONY : CMakeFiles/project11.dir/build

CMakeFiles/project11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project11.dir/clean

CMakeFiles/project11.dir/depend:
	cd /run/media/root/study/github_repository/linux_wd_learn/build-project11-C_C_2024_03_11-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /run/media/root/study/github_repository/linux_wd_learn/project11 /run/media/root/study/github_repository/linux_wd_learn/project11 /run/media/root/study/github_repository/linux_wd_learn/build-project11-C_C_2024_03_11-Debug /run/media/root/study/github_repository/linux_wd_learn/build-project11-C_C_2024_03_11-Debug /run/media/root/study/github_repository/linux_wd_learn/build-project11-C_C_2024_03_11-Debug/CMakeFiles/project11.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/project11.dir/depend
