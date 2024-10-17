# 设置所需的 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和使用的语言
set (PROJECT_NAME "oopc")
project(${PROJECT_NAME})

# 设置 C99 标准
set(CMAKE_C_STANDARD 99)

#scripts
set(KCONFIG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/scripts/kconfig")
set(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/project")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(KCONFIG_CONFIG_H "my_config.h")

# 添加一个自定义目标来运行 menuconfig
if(CMAKE_HOST_UNIX)
    # UNIX
    add_custom_target(
        menuconfig
        WORKING_DIRECTORY ${BUILD_DIR}
        COMMAND KCONFIG_CONFIG=${BUILD_DIR}/prj.conf kconfig-mconf ${CMAKE_CURRENT_SOURCE_DIR}/Kconfig
        COMMAND python3 ${KCONFIG_DIR}/kconfig.py ${CMAKE_CURRENT_SOURCE_DIR}/Kconfig prj.conf ${PROJECT_DIR}/${KCONFIG_CONFIG_H} ${BUILD_DIR}/log.txt ${PROJECT_DIR}/prj.conf
        # COMMENT "Running menuconfig"
    )
endif()

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/project/)

# 添加可执行文件，并指定源文件
file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/project/*.c)
add_executable(${PROJECT_NAME} ${SRC})

# 添加子目录，这里是 myclass
add_subdirectory(class_lib)

# 将 myclass 库链接到可执行文件
target_link_libraries(${PROJECT_NAME} PRIVATE animal_class)
target_link_libraries(${PROJECT_NAME} PRIVATE money_class)

target_compile_definitions(${PROJECT_NAME} PUBLIC ENABLE_MACRO_ISOLATION)
# target_compile_definitions(animal_class PRIVATE ENABLE_MACRO_ISOLATION)
