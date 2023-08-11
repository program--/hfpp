cmake_minimum_required(VERSION 3.14)

project(hfpp VERSION 0.1.0 LANGUAGES CXX)

add_library(hfpp INTERFACE)
target_include_directories(hfpp INTERFACE include)
