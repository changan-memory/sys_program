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
CMAKE_SOURCE_DIR = /home/xking/Project/sys_program/_1_Proj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xking/Project/sys_program/_1_Proj/build

# Include any dependencies generated for this target.
include CMakeFiles/libmath.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/libmath.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/libmath.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libmath.dir/flags.make

CMakeFiles/libmath.dir/src/Add.cpp.o: CMakeFiles/libmath.dir/flags.make
CMakeFiles/libmath.dir/src/Add.cpp.o: /home/xking/Project/sys_program/_1_Proj/src/Add.cpp
CMakeFiles/libmath.dir/src/Add.cpp.o: CMakeFiles/libmath.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/xking/Project/sys_program/_1_Proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libmath.dir/src/Add.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libmath.dir/src/Add.cpp.o -MF CMakeFiles/libmath.dir/src/Add.cpp.o.d -o CMakeFiles/libmath.dir/src/Add.cpp.o -c /home/xking/Project/sys_program/_1_Proj/src/Add.cpp

CMakeFiles/libmath.dir/src/Add.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libmath.dir/src/Add.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xking/Project/sys_program/_1_Proj/src/Add.cpp > CMakeFiles/libmath.dir/src/Add.cpp.i

CMakeFiles/libmath.dir/src/Add.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libmath.dir/src/Add.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xking/Project/sys_program/_1_Proj/src/Add.cpp -o CMakeFiles/libmath.dir/src/Add.cpp.s

CMakeFiles/libmath.dir/src/Div.cpp.o: CMakeFiles/libmath.dir/flags.make
CMakeFiles/libmath.dir/src/Div.cpp.o: /home/xking/Project/sys_program/_1_Proj/src/Div.cpp
CMakeFiles/libmath.dir/src/Div.cpp.o: CMakeFiles/libmath.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/xking/Project/sys_program/_1_Proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libmath.dir/src/Div.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libmath.dir/src/Div.cpp.o -MF CMakeFiles/libmath.dir/src/Div.cpp.o.d -o CMakeFiles/libmath.dir/src/Div.cpp.o -c /home/xking/Project/sys_program/_1_Proj/src/Div.cpp

CMakeFiles/libmath.dir/src/Div.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libmath.dir/src/Div.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xking/Project/sys_program/_1_Proj/src/Div.cpp > CMakeFiles/libmath.dir/src/Div.cpp.i

CMakeFiles/libmath.dir/src/Div.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libmath.dir/src/Div.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xking/Project/sys_program/_1_Proj/src/Div.cpp -o CMakeFiles/libmath.dir/src/Div.cpp.s

CMakeFiles/libmath.dir/src/Mul.cpp.o: CMakeFiles/libmath.dir/flags.make
CMakeFiles/libmath.dir/src/Mul.cpp.o: /home/xking/Project/sys_program/_1_Proj/src/Mul.cpp
CMakeFiles/libmath.dir/src/Mul.cpp.o: CMakeFiles/libmath.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/xking/Project/sys_program/_1_Proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libmath.dir/src/Mul.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libmath.dir/src/Mul.cpp.o -MF CMakeFiles/libmath.dir/src/Mul.cpp.o.d -o CMakeFiles/libmath.dir/src/Mul.cpp.o -c /home/xking/Project/sys_program/_1_Proj/src/Mul.cpp

CMakeFiles/libmath.dir/src/Mul.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libmath.dir/src/Mul.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xking/Project/sys_program/_1_Proj/src/Mul.cpp > CMakeFiles/libmath.dir/src/Mul.cpp.i

CMakeFiles/libmath.dir/src/Mul.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libmath.dir/src/Mul.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xking/Project/sys_program/_1_Proj/src/Mul.cpp -o CMakeFiles/libmath.dir/src/Mul.cpp.s

CMakeFiles/libmath.dir/src/Sub.cpp.o: CMakeFiles/libmath.dir/flags.make
CMakeFiles/libmath.dir/src/Sub.cpp.o: /home/xking/Project/sys_program/_1_Proj/src/Sub.cpp
CMakeFiles/libmath.dir/src/Sub.cpp.o: CMakeFiles/libmath.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/xking/Project/sys_program/_1_Proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libmath.dir/src/Sub.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libmath.dir/src/Sub.cpp.o -MF CMakeFiles/libmath.dir/src/Sub.cpp.o.d -o CMakeFiles/libmath.dir/src/Sub.cpp.o -c /home/xking/Project/sys_program/_1_Proj/src/Sub.cpp

CMakeFiles/libmath.dir/src/Sub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libmath.dir/src/Sub.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xking/Project/sys_program/_1_Proj/src/Sub.cpp > CMakeFiles/libmath.dir/src/Sub.cpp.i

CMakeFiles/libmath.dir/src/Sub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libmath.dir/src/Sub.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xking/Project/sys_program/_1_Proj/src/Sub.cpp -o CMakeFiles/libmath.dir/src/Sub.cpp.s

CMakeFiles/libmath.dir/src/swap.cpp.o: CMakeFiles/libmath.dir/flags.make
CMakeFiles/libmath.dir/src/swap.cpp.o: /home/xking/Project/sys_program/_1_Proj/src/swap.cpp
CMakeFiles/libmath.dir/src/swap.cpp.o: CMakeFiles/libmath.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/xking/Project/sys_program/_1_Proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/libmath.dir/src/swap.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libmath.dir/src/swap.cpp.o -MF CMakeFiles/libmath.dir/src/swap.cpp.o.d -o CMakeFiles/libmath.dir/src/swap.cpp.o -c /home/xking/Project/sys_program/_1_Proj/src/swap.cpp

CMakeFiles/libmath.dir/src/swap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libmath.dir/src/swap.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xking/Project/sys_program/_1_Proj/src/swap.cpp > CMakeFiles/libmath.dir/src/swap.cpp.i

CMakeFiles/libmath.dir/src/swap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libmath.dir/src/swap.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xking/Project/sys_program/_1_Proj/src/swap.cpp -o CMakeFiles/libmath.dir/src/swap.cpp.s

# Object files for target libmath
libmath_OBJECTS = \
"CMakeFiles/libmath.dir/src/Add.cpp.o" \
"CMakeFiles/libmath.dir/src/Div.cpp.o" \
"CMakeFiles/libmath.dir/src/Mul.cpp.o" \
"CMakeFiles/libmath.dir/src/Sub.cpp.o" \
"CMakeFiles/libmath.dir/src/swap.cpp.o"

# External object files for target libmath
libmath_EXTERNAL_OBJECTS =

/home/xking/Project/sys_program/_1_Proj/lib/liblibmath.a: CMakeFiles/libmath.dir/src/Add.cpp.o
/home/xking/Project/sys_program/_1_Proj/lib/liblibmath.a: CMakeFiles/libmath.dir/src/Div.cpp.o
/home/xking/Project/sys_program/_1_Proj/lib/liblibmath.a: CMakeFiles/libmath.dir/src/Mul.cpp.o
/home/xking/Project/sys_program/_1_Proj/lib/liblibmath.a: CMakeFiles/libmath.dir/src/Sub.cpp.o
/home/xking/Project/sys_program/_1_Proj/lib/liblibmath.a: CMakeFiles/libmath.dir/src/swap.cpp.o
/home/xking/Project/sys_program/_1_Proj/lib/liblibmath.a: CMakeFiles/libmath.dir/build.make
/home/xking/Project/sys_program/_1_Proj/lib/liblibmath.a: CMakeFiles/libmath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/xking/Project/sys_program/_1_Proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library /home/xking/Project/sys_program/_1_Proj/lib/liblibmath.a"
	$(CMAKE_COMMAND) -P CMakeFiles/libmath.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libmath.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libmath.dir/build: /home/xking/Project/sys_program/_1_Proj/lib/liblibmath.a
.PHONY : CMakeFiles/libmath.dir/build

CMakeFiles/libmath.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libmath.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libmath.dir/clean

CMakeFiles/libmath.dir/depend:
	cd /home/xking/Project/sys_program/_1_Proj/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xking/Project/sys_program/_1_Proj /home/xking/Project/sys_program/_1_Proj /home/xking/Project/sys_program/_1_Proj/build /home/xking/Project/sys_program/_1_Proj/build /home/xking/Project/sys_program/_1_Proj/build/CMakeFiles/libmath.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/libmath.dir/depend

