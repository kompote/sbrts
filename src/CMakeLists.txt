PROJECT(SBRTS)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "-std=c++0x")
SET(COMMON_WARNING_FLAGS "-Wall -Wextra -Wwrite-strings -Wshadow -Winit-self")

INCLUDE_DIRECTORIES(".")
INCLUDE_DIRECTORIES("include/")

LINK_DIRECTORIES("lib/")

ADD_EXECUTABLE(
       main
      	main.cpp
)

#ADD_EXECUTABLE(
#        main_martial_fps
#       	main_martial_fps.cpp
#)

target_link_libraries (main sfml-graphics sfml-window sfml-system)
#target_link_libraries (main_martial_fps sfml-graphics sfml-window sfml-system)

