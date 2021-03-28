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
include lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/progress.make

# Include the compile flags for this target's objects.
include lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/flags.make

lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.o: lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/flags.make
lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.o: ../lib/FreeRTOS/portable/MemMang/heap_2.c
lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.o: lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/portable/MemMang && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.o -MF CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.o.d -o CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.o -c /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/portable/MemMang/heap_2.c

lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/portable/MemMang && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/portable/MemMang/heap_2.c > CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.i

lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/portable/MemMang && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/portable/MemMang/heap_2.c -o CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.s

# Object files for target freertos_heap_2_dbg
freertos_heap_2_dbg_OBJECTS = \
"CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.o"

# External object files for target freertos_heap_2_dbg
freertos_heap_2_dbg_EXTERNAL_OBJECTS =

lib/libfreertos_heap_2_dbg_dbg.a: lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/heap_2.c.o
lib/libfreertos_heap_2_dbg_dbg.a: lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/build.make
lib/libfreertos_heap_2_dbg_dbg.a: lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../../libfreertos_heap_2_dbg_dbg.a"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/portable/MemMang && $(CMAKE_COMMAND) -P CMakeFiles/freertos_heap_2_dbg.dir/cmake_clean_target.cmake
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/portable/MemMang && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/freertos_heap_2_dbg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/build: lib/libfreertos_heap_2_dbg_dbg.a
.PHONY : lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/build

lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/clean:
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/portable/MemMang && $(CMAKE_COMMAND) -P CMakeFiles/freertos_heap_2_dbg.dir/cmake_clean.cmake
.PHONY : lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/clean

lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/depend:
	cd /home/braunbr/git/Projects/Valkyrie/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/braunbr/git/Projects/Valkyrie /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/portable/MemMang /home/braunbr/git/Projects/Valkyrie/build /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/portable/MemMang /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/FreeRTOS/portable/MemMang/CMakeFiles/freertos_heap_2_dbg.dir/depend

