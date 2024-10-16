# 设置所需的 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和使用的语言
project(oopc C)

#c99
set(CMAKE_C_FLAGS "-std=c99")

# 添加子目录，这里是 myclass
add_subdirectory(animal_class)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/project/)

# 添加可执行文件，并指定源文件
file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/project/*.c)
add_executable(oopc ${SRC})

# 将 myclass 库链接到可执行文件
target_link_libraries(oopc PRIVATE animal_class)

target_compile_definitions(oopc PRIVATE ENABLE_MACRO_ISOLATION)
target_compile_definitions(animal_class PRIVATE ENABLE_MACRO_ISOLATION)
