project(breakpad_crash_generation)


set(srcList ${srcDir}/client/linux/crash_generation/client_info.h
            ${srcDir}/client/linux/crash_generation/crash_generation_client.cc
            ${srcDir}/client/linux/crash_generation/crash_generation_client.h
            ${srcDir}/client/linux/crash_generation/crash_generation_server.cc
            ${srcDir}/client/linux/crash_generation/crash_generation_server.h
)

enable_language(ASM)
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -x assembler-with-cpp")

include_directories(${srcDir})
link_libraries(breakpad_common)


add_library(breakpad_crash_generation STATIC ${srcList})
add_dependencies(breakpad_crash_generation breakpad_common)