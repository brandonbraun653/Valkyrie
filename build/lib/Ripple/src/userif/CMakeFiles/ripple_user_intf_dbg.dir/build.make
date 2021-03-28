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
include lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/progress.make

# Include the compile flags for this target's objects.
include lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/flags.make

lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.o: lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/flags.make
lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.o: ../lib/Ripple/src/userif/user_init.cpp
lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.o: lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.o"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Ripple/src/userif && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.o -MF CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.o.d -o CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.o -c /home/braunbr/git/Projects/Valkyrie/lib/Ripple/src/userif/user_init.cpp

lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.i"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Ripple/src/userif && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/braunbr/git/Projects/Valkyrie/lib/Ripple/src/userif/user_init.cpp > CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.i

lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.s"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Ripple/src/userif && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/braunbr/git/Projects/Valkyrie/lib/Ripple/src/userif/user_init.cpp -o CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.s

# Object files for target ripple_user_intf_dbg
ripple_user_intf_dbg_OBJECTS = \
"CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.o"

# External object files for target ripple_user_intf_dbg
ripple_user_intf_dbg_EXTERNAL_OBJECTS =

lib/libripple_user_intf_dbg_dbg.a: lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/user_init.cpp.o
lib/libripple_user_intf_dbg_dbg.a: lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/build.make
lib/libripple_user_intf_dbg_dbg.a: lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/braunbr/git/Projects/Valkyrie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../libripple_user_intf_dbg_dbg.a"
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Ripple/src/userif && $(CMAKE_COMMAND) -P CMakeFiles/ripple_user_intf_dbg.dir/cmake_clean_target.cmake
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Ripple/src/userif && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ripple_user_intf_dbg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/build: lib/libripple_user_intf_dbg_dbg.a
.PHONY : lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/build

lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/clean:
	cd /home/braunbr/git/Projects/Valkyrie/build/lib/Ripple/src/userif && $(CMAKE_COMMAND) -P CMakeFiles/ripple_user_intf_dbg.dir/cmake_clean.cmake
.PHONY : lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/clean

lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/depend:
	cd /home/braunbr/git/Projects/Valkyrie/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/braunbr/git/Projects/Valkyrie /home/braunbr/git/Projects/Valkyrie/lib/Ripple/src/userif /home/braunbr/git/Projects/Valkyrie/build /home/braunbr/git/Projects/Valkyrie/build/lib/Ripple/src/userif /home/braunbr/git/Projects/Valkyrie/build/lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Ripple/src/userif/CMakeFiles/ripple_user_intf_dbg.dir/depend

