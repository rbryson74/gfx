cmake_minimum_required(VERSION 3.14)
project(legato_sim C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_SYSTEM_PROCESSOR "i686")

# include dependency on SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#include_directories(./gfx/middleware/library/src/)

add_executable(legato_sim)
set_target_properties(legato_sim PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
set(CMAKE_BUILD_TYPE Debug)


# add legato sources
set(LEGATO_SRC_DIR "../library/src/gfx/legato")

target_include_directories(legato_sim PRIVATE ../library/src)

target_sources(legato_sim
        PRIVATE
        ${LEGATO_SRC_DIR}/common/legato_color.c
        ${LEGATO_SRC_DIR}/common/legato_color.h
        ${LEGATO_SRC_DIR}/common/legato_color_blend.c
        ${LEGATO_SRC_DIR}/common/legato_color_convert.c
        ${LEGATO_SRC_DIR}/common/legato_color_lerp.c
        ${LEGATO_SRC_DIR}/common/legato_color_value.c
        ${LEGATO_SRC_DIR}/common/legato_common.h
        ${LEGATO_SRC_DIR}/common/legato_error.c
        ${LEGATO_SRC_DIR}/common/legato_error.h
        ${LEGATO_SRC_DIR}/common/legato_math.c
        ${LEGATO_SRC_DIR}/common/legato_math.h
        ${LEGATO_SRC_DIR}/common/legato_pixelbuffer.c
        ${LEGATO_SRC_DIR}/common/legato_pixelbuffer.h
        ${LEGATO_SRC_DIR}/common/legato_rect.c
        ${LEGATO_SRC_DIR}/common/legato_rect.h
        ${LEGATO_SRC_DIR}/common/legato_utils.c
        ${LEGATO_SRC_DIR}/common/legato_utils.h
        ${LEGATO_SRC_DIR}/core/legato_event.c
        ${LEGATO_SRC_DIR}/core/legato_event.h
        ${LEGATO_SRC_DIR}/core/legato_input.c
        ${LEGATO_SRC_DIR}/core/legato_input.h
        ${LEGATO_SRC_DIR}/core/legato_scheme.c
        ${LEGATO_SRC_DIR}/core/legato_scheme.h
        ${LEGATO_SRC_DIR}/core/legato_state.c
        ${LEGATO_SRC_DIR}/core/legato_state.h
        ${LEGATO_SRC_DIR}/core/legato_stream.c
        ${LEGATO_SRC_DIR}/datastructure/legato_array.c
        ${LEGATO_SRC_DIR}/datastructure/legato_array.h
        ${LEGATO_SRC_DIR}/datastructure/legato_list.c
        ${LEGATO_SRC_DIR}/datastructure/legato_list.h
        ${LEGATO_SRC_DIR}/datastructure/legato_rectarray.c
        ${LEGATO_SRC_DIR}/datastructure/legato_rectarray.h
        ${LEGATO_SRC_DIR}/font/legato_font.c
        ${LEGATO_SRC_DIR}/font/legato_font.h
        ${LEGATO_SRC_DIR}/font/legato_rasterfont_liberationmono1.c
        ${LEGATO_SRC_DIR}/font/legato_rasterfont_liberationmono8.c
        ${LEGATO_SRC_DIR}/font/legato_rasterfont_stream.c
        ${LEGATO_SRC_DIR}/image/legato_image.c
        ${LEGATO_SRC_DIR}/image/legato_image.h
        ${LEGATO_SRC_DIR}/image/legato_image_utils.c
        ${LEGATO_SRC_DIR}/image/legato_image_utils.h
        ${LEGATO_SRC_DIR}/image/legato_palette.c
        ${LEGATO_SRC_DIR}/image/legato_palette.h
        ${LEGATO_SRC_DIR}/image/raw/legato_imagedecoder_raw.h
        ${LEGATO_SRC_DIR}/image/raw/legato_imagedecoder_raw.c
        ${LEGATO_SRC_DIR}/image/raw/legato_imagedecoder_raw_blend.c
        ${LEGATO_SRC_DIR}/image/raw/legato_imagedecoder_raw_convert.c
        ${LEGATO_SRC_DIR}/image/raw/legato_imagedecoder_raw_mask.c
        ${LEGATO_SRC_DIR}/image/raw/legato_imagedecoder_raw_palette_internal.c
        ${LEGATO_SRC_DIR}/image/raw/legato_imagedecoder_raw_palette_stream.c
        ${LEGATO_SRC_DIR}/image/raw/legato_imagedecoder_raw_read_internal.c
        ${LEGATO_SRC_DIR}/image/raw/legato_imagedecoder_raw_read_stream.c
        ${LEGATO_SRC_DIR}/image/raw/legato_imagedecoder_raw_write.c
        ${LEGATO_SRC_DIR}/memory/legato_fixedheap.c
        ${LEGATO_SRC_DIR}/memory/legato_fixedheap.h
        ${LEGATO_SRC_DIR}/memory/legato_memory.c
        ${LEGATO_SRC_DIR}/memory/legato_memory.h
        ${LEGATO_SRC_DIR}/memory/legato_variableheap.c
        ${LEGATO_SRC_DIR}/memory/legato_variableheap.h
        ${LEGATO_SRC_DIR}/renderer/legato_draw.c
        ${LEGATO_SRC_DIR}/renderer/legato_draw_arc.c
        ${LEGATO_SRC_DIR}/renderer/legato_draw_line.c
        ${LEGATO_SRC_DIR}/renderer/legato_draw_rect.c
        ${LEGATO_SRC_DIR}/renderer/legato_driver.h
        ${LEGATO_SRC_DIR}/renderer/legato_renderer.c
        ${LEGATO_SRC_DIR}/renderer/legato_renderer.h
        ${LEGATO_SRC_DIR}/string/legato_dynamicstring.c
        ${LEGATO_SRC_DIR}/string/legato_dynamicstring.h
        ${LEGATO_SRC_DIR}/string/legato_fixedstring.c
        ${LEGATO_SRC_DIR}/string/legato_fixedstring.h
        ${LEGATO_SRC_DIR}/string/legato_string.c
        ${LEGATO_SRC_DIR}/string/legato_string.h
        ${LEGATO_SRC_DIR}/string/legato_string_renderer.c
        ${LEGATO_SRC_DIR}/string/legato_string_renderer.h
        ${LEGATO_SRC_DIR}/string/legato_string_renderer_stream.c
        ${LEGATO_SRC_DIR}/string/legato_tablestring.c
        ${LEGATO_SRC_DIR}/string/legato_tablestring.h
        ${LEGATO_SRC_DIR}/string/legato_stringtable.c
        ${LEGATO_SRC_DIR}/string/legato_stringtable.h
        ${LEGATO_SRC_DIR}/string/legato_stringutils.h
        ${LEGATO_SRC_DIR}/string/legato_stringutils.c
        ${LEGATO_SRC_DIR}/widget/arc/legato_widget_arc.c
        ${LEGATO_SRC_DIR}/widget/arc/legato_widget_arc.h
        ${LEGATO_SRC_DIR}/widget/arc/legato_widget_arc_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/bargraph/legato_widget_bar_graph.c
        ${LEGATO_SRC_DIR}/widget/bargraph/legato_widget_bar_graph.h
        ${LEGATO_SRC_DIR}/widget/bargraph/legato_widget_bar_graph_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/button/legato_widget_button.c
        ${LEGATO_SRC_DIR}/widget/button/legato_widget_button.h
        ${LEGATO_SRC_DIR}/widget/button/legato_widget_button_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/checkbox/legato_widget_checkbox.c
        ${LEGATO_SRC_DIR}/widget/checkbox/legato_widget_checkbox.h
        ${LEGATO_SRC_DIR}/widget/checkbox/legato_widget_checkbox_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/circle/legato_widget_circle.c
        ${LEGATO_SRC_DIR}/widget/circle/legato_widget_circle.h
        ${LEGATO_SRC_DIR}/widget/circle/legato_widget_circle_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/circulargauge/legato_widget_circular_gauge.c
        ${LEGATO_SRC_DIR}/widget/circulargauge/legato_widget_circular_gauge.h
        ${LEGATO_SRC_DIR}/widget/circulargauge/legato_widget_circular_gauge_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/circularslider/legato_widget_circular_slider.c
        ${LEGATO_SRC_DIR}/widget/circularslider/legato_widget_circular_slider.h
        ${LEGATO_SRC_DIR}/widget/circularslider/legato_widget_circular_slider_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/drawsurface/legato_widget_drawsurface.c
        ${LEGATO_SRC_DIR}/widget/drawsurface/legato_widget_drawsurface.h
        ${LEGATO_SRC_DIR}/widget/drawsurface/legato_widget_drawsurface_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/gradient/legato_widget_gradient.c
        ${LEGATO_SRC_DIR}/widget/gradient/legato_widget_gradient.h
        ${LEGATO_SRC_DIR}/widget/gradient/legato_widget_gradient_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/groupbox/legato_widget_groupbox.c
        ${LEGATO_SRC_DIR}/widget/groupbox/legato_widget_groupbox.h
        ${LEGATO_SRC_DIR}/widget/groupbox/legato_widget_groupbox_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/image/legato_widget_image.c
        ${LEGATO_SRC_DIR}/widget/image/legato_widget_image.h
        ${LEGATO_SRC_DIR}/widget/image/legato_widget_image_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/imageplus/legato_widget_imageplus.c
        ${LEGATO_SRC_DIR}/widget/imageplus/legato_widget_imageplus.h
        ${LEGATO_SRC_DIR}/widget/imageplus/legato_widget_imageplus_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/imagesequence/legato_widget_imagesequence.c
        ${LEGATO_SRC_DIR}/widget/imagesequence/legato_widget_imagesequence.h
        ${LEGATO_SRC_DIR}/widget/imagesequence/legato_widget_imagesequence_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/keypad/legato_widget_keypad.c
        ${LEGATO_SRC_DIR}/widget/keypad/legato_widget_keypad.h
        ${LEGATO_SRC_DIR}/widget/keypad/legato_widget_keypad_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/label/legato_widget_label.c
        ${LEGATO_SRC_DIR}/widget/label/legato_widget_label.h
        ${LEGATO_SRC_DIR}/widget/label/legato_widget_label_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/line/legato_widget_line.c
        ${LEGATO_SRC_DIR}/widget/line/legato_widget_line.h
        ${LEGATO_SRC_DIR}/widget/line/legato_widget_line_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/linegraph/legato_widget_line_graph.c
        ${LEGATO_SRC_DIR}/widget/linegraph/legato_widget_line_graph.h
        ${LEGATO_SRC_DIR}/widget/linegraph/legato_widget_line_graph_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/list/legato_widget_list.c
        ${LEGATO_SRC_DIR}/widget/list/legato_widget_list.h
        ${LEGATO_SRC_DIR}/widget/list/legato_widget_list_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/listwheel/legato_widget_listwheel.c
        ${LEGATO_SRC_DIR}/widget/listwheel/legato_widget_listwheel.h
        ${LEGATO_SRC_DIR}/widget/listwheel/legato_widget_listwheel_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/piechart/legato_widget_pie_chart.c
        ${LEGATO_SRC_DIR}/widget/piechart/legato_widget_pie_chart.h
        ${LEGATO_SRC_DIR}/widget/piechart/legato_widget_pie_chart_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/progressbar/legato_widget_progressbar.c
        ${LEGATO_SRC_DIR}/widget/progressbar/legato_widget_progressbar.h
        ${LEGATO_SRC_DIR}/widget/progressbar/legato_widget_progressbar_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/radialmenu/legato_widget_radial_menu.c
        ${LEGATO_SRC_DIR}/widget/radialmenu/legato_widget_radial_menu.h
        ${LEGATO_SRC_DIR}/widget/radialmenu/legato_widget_radial_menu_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/radiobutton/legato_radiobutton_group.c
        ${LEGATO_SRC_DIR}/widget/radiobutton/legato_radiobutton_group.h
        ${LEGATO_SRC_DIR}/widget/radiobutton/legato_widget_radiobutton.c
        ${LEGATO_SRC_DIR}/widget/radiobutton/legato_widget_radiobutton.h
        ${LEGATO_SRC_DIR}/widget/radiobutton/legato_widget_radiobutton_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/rectangle/legato_widget_rectangle.c
        ${LEGATO_SRC_DIR}/widget/rectangle/legato_widget_rectangle.h
        ${LEGATO_SRC_DIR}/widget/rectangle/legato_widget_rectangle_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/scrollbar/legato_widget_scrollbar.c
        ${LEGATO_SRC_DIR}/widget/scrollbar/legato_widget_scrollbar.h
        ${LEGATO_SRC_DIR}/widget/scrollbar/legato_widget_scrollbar_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/slider/legato_widget_slider.c
        ${LEGATO_SRC_DIR}/widget/slider/legato_widget_slider.h
        ${LEGATO_SRC_DIR}/widget/slider/legato_widget_slider_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/textfield/legato_widget_textfield.c
        ${LEGATO_SRC_DIR}/widget/textfield/legato_widget_textfield.h
        ${LEGATO_SRC_DIR}/widget/textfield/legato_widget_textfield_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/touchtest/legato_widget_touchtest.c
        ${LEGATO_SRC_DIR}/widget/touchtest/legato_widget_touchtest.h
        ${LEGATO_SRC_DIR}/widget/touchtest/legato_widget_touchtest_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/window/legato_widget_window.c
        ${LEGATO_SRC_DIR}/widget/window/legato_widget_window.h
        ${LEGATO_SRC_DIR}/widget/window/legato_widget_window_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/legato_editwidget.c
        ${LEGATO_SRC_DIR}/widget/legato_editwidget.h
        ${LEGATO_SRC_DIR}/widget/legato_widget.c
        ${LEGATO_SRC_DIR}/widget/legato_widget.h
        ${LEGATO_SRC_DIR}/widget/legato_widget_skin_classic.c
        ${LEGATO_SRC_DIR}/widget/legato_widget_skin_classic_common.c
        ${LEGATO_SRC_DIR}/widget/legato_widget_skin_classic_common.h
        ${LEGATO_SRC_DIR}/legato.h)

# add simulator sources
include_directories(src)

target_sources(legato_sim
        PRIVATE
        src/main.c
        src/sim_driver.c
        src/sim_driver.h
        src/sim_extmem.c
        src/sim_extmem.h
        src/sim_legato.c
        src/sim_legato.h
        #src/sim_memory.c
        #src/sim_memory.h
        src/sim_time.c
        src/sim_time.h
        src/sim_touch.c
        src/sim_touch.h)

set(APP_NAMES "Barebone;Benchmark;Monitor")

set(SIM_APP_NAME "Barebone" CACHE STRING "The demo application to use with the simulator")
set_property(CACHE SIM_APP_NAME PROPERTY STRINGS ${APP_NAMES})

if(SIM_APP_NAME STREQUAL "Barebone")
    target_include_directories(legato_sim PRIVATE apps/barebone)

    target_sources(legato_sim
            PRIVATE
            apps/barebone/sim_app.c
            apps/barebone/legato_config.h)

    set(SIM_FRAME_BUFFER_COUNT "1" CACHE STRING "The number of frame buffers to simulate.")
    set_property(CACHE SIM_FRAME_BUFFER_COUNT PROPERTY TYPE STRING)

    set(SIM_DISPLAY_WIDTH "480" CACHE STRING "The width of the frame buffer.")
    set_property(CACHE SIM_DISPLAY_WIDTH PROPERTY TYPE STRING)

    set(SIM_DISPLAY_HEIGHT "272" CACHE STRING "The height of the frame buffer.")
    set_property(CACHE SIM_DISPLAY_HEIGHT PROPERTY TYPE STRING)

    set(COLOR_MODES "LE_COLOR_MODE_RGB_565;LE_COLOR_MODE_RGB_888")

    set(SIM_COLOR_MODE "LE_COLOR_MODE_RGB_565" CACHE STRING "The display color mode.")
    set_property(CACHE SIM_COLOR_MODE PROPERTY STRINGS ${COLOR_MODES})

elseif(SIM_APP_NAME STREQUAL "Benchmark")
    target_include_directories(legato_sim PRIVATE apps/benchmark/app)

    target_sources(legato_sim
            PRIVATE
            apps/benchmark/app/sim_app.c
            apps/benchmark/app/screen_FPSCounters.c
            apps/benchmark/app/screen_FPSImages.c
            apps/benchmark/app/screen_FPSMotion.c
            apps/benchmark/app/screen_SplashScreen.c)

    target_include_directories(legato_sim PRIVATE apps/benchmark/generated)

    file(GLOB_RECURSE fileList
            "apps/benchmark/generated/*.c"
            "apps/benchmark/generated/*.h")

    target_sources(legato_sim PRIVATE ${fileList})

    unset(SIM_FRAME_BUFFER_COUNT CACHE)
    unset(SIM_DISPLAY_WIDTH CACHE)
    unset(SIM_DISPLAY_HEIGHT CACHE)
    unset(SIM_COLOR_MODE CACHE)

    add_compile_definitions(SIM_FRAME_BUFFER_COUNT=1)
    add_compile_definitions(SIM_DISPLAY_WIDTH=480)
    add_compile_definitions(SIM_DISPLAY_HEIGHT=272)
    add_compile_definitions(SIM_COLOR_MODE=LE_COLOR_MODE_RGB_565)

elseif(SIM_APP_NAME STREQUAL "Monitor")
    target_include_directories(legato_sim PRIVATE apps/monitor)

    target_sources(legato_sim
            PRIVATE
            apps/monitor/sim_app.c
            apps/monitor/screen_default.c)

    target_include_directories(legato_sim PRIVATE apps/monitor/generated)

    file(GLOB_RECURSE fileList
            "apps/monitor/generated/*.c"
            "apps/monitor/generated/*.h")

    target_sources(legato_sim PRIVATE ${fileList})

    unset(SIM_FRAME_BUFFER_COUNT CACHE)
    unset(SIM_DISPLAY_WIDTH CACHE)
    unset(SIM_DISPLAY_HEIGHT CACHE)
    unset(SIM_COLOR_MODE CACHE)

    add_compile_definitions(SIM_FRAME_BUFFER_COUNT=1)
    add_compile_definitions(SIM_DISPLAY_WIDTH=320)
    add_compile_definitions(SIM_DISPLAY_HEIGHT=480)
    add_compile_definitions(SIM_COLOR_MODE=LE_COLOR_MODE_RGB_565)

elseif(SIM_APP_NAME STREQUAL "Showcase")
    target_include_directories(legato_sim PRIVATE apps/showcase)

    target_sources(legato_sim
            PRIVATE
            apps/showcase/sim_app.c
            apps/showcase/screen_ListWheel.c
            apps/showcase/screen_MainMenu.c
            apps/showcase/screen_Splash.c)

    target_include_directories(legato_sim PRIVATE apps/showcase/generated)

    file(GLOB_RECURSE fileList
            "apps/showcase/generated/*.c"
            "apps/showcase/generated/*.h")

    target_sources(legato_sim PRIVATE ${fileList})

    unset(SIM_FRAME_BUFFER_COUNT CACHE)
    unset(SIM_DISPLAY_WIDTH CACHE)
    unset(SIM_DISPLAY_HEIGHT CACHE)
    unset(SIM_COLOR_MODE CACHE)

    add_compile_definitions(SIM_FRAME_BUFFER_COUNT=1)
    add_compile_definitions(SIM_DISPLAY_WIDTH=480)
    add_compile_definitions(SIM_DISPLAY_HEIGHT=320)
    add_compile_definitions(SIM_COLOR_MODE=LE_COLOR_MODE_RGB_565)

elseif(SIM_APP_NAME STREQUAL "ComposerTest")
    target_include_directories(legato_sim PRIVATE apps/barebone)

    target_sources(legato_sim
            PRIVATE
            apps/barebone/sim_app.c
            )

    target_include_directories(legato_sim PRIVATE apps/barebone/generated)

    file(GLOB fileList
            "apps/barebone/generated/gfx/legato/generated/*.c"
            "apps/barebone/generated/gfx/legato/generated/*.h")

    target_sources(legato_sim PRIVATE ${fileList})

    unset(SIM_FRAME_BUFFER_COUNT CACHE)
    unset(SIM_DISPLAY_WIDTH CACHE)
    unset(SIM_DISPLAY_HEIGHT CACHE)
    unset(SIM_COLOR_MODE CACHE)

    add_compile_definitions(SIM_FRAME_BUFFER_COUNT=1)
    add_compile_definitions(SIM_DISPLAY_WIDTH=480)
    add_compile_definitions(SIM_DISPLAY_HEIGHT=272)
    add_compile_definitions(SIM_COLOR_MODE=LE_COLOR_MODE_RGB_565)

endif()

target_link_libraries(legato_sim ${SDL2_LIBRARIES} "m")

target_compile_options(legato_sim PRIVATE -Wall)
#target_compile_options(legato_sim PRIVATE -Werror -Wall)
#target_compile_options(legato_sim PRIVATE -Wall -Wextra)

#set(CMAKE_VERBOSE_MAKEFILE True)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_compile_definitions(LINUX=1)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    add_compile_definitions(WINDOWS=1)
endif()