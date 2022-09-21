cmake_minimum_required(VERSION 3.23)
project(INF147_TP1_VS)

set(CMAKE_CXX_STANDARD 14)

include_directories("INF147 TP1")

add_executable(INF147_TP1_VS
        "INF147 TP1/graphics.h"
        "INF147 TP1/main.cpp"
        "INF147 TP1/mod_bits.cpp"
        "INF147 TP1/mod_bits.h"
        "INF147 TP1/mod_cnc.cpp"
        "INF147 TP1/mod_cnc.h"
        "INF147 TP1/mod_com.cpp"
        "INF147 TP1/mod_com.h"
        "INF147 TP1/mod_math.cpp"
        "INF147 TP1/mod_math.h"
        "INF147 TP1/mod_outils.h"
        "INF147 TP1/mod_traceur.cpp"
        "INF147 TP1/mod_traceur.h")
