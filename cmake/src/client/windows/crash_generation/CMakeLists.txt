project(breakpad_crash_generation)


set(srcList ${srcDir}/client/windows/crash_generation/client_info.cc
            ${srcDir}/client/windows/crash_generation/client_info.h
            ${srcDir}/client/windows/crash_generation/crash_generation_client.cc
            ${srcDir}/client/windows/crash_generation/crash_generation_client.h
            ${srcDir}/client/windows/crash_generation/crash_generation_server.cc
            ${srcDir}/client/windows/crash_generation/crash_generation_server.h
            ${srcDir}/client/windows/crash_generation/minidump_generator.cc
            ${srcDir}/client/windows/crash_generation/minidump_generator.h
)

enable_language(ASM)
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -x assembler-with-cpp")

include_directories(${srcDir})
link_libraries(breakpad_common)

add_library(breakpad_crash_generation STATIC ${srcList})