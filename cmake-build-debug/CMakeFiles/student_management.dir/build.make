# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "D:\Clion\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Clion\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Clion\projects\student_management

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Clion\projects\student_management\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/student_management.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/student_management.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/student_management.dir/flags.make

CMakeFiles/student_management.dir/main.c.obj: CMakeFiles/student_management.dir/flags.make
CMakeFiles/student_management.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Clion\projects\student_management\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/student_management.dir/main.c.obj"
	D:\MingW\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\student_management.dir\main.c.obj   -c D:\Clion\projects\student_management\main.c

CMakeFiles/student_management.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/student_management.dir/main.c.i"
	D:\MingW\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Clion\projects\student_management\main.c > CMakeFiles\student_management.dir\main.c.i

CMakeFiles/student_management.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/student_management.dir/main.c.s"
	D:\MingW\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Clion\projects\student_management\main.c -o CMakeFiles\student_management.dir\main.c.s

CMakeFiles/student_management.dir/student.c.obj: CMakeFiles/student_management.dir/flags.make
CMakeFiles/student_management.dir/student.c.obj: ../student.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Clion\projects\student_management\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/student_management.dir/student.c.obj"
	D:\MingW\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\student_management.dir\student.c.obj   -c D:\Clion\projects\student_management\student.c

CMakeFiles/student_management.dir/student.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/student_management.dir/student.c.i"
	D:\MingW\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Clion\projects\student_management\student.c > CMakeFiles\student_management.dir\student.c.i

CMakeFiles/student_management.dir/student.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/student_management.dir/student.c.s"
	D:\MingW\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Clion\projects\student_management\student.c -o CMakeFiles\student_management.dir\student.c.s

# Object files for target student_management
student_management_OBJECTS = \
"CMakeFiles/student_management.dir/main.c.obj" \
"CMakeFiles/student_management.dir/student.c.obj"

# External object files for target student_management
student_management_EXTERNAL_OBJECTS =

student_management.exe: CMakeFiles/student_management.dir/main.c.obj
student_management.exe: CMakeFiles/student_management.dir/student.c.obj
student_management.exe: CMakeFiles/student_management.dir/build.make
student_management.exe: CMakeFiles/student_management.dir/linklibs.rsp
student_management.exe: CMakeFiles/student_management.dir/objects1.rsp
student_management.exe: CMakeFiles/student_management.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Clion\projects\student_management\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable student_management.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\student_management.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/student_management.dir/build: student_management.exe

.PHONY : CMakeFiles/student_management.dir/build

CMakeFiles/student_management.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\student_management.dir\cmake_clean.cmake
.PHONY : CMakeFiles/student_management.dir/clean

CMakeFiles/student_management.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Clion\projects\student_management D:\Clion\projects\student_management D:\Clion\projects\student_management\cmake-build-debug D:\Clion\projects\student_management\cmake-build-debug D:\Clion\projects\student_management\cmake-build-debug\CMakeFiles\student_management.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/student_management.dir/depend

