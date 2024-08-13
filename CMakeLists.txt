cmake_minimum_required(VERSION 3.5)

set(CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  Graph
  LANGUAGES CXX)

file(GLOB MY_SRCS ./**/src/*)
file(GLOB MY_HEADRS ./**/include/**/*)
file(GLOB MY_EXECU ./app/*)

add_library(graphlib ${MY_SRCS} ${MY_HEADRS})
add_executable(${PROJECT_NAME} ${MY_EXECU})

IF(WIN32)
  target_include_directories(graphlib PRIVATE ${CMAKE_SOURCE_DIR}/**/include %userprofile%/workspace/eigen)
  target_include_directories(Graph PRIVATE ${CMAKE_SOURCE_DIR}/**/include ${CMAKE_SOURCE_DIR}/app %userprofile%/workspace/eigen)
ELSE()
  target_include_directories(graphlib PRIVATE ${CMAKE_SOURCE_DIR}/**/include ~/workspace/eigen)
  target_include_directories(Graph PRIVATE ${CMAKE_SOURCE_DIR}/**/include ~/workspace/eigen)
ENDIF()

target_link_libraries(graphlib PRIVATE)
target_link_libraries(Graph PRIVATE graphlib)

set_property(TARGET graphlib PROPERTY CXX_STANDARD 20)
set_property(TARGET Graph PROPERTY CXX_STANDARD 20)

add_custom_command(
  TARGET Graph POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_SOURCE_DIR}/compile_commands.json
)
