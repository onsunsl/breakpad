project(tools)

include_directories(${srcDir})
link_libraries(breakpad_common z dl)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Android")
    include_directories(${srcDir}/common/android/include)
	add_compile_definitions(__LITTLE_ENDIAN=0 __BIG_ENDIAN=1 __BYTE_ORDER=__BIG_ENDIAN)
else()
	add_definitions(-DHAVE_A_OUT_H)
	link_libraries(breakpad_common z dl pthread)
endif()

add_executable(dump_syms
    ${srcDir}/tools/linux/dump_syms/dump_syms.cc
    ${srcDir}/common/dwarf_cfi_to_module.cc
	${srcDir}/common/dwarf_cu_to_module.cc
	${srcDir}/common/dwarf_line_to_module.cc
	${srcDir}/common/dwarf_range_list_handler.cc
	${srcDir}/common/language.cc
	${srcDir}/common/module.cc
	${srcDir}/common/path_helper.cc
	${srcDir}/common/stabs_reader.cc
	${srcDir}/common/stabs_to_module.cc
	${srcDir}/common/dwarf/bytereader.cc
	${srcDir}/common/dwarf/dwarf2diehandler.cc
	${srcDir}/common/dwarf/dwarf2reader.cc
	${srcDir}/common/dwarf/elf_reader.cc
	${srcDir}/common/linux/crc32.cc
	${srcDir}/common/linux/dump_symbols.cc
	${srcDir}/common/linux/dump_symbols.h
	${srcDir}/common/linux/elf_symbols_to_module.cc
	${srcDir}/common/linux/elf_symbols_to_module.h
	${srcDir}/common/linux/elfutils.cc
	${srcDir}/common/linux/file_id.cc
	${srcDir}/common/linux/linux_libc_support.cc
	${srcDir}/common/linux/memory_mapped_file.cc
	${srcDir}/common/linux/safe_readlink.cc
)

add_executable(symupload
	${srcDir}/common/linux/http_upload.cc
	${srcDir}/common/path_helper.cc
	${srcDir}/tools/linux/symupload/minidump_upload.cc
)


# add_executable(core2md
#     ${srcDir}/tools/linux/core2md/core2md.cc
#     ${srcDir}/common/path_helper.cc
# )
# target_link_libraries(core2md breakpad_client)


# add_executable(pid2md
#     ${srcDir}/tools/linux/pid2md/pid2md.cc
#     ${srcDir}/common/path_helper.cc
# )
# target_link_libraries(pid2md breakpad_client)
