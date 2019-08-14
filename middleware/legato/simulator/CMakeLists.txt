cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD 99)
set(CMAKE_SYSTEM_PROCESSOR "i686")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE OFF)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_compile_definitions(LINUX=1)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    add_compile_definitions(WINDOWS=1)
endif()

# include dependency on SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# find the legato source files
file(GLOB_RECURSE srcList ./legato/gfx/legato/*.c)

foreach(filePath ${srcList})
    if(NOT ${filePath} MATCHES "^.*rtos.*$")
        list(APPEND sharedSourceList ${filePath})
    endif()
endforeach()

# find the simulator source files
file(GLOB_RECURSE srcList ./src/*.c)

foreach(filePath ${srcList})
    list(APPEND sharedSourceList ${filePath})
endforeach()

add_compile_options(-m32)
add_compile_options(-Wall)

include_directories(./legato)
include_directories(./src)

add_link_options(-m32)

link_libraries(${SDL2_LIBRARIES} "m")

add_definitions(-DLEGATO_SIM)

add_subdirectory(apps/barebone)
add_subdirectory(apps/benchmark)
add_subdirectory(apps/monitor)
add_subdirectory(apps/quickstart)
add_subdirectory(apps/showcase)