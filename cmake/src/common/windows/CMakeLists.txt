project(breakpad_common)

include(${CMAKE_CURRENT_SOURCE_DIR}/diaSDK.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/windowsSdk.cmake)

set(srcList ${srcDir}/common/windows/dia_util.cc
            ${srcDir}/common/windows/dia_util.h
            ${srcDir}/common/windows/guid_string.cc
            ${srcDir}/common/windows/guid_string.h
            ${srcDir}/common/windows/http_upload.cc
            ${srcDir}/common/windows/http_upload.h
            ${srcDir}/common/windows/module_info.h
            ${srcDir}/common/windows/omap.cc
            ${srcDir}/common/windows/omap.h
            ${srcDir}/common/windows/pdb_source_line_writer.cc
            ${srcDir}/common/windows/pdb_source_line_writer.h
            ${srcDir}/common/windows/pe_source_line_writer.cc
            ${srcDir}/common/windows/pe_source_line_writer.h
            ${srcDir}/common/windows/pe_util.cc
            ${srcDir}/common/windows/pe_util.h
            ${srcDir}/common/windows/string_utils-inl.h
            ${srcDir}/common/windows/string_utils.cc
            ${srcDir}/common/windows/sym_upload_v2_protocol.cc
            ${srcDir}/common/windows/sym_upload_v2_protocol.h
            ${srcDir}/common/windows/symbol_collector_client.cc
            ${srcDir}/common/windows/symbol_collector_client.h
)

include_directories(${srcDir}
                    ${srcDir}/common/windows
                    ${DIASDK_INCLUDE_DIR}
                    "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.37.32822/include"
                    "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.37.32822/atlmfc/include"
                    ${windowsSdkIncDir}
                    )


link_libraries(Wininet Imagehlp Dbghelp)

add_library(breakpad_common STATIC ${srcList})


