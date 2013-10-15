PROJECT(SBRTS)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "-std=c++0x")
SET(COMMON_WARNING_FLAGS "-Wall -Wextra -Wwrite-strings -Wshadow -Winit-self")

SET(SBRTS_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
SET(SBRTS_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
SET(SBRTS_LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
SET(SBRTS_BIN_OUTPUT "${CMAKE_SOURCE_DIR}/bin")

INCLUDE_DIRECTORIES(".")
INCLUDE_DIRECTORIES("${SBRTS_INCLUDE_DIR}")
INCLUDE_DIRECTORIES("${SBRTS_SOURCE_DIR}/engine")
INCLUDE_DIRECTORIES("${SBRTS_SOURCE_DIR}/core")


LINK_DIRECTORIES("${SBRTS_LIB_DIR}")
#LINK_DIRECTORIES("${CMAKE_SOURCE_DIR}/engine/")
#LINK_DIRECTORIES("${CMAKE_SOURCE_DIR}/core/")

file(

    GLOB_RECURSE

    source_files

    ${SBRTS_SOURCE_DIR}/engine/*.cpp
    ${SBRTS_SOURCE_DIR}/core/*.cpp
    ${SBRTS_SOURCE_DIR}/utils/*.cpp
    ${SBRTS_SOURCE_DIR}/engine/*.h
    ${SBRTS_SOURCE_DIR}/core/*.h
    ${SBRTS_SOURCE_DIR}/utils/*.h

    )

ADD_EXECUTABLE(
    Main
    ${SBRTS_SOURCE_DIR}/main.cpp
    ${source_files}
)

SET_TARGET_PROPERTIES(Main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SBRTS_BIN_OUTPUT})

target_link_libraries (Main sfml-graphics sfml-window sfml-system)
#target_link_libraries (main_martial_fps sfml-graphics sfml-window sfml-system) 
