# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.VHYzeaTRNC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.VHYzeaTRNC/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tinyWeb.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tinyWeb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tinyWeb.dir/flags.make

CMakeFiles/tinyWeb.dir/test.cpp.o: CMakeFiles/tinyWeb.dir/flags.make
CMakeFiles/tinyWeb.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tinyWeb.dir/test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyWeb.dir/test.cpp.o -c /tmp/tmp.VHYzeaTRNC/test.cpp

CMakeFiles/tinyWeb.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyWeb.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.VHYzeaTRNC/test.cpp > CMakeFiles/tinyWeb.dir/test.cpp.i

CMakeFiles/tinyWeb.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyWeb.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.VHYzeaTRNC/test.cpp -o CMakeFiles/tinyWeb.dir/test.cpp.s

CMakeFiles/tinyWeb.dir/Server/TcpServer.cpp.o: CMakeFiles/tinyWeb.dir/flags.make
CMakeFiles/tinyWeb.dir/Server/TcpServer.cpp.o: ../Server/TcpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tinyWeb.dir/Server/TcpServer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyWeb.dir/Server/TcpServer.cpp.o -c /tmp/tmp.VHYzeaTRNC/Server/TcpServer.cpp

CMakeFiles/tinyWeb.dir/Server/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyWeb.dir/Server/TcpServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.VHYzeaTRNC/Server/TcpServer.cpp > CMakeFiles/tinyWeb.dir/Server/TcpServer.cpp.i

CMakeFiles/tinyWeb.dir/Server/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyWeb.dir/Server/TcpServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.VHYzeaTRNC/Server/TcpServer.cpp -o CMakeFiles/tinyWeb.dir/Server/TcpServer.cpp.s

CMakeFiles/tinyWeb.dir/Server/EventLoopThreadPool.cpp.o: CMakeFiles/tinyWeb.dir/flags.make
CMakeFiles/tinyWeb.dir/Server/EventLoopThreadPool.cpp.o: ../Server/EventLoopThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tinyWeb.dir/Server/EventLoopThreadPool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyWeb.dir/Server/EventLoopThreadPool.cpp.o -c /tmp/tmp.VHYzeaTRNC/Server/EventLoopThreadPool.cpp

CMakeFiles/tinyWeb.dir/Server/EventLoopThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyWeb.dir/Server/EventLoopThreadPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.VHYzeaTRNC/Server/EventLoopThreadPool.cpp > CMakeFiles/tinyWeb.dir/Server/EventLoopThreadPool.cpp.i

CMakeFiles/tinyWeb.dir/Server/EventLoopThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyWeb.dir/Server/EventLoopThreadPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.VHYzeaTRNC/Server/EventLoopThreadPool.cpp -o CMakeFiles/tinyWeb.dir/Server/EventLoopThreadPool.cpp.s

CMakeFiles/tinyWeb.dir/Timer/TimerQueue.cpp.o: CMakeFiles/tinyWeb.dir/flags.make
CMakeFiles/tinyWeb.dir/Timer/TimerQueue.cpp.o: ../Timer/TimerQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tinyWeb.dir/Timer/TimerQueue.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyWeb.dir/Timer/TimerQueue.cpp.o -c /tmp/tmp.VHYzeaTRNC/Timer/TimerQueue.cpp

CMakeFiles/tinyWeb.dir/Timer/TimerQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyWeb.dir/Timer/TimerQueue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.VHYzeaTRNC/Timer/TimerQueue.cpp > CMakeFiles/tinyWeb.dir/Timer/TimerQueue.cpp.i

CMakeFiles/tinyWeb.dir/Timer/TimerQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyWeb.dir/Timer/TimerQueue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.VHYzeaTRNC/Timer/TimerQueue.cpp -o CMakeFiles/tinyWeb.dir/Timer/TimerQueue.cpp.s

CMakeFiles/tinyWeb.dir/Timer/Timer.cpp.o: CMakeFiles/tinyWeb.dir/flags.make
CMakeFiles/tinyWeb.dir/Timer/Timer.cpp.o: ../Timer/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tinyWeb.dir/Timer/Timer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyWeb.dir/Timer/Timer.cpp.o -c /tmp/tmp.VHYzeaTRNC/Timer/Timer.cpp

CMakeFiles/tinyWeb.dir/Timer/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyWeb.dir/Timer/Timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.VHYzeaTRNC/Timer/Timer.cpp > CMakeFiles/tinyWeb.dir/Timer/Timer.cpp.i

CMakeFiles/tinyWeb.dir/Timer/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyWeb.dir/Timer/Timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.VHYzeaTRNC/Timer/Timer.cpp -o CMakeFiles/tinyWeb.dir/Timer/Timer.cpp.s

CMakeFiles/tinyWeb.dir/Tcp/TcpConnection.cpp.o: CMakeFiles/tinyWeb.dir/flags.make
CMakeFiles/tinyWeb.dir/Tcp/TcpConnection.cpp.o: ../Tcp/TcpConnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tinyWeb.dir/Tcp/TcpConnection.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyWeb.dir/Tcp/TcpConnection.cpp.o -c /tmp/tmp.VHYzeaTRNC/Tcp/TcpConnection.cpp

CMakeFiles/tinyWeb.dir/Tcp/TcpConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyWeb.dir/Tcp/TcpConnection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.VHYzeaTRNC/Tcp/TcpConnection.cpp > CMakeFiles/tinyWeb.dir/Tcp/TcpConnection.cpp.i

CMakeFiles/tinyWeb.dir/Tcp/TcpConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyWeb.dir/Tcp/TcpConnection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.VHYzeaTRNC/Tcp/TcpConnection.cpp -o CMakeFiles/tinyWeb.dir/Tcp/TcpConnection.cpp.s

CMakeFiles/tinyWeb.dir/Log/AsyncLog.cpp.o: CMakeFiles/tinyWeb.dir/flags.make
CMakeFiles/tinyWeb.dir/Log/AsyncLog.cpp.o: ../Log/AsyncLog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/tinyWeb.dir/Log/AsyncLog.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyWeb.dir/Log/AsyncLog.cpp.o -c /tmp/tmp.VHYzeaTRNC/Log/AsyncLog.cpp

CMakeFiles/tinyWeb.dir/Log/AsyncLog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyWeb.dir/Log/AsyncLog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.VHYzeaTRNC/Log/AsyncLog.cpp > CMakeFiles/tinyWeb.dir/Log/AsyncLog.cpp.i

CMakeFiles/tinyWeb.dir/Log/AsyncLog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyWeb.dir/Log/AsyncLog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.VHYzeaTRNC/Log/AsyncLog.cpp -o CMakeFiles/tinyWeb.dir/Log/AsyncLog.cpp.s

CMakeFiles/tinyWeb.dir/Server/Acceptor.cpp.o: CMakeFiles/tinyWeb.dir/flags.make
CMakeFiles/tinyWeb.dir/Server/Acceptor.cpp.o: ../Server/Acceptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/tinyWeb.dir/Server/Acceptor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyWeb.dir/Server/Acceptor.cpp.o -c /tmp/tmp.VHYzeaTRNC/Server/Acceptor.cpp

CMakeFiles/tinyWeb.dir/Server/Acceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyWeb.dir/Server/Acceptor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.VHYzeaTRNC/Server/Acceptor.cpp > CMakeFiles/tinyWeb.dir/Server/Acceptor.cpp.i

CMakeFiles/tinyWeb.dir/Server/Acceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyWeb.dir/Server/Acceptor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.VHYzeaTRNC/Server/Acceptor.cpp -o CMakeFiles/tinyWeb.dir/Server/Acceptor.cpp.s

CMakeFiles/tinyWeb.dir/Reactor/EventLoop.cpp.o: CMakeFiles/tinyWeb.dir/flags.make
CMakeFiles/tinyWeb.dir/Reactor/EventLoop.cpp.o: ../Reactor/EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/tinyWeb.dir/Reactor/EventLoop.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyWeb.dir/Reactor/EventLoop.cpp.o -c /tmp/tmp.VHYzeaTRNC/Reactor/EventLoop.cpp

CMakeFiles/tinyWeb.dir/Reactor/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyWeb.dir/Reactor/EventLoop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.VHYzeaTRNC/Reactor/EventLoop.cpp > CMakeFiles/tinyWeb.dir/Reactor/EventLoop.cpp.i

CMakeFiles/tinyWeb.dir/Reactor/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyWeb.dir/Reactor/EventLoop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.VHYzeaTRNC/Reactor/EventLoop.cpp -o CMakeFiles/tinyWeb.dir/Reactor/EventLoop.cpp.s

CMakeFiles/tinyWeb.dir/Reactor/Channel.cpp.o: CMakeFiles/tinyWeb.dir/flags.make
CMakeFiles/tinyWeb.dir/Reactor/Channel.cpp.o: ../Reactor/Channel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/tinyWeb.dir/Reactor/Channel.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyWeb.dir/Reactor/Channel.cpp.o -c /tmp/tmp.VHYzeaTRNC/Reactor/Channel.cpp

CMakeFiles/tinyWeb.dir/Reactor/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyWeb.dir/Reactor/Channel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.VHYzeaTRNC/Reactor/Channel.cpp > CMakeFiles/tinyWeb.dir/Reactor/Channel.cpp.i

CMakeFiles/tinyWeb.dir/Reactor/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyWeb.dir/Reactor/Channel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.VHYzeaTRNC/Reactor/Channel.cpp -o CMakeFiles/tinyWeb.dir/Reactor/Channel.cpp.s

CMakeFiles/tinyWeb.dir/Reactor/Poller.cpp.o: CMakeFiles/tinyWeb.dir/flags.make
CMakeFiles/tinyWeb.dir/Reactor/Poller.cpp.o: ../Reactor/Poller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/tinyWeb.dir/Reactor/Poller.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyWeb.dir/Reactor/Poller.cpp.o -c /tmp/tmp.VHYzeaTRNC/Reactor/Poller.cpp

CMakeFiles/tinyWeb.dir/Reactor/Poller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyWeb.dir/Reactor/Poller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.VHYzeaTRNC/Reactor/Poller.cpp > CMakeFiles/tinyWeb.dir/Reactor/Poller.cpp.i

CMakeFiles/tinyWeb.dir/Reactor/Poller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyWeb.dir/Reactor/Poller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.VHYzeaTRNC/Reactor/Poller.cpp -o CMakeFiles/tinyWeb.dir/Reactor/Poller.cpp.s

CMakeFiles/tinyWeb.dir/Coroutine/Coroutine.cpp.o: CMakeFiles/tinyWeb.dir/flags.make
CMakeFiles/tinyWeb.dir/Coroutine/Coroutine.cpp.o: ../Coroutine/Coroutine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/tinyWeb.dir/Coroutine/Coroutine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyWeb.dir/Coroutine/Coroutine.cpp.o -c /tmp/tmp.VHYzeaTRNC/Coroutine/Coroutine.cpp

CMakeFiles/tinyWeb.dir/Coroutine/Coroutine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyWeb.dir/Coroutine/Coroutine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.VHYzeaTRNC/Coroutine/Coroutine.cpp > CMakeFiles/tinyWeb.dir/Coroutine/Coroutine.cpp.i

CMakeFiles/tinyWeb.dir/Coroutine/Coroutine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyWeb.dir/Coroutine/Coroutine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.VHYzeaTRNC/Coroutine/Coroutine.cpp -o CMakeFiles/tinyWeb.dir/Coroutine/Coroutine.cpp.s

# Object files for target tinyWeb
tinyWeb_OBJECTS = \
"CMakeFiles/tinyWeb.dir/test.cpp.o" \
"CMakeFiles/tinyWeb.dir/Server/TcpServer.cpp.o" \
"CMakeFiles/tinyWeb.dir/Server/EventLoopThreadPool.cpp.o" \
"CMakeFiles/tinyWeb.dir/Timer/TimerQueue.cpp.o" \
"CMakeFiles/tinyWeb.dir/Timer/Timer.cpp.o" \
"CMakeFiles/tinyWeb.dir/Tcp/TcpConnection.cpp.o" \
"CMakeFiles/tinyWeb.dir/Log/AsyncLog.cpp.o" \
"CMakeFiles/tinyWeb.dir/Server/Acceptor.cpp.o" \
"CMakeFiles/tinyWeb.dir/Reactor/EventLoop.cpp.o" \
"CMakeFiles/tinyWeb.dir/Reactor/Channel.cpp.o" \
"CMakeFiles/tinyWeb.dir/Reactor/Poller.cpp.o" \
"CMakeFiles/tinyWeb.dir/Coroutine/Coroutine.cpp.o"

# External object files for target tinyWeb
tinyWeb_EXTERNAL_OBJECTS =

tinyWeb: CMakeFiles/tinyWeb.dir/test.cpp.o
tinyWeb: CMakeFiles/tinyWeb.dir/Server/TcpServer.cpp.o
tinyWeb: CMakeFiles/tinyWeb.dir/Server/EventLoopThreadPool.cpp.o
tinyWeb: CMakeFiles/tinyWeb.dir/Timer/TimerQueue.cpp.o
tinyWeb: CMakeFiles/tinyWeb.dir/Timer/Timer.cpp.o
tinyWeb: CMakeFiles/tinyWeb.dir/Tcp/TcpConnection.cpp.o
tinyWeb: CMakeFiles/tinyWeb.dir/Log/AsyncLog.cpp.o
tinyWeb: CMakeFiles/tinyWeb.dir/Server/Acceptor.cpp.o
tinyWeb: CMakeFiles/tinyWeb.dir/Reactor/EventLoop.cpp.o
tinyWeb: CMakeFiles/tinyWeb.dir/Reactor/Channel.cpp.o
tinyWeb: CMakeFiles/tinyWeb.dir/Reactor/Poller.cpp.o
tinyWeb: CMakeFiles/tinyWeb.dir/Coroutine/Coroutine.cpp.o
tinyWeb: CMakeFiles/tinyWeb.dir/build.make
tinyWeb: CMakeFiles/tinyWeb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable tinyWeb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tinyWeb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tinyWeb.dir/build: tinyWeb

.PHONY : CMakeFiles/tinyWeb.dir/build

CMakeFiles/tinyWeb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tinyWeb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tinyWeb.dir/clean

CMakeFiles/tinyWeb.dir/depend:
	cd /tmp/tmp.VHYzeaTRNC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.VHYzeaTRNC /tmp/tmp.VHYzeaTRNC /tmp/tmp.VHYzeaTRNC/cmake-build-debug /tmp/tmp.VHYzeaTRNC/cmake-build-debug /tmp/tmp.VHYzeaTRNC/cmake-build-debug/CMakeFiles/tinyWeb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tinyWeb.dir/depend

