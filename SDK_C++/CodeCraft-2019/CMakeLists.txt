#1.cmake verson，指定cmake版本 
cmake_minimum_required(VERSION 3.7)

#2.project name，指定项目的名称，一般和项目的文件夹名称对应
PROJECT("CodeCraft-2019")

#SET(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

SET(CMAKE_BUILD_TYPE "release")
if (CMAKE_BUILD_TYPE STREQUAL debug)
    add_definitions(-D_DEBUG)
endif ()
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++11")

#3.head file path，头文件目录
INCLUDE_DIRECTORIES(
#${PROJECT_SOURCE_DIR}/include
#${PROJECT_SOURCE_DIR}/include/object
include
#${PROJECT_SOURCE_DIR}/lib
)

message(${PROJECT_SOURCE_DIR})

#4.source directory，源文件目录
#AUX_SOURCE_DIRECTORY(src DIR_SRCS)

#5.set environment variable，设置环境变量，编译用到的源文件全部都要放到这里，否则编译能够通过，但是执行的时候会出现各种问题，比如"symbol lookup error xxxxx , undefined symbol"
#SET(TEST_MATH
#${DIR_SRCS}
#)
#aux_source_directory(./src DIR_SRCS)
#6.add executable file，添加要编译的可执行文件
#ADD_EXECUTABLE(CodeCraft-2019 ${DIR_SRCS} )
ADD_EXECUTABLE(CodeCraft-2019 
	src/answer.cpp
	src/Road.cpp
	src/help.cpp
	src/Status.cpp
	src/Trajectory.cpp
	src/Scheduling.cpp
	src/AdjMatrixDirNetwork.cpp
	src/ShortestPathDijkstra.cpp
	src/b_dijkstra.cpp
	src/TrafficG.cpp
	src/IdentifyBasic.cpp
	src/Identify.cpp
	CodeCraft-2019.cpp
 )


#7.add link library，添加可执行文件所需要的库，比如我们用到了libm.so（命名规则：lib+name+.so），就添加该库的名称
#TARGET_LINK_LIBRARIES(${PROJECT_NAME} m)
