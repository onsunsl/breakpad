project(breakpad_sender)

include_directories(${srcDir})

add_library(breakpad_sender STATIC
            ${srcDir}/client/windows/sender/crash_report_sender.cc
            ${srcDir}/client/windows/sender/crash_report_sender.h
)