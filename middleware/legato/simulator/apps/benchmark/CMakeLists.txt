cmake_minimum_required(VERSION 3.14)
project(sim_benchmark)

add_executable(sim_benchmark)

# find the app files
file(GLOB_RECURSE srcList ./*.c)

# app include files
target_include_directories(sim_benchmark PRIVATE .)
target_include_directories(sim_benchmark PRIVATE ./generated/)

target_sources(sim_benchmark PRIVATE ${sharedSourceList})
target_sources(sim_benchmark PRIVATE ${srcList})

# application options
add_definitions(-DSIM_FRAME_BUFFER_COUNT=1)
add_definitions(-DSIM_DISPLAY_WIDTH=480)
add_definitions(-DSIM_DISPLAY_HEIGHT=272)
add_definitions(-DSIM_COLOR_MODE=LE_COLOR_MODE_RGB_565)
