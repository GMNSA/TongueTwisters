cmake_minimum_required(VERSION 3.14)

project(TestDbManager} LANGUAGES CXX)
set(OUT_NAME testDbManager)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-g3 -Wall -Wextra -Werror")

set(LIB_MORSE_CODE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../lib)
set(LIB_MORSE_CODE_HEADERS${CMAKE_CURRENT_SOURCE_DIR}/../../lib/DBManager/includes)

add_compile_definitions(FOR_TEST)


set(HEADERS
    includes/testdbmanager.hpp
    )

set(SOURCES
    srcs/testdbmanager.cpp
    )


find_package(Qt5 COMPONENTS Core Test Sql REQUIRED)

add_executable(${OUT_NAME} ${SOURCES} ${HEADERS})
add_test(NAME ${OUT_NAME} COMMAND ${OUT_NAME})
enable_testing()

message("LIB PATH -->>>>>  " ${PATH_LIBCONTAINERS})
message("TARGET -->>>>>  " ${TARGET})


set_target_properties(${OUT_NAME}
        PROPERTIES
        CMAKE_CXX_STANDARD 20
        CMAKE_CXX_STANDARD_REQUIRED ON
        )


target_include_directories(${OUT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/includes
        ${LIB_MORSE_CODE_PATH}
        ${LIB_MORSE_CODE_HEADERS}
        )


target_link_libraries(${OUT_NAME}
        PUBLIC
        Qt5::Core
        Qt5::Test
        Qt5::Sql
        dbManager
        )


