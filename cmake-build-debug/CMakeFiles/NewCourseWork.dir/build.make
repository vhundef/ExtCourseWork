# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/vhundef/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.5728.100/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/vhundef/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.5728.100/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vhundef/CLionProjects/NewCourseWork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vhundef/CLionProjects/NewCourseWork/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NewCourseWork.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NewCourseWork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NewCourseWork.dir/flags.make

CMakeFiles/NewCourseWork.dir/main.cpp.o: CMakeFiles/NewCourseWork.dir/flags.make
CMakeFiles/NewCourseWork.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vhundef/CLionProjects/NewCourseWork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NewCourseWork.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NewCourseWork.dir/main.cpp.o -c /home/vhundef/CLionProjects/NewCourseWork/main.cpp

CMakeFiles/NewCourseWork.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NewCourseWork.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vhundef/CLionProjects/NewCourseWork/main.cpp > CMakeFiles/NewCourseWork.dir/main.cpp.i

CMakeFiles/NewCourseWork.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NewCourseWork.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vhundef/CLionProjects/NewCourseWork/main.cpp -o CMakeFiles/NewCourseWork.dir/main.cpp.s

# Object files for target NewCourseWork
NewCourseWork_OBJECTS = \
"CMakeFiles/NewCourseWork.dir/main.cpp.o"

# External object files for target NewCourseWork
NewCourseWork_EXTERNAL_OBJECTS =

NewCourseWork: CMakeFiles/NewCourseWork.dir/main.cpp.o
NewCourseWork: CMakeFiles/NewCourseWork.dir/build.make
NewCourseWork: CMakeFiles/NewCourseWork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vhundef/CLionProjects/NewCourseWork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NewCourseWork"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NewCourseWork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NewCourseWork.dir/build: NewCourseWork

.PHONY : CMakeFiles/NewCourseWork.dir/build

CMakeFiles/NewCourseWork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NewCourseWork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NewCourseWork.dir/clean

CMakeFiles/NewCourseWork.dir/depend:
	cd /home/vhundef/CLionProjects/NewCourseWork/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vhundef/CLionProjects/NewCourseWork /home/vhundef/CLionProjects/NewCourseWork /home/vhundef/CLionProjects/NewCourseWork/cmake-build-debug /home/vhundef/CLionProjects/NewCourseWork/cmake-build-debug /home/vhundef/CLionProjects/NewCourseWork/cmake-build-debug/CMakeFiles/NewCourseWork.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NewCourseWork.dir/depend

