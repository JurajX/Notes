cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME "Design Patterns")
project(
    ${PROJECT_NAME} VERSION 0.0.0
    DESCRIPTION "Principles of designing a software."
    LANGUAGES C CXX
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(initiate)
initiate()

add_subdirectory(Strategy)
