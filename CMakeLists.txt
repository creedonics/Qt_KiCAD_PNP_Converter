cmake_minimum_required(VERSION 3.16)

project(Test_QML VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup(REQUIRES 6.8)

set(CMAKE_AUTORCC ON)

qt_add_executable(appTest_QML
    main.cpp
    Resources.qrc

)

qt_add_qml_module(appTest_QML
    URI Test_QML
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES ConfigWindow.qml
        RESOURCES Resources.qrc
        SOURCES
        SOURCES writeconf.h writeconf.cpp
        SOURCES readconf.h readconf.cpp
        SOURCES caddata.h caddata.cpp
        SOURCES readkicadfile.h readkicadfile.cpp
        SOURCES readlibfile.h readlibfile.cpp
        SOURCES writelay.h writelay.cpp
        SOURCES writepcb.h writepcb.cpp
        QML_FILES LibraryWindow.qml
)



# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTest_QML PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTest_QML
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTest_QML
    PRIVATE Qt6::Quick
)
target_link_libraries(appTest_QML PRIVATE Qt6::Core)
target_link_libraries(appTest_QML PRIVATE Qt6::Core)
target_link_libraries(appTest_QML PRIVATE Qt6::Core)
target_link_libraries(appTest_QML PRIVATE Qt6::Core)
target_link_libraries(appTest_QML PRIVATE Qt6::Core)
target_link_libraries(appTest_QML PRIVATE Qt6::Core)
target_link_libraries(appTest_QML PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS appTest_QML
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
