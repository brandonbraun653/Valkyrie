# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/cmake/846/bin/cmake

# The command to remove a file.
RM = /snap/cmake/846/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/braunbr/git/Projects/Valkyrie

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/braunbr/git/Projects/Valkyrie/build

# Include any dependencies generated for this target.
include lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/progress.make

# Include the compile flags for this target's objects.
include lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/flags.make

lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.o: lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/flags.make
lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.o: ../lib/Chimera/bsp/nucleo/nucleo_f446re.cpp
lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.o: lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/bsp/nucleo && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.o -MF CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.o.d -o CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.o -c /home/braunbr/git/Projects/Valkyrie/lib/Chimera/bsp/nucleo/nucleo_f446re.cpp

lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/bsp/nucleo && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/Chimera/bsp/nucleo/nucleo_f446re.cpp > CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.i

lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/bsp/nucleo && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/Chimera/bsp/nucleo/nucleo_f446re.cpp -o CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.s

# Object files for target bsp_nucleo_f446re_rel_dbg
bsp_nucleo_f446re_rel_dbg_OBJECTS = \
"CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.o"

# External object files for target bsp_nucleo_f446re_rel_dbg
bsp_nucleo_f446re_rel_dbg_EXTERNAL_OBJECTS =

lib/libbsp_nucleo_f446re_rel_dbg_dbg.a: lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/nucleo_f446re.cpp.o
lib/libbsp_nucleo_f446re_rel_dbg_dbg.a: lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/build.make
lib/libbsp_nucleo_f446re_rel_dbg_dbg.a: lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../libbsp_nucleo_f446re_rel_dbg_dbg.a"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/bsp/nucleo && $(CMAKE_COMMAND) -P CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/cmake_clean_target.cmake
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/bsp/nucleo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/build: lib/libbsp_nucleo_f446re_rel_dbg_dbg.a
.PHONY : lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/build

lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/clean:
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/bsp/nucleo && $(CMAKE_COMMAND) -P CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/cmake_clean.cmake
.PHONY : lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/clean

lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/depend:
	cd /home/braunbr/git/Projects/Valkyrie/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/braunbr/git/Projects/Valkyrie /home/braunbr/git/Projects/Valkyrie/lib/Chimera/bsp/nucleo /home/braunbr/git/Projects/Valkyrie/build /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/bsp/nucleo /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Chimera/bsp/nucleo/CMakeFiles/bsp_nucleo_f446re_rel_dbg.dir/depend

