cmake_minimum_required(VERSION 3.14)

project(TongueTwisters LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/examples)

# set(LIB_DBMANAGER_CODE_HEADERS${CMAKE_CURRENT_SOURCE_DIR}/lib/DBManager/includes)

set(QML_IMPORT_PATH ${CMAKE_CURRENT_LIST_DIR}/qml
    CACHE STRING "Qt Creator 5.15 extra qml import paths"
    FORCE)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick Svg REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Svg LREQUIRED)


set(PROJECT_HEADERS
        includes/modeltonguetwisters.hpp
        includes/readdata.hpp
        ${QML_IMPORT_PATH}
        # ${LIB_DBMANAGER_CODE_HEADERS}
    )

set(PROJECT_SOURCES
        srcs/modeltonguetwisters.cpp
        srcs/readdata.cpp
        srcs/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/qml.qrc
        ${CMAKE_CURRENT_LIST_DIR}/resources.qrc
        ${CMAKE_CURRENT_LIST_DIR}/application.qrc
        ${CMAKE_CURRENT_LIST_DIR}/databases.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TongueTwisters
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
    )
else()
    if(ANDROID)
        add_library(TongueTwisters SHARED
            ${PROJECT_SOURCES}
            ${PROJECT_HEADERS}
        )
    else()
        add_executable(TongueTwisters
          ${PROJECT_SOURCES}
          ${PROJECT_HEADERS}
        )
endif()

endif()

target_include_directories(TongueTwisters
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/includes
    )


find_package(dbManager)

target_compile_definitions(TongueTwisters
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(TongueTwisters
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Svg dbManager)

add_subdirectory(tests)
add_subdirectory(lib)
