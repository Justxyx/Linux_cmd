# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Linux_cmd.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Linux_cmd.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Linux_cmd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Linux_cmd.dir/flags.make

CMakeFiles/Linux_cmd.dir/01more.c.o: CMakeFiles/Linux_cmd.dir/flags.make
CMakeFiles/Linux_cmd.dir/01more.c.o: ../01more.c
CMakeFiles/Linux_cmd.dir/01more.c.o: CMakeFiles/Linux_cmd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Linux_cmd.dir/01more.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Linux_cmd.dir/01more.c.o -MF CMakeFiles/Linux_cmd.dir/01more.c.o.d -o CMakeFiles/Linux_cmd.dir/01more.c.o -c /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/01more.c

CMakeFiles/Linux_cmd.dir/01more.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Linux_cmd.dir/01more.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/01more.c > CMakeFiles/Linux_cmd.dir/01more.c.i

CMakeFiles/Linux_cmd.dir/01more.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Linux_cmd.dir/01more.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/01more.c -o CMakeFiles/Linux_cmd.dir/01more.c.s

CMakeFiles/Linux_cmd.dir/02more.c.o: CMakeFiles/Linux_cmd.dir/flags.make
CMakeFiles/Linux_cmd.dir/02more.c.o: 02more.c
CMakeFiles/Linux_cmd.dir/02more.c.o: CMakeFiles/Linux_cmd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Linux_cmd.dir/02more.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Linux_cmd.dir/02more.c.o -MF CMakeFiles/Linux_cmd.dir/02more.c.o.d -o CMakeFiles/Linux_cmd.dir/02more.c.o -c /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/cmake-build-debug/02more.c

CMakeFiles/Linux_cmd.dir/02more.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Linux_cmd.dir/02more.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/cmake-build-debug/02more.c > CMakeFiles/Linux_cmd.dir/02more.c.i

CMakeFiles/Linux_cmd.dir/02more.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Linux_cmd.dir/02more.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/cmake-build-debug/02more.c -o CMakeFiles/Linux_cmd.dir/02more.c.s

CMakeFiles/Linux_cmd.dir/test.c.o: CMakeFiles/Linux_cmd.dir/flags.make
CMakeFiles/Linux_cmd.dir/test.c.o: ../test.c
CMakeFiles/Linux_cmd.dir/test.c.o: CMakeFiles/Linux_cmd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Linux_cmd.dir/test.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Linux_cmd.dir/test.c.o -MF CMakeFiles/Linux_cmd.dir/test.c.o.d -o CMakeFiles/Linux_cmd.dir/test.c.o -c /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/test.c

CMakeFiles/Linux_cmd.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Linux_cmd.dir/test.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/test.c > CMakeFiles/Linux_cmd.dir/test.c.i

CMakeFiles/Linux_cmd.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Linux_cmd.dir/test.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/test.c -o CMakeFiles/Linux_cmd.dir/test.c.s

# Object files for target Linux_cmd
Linux_cmd_OBJECTS = \
"CMakeFiles/Linux_cmd.dir/01more.c.o" \
"CMakeFiles/Linux_cmd.dir/02more.c.o" \
"CMakeFiles/Linux_cmd.dir/test.c.o"

# External object files for target Linux_cmd
Linux_cmd_EXTERNAL_OBJECTS =

Linux_cmd: CMakeFiles/Linux_cmd.dir/01more.c.o
Linux_cmd: CMakeFiles/Linux_cmd.dir/02more.c.o
Linux_cmd: CMakeFiles/Linux_cmd.dir/test.c.o
Linux_cmd: CMakeFiles/Linux_cmd.dir/build.make
Linux_cmd: CMakeFiles/Linux_cmd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Linux_cmd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Linux_cmd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Linux_cmd.dir/build: Linux_cmd
.PHONY : CMakeFiles/Linux_cmd.dir/build

CMakeFiles/Linux_cmd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Linux_cmd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Linux_cmd.dir/clean

CMakeFiles/Linux_cmd.dir/depend:
	cd /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/cmake-build-debug /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/cmake-build-debug /Users/xiaoyingxiong/projects/ClionProjects/Linux_cmd/cmake-build-debug/CMakeFiles/Linux_cmd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Linux_cmd.dir/depend

