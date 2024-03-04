project(minidump_dump)


include_directories(${srcDir})


set(srcList ${srcDir}/processor/minidump_dump.cc
            ${srcDir}/processor/basic_code_modules.cc
            ${srcDir}/processor/convert_old_arm64_context.cc
            ${srcDir}/processor/dump_context.cc
            ${srcDir}/processor/dump_object.cc
            ${srcDir}/processor/logging.cc
            ${srcDir}/processor/minidump.cc
            ${srcDir}/processor/pathname_stripper.cc
            ${srcDir}/processor/proc_maps_linux.cc
            ${srcDir}/common/path_helper.cc)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux" OR ${CMAKE_SYSTEM_NAME} STREQUAL "Android")
    list(APPEND srcList ${srcDir}/common/linux/scoped_pipe.h
                        ${srcDir}/common/linux/scoped_pipe.cc
                        ${srcDir}/common/linux/scoped_tmpfile.h
                        ${srcDir}/common/linux/scoped_tmpfile.cc
                        ${srcDir}/processor/disassembler_objdump.h
                        ${srcDir}/processor/disassembler_objdump.cc
                        ${srcDir}/common/linux/breakpad_getcontext.S
    )
endif()


add_executable(minidump_dump ${srcList})
