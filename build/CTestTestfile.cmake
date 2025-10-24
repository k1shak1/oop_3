# CMake generated Testfile for 
# Source directory: /workspaces/lab_oop_03
# Build directory: /workspaces/lab_oop_03/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(FiguresUnitTests "/workspaces/lab_oop_03/build/tests")
set_tests_properties(FiguresUnitTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/lab_oop_03/CMakeLists.txt;40;add_test;/workspaces/lab_oop_03/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
