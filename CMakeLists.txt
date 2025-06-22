cmake_minimum_required(VERSION 3.10)
project(CircuitSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include path for headers
include_directories(include)

# Vind alle cpp- en h-bestanden
file(GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB HEADER_FILES "${PROJECT_SOURCE_DIR}/include/*.h")

# Voeg main.cpp, source files en header files toe aan het project
add_executable(${PROJECT_NAME}
    main.cpp
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

# Zorg ervoor dat de compiler ook weet waar de headers zijn
target_include_directories(${PROJECT_NAME} PRIVATE include)
