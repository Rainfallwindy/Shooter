cmake_minimum_required(VERSION 3.10)
project(Shooter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(h)
include_directories(raylib/include)

link_directories(raylib/lib)

add_executable(Shooter
cpp/main.cpp
cpp/Bullet.cpp
cpp/Player.cpp
cpp/Monster.cpp
cpp/Common.cpp
)

target_link_libraries(Shooter raylib winmm gdi32 user32 shell32)

add_custom_command(TARGET Shooter POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/raylib/lib/raylib.dll"
    $<TARGET_FILE_DIR:Shooter>
)