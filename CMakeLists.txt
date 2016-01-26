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
        textures/characters/*.cpp
        textures/characters/*.h
        utilities/*.cpp
        utilities/*.h
)

set(SOURCE_FILES ${SOURCES} utilities/TextureInfo.cpp utilities/TextureInfo.h)
add_executable(IndividualProject ${SOURCE_FILES} main.cpp)

target_link_libraries(IndividualProject ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})