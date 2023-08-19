cmake_minimum_required(VERSION 3.14...3.26)

project(hfpp
        VERSION      0.1.0
        DESCRIPTION  "Hydrofabric Modeling Library"
        HOMEPAGE_URL "https://github.com/program--/hfpp"
        LANGUAGES    CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

include(hfppMacros)

find_package(immer REQUIRED)

add_library(hfpp)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib/hfpp)
target_include_directories(hfpp PUBLIC ${CMAKE_CURRENT_LIST_DIR}/lib)
target_debug_extra(hfpp)
target_compile_strict_cxx14(hfpp)
target_link_libraries(hfpp immer)

include(CTest)
if((PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME) AND BUILD_TESTING)
    add_subdirectory("tests")
endif()
