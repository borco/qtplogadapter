set(LIB_NAME qtplogwrapper)

qt_add_library(${LIB_NAME} STATIC
    MANUAL_FINALIZATION
    logging/basicformatter.cpp
    logging/basicformatter.h
    logging/guiappender.cpp
    logging/guiappender.h
    logging/messagehandler.cpp
    logging/messagehandler.h
    logging/setup.cpp
    logging/setup.h
)

target_include_directories(${LIB_NAME} PUBLIC
    src/3rdparty/plog/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${LIB_NAME} PUBLIC
    Qt6::Core
)

qt_finalize_target(${LIB_NAME})
