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

# Utility rule file for BizServer-upload.

# Include the progress variables for this target.
include src/CMakeFiles/BizServer-upload.dir/progress.make

src/CMakeFiles/BizServer-upload:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/root/BizServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "upload TodoApp.BizServer.tgz and publish..."
	/usr/bin/cmake -P /root/BizServer/build/src/run-upload-BizServer.cmake

BizServer-upload: src/CMakeFiles/BizServer-upload
BizServer-upload: src/CMakeFiles/BizServer-upload.dir/build.make

.PHONY : BizServer-upload

# Rule to build all files generated by this target.
src/CMakeFiles/BizServer-upload.dir/build: BizServer-upload

.PHONY : src/CMakeFiles/BizServer-upload.dir/build

src/CMakeFiles/BizServer-upload.dir/clean:
	cd /root/BizServer/build/src && $(CMAKE_COMMAND) -P CMakeFiles/BizServer-upload.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/BizServer-upload.dir/clean

src/CMakeFiles/BizServer-upload.dir/depend:
	cd /root/BizServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/BizServer /root/BizServer/src /root/BizServer/build /root/BizServer/build/src /root/BizServer/build/src/CMakeFiles/BizServer-upload.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/BizServer-upload.dir/depend

