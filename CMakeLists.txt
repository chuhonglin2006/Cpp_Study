cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE "E:/Clion/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

project(Cpp_Study_Project LANGUAGES CXX)

# C++ 编译标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 目录定义
set(STUDY_DIR     ${CMAKE_SOURCE_DIR}/Cpp_Study)
set(ALGORITHM_DIR ${CMAKE_SOURCE_DIR}/Algorithm)
set(HEAD_DIR      ${STUDY_DIR}/head_folder)
set(FUNCTION_DIR  ${STUDY_DIR}/function_folder)

# EXE 输出目录:cmake-build-debug/exe
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/exe)
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/exe)
endforeach()

# vcpkg 头文件目录
include_directories("E:/Clion/vcpkg/installed/x64-mingw-dynamic/include")

# ---------- 函数实现静态库 ----------
file(GLOB_RECURSE FUNCTION_SOURCES CONFIGURE_DEPENDS
        ${FUNCTION_DIR}/*.cpp
)

if(FUNCTION_SOURCES)
    add_library(study_functions STATIC ${FUNCTION_SOURCES})
    target_include_directories(study_functions PUBLIC ${HEAD_DIR})
endif()

# ---------- 扫描 Algorithm 和 Cpp_Study 下所有 cpp ----------
file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS
        ${ALGORITHM_DIR}/*.cpp
        ${STUDY_DIR}/*.cpp
)

# 排除函数实现目录(没有 main,已编进静态库)
list(FILTER ALL_SOURCES EXCLUDE REGEX ".*/Cpp_Study/function_folder/.*")

# ---------- 为每个 cpp 创建独立 EXE ----------
foreach(src ${ALL_SOURCES})
    get_filename_component(file_name ${src} NAME_WE)
    get_filename_component(dir_path  ${src} DIRECTORY)
    get_filename_component(dir_name  ${dir_path} NAME)

    # 重名时加上所在文件夹名作前缀
    set(target_name ${file_name})
    if(TARGET ${target_name})
        set(target_name ${dir_name}_${file_name})
    endif()

    add_executable(${target_name} ${src})
    target_include_directories(${target_name} PRIVATE ${HEAD_DIR})

    if(TARGET study_functions)
        target_link_libraries(${target_name} PRIVATE study_functions)
    endif()
endforeach()

message(STATUS "========== CMake 配置完成,共 ${CMAKE_CURRENT_LIST_LINE} 行已处理 ==========")