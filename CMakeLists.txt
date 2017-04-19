cmake_minimum_required(VERSION 2.8)

project(DataStructure C)

#设置路径
set(DS_WORKSPACE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(DS_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(DS_SOURCE_DIR ${DS_WORKSPACE_DIR}/src)
set(DS_INCLUDE_DIR ${DS_WORKSPACE_DIR}/include)
set(DS_TEST_DIR ${DS_WORKSPACE_DIR}/tests)

#加载头文件
include_directories(BEFORE
                    ${DS_INCLUDE_DIR})

#加载源文件
add_subdirectory(${DS_SOURCE_DIR})

#加载测试
add_subdirectory(${DS_TEST_DIR})


