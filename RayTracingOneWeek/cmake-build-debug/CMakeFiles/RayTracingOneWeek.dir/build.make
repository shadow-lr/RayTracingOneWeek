# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = B:\ClionProjects\RayTracingOneWeek

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = B:\ClionProjects\RayTracingOneWeek\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RayTracingOneWeek.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RayTracingOneWeek.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RayTracingOneWeek.dir/flags.make

CMakeFiles/RayTracingOneWeek.dir/main.cpp.obj: CMakeFiles/RayTracingOneWeek.dir/flags.make
CMakeFiles/RayTracingOneWeek.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=B:\ClionProjects\RayTracingOneWeek\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RayTracingOneWeek.dir/main.cpp.obj"
	B:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RayTracingOneWeek.dir\main.cpp.obj -c B:\ClionProjects\RayTracingOneWeek\main.cpp

CMakeFiles/RayTracingOneWeek.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracingOneWeek.dir/main.cpp.i"
	B:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E B:\ClionProjects\RayTracingOneWeek\main.cpp > CMakeFiles\RayTracingOneWeek.dir\main.cpp.i

CMakeFiles/RayTracingOneWeek.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracingOneWeek.dir/main.cpp.s"
	B:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S B:\ClionProjects\RayTracingOneWeek\main.cpp -o CMakeFiles\RayTracingOneWeek.dir\main.cpp.s

# Object files for target RayTracingOneWeek
RayTracingOneWeek_OBJECTS = \
"CMakeFiles/RayTracingOneWeek.dir/main.cpp.obj"

# External object files for target RayTracingOneWeek
RayTracingOneWeek_EXTERNAL_OBJECTS =

RayTracingOneWeek.exe: CMakeFiles/RayTracingOneWeek.dir/main.cpp.obj
RayTracingOneWeek.exe: CMakeFiles/RayTracingOneWeek.dir/build.make
RayTracingOneWeek.exe: CMakeFiles/RayTracingOneWeek.dir/linklibs.rsp
RayTracingOneWeek.exe: CMakeFiles/RayTracingOneWeek.dir/objects1.rsp
RayTracingOneWeek.exe: CMakeFiles/RayTracingOneWeek.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=B:\ClionProjects\RayTracingOneWeek\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RayTracingOneWeek.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RayTracingOneWeek.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RayTracingOneWeek.dir/build: RayTracingOneWeek.exe

.PHONY : CMakeFiles/RayTracingOneWeek.dir/build

CMakeFiles/RayTracingOneWeek.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RayTracingOneWeek.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RayTracingOneWeek.dir/clean

CMakeFiles/RayTracingOneWeek.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" B:\ClionProjects\RayTracingOneWeek B:\ClionProjects\RayTracingOneWeek B:\ClionProjects\RayTracingOneWeek\cmake-build-debug B:\ClionProjects\RayTracingOneWeek\cmake-build-debug B:\ClionProjects\RayTracingOneWeek\cmake-build-debug\CMakeFiles\RayTracingOneWeek.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RayTracingOneWeek.dir/depend

