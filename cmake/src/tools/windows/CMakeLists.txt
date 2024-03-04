project(tools)

include(${CMAKE_SOURCE_DIR}/src/common/windows/diaSDK.cmake)
include_directories(${srcDir}  ${DIASDK_INCLUDE_DIR})
link_libraries(Wininet Imagehlp Dbghelp breakpad_common ${DIASDK_LIBRARIES} version)

add_executable(dump_syms
    ${srcDir}/tools/windows/dump_syms/dump_syms.cc
)

# symupload.cc 依赖的breakpad_common中的google_breakpad::SymUploadV2ProtocolSend
# 需要在src\common\windows\sym_upload_v2_protocol.cc文件的static应该去掉才能链接到
add_executable(symupload
    ${srcDir}/tools/windows/symupload/symupload.cc
)