
cmake_minimum_required(VERSION 3.14)

project(TestModel} LANGUAGES CXX)
set(OUT_NAME testModel)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-g3 -Wall -Wextra -Werror")

# set(LIB_MORSE_CODE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../lib)
# set(LIB_MORSE_CODE_HEADERS${CMAKE_CURRENT_SOURCE_DIR}/../../lib/morseCodeLib/includes)
set(MODEL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../srcs/)
set(MODEL_PATH_H ${CMAKE_CURRENT_SOURCE_DIR}/../../includes/)


set(HEADERS
    includes/tst_model.hpp
	${MODEL_PATH_H}/readdata.hpp
    )

set(SOURCES
    srcs/tst_model.cpp
	${MODEL_PATH}/readdata.cpp
    )


find_package(Qt5 COMPONENTS Core Test REQUIRED)

add_executable(${OUT_NAME} ${SOURCES} ${HEADERS})
add_test(NAME testModel COMMAND testModel)
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
        ${CMAKE_CURRENT_LIST_DIR}/../../includes
        ${LIB_MORSE_CODE_PATH}
        ${LIB_MORSE_CODE_HEADERS}
        )



target_link_libraries(${OUT_NAME}
        PUBLIC
        Qt5::Core
        Qt5::Test
        )


