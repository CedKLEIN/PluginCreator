cmake_minimum_required(VERSION 3.9)

project(PluginSystem)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)

set(src PluginSystem.cpp)
set(headers PluginSystem.h)

add_library(${PROJECT_NAME} ${src} ${headers})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC dl)
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")
target_include_directories(${PROJECT_NAME} PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/> $<INSTALL_INTERFACE:>)
install(TARGETS ${PROJECT_NAME} DESTINATION Libs)

