# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/admin/C++_Network

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/admin/C++_Network/cmake-build-debug

# Include any dependencies generated for this target.
include applications/Echo/CMakeFiles/echo_client.dir/depend.make

# Include the progress variables for this target.
include applications/Echo/CMakeFiles/echo_client.dir/progress.make

# Include the compile flags for this target's objects.
include applications/Echo/CMakeFiles/echo_client.dir/flags.make

applications/Echo/CMakeFiles/echo_client.dir/EchoClient.cpp.o: applications/Echo/CMakeFiles/echo_client.dir/flags.make
applications/Echo/CMakeFiles/echo_client.dir/EchoClient.cpp.o: ../applications/Echo/EchoClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/C++_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object applications/Echo/CMakeFiles/echo_client.dir/EchoClient.cpp.o"
	cd /Users/admin/C++_Network/cmake-build-debug/applications/Echo && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/echo_client.dir/EchoClient.cpp.o -c /Users/admin/C++_Network/applications/Echo/EchoClient.cpp

applications/Echo/CMakeFiles/echo_client.dir/EchoClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/echo_client.dir/EchoClient.cpp.i"
	cd /Users/admin/C++_Network/cmake-build-debug/applications/Echo && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/admin/C++_Network/applications/Echo/EchoClient.cpp > CMakeFiles/echo_client.dir/EchoClient.cpp.i

applications/Echo/CMakeFiles/echo_client.dir/EchoClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/echo_client.dir/EchoClient.cpp.s"
	cd /Users/admin/C++_Network/cmake-build-debug/applications/Echo && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/admin/C++_Network/applications/Echo/EchoClient.cpp -o CMakeFiles/echo_client.dir/EchoClient.cpp.s

# Object files for target echo_client
echo_client_OBJECTS = \
"CMakeFiles/echo_client.dir/EchoClient.cpp.o"

# External object files for target echo_client
echo_client_EXTERNAL_OBJECTS =

applications/Echo/echo_client: applications/Echo/CMakeFiles/echo_client.dir/EchoClient.cpp.o
applications/Echo/echo_client: applications/Echo/CMakeFiles/echo_client.dir/build.make
applications/Echo/echo_client: netlib/libnetlib.a
applications/Echo/echo_client: applications/Echo/CMakeFiles/echo_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/admin/C++_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable echo_client"
	cd /Users/admin/C++_Network/cmake-build-debug/applications/Echo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/echo_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
applications/Echo/CMakeFiles/echo_client.dir/build: applications/Echo/echo_client

.PHONY : applications/Echo/CMakeFiles/echo_client.dir/build

applications/Echo/CMakeFiles/echo_client.dir/clean:
	cd /Users/admin/C++_Network/cmake-build-debug/applications/Echo && $(CMAKE_COMMAND) -P CMakeFiles/echo_client.dir/cmake_clean.cmake
.PHONY : applications/Echo/CMakeFiles/echo_client.dir/clean

applications/Echo/CMakeFiles/echo_client.dir/depend:
	cd /Users/admin/C++_Network/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/admin/C++_Network /Users/admin/C++_Network/applications/Echo /Users/admin/C++_Network/cmake-build-debug /Users/admin/C++_Network/cmake-build-debug/applications/Echo /Users/admin/C++_Network/cmake-build-debug/applications/Echo/CMakeFiles/echo_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : applications/Echo/CMakeFiles/echo_client.dir/depend

