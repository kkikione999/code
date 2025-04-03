# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 指定工程名
project(MyCProject C)

# 设置 C 标准版本，这里以 C11 为例
set(CMAKE_C_STANDARD 11)

# 指定要编译的源文件并生成可执行文件
add_executable(my_program main.c queue.c)


my_project
├── CMakeLists.txt         # 顶层
├── src
│   ├── CMakeLists.txt     # src 目录的 CMakeLists.txt
│   ├── main.c
│   └── utils.c
└── libs
    ├── mylib
    │   ├── CMakeLists.txt # 单独管理一个库
    │   ├── foo.c
    │   └── foo.h