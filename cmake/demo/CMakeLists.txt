if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    add_subdirectory(windows)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_subdirectory(linux)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Android")
    add_subdirectory(linux)
else()
    message(FATAL_ERROR "Unsupported platform")
endif()
