
set(windowsSdkVersion "10.0.19041.0")
set(windowsSdkDir "C:/Program Files (x86)/Windows Kits/10")
set(windowsSdkIncDir "${windowsSdkDir}/include/${windowsSdkVersion}/um"
                        "${windowsSdkDir}/include/${windowsSdkVersion}/shared"
                        "${windowsSdkDir}/include/${windowsSdkVersion}/winrt"
                        "${windowsSdkDir}/include/${windowsSdkVersion}/ucrt"
                        "${windowsSdkDir}/include/${windowsSdkVersion}/cppwinrt"
)

set(windowsSdkLibDir "${windowsSdkDir}/lib/${windowsSdkVersion}/um/${CMAKE_SYSTEM_PROCESSOR}"
                        "${windowsSdkDir}/lib/${windowsSdkVersion}/ucrt/${CMAKE_SYSTEM_PROCESSOR}"
                        "${windowsSdkDir}/lib/${windowsSdkVersion}/onecore/${CMAKE_SYSTEM_PROCESSOR}"
                        "${windowsSdkDir}/lib/${windowsSdkVersion}/store/${CMAKE_SYSTEM_PROCESSOR}"
                        "${windowsSdkDir}/lib/${windowsSdkVersion}/cppwinrt/${CMAKE_SYSTEM_PROCESSOR}"
                        "${windowsSdkDir}/lib/${windowsSdkVersion}/winrt/${CMAKE_SYSTEM_PROCESSOR}"
                        )

message(STATUS "windowsSdkDir: ${windowsSdkDir}")