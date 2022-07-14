set(
    HDRS
    ${CMAKE_CURRENT_SOURCE_DIR}/Animal.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Dog.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Bird.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Flys.hpp
)

install(
    FILES ${HDRS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    COMPONENT development
)

add_library(
    strategy SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/Animal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Dog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Bird.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Flys.cpp
    ${HDRS}
)
add_compile_options(
    TARGET strategy
    OPTIM_OPTIONS "-O3"
)

set_target_properties(
    strategy PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_link_libraries(
    strategy
    PUBLIC
    fmt::fmt
)

target_include_directories(
    strategy PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/Strategy>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>
)

add_exe(
    NAME Strategy
    LINK_LIBRARIES fmt::fmt strategy
    OPTIM_OPTIONS "-O3"
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED
    CXX_EXTENSIONS_OFF
)
