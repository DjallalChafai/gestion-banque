cmake_minimum_required(VERSION 3.20)
project(gestion-banque VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets LinguistTools WebSockets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools WebSockets)
find_package(Qt6Sql REQUIRED)

# assets filess
set(PROJECT_RESOURCES assets.qrc)

# translations/locales files
set(GLOB TS_FILES "*.ts")

# C++ source code files
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        dialog.cpp
        fermer_compte.cpp
        solde_compte.cpp
        numero_compte.cpp
        retrait.cpp
        depot.cpp
        #mythread.cpp
        ${TS_FILES}
)

# header files
set(GLOB PROJECT_HEADERS "*.h")

# Qt UI files
set(GLOB PROJECT_FORMS "*.ui")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(gestion-banque
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        ${PROJECT_FORMS}
        ${PROJECT_RESOURCES}
    )

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(gestion-banque SHARED ${PROJECT_SOURCES})
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(gestion-banque ${PROJECT_SOURCES})
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(gestion-banque PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql Qt6::WebSockets)
#target_link_libraries(mytarget PUBLIC Qt6::Core5Compat)

set_target_properties(gestion-banque PROPERTIES WIN32_EXECUTABLE TRUE)

install(TARGETS gestion-banque
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(gestion-banque)
endif()
