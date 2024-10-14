cmake_minimum_required(VERSION 3.29)
project(321L6 C)

set(CMAKE_C_STANDARD 11)

add_executable(321L6
        gates.c
        gates.h
        logic_simulator.c
        logic_simulator_circuit.c
        logic_simulator_circuit.h)
