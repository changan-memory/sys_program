# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/xking/Project/sys_program/Read_and_copy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xking/Project/sys_program/Read_and_copy/build

# Include any dependencies generated for this target.
include CMakeFiles/proj_exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/proj_exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/proj_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj_exe.dir/flags.make

CMakeFiles/proj_exe.dir/main.cpp.o: CMakeFiles/proj_exe.dir/flags.make
CMakeFiles/proj_exe.dir/main.cpp.o: /home/xking/Project/sys_program/Read_and_copy/main.cpp
CMakeFiles/proj_exe.dir/main.cpp.o: CMakeFiles/proj_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/xking/Project/sys_program/Read_and_copy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proj_exe.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proj_exe.dir/main.cpp.o -MF CMakeFiles/proj_exe.dir/main.cpp.o.d -o CMakeFiles/proj_exe.dir/main.cpp.o -c /home/xking/Project/sys_program/Read_and_copy/main.cpp

CMakeFiles/proj_exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proj_exe.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xking/Project/sys_program/Read_and_copy/main.cpp > CMakeFiles/proj_exe.dir/main.cpp.i

CMakeFiles/proj_exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proj_exe.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xking/Project/sys_program/Read_and_copy/main.cpp -o CMakeFiles/proj_exe.dir/main.cpp.s

# Object files for target proj_exe
proj_exe_OBJECTS = \
"CMakeFiles/proj_exe.dir/main.cpp.o"

# External object files for target proj_exe
proj_exe_EXTERNAL_OBJECTS =

proj_exe: CMakeFiles/proj_exe.dir/main.cpp.o
proj_exe: CMakeFiles/proj_exe.dir/build.make
proj_exe: CMakeFiles/proj_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/xking/Project/sys_program/Read_and_copy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable proj_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proj_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj_exe.dir/build: proj_exe
.PHONY : CMakeFiles/proj_exe.dir/build

CMakeFiles/proj_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proj_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proj_exe.dir/clean

CMakeFiles/proj_exe.dir/depend:
	cd /home/xking/Project/sys_program/Read_and_copy/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xking/Project/sys_program/Read_and_copy /home/xking/Project/sys_program/Read_and_copy /home/xking/Project/sys_program/Read_and_copy/build /home/xking/Project/sys_program/Read_and_copy/build /home/xking/Project/sys_program/Read_and_copy/build/CMakeFiles/proj_exe.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/proj_exe.dir/depend

