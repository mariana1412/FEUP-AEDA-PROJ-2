# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\maria\OneDrive\Ambiente de Trabalho\FEUP\2ano 1sem\AEDA\UghEats2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\maria\OneDrive\Ambiente de Trabalho\FEUP\2ano 1sem\AEDA\UghEats2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/UghEats2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UghEats2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UghEats2.dir/flags.make

CMakeFiles/UghEats2.dir/main.cpp.obj: CMakeFiles/UghEats2.dir/flags.make
CMakeFiles/UghEats2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\maria\OneDrive\Ambiente de Trabalho\FEUP\2ano 1sem\AEDA\UghEats2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UghEats2.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\UghEats2.dir\main.cpp.obj -c "C:\Users\maria\OneDrive\Ambiente de Trabalho\FEUP\2ano 1sem\AEDA\UghEats2\main.cpp"

CMakeFiles/UghEats2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UghEats2.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\maria\OneDrive\Ambiente de Trabalho\FEUP\2ano 1sem\AEDA\UghEats2\main.cpp" > CMakeFiles\UghEats2.dir\main.cpp.i

CMakeFiles/UghEats2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UghEats2.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\maria\OneDrive\Ambiente de Trabalho\FEUP\2ano 1sem\AEDA\UghEats2\main.cpp" -o CMakeFiles\UghEats2.dir\main.cpp.s

# Object files for target UghEats2
UghEats2_OBJECTS = \
"CMakeFiles/UghEats2.dir/main.cpp.obj"

# External object files for target UghEats2
UghEats2_EXTERNAL_OBJECTS =

UghEats2.exe: CMakeFiles/UghEats2.dir/main.cpp.obj
UghEats2.exe: CMakeFiles/UghEats2.dir/build.make
UghEats2.exe: CMakeFiles/UghEats2.dir/linklibs.rsp
UghEats2.exe: CMakeFiles/UghEats2.dir/objects1.rsp
UghEats2.exe: CMakeFiles/UghEats2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\maria\OneDrive\Ambiente de Trabalho\FEUP\2ano 1sem\AEDA\UghEats2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable UghEats2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\UghEats2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UghEats2.dir/build: UghEats2.exe

.PHONY : CMakeFiles/UghEats2.dir/build

CMakeFiles/UghEats2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\UghEats2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/UghEats2.dir/clean

CMakeFiles/UghEats2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\maria\OneDrive\Ambiente de Trabalho\FEUP\2ano 1sem\AEDA\UghEats2" "C:\Users\maria\OneDrive\Ambiente de Trabalho\FEUP\2ano 1sem\AEDA\UghEats2" "C:\Users\maria\OneDrive\Ambiente de Trabalho\FEUP\2ano 1sem\AEDA\UghEats2\cmake-build-debug" "C:\Users\maria\OneDrive\Ambiente de Trabalho\FEUP\2ano 1sem\AEDA\UghEats2\cmake-build-debug" "C:\Users\maria\OneDrive\Ambiente de Trabalho\FEUP\2ano 1sem\AEDA\UghEats2\cmake-build-debug\CMakeFiles\UghEats2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/UghEats2.dir/depend

