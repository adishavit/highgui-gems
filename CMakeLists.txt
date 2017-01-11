project(highgui_gems)
cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(highgui_gems highgui_gems.cpp)
target_link_libraries(highgui_gems ${OpenCV_LIBS})


if(UNIX  OR CMAKE_COMPILER_IS_GNUCXX)

    SET(CMAKE_CXX_FLAGS "-Wall -std=c++1z" CACHE STRING "compile flags" FORCE )

elseif(MSVC)

   add_definitions(/D_CRT_SECURE_NO_WARNINGS)
   add_definitions(/D_SCL_SECURE_NO_WARNINGS)
   add_definitions(/DNOMINMAX)
   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
   
endif()


