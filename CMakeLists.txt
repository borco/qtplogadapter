set(LIB_NAME QtPlogAdapter)

file(GLOB_RECURSE PLOG_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/plog/include/*.h)

qt_add_library(${LIB_NAME}
    STATIC
    ${PLOG_HEADERS}
    src/qtplogadapter/basicformatter.cpp
    src/qtplogadapter/basicformatter.h
    src/qtplogadapter/guiappender.cpp
    src/qtplogadapter/guiappender.h
    src/qtplogadapter/guimessage.h
    src/qtplogadapter/messagehandler.cpp
    src/qtplogadapter/messagehandler.h
    src/qtplogadapter/setup.cpp
    src/qtplogadapter/setup.h
)

qt_add_qml_module(${LIB_NAME}
    URI ${LIB_NAME}
    VERSION 1.0
    PLUGIN_TARGET ${LIB_NAME}Plugin
    QML_FILES
        src/qml/PlogMessageView.qml
    SOURCES
        src/qtplogadapter/plogmessagemodel.cpp
        src/qtplogadapter/plogmessagemodel.h
)

target_include_directories(${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/qtplogadapter
)

target_link_libraries(${LIB_NAME} PUBLIC
    Qt6::Core
    Qt6::Qml
    Qt6::Quick
)
