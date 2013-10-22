PROJECT(SBRTS)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "-std=c++0x")
SET(COMMON_WARNING_FLAGS "-Wall -Wextra -Wwrite-strings -Wshadow -Winit-self")

SET(SBRTS_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
SET(SBRTS_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
SET(SBRTS_LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
SET(SBRTS_BIN_OUTPUT "./bin")
SET(SBRTS_DOC_DIR "${CMAKE_SOURCE_DIR}/docs")

# Documentation
INCLUDE(cmake-modules/sbrts_doc.cmake)

INCLUDE_DIRECTORIES("${SBRTS_INCLUDE_DIR}")

LINK_DIRECTORIES("${SBRTS_LIB_DIR}")

file(
    GLOB_RECURSE
    source_files
    ${SBRTS_SOURCE_DIR}/*
    )
file(
	COPY ${SBRTS_SOURCE_DIR}/resources/ DESTINATION ${SBRTS_BIN_OUTPUT}/resources
	)

ADD_EXECUTABLE(
    Main
    ${SBRTS_SOURCE_DIR}/main.cpp
    ${source_files}
)

SET_TARGET_PROPERTIES(Main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SBRTS_BIN_OUTPUT})

target_link_libraries (Main sfml-graphics sfml-window sfml-system)



