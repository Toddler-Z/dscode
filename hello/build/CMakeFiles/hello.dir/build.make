# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/86159/Desktop/dscode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/86159/Desktop/dscode/build

# Include any dependencies generated for this target.
include CMakeFiles/hello.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hello.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello.dir/flags.make

CMakeFiles/hello.dir/hello.obj: CMakeFiles/hello.dir/flags.make
CMakeFiles/hello.dir/hello.obj: C:/Users/86159/Desktop/dscode/hello.cpp
CMakeFiles/hello.dir/hello.obj: CMakeFiles/hello.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/86159/Desktop/dscode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello.dir/hello.obj"
	C:/TDM-GCC-64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hello.dir/hello.obj -MF CMakeFiles/hello.dir/hello.obj.d -o CMakeFiles/hello.dir/hello.obj -c C:/Users/86159/Desktop/dscode/hello.cpp

CMakeFiles/hello.dir/hello.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/hello.dir/hello.i"
	C:/TDM-GCC-64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/86159/Desktop/dscode/hello.cpp > CMakeFiles/hello.dir/hello.i

CMakeFiles/hello.dir/hello.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/hello.dir/hello.s"
	C:/TDM-GCC-64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/86159/Desktop/dscode/hello.cpp -o CMakeFiles/hello.dir/hello.s

# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/hello.obj"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

hello.exe: CMakeFiles/hello.dir/hello.obj
hello.exe: CMakeFiles/hello.dir/build.make
hello.exe: CMakeFiles/hello.dir/linkLibs.rsp
hello.exe: CMakeFiles/hello.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:/Users/86159/Desktop/dscode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/hello.dir/objects.a
	C:/TDM-GCC-64/bin/ar.exe qc CMakeFiles/hello.dir/objects.a @CMakeFiles/hello.dir/objects1.rsp
	C:/TDM-GCC-64/bin/g++.exe -g -Wl,--whole-archive CMakeFiles/hello.dir/objects.a -Wl,--no-whole-archive -o hello.exe -Wl,--out-implib,libhello.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/hello.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/hello.dir/build: hello.exe
.PHONY : CMakeFiles/hello.dir/build

CMakeFiles/hello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello.dir/clean

CMakeFiles/hello.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/86159/Desktop/dscode C:/Users/86159/Desktop/dscode C:/Users/86159/Desktop/dscode/build C:/Users/86159/Desktop/dscode/build C:/Users/86159/Desktop/dscode/build/CMakeFiles/hello.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/hello.dir/depend
