project(demo)

include_directories(${srcDir})

link_directories(${outDir})
link_libraries(breakpad_handler )



add_executable(demo demo.cpp)
add_dependencies(demo breakpad_handler)

set_target_properties(demo PROPERTIES
    COMPILE_OPTIONS "/Zi"
    LINK_OPTIONS "/DEBUG"
)