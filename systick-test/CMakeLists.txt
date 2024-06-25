cmake_minimum_required(VERSION 3.13)

include(../testing_pico_sdk.cmake)

project(systick_test)

add_executable(${PROJECT_NAME} 
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
)

pico_add_extra_outputs(${PROJECT_NAME})