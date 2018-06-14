cmake_minimum_required(VERSION 3.1.0)
project(wlib-malloc)

set(CMAKE_CXX_STANDARD 11)

set(WLIB_TLSF_DIR ${CMAKE_CURRENT_LIST_DIR}/.wio/node_modules/wlib-tlsf)
set(WLIB_TLSF_INCLUDE_DIR ${WLIB_TLSF_DIR}/include)
set(WLIB_TLSF_SRC ${WLIB_TLSF_DIR}/src)

file(GLOB_RECURSE WLIB_TLSF_FILES ${WLIB_TLSF_SRC}/* ${WLIB_TLSF_INCLUDE_DIR}/*)

add_library(wlib-tlsf ${WLIB_TLSF_FILES})
target_include_directories(wlib-tlsf PRIVATE ${WLIB_TLSF_INCLUDE_DIR})
target_compile_definitions(wlib-tlsf PRIVATE
    WLIB_TLSF_32BIT
    WLIB_TLSF_LOG2_ALIGN=2
    WLIB_TLSF_LOG2_DIV=3
    WLIB_TLSF_LOG2_MAX=12
    WLIB_TLSF_DEBUG_LEVEL=1
)

set(WLIB_MALLOC_DIR ${CMAKE_CURRENT_LIST_DIR})
set(WLIB_MALLOC_INCLUDE_DIR ${WLIB_MALLOC_DIR}/include)
set(WLIB_MALLOC_SRC ${WLIB_MALLOC_DIR}/src)

file(GLOB_RECURSE WLIB_MALLOC_FILES
    ${WLIB_MALLOC_SRC}/*.cpp
    ${WLIB_MALLOC_SRC}/*.h
    ${WLIB_MALLOC_INCLUDE_DIR}/*
    )

add_library(wlib-malloc ${WLIB_MALLOC_FILES})
target_include_directories(wlib-malloc PRIVATE
    ${WLIB_MALLOC_INCLUDE_DIR}
    ${WLIB_TLSF_INCLUDE_DIR}
    )
target_link_libraries(wlib-malloc wlib-tlsf)

file(GLOB_RECURSE TEST_FILES
    tests/*.h
    tests/*.cpp
    )

add_executable(tests ${TEST_FILES})
target_link_libraries(tests wlib-malloc)
target_include_directories(tests PRIVATE ${WLIB_MALLOC_INCLUDE_DIR})
