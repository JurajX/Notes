set(
    HDRS
    ${CMAKE_CURRENT_SOURCE_DIR}/Publisher.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Subscriber.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/StockGrabber.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/StockObserver.hpp
)

install(
    FILES ${HDRS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    COMPONENT development
)

add_library(
    observer SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/StockGrabber.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/StockObserver.cpp
    ${HDRS}
)
add_compile_options(
    TARGET observer
    OPTIM_OPTIONS "-O3"
)

set_target_properties(
    observer PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_link_libraries(
    observer
    PUBLIC
    fmt::fmt
)

target_include_directories(
    observer PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/Observer>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>
)

add_exe(
    NAME Observer
    LINK_LIBRARIES fmt::fmt observer
    OPTIM_OPTIONS "-O3"
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED
    CXX_EXTENSIONS_OFF
)
