cmake_minimum_required(VERSION 2.8.12)
project(tricycle_demo)

if (UNIX AND NOT APPLE)
    set(LINUX TRUE)
    message(STATUS "Operating system is Linux")
endif ()

if (LINUX)
    message(STATUS "Use cxx 98")
    set(CMAKE_CXX_STANDARD 98)
elseif (APPLE)
    message(STATUS "Use cxx 11")
    set(CMAKE_CXX_STANDARD 11)
else ()
    message(FATAL_ERROR "Unsupported operating system")
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DHAVE_NETINET_IN_H -DHAVE_INTTYPES_H")

INCLUDE_DIRECTORIES(/usr/local/include)
LINK_DIRECTORIES(/usr/local/lib)

set(demo_source_dir ${PROJECT_SOURCE_DIR}/src)

add_executable(tricycle_demo
        ${demo_source_dir}/main.cpp
        ${demo_source_dir}/demo_service.hpp
        ${demo_source_dir}/demo_service.cpp
        )

# 如果是 OSX, 需要在 .bash_profile 设置一下环境变量, 否则会找不到 dylib
# export DYLD_LIBRARY_PATH=/usr/local/lib/tricycle:$DYLD_LIBRARY_PATH

file(GLOB LIBRARIES
        "/usr/local/lib/tricycle/libtricycle.dylib"
        )
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(tricycle_demo ${LIBRARIES})
