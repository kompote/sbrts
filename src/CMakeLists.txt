PROJECT(SBRTS)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "-std=c++0x")
SET(COMMON_WARNING_FLAGS "-Wall -Wextra -Wwrite-strings -Wshadow -Winit-self")

INCLUDE_DIRECTORIES(".")
INCLUDE_DIRECTORIES("include/")
INCLUDE_DIRECTORIES("engine/")


LINK_DIRECTORIES("${CMAKE_SOURCE_DIR}/lib/")
#LINK_DIRECTORIES("${CMAKE_SOURCE_DIR}/engine/")
#LINK_DIRECTORIES("${CMAKE_SOURCE_DIR}/core/")

file(

    GLOB_RECURSE

    source_files

    engine/*.cpp
    core/*.cpp
    engine/*.h
    core/*.h

    )

ADD_EXECUTABLE(
    Main
    main.cpp
    ${source_files}
)

target_link_libraries (Main sfml-graphics sfml-window sfml-system)
#target_link_libraries (main_martial_fps sfml-graphics sfml-window sfml-system)

