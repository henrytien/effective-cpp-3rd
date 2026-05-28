cmake_minimum_required(VERSION 3.20)

project(EffectiveCpp3rd
    VERSION 1.0.0
    DESCRIPTION "Effective C++ 3rd Edition - Code Examples"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(ItemHelpers)

option(BUILD_ALL_ITEMS "Build all Item examples" ON)

file(GLOB item_dirs RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/src" "src/Item[0-5][0-9]")
list(SORT item_dirs)

foreach(item_dir IN LISTS item_dirs)
    string(REGEX REPLACE "Item0*([0-9]+)" "\\1" item_num "${item_dir}")
    option(BUILD_ITEM_${item_num} "Build Item ${item_num}" ${BUILD_ALL_ITEMS})

    if(BUILD_ITEM_${item_num})
        add_subdirectory("src/${item_dir}")
    endif()
endforeach()
