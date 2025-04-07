
# cmake_minimum_required(VERSION 3.10)

# project(MyProject C)

# add_executable(area main.c)

# add_compile_options(-Wall -g)



cmake_minimum_required(VERSION 3.10)
project(MyProject C)

# 设置编译选项，如 -Wall、-g 等
add_compile_options(-Wall -g)

add_executable(my_program
    main.c
)
