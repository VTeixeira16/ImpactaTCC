# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Victor Teixeira\Documents\Projetos\ImpactaTCC\AppFrontCPP"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Victor Teixeira\Documents\Projetos\ImpactaTCC\AppFrontCPP\build"

# Include any dependencies generated for this target.
include CMakeFiles/IMPACTA_TCC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/IMPACTA_TCC.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/IMPACTA_TCC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IMPACTA_TCC.dir/flags.make

CMakeFiles/IMPACTA_TCC.dir/main.cpp.obj: CMakeFiles/IMPACTA_TCC.dir/flags.make
CMakeFiles/IMPACTA_TCC.dir/main.cpp.obj: CMakeFiles/IMPACTA_TCC.dir/includes_CXX.rsp
CMakeFiles/IMPACTA_TCC.dir/main.cpp.obj: C:/Users/Victor\ Teixeira/Documents/Projetos/ImpactaTCC/AppFrontCPP/main.cpp
CMakeFiles/IMPACTA_TCC.dir/main.cpp.obj: CMakeFiles/IMPACTA_TCC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Victor Teixeira\Documents\Projetos\ImpactaTCC\AppFrontCPP\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IMPACTA_TCC.dir/main.cpp.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/IMPACTA_TCC.dir/main.cpp.obj -MF CMakeFiles\IMPACTA_TCC.dir\main.cpp.obj.d -o CMakeFiles\IMPACTA_TCC.dir\main.cpp.obj -c "C:\Users\Victor Teixeira\Documents\Projetos\ImpactaTCC\AppFrontCPP\main.cpp"

CMakeFiles/IMPACTA_TCC.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IMPACTA_TCC.dir/main.cpp.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Victor Teixeira\Documents\Projetos\ImpactaTCC\AppFrontCPP\main.cpp" > CMakeFiles\IMPACTA_TCC.dir\main.cpp.i

CMakeFiles/IMPACTA_TCC.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IMPACTA_TCC.dir/main.cpp.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Victor Teixeira\Documents\Projetos\ImpactaTCC\AppFrontCPP\main.cpp" -o CMakeFiles\IMPACTA_TCC.dir\main.cpp.s

# Object files for target IMPACTA_TCC
IMPACTA_TCC_OBJECTS = \
"CMakeFiles/IMPACTA_TCC.dir/main.cpp.obj"

# External object files for target IMPACTA_TCC
IMPACTA_TCC_EXTERNAL_OBJECTS =

IMPACTA_TCC.exe: CMakeFiles/IMPACTA_TCC.dir/main.cpp.obj
IMPACTA_TCC.exe: CMakeFiles/IMPACTA_TCC.dir/build.make
IMPACTA_TCC.exe: BD_Graphics/libBD_Graph.a
IMPACTA_TCC.exe: BD_Core/libBD_Core.a
IMPACTA_TCC.exe: C:/Users/Victor\ Teixeira/Documents/Projetos/ImpactaTCC/AppFrontCPP/BD_Core/curl/bin/libcurl-x64.dll
IMPACTA_TCC.exe: CMakeFiles/IMPACTA_TCC.dir/linkLibs.rsp
IMPACTA_TCC.exe: CMakeFiles/IMPACTA_TCC.dir/objects1.rsp
IMPACTA_TCC.exe: CMakeFiles/IMPACTA_TCC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Victor Teixeira\Documents\Projetos\ImpactaTCC\AppFrontCPP\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable IMPACTA_TCC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\IMPACTA_TCC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IMPACTA_TCC.dir/build: IMPACTA_TCC.exe
.PHONY : CMakeFiles/IMPACTA_TCC.dir/build

CMakeFiles/IMPACTA_TCC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\IMPACTA_TCC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/IMPACTA_TCC.dir/clean

CMakeFiles/IMPACTA_TCC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Victor Teixeira\Documents\Projetos\ImpactaTCC\AppFrontCPP" "C:\Users\Victor Teixeira\Documents\Projetos\ImpactaTCC\AppFrontCPP" "C:\Users\Victor Teixeira\Documents\Projetos\ImpactaTCC\AppFrontCPP\build" "C:\Users\Victor Teixeira\Documents\Projetos\ImpactaTCC\AppFrontCPP\build" "C:\Users\Victor Teixeira\Documents\Projetos\ImpactaTCC\AppFrontCPP\build\CMakeFiles\IMPACTA_TCC.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/IMPACTA_TCC.dir/depend
