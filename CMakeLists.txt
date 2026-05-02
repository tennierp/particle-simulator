cmake_minimum_required(VERSION 4.0)
project(particle-simulator)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-3.4.0
)
FetchContent_MakeAvailable(SDL3)

add_executable(particle-simulator main.cpp
        Engine.cpp
        Engine.h
        Particle.h
        World.cpp
        World.h
        Utils.h)
target_link_libraries(particle-simulator PRIVATE SDL3::SDL3)

if(WIN32)
    add_custom_command(TARGET particle-simulator POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SDL3::SDL3>
            $<TARGET_FILE_DIR:particle-simulator>
    )
endif()
