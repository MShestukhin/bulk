cmake_minimum_required(VERSION 2.8)

project(bulk)
FILE(GLOB_RECURSE LibFiles "*.h")
add_custom_target(headers SOURCES ${LibFiles})
aux_source_directory(. SRC_LIST)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_executable(${PROJECT_NAME} ${SRC_LIST})
