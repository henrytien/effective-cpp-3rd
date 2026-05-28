function(add_item_executable TARGET_NAME)
    if(ARGC GREATER 1)
        set(SOURCES ${ARGN})
    else()
        file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
    endif()

    add_executable(${TARGET_NAME} ${SOURCES})

    target_include_directories(${TARGET_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
    )

    if(MSVC)
        target_compile_options(${TARGET_NAME} PRIVATE /W4)
    else()
        target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic)
    endif()

    set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endfunction()
