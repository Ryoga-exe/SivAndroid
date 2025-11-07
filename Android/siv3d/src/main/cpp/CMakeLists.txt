cmake_minimum_required(VERSION 3.22.1)

project(siv3d
    VERSION 0.6.16
    LANGUAGES CXX C ASM
    HOMEPAGE_URL "https://github.com/Siv3D/OpenSiv3D"
    DESCRIPTION "A C++20 framework for creative coding (2D/3D games, media art, visualizers, and simulators)."
)

set(SIV3D_INTERNAL_SOURCES
    ../../../../../Siv3D/src/Siv3D-Platform/Android/Siv3D/Siv3DMain.cpp
)

set(SIV3D_INTERNAL_INCLUDE_DIRS
    ../../../../../Siv3D/include
    ../../../../../Siv3D/src
    ../../../../../Siv3D/src/Siv3D-Platform/Android
)

add_library(siv3d STATIC ${SIV3D_INTERNAL_SOURCES})

find_package(game-activity REQUIRED CONFIG)

# Forces the linker to keep the JNI entry point for GameActivity
set(CMAKE_SHARED_LINKER_FLAGS
        "${CMAKE_SHARED_LINKER_FLAGS} -u Java_com_google_androidgamesdk_GameActivity_initializeNativeCode")

target_link_libraries(siv3d
    game-activity::game-activity_static
    EGL
    GLESv3
    jnigraphics
    android
    log
)