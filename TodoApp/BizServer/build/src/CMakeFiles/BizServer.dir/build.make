# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/BizServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/BizServer/build

# Include any dependencies generated for this target.
include src/CMakeFiles/BizServer.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/BizServer.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/BizServer.dir/flags.make

src/CMakeFiles/BizServer.dir/BizServer.cpp.o: src/CMakeFiles/BizServer.dir/flags.make
src/CMakeFiles/BizServer.dir/BizServer.cpp.o: ../src/BizServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/BizServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/BizServer.dir/BizServer.cpp.o"
	cd /root/BizServer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BizServer.dir/BizServer.cpp.o -c /root/BizServer/src/BizServer.cpp

src/CMakeFiles/BizServer.dir/BizServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BizServer.dir/BizServer.cpp.i"
	cd /root/BizServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/BizServer/src/BizServer.cpp > CMakeFiles/BizServer.dir/BizServer.cpp.i

src/CMakeFiles/BizServer.dir/BizServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BizServer.dir/BizServer.cpp.s"
	cd /root/BizServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/BizServer/src/BizServer.cpp -o CMakeFiles/BizServer.dir/BizServer.cpp.s

src/CMakeFiles/BizServer.dir/TodoTarsObjImp.cpp.o: src/CMakeFiles/BizServer.dir/flags.make
src/CMakeFiles/BizServer.dir/TodoTarsObjImp.cpp.o: ../src/TodoTarsObjImp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/BizServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/BizServer.dir/TodoTarsObjImp.cpp.o"
	cd /root/BizServer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BizServer.dir/TodoTarsObjImp.cpp.o -c /root/BizServer/src/TodoTarsObjImp.cpp

src/CMakeFiles/BizServer.dir/TodoTarsObjImp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BizServer.dir/TodoTarsObjImp.cpp.i"
	cd /root/BizServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/BizServer/src/TodoTarsObjImp.cpp > CMakeFiles/BizServer.dir/TodoTarsObjImp.cpp.i

src/CMakeFiles/BizServer.dir/TodoTarsObjImp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BizServer.dir/TodoTarsObjImp.cpp.s"
	cd /root/BizServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/BizServer/src/TodoTarsObjImp.cpp -o CMakeFiles/BizServer.dir/TodoTarsObjImp.cpp.s

# Object files for target BizServer
BizServer_OBJECTS = \
"CMakeFiles/BizServer.dir/BizServer.cpp.o" \
"CMakeFiles/BizServer.dir/TodoTarsObjImp.cpp.o"

# External object files for target BizServer
BizServer_EXTERNAL_OBJECTS =

bin/BizServer: src/CMakeFiles/BizServer.dir/BizServer.cpp.o
bin/BizServer: src/CMakeFiles/BizServer.dir/TodoTarsObjImp.cpp.o
bin/BizServer: src/CMakeFiles/BizServer.dir/build.make
bin/BizServer: /usr/local/tars/cpp/lib/libtarsservant.a
bin/BizServer: /usr/local/tars/cpp/lib/libtarsutil.a
bin/BizServer: src/CMakeFiles/BizServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/BizServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/BizServer"
	cd /root/BizServer/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BizServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/BizServer.dir/build: bin/BizServer

.PHONY : src/CMakeFiles/BizServer.dir/build

src/CMakeFiles/BizServer.dir/clean:
	cd /root/BizServer/build/src && $(CMAKE_COMMAND) -P CMakeFiles/BizServer.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/BizServer.dir/clean

src/CMakeFiles/BizServer.dir/depend:
	cd /root/BizServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/BizServer /root/BizServer/src /root/BizServer/build /root/BizServer/build/src /root/BizServer/build/src/CMakeFiles/BizServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/BizServer.dir/depend

