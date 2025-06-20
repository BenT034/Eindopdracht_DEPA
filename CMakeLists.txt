cmake_minimum_required(VERSION 3.10)
project(CircuitSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CircuitSimulator main.cpp
    src/Component.h src/Component.cpp
    src/InputNode.h src/InputNode.cpp
    src/ProbeNode.h src/ProbeNode.cpp
    src/GateNode.h src/GateNode.cpp
    src/AndGate.h src/AndGate.cpp
    src/OrGate.h src/OrGate.cpp
    src/NotGate.h src/NotGate.cpp
    src/NandGate.h src/NandGate.cpp
    src/NorGate.h src/NorGate.cpp
    src/XorGate.h src/XorGate.cpp
    src/Circuit.h src/Circuit.cpp
    src/Simulator.h src/Simulator.cpp
    src/FileReader.h src/FileReader.cpp
    src/Application.h src/Application.cpp
)

target_include_directories(CircuitSimulator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
