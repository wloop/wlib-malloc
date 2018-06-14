cmake_minimum_required(VERSION 3.1.0)
project(wlib-memory)

set(CMAKE_CXX_STANDARD 11)

set(WLIB_TLSF_DIR ${CMAKE_CURRENT_LIST_DIR}/.wio/node_modules/wlib-tlsf)
set(WLIB_TLSF_INCLUDE_DIR ${WLIB_TLSF_DIR}/include)
set(WLIB_TLSF_SRC ${WLIB_TLSF_DIR}/src)

file(GLOB_RECURSE WLIB_TLSF_FILES ${WLIB_TLSF_SRC}/* ${WLIB_TLSF_INCLUDE_DIR}/*)

add_library(wlib-tlsf ${WLIB_TLSF_FILES})
target_include_directories(wlib-tlsf PRIVATE ${WLIB_TLSF_INCLUDE_DIR})
target_compile_definitions(wlib-tlsf PRIVATE
    WLIB_TLSF_64BIT
    WLIB_TLSF_LOG2_ALIGN=3
    WLIB_TLSF_LOG2_DIV=3
    WLIB_TLSF_LOG2_MAX=12
    WLIB_TLSF_DEBUG_LEVEL=1
)

set(WLIB_MEMORY_DIR ${CMAKE_CURRENT_LIST_DIR})
set(WLIB_MEMORY_INCLUDE_DIR ${WLIB_MEMORY_DIR}/include)
set(WLIB_MEMORY_SRC ${WLIB_MEMORY_DIR}/src)

file(GLOB_RECURSE WLIB_MEMORY_FILES
    ${WLIB_MEMORY_SRC}/*.cpp
    ${WLIB_MEMORY_SRC}/*.h
    ${WLIB_MEMORY_INCLUDE}/*
    )

add_library(wlib-memory ${WLIB_MEMORY_FILES})
target_include_directories(wlib-memory PRIVATE
    ${WLIB_MEMORY_INCLUDE_DIR}
    ${WLIB_TLSF_INCLUDE_DIR}
    )
target_link_libraries(wlib-memory wlib-tlsf)
