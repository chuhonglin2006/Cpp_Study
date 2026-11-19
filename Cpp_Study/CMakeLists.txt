
cmake_minimum_required(VERSION 3.16)

project(Cpp_Study_Project LANGUAGES CXX)


# C++ 编译标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 定义项目目录
set(STUDY_DIR .)

# 头文件目录
set(HEAD_DIR ${STUDY_DIR}/head_folder)

# 函数实现目录
set(FUNCTION_DIR ${STUDY_DIR}/function_folder)

# 设置 EXE 输出目录
# 所有 exe 输出到 cmake-build-debug/exe
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/exe
)

# 多配置生成器兼容
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})

    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER}
            ${CMAKE_BINARY_DIR}/exe
    )

endforeach()

# 自动扫描函数实现文件
file(GLOB_RECURSE FUNCTION_SOURCES CONFIGURE_DEPENDS
        ${FUNCTION_DIR}/*.cpp
)

# 创建函数静态库
if(FUNCTION_SOURCES)

    add_library(study_functions STATIC
            ${FUNCTION_SOURCES}
    )
    # 静态库公开头文件目录
    target_include_directories(study_functions PUBLIC
            ${HEAD_DIR}
    )
    message(STATUS "========== 函数库 ==========")
    message(STATUS "找到 ${FUNCTION_SOURCES} 个函数实现文件")

endif()

# 自动扫描学习目录下的 cpp 文件
file(GLOB STUDY_SOURCES CONFIGURE_DEPENDS
        ${STUDY_DIR}/*.cpp
)

# 自动创建独立 EXE
foreach(src ${STUDY_SOURCES})
    # 获取不带扩展名的文件名
    get_filename_component(target_name ${src} NAME_WE)
    # 创建独立可执行程序
    add_executable(${target_name} ${src})
    # 设置头文件搜索目录
    target_include_directories(${target_name} PRIVATE
            ${HEAD_DIR}
    )
    # 自动链接函数库
    if(TARGET study_functions)
        target_link_libraries(${target_name} PRIVATE
                study_functions
        )
    endif()
    message(STATUS "创建 EXE: ${target_name}")
endforeach()
message(STATUS "========== CMake 配置完成 ==========")
