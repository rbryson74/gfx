cmake_minimum_required(VERSION 3.14)
project(sim_quickstart)

add_executable(sim_quickstart)

# find the app files
file(GLOB_RECURSE srcList ./*.c)

# app include files
target_include_directories(sim_quickstart PRIVATE .)
target_include_directories(sim_quickstart PRIVATE ./generated/)

target_sources(sim_quickstart PRIVATE ${sharedSourceList})
target_sources(sim_quickstart PRIVATE ${srcList})

# application options
add_definitions(-DSIM_FRAME_BUFFER_COUNT=1)
add_definitions(-DSIM_DISPLAY_WIDTH=320)
add_definitions(-DSIM_DISPLAY_HEIGHT=480)
add_definitions(-DSIM_COLOR_MODE=LE_COLOR_MODE_RGB_565)
