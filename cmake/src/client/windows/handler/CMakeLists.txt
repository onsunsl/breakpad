project(breakpad_handler)

include_directories(${srcDir})

link_libraries(breakpad_crash_generation)

add_library(breakpad_handler STATIC
    ${srcDir}/client/windows/handler/exception_handler.cc
    ${srcDir}/client/windows/handler/exception_handler.h
)