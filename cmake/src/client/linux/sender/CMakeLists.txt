project(breakpad_sender)

include_directories(${srcDir})

add_library(breakpad_sender STATIC
            ${srcDir}/client/linux/sender/google_crash_report_sender.cc
)