project(breakpad_handler)

include_directories(${srcDir})
link_libraries(breakpad_crash_generation)

add_library(breakpad_handler STATIC
            ${srcDir}/client/linux/handler/exception_handler.cc
            ${srcDir}/client/linux/handler/exception_handler.h
            ${srcDir}/client/linux/handler/minidump_descriptor.cc
            ${srcDir}/client/linux/handler/minidump_descriptor.h
            ${srcDir}/client/linux/crash_generation/crash_generation_client.cc
            ${srcDir}/client/linux/crash_generation/crash_generation_server.cc
            ${srcDir}/client/linux/dump_writer_common/thread_info.cc
            ${srcDir}/client/linux/dump_writer_common/ucontext_reader.cc
            ${srcDir}/client/linux/log/log.cc
            ${srcDir}/client/linux/log/log.h
            ${srcDir}/client/linux/microdump_writer/microdump_writer.cc
            ${srcDir}/client/linux/microdump_writer/microdump_writer.h
            ${srcDir}/client/linux/minidump_writer/linux_core_dumper.cc
            ${srcDir}/client/linux/minidump_writer/linux_dumper.cc
            ${srcDir}/client/linux/minidump_writer/linux_ptrace_dumper.cc
            ${srcDir}/client/linux/minidump_writer/minidump_writer.cc
            ${srcDir}/client/linux/minidump_writer/pe_file.cc
            ${srcDir}/client/minidump_file_writer-inl.h
            ${srcDir}/client/minidump_file_writer.cc
            ${srcDir}/client/minidump_file_writer.h
)
add_dependencies(breakpad_handler breakpad_crash_generation)
if(${CMAKE_SYSTEM_NAME} STREQUAL "Android")
    find_library(LOG_LIBRARY log)
    include_directories(${srcDir}/common/android/include)
    target_link_libraries(breakpad_handler ${LOG_LIBRARY})
endif()
