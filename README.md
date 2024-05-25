# leeyangy-shell
## 使用Cmake构建项目

1. 创建 CMakeLists.txt 文件

2. 添加内容测试Cmke是否可用

   ```shell
   CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
   
   PROJECT(myshell)
   
   # 设置C++标准
   SET(CMAKE_CXX_STANDARD 11)
   
   # 添加可执行文件
   ADD_EXECUTABLE(myshell src/main.c)
   
   aux_source_directory(${PROJECT_SOURCE_DIR}/src src_dirs)
   
   # 条件判断
   if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
       set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -O0")
       message("Debug mode:${CMAKE_C_FLAGS_DEBUG}")
       add_executable(test_debug ${src_dirs})
   
   elseif(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))
       set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall -O3")
       message("Release mode:${CMAKE_C_FLAGS_RELEASE}")
       add_executable(test_release ${src_dirs})
   else()
       message("else:${CMAKE_BUILD_TYPE}")
       message("else:${CMAKE_C_FLAGS_RELEASE}")
       add_executable(test_release ${src_dirs})
   endif()
   
   ```

   

3. 创建 main.c 文件

   ```c
   #include <stdio.h>
   
   int main(int argc, char *argv[]) {
       printf("argc=%d argv=%s\n",argc,argv[1]);
       printf("hello world");
       return 0;
   }
   ```

   ```shell
   # 新建一个编译目录
   mkdir build
   # 使用 cmake 编译上层文件
   cd build
   # cmake -DCMAKE_BUILD_TYPE=Release ..
   # cmake -DCMAKE_BUILD_TYPE=Debug ..
   cmake ..
   # 编译源文件
   cmake --build .
   # 执行
   .\Debug\myshell.exe hello
   ```

   
