cmake_minimum_required(VERSION 3.15)

project(HSM_Media_Lib
  VERSION 1.0
  DESCRIPTION "HSM Media Library"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)

add_executable(${PROJECT_NAME} "src/main.cpp")

target_include_directories(${PROJECT_NAME} PRIVATE "include")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} PRIVATE hsm_media_lib)

target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall
  -Wextra
  -Wshadow
  -Wnon-virtual-dtor
  -Wcast-align -Wunused
  -Woverloaded-virtual
  -Wconversion
  -Wsign-conversion
  -Wduplicated-cond
  -Wnull-dereference
  -Wuseless-cast
  -Wdouble-promotion
  -Wformat=2
  -pedantic)

