project(minidump_stackwalk)


set(srcList    ${srcDir}/processor/minidump_stackwalk.cc
               ${srcDir}/common/path_helper.cc
               ${srcDir}/processor/basic_code_modules.cc
               ${srcDir}/processor/basic_source_line_resolver.cc
               ${srcDir}/processor/call_stack.cc
               ${srcDir}/processor/cfi_frame_info.cc
               ${srcDir}/processor/convert_old_arm64_context.cc
               ${srcDir}/processor/disassembler_x86.cc
               ${srcDir}/processor/dump_context.cc
               ${srcDir}/processor/dump_object.cc
               ${srcDir}/processor/exploitability.cc
               ${srcDir}/processor/exploitability_linux.cc
               ${srcDir}/processor/exploitability_win.cc
               ${srcDir}/processor/logging.cc
               ${srcDir}/processor/minidump.cc
               ${srcDir}/processor/minidump_processor.cc
               ${srcDir}/processor/pathname_stripper.cc
               ${srcDir}/processor/process_state.cc
               ${srcDir}/processor/proc_maps_linux.cc
               ${srcDir}/processor/simple_symbol_supplier.cc
               ${srcDir}/processor/source_line_resolver_base.cc
               ${srcDir}/processor/stack_frame_cpu.cc
               ${srcDir}/processor/stack_frame_symbolizer.cc
               ${srcDir}/processor/stackwalk_common.cc
               ${srcDir}/processor/stackwalker.cc
               ${srcDir}/processor/stackwalker_address_list.cc
               ${srcDir}/processor/stackwalker_amd64.cc
               ${srcDir}/processor/stackwalker_arm.cc
               ${srcDir}/processor/stackwalker_arm64.cc
               ${srcDir}/processor/stackwalker_mips.cc
               ${srcDir}/processor/stackwalker_ppc.cc
               ${srcDir}/processor/stackwalker_ppc64.cc
               ${srcDir}/processor/stackwalker_riscv.cc
               ${srcDir}/processor/stackwalker_riscv64.cc
               ${srcDir}/processor/stackwalker_sparc.cc
               ${srcDir}/processor/stackwalker_x86.cc
               ${srcDir}/processor/symbolic_constants_win.cc
               ${srcDir}/processor/tokenize.cc
)

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

link_libraries(libdisasm)
include_directories(${srcDir})
add_executable(${PROJECT_NAME} ${srcList})