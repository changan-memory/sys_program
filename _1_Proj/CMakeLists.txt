cmake_minimum_required(VERSION 3.5)

project(cmake_swap)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall") # 设置编译信息

include_directories(${CMAKE_SOURCE_DIR}/include) # 包含头文件
# ${CMAKE_SOURCE_DIR}/include 代表cmakelists 所在目录下的的 include 文件夹

# 包含源文件
# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC)

# file(GLOB/GLOB_RECURSE 变量名 要搜索的文件路径和文件类型)

file(GLOB SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")  # 把搜索到的文件存在变量 SRC 中

# 设置静态库/动态库输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 制作静态库   动态库
add_library(math STATIC ${SRC})
add_library(cal SHARED ${SRC})

# 包含静态库路径
link_directories(${PROJECT_SOURCE_DIR}/lib)

# 链接静态库
link_libraries(math)


add_executable(proj_exe ${SRC} main.cpp )

# 链接动态库
target_link_libraries(proj_exe cal)