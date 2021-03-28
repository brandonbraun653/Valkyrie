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
include lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/progress.make

# Include the compile flags for this target's objects.
include lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/flags.make

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/croutine.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/flags.make
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/croutine.c.o: ../lib/FreeRTOS/src/croutine.c
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/croutine.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/croutine.c.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/croutine.c.o -MF CMakeFiles/freertos_core_dbg.dir/croutine.c.o.d -o CMakeFiles/freertos_core_dbg.dir/croutine.c.o -c /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/croutine.c

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/croutine.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/freertos_core_dbg.dir/croutine.c.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/croutine.c > CMakeFiles/freertos_core_dbg.dir/croutine.c.i

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/croutine.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/freertos_core_dbg.dir/croutine.c.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/croutine.c -o CMakeFiles/freertos_core_dbg.dir/croutine.c.s

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/event_groups.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/flags.make
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/event_groups.c.o: ../lib/FreeRTOS/src/event_groups.c
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/event_groups.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/event_groups.c.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/event_groups.c.o -MF CMakeFiles/freertos_core_dbg.dir/event_groups.c.o.d -o CMakeFiles/freertos_core_dbg.dir/event_groups.c.o -c /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/event_groups.c

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/event_groups.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/freertos_core_dbg.dir/event_groups.c.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/event_groups.c > CMakeFiles/freertos_core_dbg.dir/event_groups.c.i

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/event_groups.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/freertos_core_dbg.dir/event_groups.c.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/event_groups.c -o CMakeFiles/freertos_core_dbg.dir/event_groups.c.s

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/list.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/flags.make
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/list.c.o: ../lib/FreeRTOS/src/list.c
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/list.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/list.c.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/list.c.o -MF CMakeFiles/freertos_core_dbg.dir/list.c.o.d -o CMakeFiles/freertos_core_dbg.dir/list.c.o -c /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/list.c

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/freertos_core_dbg.dir/list.c.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/list.c > CMakeFiles/freertos_core_dbg.dir/list.c.i

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/freertos_core_dbg.dir/list.c.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/list.c -o CMakeFiles/freertos_core_dbg.dir/list.c.s

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/queue.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/flags.make
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/queue.c.o: ../lib/FreeRTOS/src/queue.c
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/queue.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/queue.c.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/queue.c.o -MF CMakeFiles/freertos_core_dbg.dir/queue.c.o.d -o CMakeFiles/freertos_core_dbg.dir/queue.c.o -c /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/queue.c

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/freertos_core_dbg.dir/queue.c.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/queue.c > CMakeFiles/freertos_core_dbg.dir/queue.c.i

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/freertos_core_dbg.dir/queue.c.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/queue.c -o CMakeFiles/freertos_core_dbg.dir/queue.c.s

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/flags.make
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.o: ../lib/FreeRTOS/src/stream_buffer.c
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.o -MF CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.o.d -o CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.o -c /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/stream_buffer.c

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/stream_buffer.c > CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.i

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/stream_buffer.c -o CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.s

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/tasks.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/flags.make
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/tasks.c.o: ../lib/FreeRTOS/src/tasks.c
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/tasks.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/tasks.c.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/tasks.c.o -MF CMakeFiles/freertos_core_dbg.dir/tasks.c.o.d -o CMakeFiles/freertos_core_dbg.dir/tasks.c.o -c /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/tasks.c

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/tasks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/freertos_core_dbg.dir/tasks.c.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/tasks.c > CMakeFiles/freertos_core_dbg.dir/tasks.c.i

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/tasks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/freertos_core_dbg.dir/tasks.c.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/tasks.c -o CMakeFiles/freertos_core_dbg.dir/tasks.c.s

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/timers.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/flags.make
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/timers.c.o: ../lib/FreeRTOS/src/timers.c
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/timers.c.o: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/timers.c.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/timers.c.o -MF CMakeFiles/freertos_core_dbg.dir/timers.c.o.d -o CMakeFiles/freertos_core_dbg.dir/timers.c.o -c /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/timers.c

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/timers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/freertos_core_dbg.dir/timers.c.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/timers.c > CMakeFiles/freertos_core_dbg.dir/timers.c.i

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/timers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/freertos_core_dbg.dir/timers.c.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src/timers.c -o CMakeFiles/freertos_core_dbg.dir/timers.c.s

# Object files for target freertos_core_dbg
freertos_core_dbg_OBJECTS = \
"CMakeFiles/freertos_core_dbg.dir/croutine.c.o" \
"CMakeFiles/freertos_core_dbg.dir/event_groups.c.o" \
"CMakeFiles/freertos_core_dbg.dir/list.c.o" \
"CMakeFiles/freertos_core_dbg.dir/queue.c.o" \
"CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.o" \
"CMakeFiles/freertos_core_dbg.dir/tasks.c.o" \
"CMakeFiles/freertos_core_dbg.dir/timers.c.o"

# External object files for target freertos_core_dbg
freertos_core_dbg_EXTERNAL_OBJECTS =

lib/libfreertos_core_dbg_dbg.a: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/croutine.c.o
lib/libfreertos_core_dbg_dbg.a: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/event_groups.c.o
lib/libfreertos_core_dbg_dbg.a: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/list.c.o
lib/libfreertos_core_dbg_dbg.a: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/queue.c.o
lib/libfreertos_core_dbg_dbg.a: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/stream_buffer.c.o
lib/libfreertos_core_dbg_dbg.a: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/tasks.c.o
lib/libfreertos_core_dbg_dbg.a: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/timers.c.o
lib/libfreertos_core_dbg_dbg.a: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/build.make
lib/libfreertos_core_dbg_dbg.a: lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C static library ../../libfreertos_core_dbg_dbg.a"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && $(CMAKE_COMMAND) -P CMakeFiles/freertos_core_dbg.dir/cmake_clean_target.cmake
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/freertos_core_dbg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/build: lib/libfreertos_core_dbg_dbg.a
.PHONY : lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/build

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/clean:
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src && $(CMAKE_COMMAND) -P CMakeFiles/freertos_core_dbg.dir/cmake_clean.cmake
.PHONY : lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/clean

lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/depend:
	cd /home/braunbr/git/Projects/Valkyrie/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/braunbr/git/Projects/Valkyrie /home/braunbr/git/Projects/Valkyrie/lib/FreeRTOS/src /home/braunbr/git/Projects/Valkyrie/build /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src /home/braunbr/git/Projects/Valkyrie/build/lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/FreeRTOS/src/CMakeFiles/freertos_core_dbg.dir/depend

