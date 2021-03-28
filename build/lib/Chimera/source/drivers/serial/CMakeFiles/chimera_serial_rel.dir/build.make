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
include lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/progress.make

# Include the compile flags for this target's objects.
include lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/flags.make

lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.o: lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/flags.make
lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.o: ../lib/Chimera/source/drivers/serial/chimera_serial.cpp
lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.o: lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/source/drivers/serial && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.o -MF CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.o.d -o CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.o -c /home/braunbr/git/Projects/Valkyrie/lib/Chimera/source/drivers/serial/chimera_serial.cpp

lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/source/drivers/serial && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/Chimera/source/drivers/serial/chimera_serial.cpp > CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.i

lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/source/drivers/serial && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/Chimera/source/drivers/serial/chimera_serial.cpp -o CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.s

# Object files for target chimera_serial_rel
chimera_serial_rel_OBJECTS = \
"CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.o"

# External object files for target chimera_serial_rel
chimera_serial_rel_EXTERNAL_OBJECTS =

lib/libchimera_serial_rel_dbg.a: lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/chimera_serial.cpp.o
lib/libchimera_serial_rel_dbg.a: lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/build.make
lib/libchimera_serial_rel_dbg.a: lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../../libchimera_serial_rel_dbg.a"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/source/drivers/serial && $(CMAKE_COMMAND) -P CMakeFiles/chimera_serial_rel.dir/cmake_clean_target.cmake
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/source/drivers/serial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chimera_serial_rel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/build: lib/libchimera_serial_rel_dbg.a
.PHONY : lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/build

lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/clean:
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/source/drivers/serial && $(CMAKE_COMMAND) -P CMakeFiles/chimera_serial_rel.dir/cmake_clean.cmake
.PHONY : lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/clean

lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/depend:
	cd /home/braunbr/git/Projects/Valkyrie/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/braunbr/git/Projects/Valkyrie /home/braunbr/git/Projects/Valkyrie/lib/Chimera/source/drivers/serial /home/braunbr/git/Projects/Valkyrie/build /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/source/drivers/serial /home/braunbr/git/Projects/Valkyrie/build/lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Chimera/source/drivers/serial/CMakeFiles/chimera_serial_rel.dir/depend

