cmake_minimum_required(VERSION 3.16)
project(RayTracingOneWeek)

#设置静态编译
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

set(CMAKE_CXX_STANDARD 14)
# 生成独立可执行行文件
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(RayTracingOneWeek main.cpp vec3.h color.h ray.h hittable.h sphere.h rtweekend.h camera.h hittable_list.h material.h render_thread.h cube.h)

#链接静态库
#链接boost静态库(project_Name为你的项目名，*分别代表库名、mingw版本号、boost库版本号，如：libboost_system-mgw72-mt-s-1_65_1.a)
#target_link_libraries(RayTracingOneWeek libboost_*-mgw*-mt-s-*.a)
#链接gcc-g++静态库
target_link_libraries(RayTracingOneWeek libgcc.a)
target_link_libraries(RayTracingOneWeek libstdc++.a)
#链接网络库（如需要）
target_link_libraries(RayTracingOneWeek ws2_32)
#链接线程库（必须放到最后）
target_link_libraries(RayTracingOneWeek libpthread.a)
