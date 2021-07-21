cmake_minimum_required(VERSION 3.9)

project(CAPTSURVEY)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(src main.cpp CaptFactory.cpp)
set(headers CaptFactory.h)

add_executable(CAPTSURVEY ${src} ${headers})

target_link_libraries(${PROJECT_NAME} PRIVATE Capt PluginSystem)
target_include_directories(${PROJECT_NAME} PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/> $<INSTALL_INTERFACE:>)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

add_subdirectory(LibCapt)
add_subdirectory(PluginCaptSurvey)
add_subdirectory(PluginSystem)
add_subdirectory(PluginGps)

