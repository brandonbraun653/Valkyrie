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
include lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/progress.make

# Include the compile flags for this target's objects.
include lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/flags.make

lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.o: lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/flags.make
lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.o: ../lib/Aurora/source/memory/generic/generic_utils.cpp
lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.o: lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Aurora/source/memory/generic && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.o -MF CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.o.d -o CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.o -c /home/braunbr/git/Projects/Valkyrie/lib/Aurora/source/memory/generic/generic_utils.cpp

lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Aurora/source/memory/generic && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/Aurora/source/memory/generic/generic_utils.cpp > CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.i

lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Aurora/source/memory/generic && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/Aurora/source/memory/generic/generic_utils.cpp -o CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.s

# Object files for target aurora_memory_generic
aurora_memory_generic_OBJECTS = \
"CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.o"

# External object files for target aurora_memory_generic
aurora_memory_generic_EXTERNAL_OBJECTS =

lib/libaurora_memory_generic_dbg.a: lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/generic_utils.cpp.o
lib/libaurora_memory_generic_dbg.a: lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/build.make
lib/libaurora_memory_generic_dbg.a: lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../../libaurora_memory_generic_dbg.a"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Aurora/source/memory/generic && $(CMAKE_COMMAND) -P CMakeFiles/aurora_memory_generic.dir/cmake_clean_target.cmake
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Aurora/source/memory/generic && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aurora_memory_generic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/build: lib/libaurora_memory_generic_dbg.a
.PHONY : lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/build

lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/clean:
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Aurora/source/memory/generic && $(CMAKE_COMMAND) -P CMakeFiles/aurora_memory_generic.dir/cmake_clean.cmake
.PHONY : lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/clean

lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/depend:
	cd /home/braunbr/git/Projects/Valkyrie/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/braunbr/git/Projects/Valkyrie /home/braunbr/git/Projects/Valkyrie/lib/Aurora/source/memory/generic /home/braunbr/git/Projects/Valkyrie/build /home/braunbr/git/Projects/Valkyrie/build/lib/Aurora/source/memory/generic /home/braunbr/git/Projects/Valkyrie/build/lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Aurora/source/memory/generic/CMakeFiles/aurora_memory_generic.dir/depend

