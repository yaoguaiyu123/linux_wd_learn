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
CMAKE_SOURCE_DIR = /run/media/root/study/github_repository/linux_wd_learn/project09

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /run/media/root/study/github_repository/linux_wd_learn/build-project09-C_C_2024_03_10-Debug

# Include any dependencies generated for this target.
include CMakeFiles/project09.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project09.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project09.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project09.dir/flags.make

CMakeFiles/project09.dir/main.c.o: CMakeFiles/project09.dir/flags.make
CMakeFiles/project09.dir/main.c.o: /run/media/root/study/github_repository/linux_wd_learn/project09/main.c
CMakeFiles/project09.dir/main.c.o: CMakeFiles/project09.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/run/media/root/study/github_repository/linux_wd_learn/build-project09-C_C_2024_03_10-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/project09.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/project09.dir/main.c.o -MF CMakeFiles/project09.dir/main.c.o.d -o CMakeFiles/project09.dir/main.c.o -c /run/media/root/study/github_repository/linux_wd_learn/project09/main.c

CMakeFiles/project09.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/project09.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /run/media/root/study/github_repository/linux_wd_learn/project09/main.c > CMakeFiles/project09.dir/main.c.i

CMakeFiles/project09.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/project09.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /run/media/root/study/github_repository/linux_wd_learn/project09/main.c -o CMakeFiles/project09.dir/main.c.s

# Object files for target project09
project09_OBJECTS = \
"CMakeFiles/project09.dir/main.c.o"

# External object files for target project09
project09_EXTERNAL_OBJECTS =

project09: CMakeFiles/project09.dir/main.c.o
project09: CMakeFiles/project09.dir/build.make
project09: CMakeFiles/project09.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/run/media/root/study/github_repository/linux_wd_learn/build-project09-C_C_2024_03_10-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable project09"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project09.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project09.dir/build: project09
.PHONY : CMakeFiles/project09.dir/build

CMakeFiles/project09.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project09.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project09.dir/clean

CMakeFiles/project09.dir/depend:
	cd /run/media/root/study/github_repository/linux_wd_learn/build-project09-C_C_2024_03_10-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /run/media/root/study/github_repository/linux_wd_learn/project09 /run/media/root/study/github_repository/linux_wd_learn/project09 /run/media/root/study/github_repository/linux_wd_learn/build-project09-C_C_2024_03_10-Debug /run/media/root/study/github_repository/linux_wd_learn/build-project09-C_C_2024_03_10-Debug /run/media/root/study/github_repository/linux_wd_learn/build-project09-C_C_2024_03_10-Debug/CMakeFiles/project09.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/project09.dir/depend
