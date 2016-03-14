cmake_minimum_required(VERSION 3.3)
project(IndividualProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

file(GLOB SOURCES
        Code/utilities/*.cpp
        Code/utilities/*.h
        Code/media/*.cpp
        Code/media/*.h
        Code/UI/*.cpp
        Code/UI/*.h
        Code/terrain/*.cpp
        Code/terrain/*.h
        Code/*.cpp
        Code/*.h

        Code/Characters/*.cpp
        Code/Characters/*.h
        Code/Characters/Enemies/*.cpp
        Code/Characters/Enemies/*.h
)

set(SOURCE_FILES ${SOURCES})
add_executable(IndividualProject ${SOURCE_FILES} main.cpp)

target_link_libraries(IndividualProject ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})