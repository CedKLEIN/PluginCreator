cmake_minimum_required(VERSION 3.9)

project(PluginCaptSurvey)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(src PluginSurvey.cpp PluginSurveyCreator.cpp)
set(headers PluginSurvey.h)

add_library(${PROJECT_NAME} SHARED ${src} ${headers})


target_link_libraries(${PROJECT_NAME} LINK_PUBLIC Capt)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/> $<INSTALL_INTERFACE:>)
install(TARGETS ${PROJECT_NAME} DESTINATION Libs)

