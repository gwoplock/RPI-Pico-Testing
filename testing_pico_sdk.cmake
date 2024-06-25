cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_FETCH_FROM_GIT on)

include(/home/garrett/Documents/Testing/pico_sdk_import.cmake)

pico_sdk_init()

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)