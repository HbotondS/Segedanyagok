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
CMAKE_SOURCE_DIR = D:\Egyetem\Programming\Graph\Ford-Fulkerson

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Egyetem\Programming\Graph\Ford-Fulkerson\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ford_Fulkerson.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ford_Fulkerson.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ford_Fulkerson.dir/flags.make

CMakeFiles/Ford_Fulkerson.dir/main.c.obj: CMakeFiles/Ford_Fulkerson.dir/flags.make
CMakeFiles/Ford_Fulkerson.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Egyetem\Programming\Graph\Ford-Fulkerson\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Ford_Fulkerson.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Ford_Fulkerson.dir\main.c.obj   -c D:\Egyetem\Programming\Graph\Ford-Fulkerson\main.c

CMakeFiles/Ford_Fulkerson.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ford_Fulkerson.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Egyetem\Programming\Graph\Ford-Fulkerson\main.c > CMakeFiles\Ford_Fulkerson.dir\main.c.i

CMakeFiles/Ford_Fulkerson.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ford_Fulkerson.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Egyetem\Programming\Graph\Ford-Fulkerson\main.c -o CMakeFiles\Ford_Fulkerson.dir\main.c.s

CMakeFiles/Ford_Fulkerson.dir/main.c.obj.requires:

.PHONY : CMakeFiles/Ford_Fulkerson.dir/main.c.obj.requires

CMakeFiles/Ford_Fulkerson.dir/main.c.obj.provides: CMakeFiles/Ford_Fulkerson.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\Ford_Fulkerson.dir\build.make CMakeFiles/Ford_Fulkerson.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/Ford_Fulkerson.dir/main.c.obj.provides

CMakeFiles/Ford_Fulkerson.dir/main.c.obj.provides.build: CMakeFiles/Ford_Fulkerson.dir/main.c.obj


# Object files for target Ford_Fulkerson
Ford_Fulkerson_OBJECTS = \
"CMakeFiles/Ford_Fulkerson.dir/main.c.obj"

# External object files for target Ford_Fulkerson
Ford_Fulkerson_EXTERNAL_OBJECTS =

Ford_Fulkerson.exe: CMakeFiles/Ford_Fulkerson.dir/main.c.obj
Ford_Fulkerson.exe: CMakeFiles/Ford_Fulkerson.dir/build.make
Ford_Fulkerson.exe: CMakeFiles/Ford_Fulkerson.dir/linklibs.rsp
Ford_Fulkerson.exe: CMakeFiles/Ford_Fulkerson.dir/objects1.rsp
Ford_Fulkerson.exe: CMakeFiles/Ford_Fulkerson.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Egyetem\Programming\Graph\Ford-Fulkerson\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Ford_Fulkerson.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ford_Fulkerson.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ford_Fulkerson.dir/build: Ford_Fulkerson.exe

.PHONY : CMakeFiles/Ford_Fulkerson.dir/build

CMakeFiles/Ford_Fulkerson.dir/requires: CMakeFiles/Ford_Fulkerson.dir/main.c.obj.requires

.PHONY : CMakeFiles/Ford_Fulkerson.dir/requires

CMakeFiles/Ford_Fulkerson.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ford_Fulkerson.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ford_Fulkerson.dir/clean

CMakeFiles/Ford_Fulkerson.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Egyetem\Programming\Graph\Ford-Fulkerson D:\Egyetem\Programming\Graph\Ford-Fulkerson D:\Egyetem\Programming\Graph\Ford-Fulkerson\cmake-build-debug D:\Egyetem\Programming\Graph\Ford-Fulkerson\cmake-build-debug D:\Egyetem\Programming\Graph\Ford-Fulkerson\cmake-build-debug\CMakeFiles\Ford_Fulkerson.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ford_Fulkerson.dir/depend

