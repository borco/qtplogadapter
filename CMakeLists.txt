set(LIB_NAME QtPlogAdapter)

qt_add_library(${LIB_NAME} STATIC
    MANUAL_FINALIZATION
    src/qtplogadapter/basicformatter.cpp
    src/qtplogadapter/basicformatter.h
    src/qtplogadapter/guiappender.cpp
    src/qtplogadapter/guiappender.h
    src/qtplogadapter/messagehandler.cpp
    src/qtplogadapter/messagehandler.h
    src/qtplogadapter/setup.cpp
    src/qtplogadapter/setup.h
)

target_include_directories(${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/3rdparty/plog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

target_link_libraries(${LIB_NAME} PUBLIC
    Qt6::Core
)

qt_finalize_target(${LIB_NAME})
