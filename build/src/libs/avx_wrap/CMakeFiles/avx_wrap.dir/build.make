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
CMAKE_SOURCE_DIR = "/home/dmitry/Рабочий стол/Github/pucch-f2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/dmitry/Рабочий стол/Github/pucch-f2/build"

# Include any dependencies generated for this target.
include src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/compiler_depend.make

# Include the progress variables for this target.
include src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/progress.make

# Include the compile flags for this target's objects.
include src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/flags.make

src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.o: src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/flags.make
src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.o: /home/dmitry/Рабочий\ стол/Github/pucch-f2/src/libs/avx_wrap/src/avx_wrap.cpp
src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.o: src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/dmitry/Рабочий стол/Github/pucch-f2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.o"
	cd "/home/dmitry/Рабочий стол/Github/pucch-f2/build/src/libs/avx_wrap" && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.o -MF CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.o.d -o CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.o -c "/home/dmitry/Рабочий стол/Github/pucch-f2/src/libs/avx_wrap/src/avx_wrap.cpp"

src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.i"
	cd "/home/dmitry/Рабочий стол/Github/pucch-f2/build/src/libs/avx_wrap" && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/dmitry/Рабочий стол/Github/pucch-f2/src/libs/avx_wrap/src/avx_wrap.cpp" > CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.i

src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.s"
	cd "/home/dmitry/Рабочий стол/Github/pucch-f2/build/src/libs/avx_wrap" && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/dmitry/Рабочий стол/Github/pucch-f2/src/libs/avx_wrap/src/avx_wrap.cpp" -o CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.s

# Object files for target avx_wrap
avx_wrap_OBJECTS = \
"CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.o"

# External object files for target avx_wrap
avx_wrap_EXTERNAL_OBJECTS =

src/libs/avx_wrap/libavx_wrap.a: src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/src/avx_wrap.cpp.o
src/libs/avx_wrap/libavx_wrap.a: src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/build.make
src/libs/avx_wrap/libavx_wrap.a: src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/dmitry/Рабочий стол/Github/pucch-f2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libavx_wrap.a"
	cd "/home/dmitry/Рабочий стол/Github/pucch-f2/build/src/libs/avx_wrap" && $(CMAKE_COMMAND) -P CMakeFiles/avx_wrap.dir/cmake_clean_target.cmake
	cd "/home/dmitry/Рабочий стол/Github/pucch-f2/build/src/libs/avx_wrap" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/avx_wrap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/build: src/libs/avx_wrap/libavx_wrap.a
.PHONY : src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/build

src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/clean:
	cd "/home/dmitry/Рабочий стол/Github/pucch-f2/build/src/libs/avx_wrap" && $(CMAKE_COMMAND) -P CMakeFiles/avx_wrap.dir/cmake_clean.cmake
.PHONY : src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/clean

src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/depend:
	cd "/home/dmitry/Рабочий стол/Github/pucch-f2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/dmitry/Рабочий стол/Github/pucch-f2" "/home/dmitry/Рабочий стол/Github/pucch-f2/src/libs/avx_wrap" "/home/dmitry/Рабочий стол/Github/pucch-f2/build" "/home/dmitry/Рабочий стол/Github/pucch-f2/build/src/libs/avx_wrap" "/home/dmitry/Рабочий стол/Github/pucch-f2/build/src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : src/libs/avx_wrap/CMakeFiles/avx_wrap.dir/depend

