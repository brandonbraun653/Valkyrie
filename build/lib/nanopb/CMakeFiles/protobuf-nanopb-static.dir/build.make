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
include lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/progress.make

# Include the compile flags for this target's objects.
include lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/flags.make

lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.o: lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/flags.make
lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.o: ../lib/nanopb/pb_common.c
lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.o: lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.o -MF CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.o.d -o CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.o -c /home/braunbr/git/Projects/Valkyrie/lib/nanopb/pb_common.c

lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/nanopb/pb_common.c > CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.i

lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/nanopb/pb_common.c -o CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.s

lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.o: lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/flags.make
lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.o: ../lib/nanopb/pb_encode.c
lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.o: lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.o -MF CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.o.d -o CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.o -c /home/braunbr/git/Projects/Valkyrie/lib/nanopb/pb_encode.c

lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/nanopb/pb_encode.c > CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.i

lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/nanopb/pb_encode.c -o CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.s

lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.o: lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/flags.make
lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.o: ../lib/nanopb/pb_decode.c
lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.o: lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.o -MF CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.o.d -o CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.o -c /home/braunbr/git/Projects/Valkyrie/lib/nanopb/pb_decode.c

lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/nanopb/pb_decode.c > CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.i

lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/nanopb/pb_decode.c -o CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.s

# Object files for target protobuf-nanopb-static
protobuf__nanopb__static_OBJECTS = \
"CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.o" \
"CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.o" \
"CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.o"

# External object files for target protobuf-nanopb-static
protobuf__nanopb__static_EXTERNAL_OBJECTS =

lib/libprotobuf-nanopb_dbg.a: lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_common.c.o
lib/libprotobuf-nanopb_dbg.a: lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_encode.c.o
lib/libprotobuf-nanopb_dbg.a: lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/pb_decode.c.o
lib/libprotobuf-nanopb_dbg.a: lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/build.make
lib/libprotobuf-nanopb_dbg.a: lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library ../libprotobuf-nanopb_dbg.a"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb && $(CMAKE_COMMAND) -P CMakeFiles/protobuf-nanopb-static.dir/cmake_clean_target.cmake
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/protobuf-nanopb-static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/build: lib/libprotobuf-nanopb_dbg.a
.PHONY : lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/build

lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/clean:
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb && $(CMAKE_COMMAND) -P CMakeFiles/protobuf-nanopb-static.dir/cmake_clean.cmake
.PHONY : lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/clean

lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/depend:
	cd /home/braunbr/git/Projects/Valkyrie/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/braunbr/git/Projects/Valkyrie /home/braunbr/git/Projects/Valkyrie/lib/nanopb /home/braunbr/git/Projects/Valkyrie/build /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb /home/braunbr/git/Projects/Valkyrie/build/lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/nanopb/CMakeFiles/protobuf-nanopb-static.dir/depend

