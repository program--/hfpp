find_package(doctest REQUIRED)

# Test source files
add_library(test_files OBJECT test_catchment.cpp)
target_link_libraries(test_files doctest::doctest hfpp)
target_compile_strict_cxx14(test_files)

# Test runner
add_executable(hfpp_tests tests.cpp)
target_link_libraries(hfpp_tests PRIVATE doctest::doctest test_files)
target_compile_strict_cxx14(hfpp_tests)

# doctest/CTest
include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(hfpp_tests)
