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
include CMakeFiles/pucch_f2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pucch_f2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pucch_f2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pucch_f2.dir/flags.make

CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.o: CMakeFiles/pucch_f2.dir/flags.make
CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.o: /home/dmitry/Рабочий\ стол/Github/pucch-f2/src/shared/awgn.cpp
CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.o: CMakeFiles/pucch_f2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/dmitry/Рабочий стол/Github/pucch-f2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.o -MF CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.o.d -o CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.o -c "/home/dmitry/Рабочий стол/Github/pucch-f2/src/shared/awgn.cpp"

CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/dmitry/Рабочий стол/Github/pucch-f2/src/shared/awgn.cpp" > CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.i

CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/dmitry/Рабочий стол/Github/pucch-f2/src/shared/awgn.cpp" -o CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.s

CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.o: CMakeFiles/pucch_f2.dir/flags.make
CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.o: /home/dmitry/Рабочий\ стол/Github/pucch-f2/src/shared/b_codec.cpp
CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.o: CMakeFiles/pucch_f2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/dmitry/Рабочий стол/Github/pucch-f2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.o -MF CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.o.d -o CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.o -c "/home/dmitry/Рабочий стол/Github/pucch-f2/src/shared/b_codec.cpp"

CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/dmitry/Рабочий стол/Github/pucch-f2/src/shared/b_codec.cpp" > CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.i

CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/dmitry/Рабочий стол/Github/pucch-f2/src/shared/b_codec.cpp" -o CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.s

CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.o: CMakeFiles/pucch_f2.dir/flags.make
CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.o: /home/dmitry/Рабочий\ стол/Github/pucch-f2/src/shared/orchest.cpp
CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.o: CMakeFiles/pucch_f2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/dmitry/Рабочий стол/Github/pucch-f2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.o -MF CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.o.d -o CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.o -c "/home/dmitry/Рабочий стол/Github/pucch-f2/src/shared/orchest.cpp"

CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/dmitry/Рабочий стол/Github/pucch-f2/src/shared/orchest.cpp" > CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.i

CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/dmitry/Рабочий стол/Github/pucch-f2/src/shared/orchest.cpp" -o CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.s

CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.o: CMakeFiles/pucch_f2.dir/flags.make
CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.o: /home/dmitry/Рабочий\ стол/Github/pucch-f2/src/shared/fmath/fmath.cpp
CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.o: CMakeFiles/pucch_f2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/dmitry/Рабочий стол/Github/pucch-f2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.o -MF CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.o.d -o CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.o -c "/home/dmitry/Рабочий стол/Github/pucch-f2/src/shared/fmath/fmath.cpp"

CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/dmitry/Рабочий стол/Github/pucch-f2/src/shared/fmath/fmath.cpp" > CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.i

CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/dmitry/Рабочий стол/Github/pucch-f2/src/shared/fmath/fmath.cpp" -o CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.s

CMakeFiles/pucch_f2.dir/src/app/main.cpp.o: CMakeFiles/pucch_f2.dir/flags.make
CMakeFiles/pucch_f2.dir/src/app/main.cpp.o: /home/dmitry/Рабочий\ стол/Github/pucch-f2/src/app/main.cpp
CMakeFiles/pucch_f2.dir/src/app/main.cpp.o: CMakeFiles/pucch_f2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/dmitry/Рабочий стол/Github/pucch-f2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pucch_f2.dir/src/app/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pucch_f2.dir/src/app/main.cpp.o -MF CMakeFiles/pucch_f2.dir/src/app/main.cpp.o.d -o CMakeFiles/pucch_f2.dir/src/app/main.cpp.o -c "/home/dmitry/Рабочий стол/Github/pucch-f2/src/app/main.cpp"

CMakeFiles/pucch_f2.dir/src/app/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pucch_f2.dir/src/app/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/dmitry/Рабочий стол/Github/pucch-f2/src/app/main.cpp" > CMakeFiles/pucch_f2.dir/src/app/main.cpp.i

CMakeFiles/pucch_f2.dir/src/app/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pucch_f2.dir/src/app/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/dmitry/Рабочий стол/Github/pucch-f2/src/app/main.cpp" -o CMakeFiles/pucch_f2.dir/src/app/main.cpp.s

# Object files for target pucch_f2
pucch_f2_OBJECTS = \
"CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.o" \
"CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.o" \
"CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.o" \
"CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.o" \
"CMakeFiles/pucch_f2.dir/src/app/main.cpp.o"

# External object files for target pucch_f2
pucch_f2_EXTERNAL_OBJECTS =

pucch_f2: CMakeFiles/pucch_f2.dir/src/shared/awgn.cpp.o
pucch_f2: CMakeFiles/pucch_f2.dir/src/shared/b_codec.cpp.o
pucch_f2: CMakeFiles/pucch_f2.dir/src/shared/orchest.cpp.o
pucch_f2: CMakeFiles/pucch_f2.dir/src/shared/fmath/fmath.cpp.o
pucch_f2: CMakeFiles/pucch_f2.dir/src/app/main.cpp.o
pucch_f2: CMakeFiles/pucch_f2.dir/build.make
pucch_f2: src/libs/matrix/libmatrix.a
pucch_f2: CMakeFiles/pucch_f2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/dmitry/Рабочий стол/Github/pucch-f2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable pucch_f2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pucch_f2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pucch_f2.dir/build: pucch_f2
.PHONY : CMakeFiles/pucch_f2.dir/build

CMakeFiles/pucch_f2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pucch_f2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pucch_f2.dir/clean

CMakeFiles/pucch_f2.dir/depend:
	cd "/home/dmitry/Рабочий стол/Github/pucch-f2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/dmitry/Рабочий стол/Github/pucch-f2" "/home/dmitry/Рабочий стол/Github/pucch-f2" "/home/dmitry/Рабочий стол/Github/pucch-f2/build" "/home/dmitry/Рабочий стол/Github/pucch-f2/build" "/home/dmitry/Рабочий стол/Github/pucch-f2/build/CMakeFiles/pucch_f2.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/pucch_f2.dir/depend

