## CMake命令
### CMakeLists.txt
- `#`,`#[[  ]]`:注释

  ```cmake
  # 单行注释
  # [[
  多行注释
  ]]
  ```
- `cmake_minimum_required`:指定CMake的最低版本

  ```cmake
  # 这是一个 CMakeLists.txt 文件
  cmake_minimum_required(VERSION 3.0.0)
  ```
- `project`:定义工程名称

  ```cmake
  # PROJECT 指令的语法：
  project(<PROJECT-NAME> [<language-name>...])
  project(<PROJECT-NAME>
         [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
         [DESCRIPTION <project-description-string>]
         [HOMEPAGE_URL <url-string>]
         [LANGUAGES <language-name>...])
  ```
- `add_executable`:定义工程会生成一个可执行程序

  ```cmake
  add_executable(可执行程序名 源文件名)
  ```
- `Windows编译命令`:
  ```cmake
  mkdir build
  cd build
  cmake -G "MinGW Makefiles" ..
  ```
- 指定C语言编译使用`c99`标准:
  ```cmake
  set(CMAKE_C_FLAGS "-std=c99")
  ```
- 指定指定输出路径:
  ```cmake
  # 设置home路径为上一级
  set(HOME ..)
  set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)
  ```
- `aux_source_directory`:搜索指定文件下的所有源文件
  ```cmake
  aux_source_directory(<dir> $(SRC_LIST))
  ```
- `file`:递归搜索
  ```cmake
  # PROJECT_SOURCE_DIR 项目根目录
  # CMAKE_CURRENT_SOURCE_DIR CMakeLists.txt所在路径
  file(GLOB/GLOB_RECURSE 变量名 要搜索的路径和文件名)
  ```
- `include_directories`:添加头路径
  ```cmake
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/xxx)
  ```
  