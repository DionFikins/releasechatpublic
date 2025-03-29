cmake_minimum_required(VERSION 3.5)

project(releasechatclient VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES releasechatclient_ru_RU.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.hpp
        mainwindow.ui
        controlmenu.cpp
        controlmenu.hpp
        controlmenu.ui
        loginform.cpp
        loginform.hpp
        loginform.ui
        registrationform.cpp
        registrationform.hpp
        registrationform.ui
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(releasechatclient
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(releasechatclient SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(releasechatclient
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(releasechatclient PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(releasechatclient PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS releasechatclient
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(releasechatclient)
endif()
