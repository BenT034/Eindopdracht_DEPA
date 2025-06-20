cmake_minimum_required(VERSION 3.10)
project(CircuitSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME}
    main.cpp
    ${SOURCE_FILES}
)
target_include_directories(${PROJECT_NAME} PRIVATE include)


