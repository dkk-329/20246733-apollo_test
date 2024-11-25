#!/bin/bash

# 设置编译器为 g++
COMPILER=g++

# 指定源文件和目标文件
SOURCE_FILE=solution.cpp
OUTPUT_FILE=solution

# 编译选项，这里添加了 -std=c++11 以支持 C++11 特性（如果需要）
COMPILE_OPTIONS=-std=c++11 -Wall -Wextra -O2

# 编译源文件并生成可执行文件
$COMPILER $COMPILE_OPTIONS $SOURCE_FILE -o $OUTPUT_FILE

# 检查编译是否成功
if [ $? -eq 0 ]; then
    echo "编译成功！"
else
    echo "编译失败！"
    exit 1
fi

# 可选：运行生成的可执行文件
# ./$OUTPUT_FILE