
project(breakpad_client)
include_directories(${srcDir})

if(${CMAKE_SYSTEM_NAME} STREQUAL "Android")
    find_library(LOG_LIBRARY log)
    include_directories(${srcDir}/common/android/include)
    target_link_libraries(breakpad_handler ${LOG_LIBRARY})
endif()

add_library(${PROJECT_NAME} STATIC
    ${srcDir}/client/linux/crash_generation/crash_generation_client.cc
	${srcDir}/client/linux/crash_generation/crash_generation_server.cc
	${srcDir}/client/linux/dump_writer_common/thread_info.cc
	${srcDir}/client/linux/dump_writer_common/ucontext_reader.cc
	${srcDir}/client/linux/handler/exception_handler.cc
	${srcDir}/client/linux/handler/exception_handler.h
	${srcDir}/client/linux/handler/minidump_descriptor.cc
	${srcDir}/client/linux/handler/minidump_descriptor.h
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
	${srcDir}/common/convert_UTF.cc
	${srcDir}/common/convert_UTF.h
	${srcDir}/common/md5.cc
	${srcDir}/common/md5.h
	${srcDir}/common/string_conversion.cc
	${srcDir}/common/string_conversion.h
	${srcDir}/common/linux/elf_core_dump.cc
	${srcDir}/common/linux/elfutils.cc
	${srcDir}/common/linux/elfutils.h
	${srcDir}/common/linux/file_id.cc
	${srcDir}/common/linux/file_id.h
	${srcDir}/common/linux/guid_creator.cc
	${srcDir}/common/linux/guid_creator.h
	${srcDir}/common/linux/linux_libc_support.cc
	${srcDir}/common/linux/memory_mapped_file.cc
	${srcDir}/common/linux/safe_readlink.cc
)