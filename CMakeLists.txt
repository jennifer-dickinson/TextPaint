cmake_minimum_required(VERSION 3.5)
project(final_project_paint)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    canvas.c
    canvas.h
    commands.c
    commands.h
    draw.c
    draw.h
        arguments.c
        arguments.h
    main.c
    Makefile
    README.md
    saveload.c
    saveload.h)

add_executable(final_project_paint ${SOURCE_FILES})