cmake_minimum_required(VERSION 2.8.12)

set(module_name tricycle)
project(${module_name})

# cxx standard 设置
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

# project 版本设置
set(PROJECT_VERSION 0.0.1)
set(PROJECT_VERSION_MAJOR 0)

message(STATUS "Configuring ${module_name}")

# 项目源码设置
set(tricycle_include_dir "${PROJECT_SOURCE_DIR}/include")
set(tricycle_source_dir "${PROJECT_SOURCE_DIR}/src")

set(headers
        ${tricycle_include_dir}/generic_service_constants.h
        ${tricycle_include_dir}/generic_service_types.h
        ${tricycle_include_dir}/generic_service.h
        ${tricycle_include_dir}/json.h
        ${tricycle_include_dir}/json-forwards.h
        ${tricycle_include_dir}/tricycle.hpp
        ${tricycle_include_dir}/tricycle_server.hpp
        )

set(sources
        ${tricycle_source_dir}/generic_service_constants.cpp
        ${tricycle_source_dir}/generic_service_types.cpp
        ${tricycle_source_dir}/generic_service.cpp
        ${tricycle_source_dir}/jsoncpp.cpp
        ${tricycle_source_dir}/tricycle.cpp
        ${tricycle_source_dir}/tricycle_server.cpp
        )

add_library(tricycle SHARED
        ${headers}
        ${sources})

# so 版本号配置
# so 暴露 header 配置
set(tricycle_public_headers
        ${tricycle_include_dir}/generic_service.h
        ${tricycle_include_dir}/generic_service_constants.h
        ${tricycle_include_dir}/generic_service_types.h
        ${tricycle_include_dir}/json.h
        ${tricycle_include_dir}/json-forwards.h
        ${tricycle_include_dir}/tricycle.hpp
        ${tricycle_include_dir}/tricycle_server.hpp)

set_target_properties(${module_name} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        PUBLIC_HEADER "${tricycle_public_headers}"
        )

# 头文件及目标文件所在目录
target_include_directories(tricycle PRIVATE ${tricycle_include_dir})
target_include_directories(tricycle PRIVATE ${tricycle_source_dir})

# 支持 uint_32
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DHAVE_NETINET_IN_H -DHAVE_INTTYPES_H")

# cmake 目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 安装目录
include(GNUInstallDirs)

install(TARGETS ${module_name}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/${module_name}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${module_name})

# thrift 依赖
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
find_package(Thrift REQUIRED)

if (THRIFT_FOUND)
    message(STATUS "found thrift include dir: ${THRIFT_INCLUDE_DIR}")
    message(STATUS "found thrift libs: ${THRIFT_LIBRARIES}")
else ()
    message(FATAL_ERROR "thrift not found")
endif ()

TARGET_LINK_LIBRARIES(${module_name} ${THRIFT_LIBRARIES})

# 链接 thrift

#MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")
#
#IF (LINUX)
#    MESSAGE(STATUS "Load linux thrift lib: /usr/local/lib/libthrift.so")
#    file(GLOB LIBRARIES "/usr/local/lib/libthrift.so")
#ELSEIF (APPLE)
#    MESSAGE(STATUS "Load OSX thrift lib: /usr/local/lib/libthrift.dylib")
#    file(GLOB LIBRARIES "/usr/local/lib/libthrift.dylib")
#ELSE ()
#    message(FATAL_ERROR "Unsupported operating system")
#ENDIF ()
#
#message("LIBRARIES = ${LIBRARIES}")
#
#TARGET_LINK_LIBRARIES(tricycle ${LIBRARIES})