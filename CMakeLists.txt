cmake_minimum_required(VERSION 3.16)
project(Cpp_Study_Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 所有 exe 输出到 构建目录/exe 文件夹
# 例如 cmake-build-debug/exe
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/exe)

# 下面三行强制取消,保证 exe 直接在 exe 文件夹下
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/exe)
endforeach()

# 扫描 Cpp_Study 下所有 cpp 文件(CONFIGURE_DEPENDS: 新增文件后自动重新扫描)
file(GLOB STUDY_SOURCES CONFIGURE_DEPENDS
        ${CMAKE_SOURCE_DIR}/Cpp_Study/*.cpp
)

# 为每个 cpp 文件生成一个同名可执行文件
foreach(src ${STUDY_SOURCES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src}
            Cpp_Study/10_constant.cpp)
endforeach()
