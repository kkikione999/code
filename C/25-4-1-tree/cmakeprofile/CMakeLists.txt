cmake_minimum_required(VERSION 3.10)  # 指定 CMake 最低版本
project(MyCProject)                   # 定义项目名称

set(CMAKE_C_STANDARD 99)              # 设置 C 标准为 C99

# 修复源文件路径
add_executable(main ../main.c ../tree.c)

include_directories(include)          # 添加头文件搜索路径