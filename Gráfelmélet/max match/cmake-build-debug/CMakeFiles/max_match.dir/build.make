# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Egyetem\Programming\Graph\max match"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Egyetem\Programming\Graph\max match\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/max_match.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/max_match.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/max_match.dir/flags.make

CMakeFiles/max_match.dir/main.c.obj: CMakeFiles/max_match.dir/flags.make
CMakeFiles/max_match.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Egyetem\Programming\Graph\max match\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/max_match.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\max_match.dir\main.c.obj   -c "D:\Egyetem\Programming\Graph\max match\main.c"

CMakeFiles/max_match.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/max_match.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Egyetem\Programming\Graph\max match\main.c" > CMakeFiles\max_match.dir\main.c.i

CMakeFiles/max_match.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/max_match.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Egyetem\Programming\Graph\max match\main.c" -o CMakeFiles\max_match.dir\main.c.s

CMakeFiles/max_match.dir/main.c.obj.requires:

.PHONY : CMakeFiles/max_match.dir/main.c.obj.requires

CMakeFiles/max_match.dir/main.c.obj.provides: CMakeFiles/max_match.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\max_match.dir\build.make CMakeFiles/max_match.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/max_match.dir/main.c.obj.provides

CMakeFiles/max_match.dir/main.c.obj.provides.build: CMakeFiles/max_match.dir/main.c.obj


# Object files for target max_match
max_match_OBJECTS = \
"CMakeFiles/max_match.dir/main.c.obj"

# External object files for target max_match
max_match_EXTERNAL_OBJECTS =

max_match.exe: CMakeFiles/max_match.dir/main.c.obj
max_match.exe: CMakeFiles/max_match.dir/build.make
max_match.exe: CMakeFiles/max_match.dir/linklibs.rsp
max_match.exe: CMakeFiles/max_match.dir/objects1.rsp
max_match.exe: CMakeFiles/max_match.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Egyetem\Programming\Graph\max match\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable max_match.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\max_match.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/max_match.dir/build: max_match.exe

.PHONY : CMakeFiles/max_match.dir/build

CMakeFiles/max_match.dir/requires: CMakeFiles/max_match.dir/main.c.obj.requires

.PHONY : CMakeFiles/max_match.dir/requires

CMakeFiles/max_match.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\max_match.dir\cmake_clean.cmake
.PHONY : CMakeFiles/max_match.dir/clean

CMakeFiles/max_match.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Egyetem\Programming\Graph\max match" "D:\Egyetem\Programming\Graph\max match" "D:\Egyetem\Programming\Graph\max match\cmake-build-debug" "D:\Egyetem\Programming\Graph\max match\cmake-build-debug" "D:\Egyetem\Programming\Graph\max match\cmake-build-debug\CMakeFiles\max_match.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/max_match.dir/depend

