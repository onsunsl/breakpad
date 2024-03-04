project(breakpad_common)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Android")
    add_definitions(-DNO_STABS_SUPPORT)
    include_directories(${srcDir}/common/android/include)
else()
    link_libraries(pthread)
endif()

add_definitions(-DHAVE_A_OUT_H)

set(srcList ${srcDir}/common/linux/breakpad_getcontext.h
            ${srcDir}/common/linux/breakpad_getcontext.S
            ${srcDir}/common/linux/crc32.cc
            ${srcDir}/common/linux/crc32.h
            ${srcDir}/common/linux/dump_symbols.cc
            ${srcDir}/common/linux/dump_symbols.h
            ${srcDir}/common/linux/eintr_wrapper.h
            ${srcDir}/common/linux/elf_core_dump.cc
            ${srcDir}/common/linux/elf_core_dump.h
            ${srcDir}/common/linux/elf_gnu_compat.h
            ${srcDir}/common/linux/elf_symbols_to_module.cc
            ${srcDir}/common/linux/elf_symbols_to_module.h
            ${srcDir}/common/linux/elfutils-inl.h
            ${srcDir}/common/linux/elfutils.cc
            ${srcDir}/common/linux/elfutils.h
            ${srcDir}/common/linux/file_id.cc
            ${srcDir}/common/linux/file_id.h
            ${srcDir}/common/linux/google_crashdump_uploader.cc
            ${srcDir}/common/linux/google_crashdump_uploader.h
            ${srcDir}/common/linux/guid_creator.cc
            ${srcDir}/common/linux/guid_creator.h
            ${srcDir}/common/linux/http_upload.cc
            ${srcDir}/common/linux/http_upload.h
            ${srcDir}/common/linux/ignore_ret.h
            ${srcDir}/common/linux/libcurl_wrapper.cc
            ${srcDir}/common/linux/libcurl_wrapper.h
            ${srcDir}/common/linux/linux_libc_support.cc
            ${srcDir}/common/linux/linux_libc_support.h
            ${srcDir}/common/linux/ucontext_constants.h
            ${srcDir}/common/linux/synth_elf.h
            ${srcDir}/common/linux/synth_elf.cc
            ${srcDir}/common/linux/symbol_upload.h
            ${srcDir}/common/linux/symbol_upload.cc
            ${srcDir}/common/linux/symbol_collector_client.h
            ${srcDir}/common/linux/symbol_collector_client.cc
            ${srcDir}/common/linux/scoped_tmpfile.h
            ${srcDir}/common/linux/scoped_tmpfile.cc
            ${srcDir}/common/linux/scoped_pipe.h
            ${srcDir}/common/linux/scoped_pipe.cc
            ${srcDir}/common/linux/safe_readlink.h
            ${srcDir}/common/linux/safe_readlink.cc
            ${srcDir}/common/linux/memory_mapped_file.h
            ${srcDir}/common/linux/memory_mapped_file.cc
            ${srcDir}/common/basictypes.h
            ${srcDir}/common/byte_cursor.h
            ${srcDir}/common/convert_UTF.cc
            ${srcDir}/common/convert_UTF.h
            ${srcDir}/common/dwarf_cfi_to_module.cc
            ${srcDir}/common/dwarf_cfi_to_module.h
            ${srcDir}/common/dwarf_cu_to_module.cc
            ${srcDir}/common/dwarf_cu_to_module.h
            ${srcDir}/common/dwarf_line_to_module.cc
            ${srcDir}/common/dwarf_line_to_module.h
            ${srcDir}/common/dwarf_range_list_handler.cc
            ${srcDir}/common/dwarf_range_list_handler.h
            ${srcDir}/common/language.cc
            ${srcDir}/common/language.h
            ${srcDir}/common/long_string_dictionary.cc
            ${srcDir}/common/long_string_dictionary.h
            ${srcDir}/common/macros.h
            ${srcDir}/common/md5.cc
            ${srcDir}/common/md5.h
            ${srcDir}/common/memory_allocator.h
            ${srcDir}/common/memory_range.h
            ${srcDir}/common/minidump_type_helper.h
            ${srcDir}/common/module.cc
            ${srcDir}/common/module.h
            ${srcDir}/common/path_helper.cc
            ${srcDir}/common/path_helper.h
            ${srcDir}/common/safe_math.h
            ${srcDir}/common/scoped_ptr.h
            ${srcDir}/common/simple_string_dictionary.cc
            ${srcDir}/common/simple_string_dictionary.h
            # ${srcDir}/common/stabs_reader_unittest.cc
            # ${srcDir}/common/stabs_reader.cc
            # ${srcDir}/common/stabs_reader.h
            # ${srcDir}/common/stabs_to_module.cc
            # ${srcDir}/common/stabs_to_module.h
            ${srcDir}/common/stdio_wrapper.h
            ${srcDir}/common/string_conversion.cc
            ${srcDir}/common/string_conversion.h
            ${srcDir}/common/string_view.h
            ${srcDir}/common/symbol_data.h
            ${srcDir}/common/test_assembler.cc
            ${srcDir}/common/test_assembler.h
            ${srcDir}/common/unordered.h
            ${srcDir}/common/using_std_string.h

)

include_directories(${srcDir}
                    ${srcDir}/common/linux
                    )


add_library(breakpad_common STATIC ${srcList})

