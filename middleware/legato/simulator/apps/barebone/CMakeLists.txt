cmake_minimum_required(VERSION 3.14)
project(sim_barebone)

add_executable(sim_barebone)

# find the app files
file(GLOB_RECURSE srcList ./*.c)

# app include files
target_include_directories(sim_barebone PRIVATE .)
target_include_directories(sim_barebone PRIVATE ./generated/)

target_sources(sim_barebone PRIVATE ${sharedSourceList})
target_sources(sim_barebone PRIVATE ${srcList})

# application options
set(SIM_FRAME_BUFFER_COUNT "1" CACHE STRING "The number of frame buffers to simulate.")
set_property(CACHE SIM_FRAME_BUFFER_COUNT PROPERTY TYPE STRING)

set(SIM_DISPLAY_WIDTH "480" CACHE STRING "The width of the frame buffer.")
set_property(CACHE SIM_DISPLAY_WIDTH PROPERTY TYPE STRING)

set(SIM_DISPLAY_HEIGHT "272" CACHE STRING "The height of the frame buffer.")
set_property(CACHE SIM_DISPLAY_HEIGHT PROPERTY TYPE STRING)

set(COLOR_MODES "LE_COLOR_MODE_RGB_565")

set(SIM_COLOR_MODE "LE_COLOR_MODE_RGB_565" CACHE STRING "The display color mode.")
set_property(CACHE SIM_COLOR_MODE PROPERTY STRINGS ${COLOR_MODES})

add_definitions(-DSIM_FRAME_BUFFER_COUNT=${SIM_FRAME_BUFFER_COUNT})
add_definitions(-DSIM_DISPLAY_WIDTH=${SIM_DISPLAY_WIDTH})
add_definitions(-DSIM_DISPLAY_HEIGHT=${SIM_DISPLAY_HEIGHT})
add_definitions(-DSIM_COLOR_MODE=${SIM_COLOR_MODE})