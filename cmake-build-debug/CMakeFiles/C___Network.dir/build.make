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
include CMakeFiles/C___Network.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C___Network.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C___Network.dir/flags.make

CMakeFiles/C___Network.dir/server.c.o: CMakeFiles/C___Network.dir/flags.make
CMakeFiles/C___Network.dir/server.c.o: ../server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/C++_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/C___Network.dir/server.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C___Network.dir/server.c.o   -c /Users/admin/C++_Network/server.c

CMakeFiles/C___Network.dir/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C___Network.dir/server.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/admin/C++_Network/server.c > CMakeFiles/C___Network.dir/server.c.i

CMakeFiles/C___Network.dir/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C___Network.dir/server.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/admin/C++_Network/server.c -o CMakeFiles/C___Network.dir/server.c.s

CMakeFiles/C___Network.dir/client.c.o: CMakeFiles/C___Network.dir/flags.make
CMakeFiles/C___Network.dir/client.c.o: ../client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/C++_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/C___Network.dir/client.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C___Network.dir/client.c.o   -c /Users/admin/C++_Network/client.c

CMakeFiles/C___Network.dir/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C___Network.dir/client.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/admin/C++_Network/client.c > CMakeFiles/C___Network.dir/client.c.i

CMakeFiles/C___Network.dir/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C___Network.dir/client.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/admin/C++_Network/client.c -o CMakeFiles/C___Network.dir/client.c.s

CMakeFiles/C___Network.dir/multiservers.c.o: CMakeFiles/C___Network.dir/flags.make
CMakeFiles/C___Network.dir/multiservers.c.o: ../multiservers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/C++_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/C___Network.dir/multiservers.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C___Network.dir/multiservers.c.o   -c /Users/admin/C++_Network/multiservers.c

CMakeFiles/C___Network.dir/multiservers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C___Network.dir/multiservers.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/admin/C++_Network/multiservers.c > CMakeFiles/C___Network.dir/multiservers.c.i

CMakeFiles/C___Network.dir/multiservers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C___Network.dir/multiservers.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/admin/C++_Network/multiservers.c -o CMakeFiles/C___Network.dir/multiservers.c.s

CMakeFiles/C___Network.dir/network/connection.cpp.o: CMakeFiles/C___Network.dir/flags.make
CMakeFiles/C___Network.dir/network/connection.cpp.o: ../network/connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/C++_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/C___Network.dir/network/connection.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/C___Network.dir/network/connection.cpp.o -c /Users/admin/C++_Network/network/connection.cpp

CMakeFiles/C___Network.dir/network/connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C___Network.dir/network/connection.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/admin/C++_Network/network/connection.cpp > CMakeFiles/C___Network.dir/network/connection.cpp.i

CMakeFiles/C___Network.dir/network/connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C___Network.dir/network/connection.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/admin/C++_Network/network/connection.cpp -o CMakeFiles/C___Network.dir/network/connection.cpp.s

CMakeFiles/C___Network.dir/experiment.cpp.o: CMakeFiles/C___Network.dir/flags.make
CMakeFiles/C___Network.dir/experiment.cpp.o: ../experiment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/C++_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/C___Network.dir/experiment.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/C___Network.dir/experiment.cpp.o -c /Users/admin/C++_Network/experiment.cpp

CMakeFiles/C___Network.dir/experiment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C___Network.dir/experiment.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/admin/C++_Network/experiment.cpp > CMakeFiles/C___Network.dir/experiment.cpp.i

CMakeFiles/C___Network.dir/experiment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C___Network.dir/experiment.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/admin/C++_Network/experiment.cpp -o CMakeFiles/C___Network.dir/experiment.cpp.s

CMakeFiles/C___Network.dir/myserver.cpp.o: CMakeFiles/C___Network.dir/flags.make
CMakeFiles/C___Network.dir/myserver.cpp.o: ../myserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/C++_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/C___Network.dir/myserver.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/C___Network.dir/myserver.cpp.o -c /Users/admin/C++_Network/myserver.cpp

CMakeFiles/C___Network.dir/myserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C___Network.dir/myserver.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/admin/C++_Network/myserver.cpp > CMakeFiles/C___Network.dir/myserver.cpp.i

CMakeFiles/C___Network.dir/myserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C___Network.dir/myserver.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/admin/C++_Network/myserver.cpp -o CMakeFiles/C___Network.dir/myserver.cpp.s

# Object files for target C___Network
C___Network_OBJECTS = \
"CMakeFiles/C___Network.dir/server.c.o" \
"CMakeFiles/C___Network.dir/client.c.o" \
"CMakeFiles/C___Network.dir/multiservers.c.o" \
"CMakeFiles/C___Network.dir/network/connection.cpp.o" \
"CMakeFiles/C___Network.dir/experiment.cpp.o" \
"CMakeFiles/C___Network.dir/myserver.cpp.o"

# External object files for target C___Network
C___Network_EXTERNAL_OBJECTS =

C___Network: CMakeFiles/C___Network.dir/server.c.o
C___Network: CMakeFiles/C___Network.dir/client.c.o
C___Network: CMakeFiles/C___Network.dir/multiservers.c.o
C___Network: CMakeFiles/C___Network.dir/network/connection.cpp.o
C___Network: CMakeFiles/C___Network.dir/experiment.cpp.o
C___Network: CMakeFiles/C___Network.dir/myserver.cpp.o
C___Network: CMakeFiles/C___Network.dir/build.make
C___Network: CMakeFiles/C___Network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/admin/C++_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable C___Network"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/C___Network.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C___Network.dir/build: C___Network

.PHONY : CMakeFiles/C___Network.dir/build

CMakeFiles/C___Network.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/C___Network.dir/cmake_clean.cmake
.PHONY : CMakeFiles/C___Network.dir/clean

CMakeFiles/C___Network.dir/depend:
	cd /Users/admin/C++_Network/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/admin/C++_Network /Users/admin/C++_Network /Users/admin/C++_Network/cmake-build-debug /Users/admin/C++_Network/cmake-build-debug /Users/admin/C++_Network/cmake-build-debug/CMakeFiles/C___Network.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/C___Network.dir/depend

