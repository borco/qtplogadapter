set(LIB_NAME qtplogwrapper)

qt_add_library(${LIB_NAME} STATIC
    MANUAL_FINALIZATION
    src/logging/basicformatter.cpp
    src/logging/basicformatter.h
    src/logging/guiappender.cpp
    src/logging/guiappender.h
    src/logging/messagehandler.cpp
    src/logging/messagehandler.h
    src/logging/setup.cpp
    src/logging/setup.h
)

target_include_directories(${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/3rdparty/plog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

target_link_libraries(${LIB_NAME} PUBLIC
    Qt6::Core
)

qt_finalize_target(${LIB_NAME})
